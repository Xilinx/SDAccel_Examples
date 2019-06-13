/*  main.c
 *  Created by Mengyao Zhao on 06/23/11.
 *    Version 0.1.5
 *  Last revision by Mengyao Zhao on 06/27/14.
 */

#include "kseq.h"
#include "ssw.h"
#include <emmintrin.h>
#include <math.h>
#include <omp.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>
#include <time.h>
#include <unistd.h>
#include <zlib.h>

#ifdef __GNUC__
#define LIKELY(x) __builtin_expect((x), 1)
#define UNLIKELY(x) __builtin_expect((x), 0)
#else
#define LIKELY(x) (x)
#define UNLIKELY(x) (x)
#endif

/*! @function
  @abstract  Round an integer to the next closest power-2 integer.
  @param  x  integer to be rounded (in place)
  @discussion x will be modified.
*/
#define kroundup32(x)                                                                                                  \
    (--(x), (x) |= (x) >> 1, (x) |= (x) >> 2, (x) |= (x) >> 4, (x) |= (x) >> 8, (x) |= (x) >> 16, ++(x))

KSEQ_INIT(gzFile, gzread);

// l is length
// m is allocated memory
void genSeq(kseq_t *read, kseq_t *ref) {
    const int reflen = 256;
    const int readlen = 128;

    int baseidx;

    read->name.s = strdup("READ");
    read->seq.s = (char *)malloc(readlen * sizeof(char) + 1);
    read->seq.m = readlen;
    ref->name.s = strdup("REF");
    ref->seq.s = (char *)malloc(reflen * sizeof(char) + 1);
    ref->seq.m = reflen;

    char bases[5] = "ACTG";
    for (baseidx = 0; baseidx < reflen; ++baseidx) {
        char b = bases[rand() % 4];
        ref->seq.s[baseidx] = b;
    }
    ref->seq.l = reflen;
    for (baseidx = 0; baseidx < readlen; ++baseidx) {
        char b = bases[rand() % 4];
        read->seq.s[baseidx] = b;
    }
    read->seq.l = readlen;
    ref->seq.s[reflen] = '\0';
    read->seq.s[readlen] = '\0';
    /*printf("READ: %s\nREF:  %s\n",read->seq.s,ref->seq.s);*/
}

void freeSeq(kseq_t *seq) {
    free(seq->name.s);
    free(seq->seq.s);
}

static void ssw_write(const s_align *a,
                      const kseq_t *ref_seq,
                      const kseq_t *read,
                      const char *read_seq, // strand == 0: original read; strand == 1: reverse complement read
                      const int8_t *table,
                      int8_t strand) { // 0: forward aligned ; 1: reverse complement aligned

    //fprintf(stdout, "target_name: %s\nquery_name: %s\noptimal_alignment_score: %d\t", ref_seq->name.s, read->name.s, a->score1);
    //if (a->score2 > 0) fprintf(stdout, "suboptimal_alignment_score: %d\t", a->score2);
    //if (strand == 0) fprintf(stdout, "strand: +\t");
    //else fprintf(stdout, "strand: -\t");
    //if (a->ref_begin1 + 1) fprintf(stdout, "target_begin: %d\t", a->ref_begin1 + 1);
    //fprintf(stdout, "target_end: %d\t", a->ref_end1 + 1);
    //if (a->read_begin1 + 1) fprintf(stdout, "query_begin: %d\t", a->read_begin1 + 1);
    //fprintf(stdout, "query_end: %d\n\n", a->read_end1 + 1);
    if (a->cigar) {
        int32_t c = 0, left = 0, e = 0, qb = a->ref_begin1, pb = a->read_begin1;
        uint32_t i;
        while (e < a->cigarLen || left > 0) {
            int32_t count = 0;
            int32_t q = qb;
            int32_t p = pb;
            fprintf(stdout, "Target: %8d    ", q + 1);
            for (c = e; c < a->cigarLen; ++c) {
                char letter = cigar_int_to_op(a->cigar[c]);
                uint32_t length = cigar_int_to_len(a->cigar[c]);
                uint32_t l = (count == 0 && left > 0) ? left : length;
                for (i = 0; i < l; ++i) {
                    if (letter == 'I')
                        fprintf(stdout, "-");
                    else {
                        fprintf(stdout, "%c", *(ref_seq->seq.s + q));
                        ++q;
                    }
                    ++count;
                    if (count == 60)
                        goto step2;
                }
            }
        step2:
            fprintf(stdout, "    %d\n                    ", q);
            q = qb;
            count = 0;
            for (c = e; c < a->cigarLen; ++c) {
                char letter = cigar_int_to_op(a->cigar[c]);
                uint32_t length = cigar_int_to_len(a->cigar[c]);
                uint32_t l = (count == 0 && left > 0) ? left : length;
                for (i = 0; i < l; ++i) {
                    if (letter == 'M') {
                        if (table[(int)*(ref_seq->seq.s + q)] == table[(int)*(read_seq + p)])
                            fprintf(stdout, "|");
                        else
                            fprintf(stdout, "*");
                        ++q;
                        ++p;
                    } else {
                        fprintf(stdout, " ");
                        if (letter == 'I')
                            ++p;
                        else
                            ++q;
                    }
                    ++count;
                    if (count == 60) {
                        qb = q;
                        goto step3;
                    }
                }
            }
        step3:
            p = pb;
            fprintf(stdout, "\nQuery:  %8d    ", p + 1);
            count = 0;
            for (c = e; c < a->cigarLen; ++c) {
                char letter = cigar_int_to_op(a->cigar[c]);
                uint32_t length = cigar_int_to_len(a->cigar[c]);
                uint32_t l = (count == 0 && left > 0) ? left : length;
                for (i = 0; i < l; ++i) {
                    if (letter == 'D')
                        fprintf(stdout, "-");
                    else {
                        fprintf(stdout, "%c", *(read_seq + p));
                        ++p;
                    }
                    ++count;
                    if (count == 60) {
                        pb = p;
                        left = l - i - 1;
                        e = (left == 0) ? (c + 1) : c;
                        goto end;
                    }
                }
            }
            e = c;
            left = 0;
        end:
            fprintf(stdout, "    %d\n\n", p);
        }
    }
}

void genSSWData(int niter, int numsample, kseq_t **read, kseq_t **ref) {
    //seed randrom to get more chaotic output
    srand(time(NULL));

    kseq_t *testread = (kseq_t *)malloc(sizeof(kseq_t) * niter * numsample);
    kseq_t *testref = (kseq_t *)malloc(sizeof(kseq_t) * niter * numsample);
    int ii;
    for (ii = 0; ii < niter * numsample; ++ii) {
        genSeq(&testread[ii], &testref[ii]);
    }
    *read = testread;
    *ref = testref;
}
void deleteSSWData(int niter, int numsample, kseq_t **read, kseq_t **ref) {
    kseq_t *testread = *read;
    kseq_t *testref = *ref;
    int ii;
    for (ii = 0; ii < niter * numsample; ++ii) {
        freeSeq(&testread[ii]);
        freeSeq(&testref[ii]);
    }
    free(*read);
    free(*ref);
}

float SSW(
    int numsample, int tid, kseq_t *read, kseq_t *ref, unsigned int *maxr, unsigned int *maxc, unsigned int *maxv) {

    kseq_t *read_seq, *ref_seq;
    int32_t l, m, k, match = 2, mismatch = 2, gap_open = 3, gap_extension = 1, path = 0, n = 5, s1 = 67108864, s2 = 128,
                     filter = 0;
    int8_t *mata = (int8_t *)calloc(25, sizeof(int8_t));
    const int8_t *mat = mata;
    int8_t *ref_num = (int8_t *)malloc(s1);
    int8_t *num = (int8_t *)malloc(s2), *num_rc = 0;
    char *read_rc = 0;
    int total = numsample;
    float total_cups = 0;

    /* This table is used to transform nucleotide letters into numbers. */
    int8_t nt_table[128] = {4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 1, 4, 4, 4, 2, 4, 4, 4, 4, 4, 4,
                            4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 0, 4, 1, 4, 4, 4, 2,
                            4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 3, 3, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4};

    int8_t *table = nt_table;
    fprintf(stdout, "Processing %d samples using Intel Vector Instruction Set in Thread %d\n", numsample, tid);

    // initialize scoring matrix for genome sequences
    for (l = k = 0; LIKELY(l < 4); ++l) {
        for (m = 0; LIKELY(m < 4); ++m)
            mata[k++] = l == m ? match : -mismatch; /* weight_match : -weight_mismatch */
        mata[k++] = 0;                              // ambiguous base
    }
    for (m = 0; LIKELY(m < 5); ++m)
        mata[k++] = 0;

    // alignment
    int ii;
    for (ii = 0; ii < total; ++ii) {
        // clear screen newline
        //printf("\033[2J\033[1;1H");

        read_seq = &read[ii];
        ref_seq = &ref[ii];
        {
            s_profile *p = 0;
            int32_t readLen = read_seq->seq.l;
            int32_t maskLen = readLen / 2;

            while (readLen >= s2) {
                ++s2;
                kroundup32(s2);
                num = (int8_t *)realloc(num, s2);
            }
            for (m = 0; m < readLen; ++m)
                num[m] = table[(int)read_seq->seq.s[m]];
            p = ssw_init(num, readLen, mat, n, 2);

            {
                s_align *result, *result_rc = 0;
                int32_t refLen = ref_seq->seq.l;
                int8_t flag = 0;
                while (refLen > s1) {
                    ++s1;
                    kroundup32(s1);
                    ref_num = (int8_t *)realloc(ref_num, s1);
                }
                for (m = 0; m < refLen; ++m)
                    ref_num[m] = table[(int)ref_seq->seq.s[m]];
                if (path == 1)
                    flag = 2;
                result = ssw_align(p,
                                   ref_num,
                                   refLen,
                                   gap_open,
                                   gap_extension,
                                   flag,
                                   filter,
                                   0,
                                   maskLen,
                                   &total_cups,
                                   &maxr[ii],
                                   &maxc[ii],
                                   &maxv[ii]);
                if (result_rc && result_rc->score1 > result->score1 && result_rc->score1 >= filter) {
                    ssw_write(result_rc, ref_seq, read_seq, read_rc, table, 1);
                } else if (result && result->score1 >= filter) {
                    ssw_write(result, ref_seq, read_seq, read_seq->seq.s, table, 0);
                } else if (!result)
                    return 1;
                if (result_rc)
                    align_destroy(result_rc);
                align_destroy(result);
            }

            init_destroy(p);
        }
    }

    if (num_rc) {
        free(num_rc);
        free(read_rc);
    }
    //kseq_destroy(read_seq);
    free(num);
    free(ref_num);
    free(mata);
    return total_cups / (numsample);
}

long xgetusec() {
    struct timeval tval_result;
    gettimeofday(&tval_result, NULL);
    long retval = tval_result.tv_sec * 1e6 + tval_result.tv_usec;
    return retval;
}

int SSW_par(int nblocks,
            int nSamples,
            int nThreads,
            char **rd,
            char **rf,
            unsigned int *maxr,
            unsigned int *maxc,
            unsigned int *maxv) {
    int i;
    omp_set_num_threads(nThreads);
    kseq_t *read, *ref;
    clock_t start, end;
    start = clock();
    printf("Generating samples\n");
    genSSWData(nblocks, nSamples, &read, &ref);
    printf("Done generating %d samples\n", nblocks * nSamples);
    end = clock();
    float cpu_time_read = ((float)(end - start)) / CLOCKS_PER_SEC;
    printf("Time to generate Samples Secs: %f\n", (float)cpu_time_read);
    printf("Distributing samples on %d threads\n", nThreads);
    double ostart = omp_get_wtime();
    int ID;
    int nIter = nThreads;
    int samples = nblocks * nSamples / nIter;
#pragma omp parallel for
    for (i = 0; i < nIter; ++i) {
        ID = omp_get_thread_num();
        SSW(samples,
            ID,
            (read + i * samples),
            (ref + i * samples),
            (maxr + i * samples),
            (maxc + i * samples),
            (maxv + i * samples));
    }
    double oend = omp_get_wtime();
    float Gsamples = 256 * 128;
    Gsamples = Gsamples * nSamples * nblocks;
    Gsamples = Gsamples / (1024 * 1024 * 1024);
    float Gcups = Gsamples / (float)(oend - ostart);

    printf("Total Cell Updates(G)=%f\n", Gsamples);
    printf("Total Threads=%d\n", nThreads);
    printf("Time to complete computation Secs: %f\n", (float)(oend - ostart));
    printf("Cell updates per second(GCups)=%f\n", Gcups);
    for (i = 0; i < nblocks * nSamples; ++i) {
        strcpy(rd[i], read[i].seq.s);
        strcpy(rf[i], ref[i].seq.s);
    }
    deleteSSWData(nblocks, nSamples, &read, &ref);

    return 0;
}

/*
int main (int argc, char * const argv[]) {
  
  clock_t start, end;
  float cpu_time;
  kseq_t *read_seq, *ref_seq;
  int32_t l, m, k, match = 2, mismatch = 2, gap_open = 3, gap_extension = 1, path = 0, n = 5, s1 = 67108864, s2 = 128, filter=0;
  int8_t* mata = (int8_t*)calloc(25, sizeof(int8_t));
  
  int8_t nt_table[128] = {
    4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 0, 4, 1,  4, 4, 4, 2,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 4, 4, 4,  3, 3, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 0, 4, 1,  4, 4, 4, 2,  4, 4, 4, 4,  4, 4, 4, 4,
    4, 4, 4, 4,  3, 3, 4, 4,  4, 4, 4, 4,  4, 4, 4, 4
  };
  
  
  // Parse command line.
  while ((l = getopt(argc, argv, "m:x:o:e:a:f:pcrsh")) >= 0) {
    switch (l) {
    case 'm': match = atoi(optarg); break;
    case 'x': mismatch = atoi(optarg); break;
    case 'o': gap_open = atoi(optarg); break;
    case 'e': gap_extension = atoi(optarg); break;
    case 'f': filter = atoi(optarg); break;
    case 'c': path = 1; break;
    }
  }
  if (0 && optind + 2 > argc) {
    fprintf(stderr, "\n");
    fprintf(stderr, "Usage: ssw_test [options] ... <target.fasta> <query.fasta>(or <query.fastq>)\n");
    fprintf(stderr, "Options:\n");
    fprintf(stderr, "\t-m N\tN is a positive integer for weight match in genome sequence alignment. [default: 2]\n");
    fprintf(stderr, "\t-x N\tN is a positive integer. -N will be used as weight mismatch in genome sequence alignment. [default: 2]\n");
    fprintf(stderr, "\t-o N\tN is a positive integer. -N will be used as the weight for the gap opening. [default: 3]\n");
    fprintf(stderr, "\t-e N\tN is a positive integer. -N will be used as the weight for the gap extension. [default: 1]\n");
    fprintf(stderr, "\t-c\tReturn the alignment path.\n");
    fprintf(stderr, "\t-f N\tN is a positive integer. Only output the alignments with the Smith-Waterman score >= N.\n");
    return 1;
  }
  SSW();
  
  }
  */
