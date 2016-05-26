#include "krnl_sobel.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void krnl_sobel::thread_exitcond2_fu_23667_p2() {
    exitcond2_fu_23667_p2 = (!indvar1_phi_fu_2669_p4.read().is_01() || !rd_cnt_burst_reg_70824.read().is_01())? sc_lv<1>(): sc_lv<1>(indvar1_phi_fu_2669_p4.read() == rd_cnt_burst_reg_70824.read());
}

void krnl_sobel::thread_exitcond3_fu_23724_p2() {
    exitcond3_fu_23724_p2 = (!tmp_5_reg_70799.read().is_01() || !ap_const_lv2_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_5_reg_70799.read() == ap_const_lv2_0);
}

void krnl_sobel::thread_exitcond4_fu_23560_p2() {
    exitcond4_fu_23560_p2 = (!p_ph3_reg_2633.read().is_01() || !tmp_11_reg_70926.read().is_01())? sc_lv<1>(): sc_lv<1>(p_ph3_reg_2633.read() == tmp_11_reg_70926.read());
}

void krnl_sobel::thread_exitcond7_fu_23925_p2() {
    exitcond7_fu_23925_p2 = (!indvar2_phi_fu_2736_p4.read().is_01() || !rd_cnt_burst1_reg_71118.read().is_01())? sc_lv<1>(): sc_lv<1>(indvar2_phi_fu_2736_p4.read() == rd_cnt_burst1_reg_71118.read());
}

void krnl_sobel::thread_exitcond8_fu_23982_p2() {
    exitcond8_fu_23982_p2 = (!p_ph6_reg_2718.read().is_01() || !tmp_45_reg_71181.read().is_01())? sc_lv<1>(): sc_lv<1>(p_ph6_reg_2718.read() == tmp_45_reg_71181.read());
}

void krnl_sobel::thread_exitcond9_fu_24017_p2() {
    exitcond9_fu_24017_p2 = (!tmp_46_reg_71188.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<1>(): sc_lv<1>(tmp_46_reg_71188.read() == ap_const_lv32_1);
}

void krnl_sobel::thread_exitcond_fu_23489_p2() {
    exitcond_fu_23489_p2 = (!indvar_phi_fu_2658_p4.read().is_01() || !wr_cnt_burst_reg_70880.read().is_01())? sc_lv<1>(): sc_lv<1>(indvar_phi_fu_2658_p4.read() == wr_cnt_burst_reg_70880.read());
}

void krnl_sobel::thread_gepindex10_fu_24819_p2() {
    gepindex10_fu_24819_p2 = (!ap_const_lv14_E88.is_01() || !tmp_221_reg_71666.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_E88) + sc_biguint<14>(tmp_221_reg_71666.read()));
}

void krnl_sobel::thread_gepindex11_fu_24857_p2() {
    gepindex11_fu_24857_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_223_reg_71706.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_223_reg_71706.read()));
}

void krnl_sobel::thread_gepindex12_fu_24867_p2() {
    gepindex12_fu_24867_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_223_reg_71706.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_223_reg_71706.read()));
}

void krnl_sobel::thread_gepindex13_fu_47778_p2() {
    gepindex13_fu_47778_p2 = (!ap_const_lv14_E88.is_01() || !tmp_259_reg_80704.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_E88) + sc_biguint<14>(tmp_259_reg_80704.read()));
}

void krnl_sobel::thread_gepindex14_fu_47804_p2() {
    gepindex14_fu_47804_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_259_reg_80704.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_259_reg_80704.read()));
}

void krnl_sobel::thread_gepindex15_fu_47814_p2() {
    gepindex15_fu_47814_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_259_reg_80704.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_259_reg_80704.read()));
}

void krnl_sobel::thread_gepindex16_fu_47852_p2() {
    gepindex16_fu_47852_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_265_reg_80739.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_265_reg_80739.read()));
}

void krnl_sobel::thread_gepindex17_fu_47862_p2() {
    gepindex17_fu_47862_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_265_reg_80739.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_265_reg_80739.read()));
}

void krnl_sobel::thread_gepindex18_fu_47942_p2() {
    gepindex18_fu_47942_p2 = (!ap_const_lv14_E88.is_01() || !tmp_270_reg_80780.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_E88) + sc_biguint<14>(tmp_270_reg_80780.read()));
}

void krnl_sobel::thread_gepindex1924_cast_fu_24524_p1() {
    gepindex1924_cast_fu_24524_p1 = esl_sext<64,14>(gepindex1_fu_24519_p2.read());
}

void krnl_sobel::thread_gepindex1929_cast_fu_24534_p1() {
    gepindex1929_cast_fu_24534_p1 = esl_sext<64,14>(gepindex2_fu_24529_p2.read());
}

void krnl_sobel::thread_gepindex1937_cast_fu_24572_p1() {
    gepindex1937_cast_fu_24572_p1 = esl_sext<64,14>(gepindex3_fu_24567_p2.read());
}

void krnl_sobel::thread_gepindex1942_cast_fu_24582_p1() {
    gepindex1942_cast_fu_24582_p1 = esl_sext<64,14>(gepindex4_fu_24577_p2.read());
}

void krnl_sobel::thread_gepindex1955_cast_fu_24664_p1() {
    gepindex1955_cast_fu_24664_p1 = esl_sext<64,14>(gepindex5_fu_24659_p2.read());
}

void krnl_sobel::thread_gepindex1960_cast_fu_24678_p1() {
    gepindex1960_cast_fu_24678_p1 = esl_sext<64,14>(gepindex6_fu_24673_p2.read());
}

void krnl_sobel::thread_gepindex1965_cast_fu_24688_p1() {
    gepindex1965_cast_fu_24688_p1 = esl_sext<64,14>(gepindex7_fu_24683_p2.read());
}

void krnl_sobel::thread_gepindex1981_cast_fu_24788_p1() {
    gepindex1981_cast_fu_24788_p1 = esl_sext<64,14>(gepindex8_fu_24783_p2.read());
}

void krnl_sobel::thread_gepindex1986_cast_fu_24814_p1() {
    gepindex1986_cast_fu_24814_p1 = esl_sext<64,14>(gepindex9_fu_24809_p2.read());
}

void krnl_sobel::thread_gepindex1991_cast_fu_24824_p1() {
    gepindex1991_cast_fu_24824_p1 = esl_sext<64,14>(gepindex10_fu_24819_p2.read());
}

void krnl_sobel::thread_gepindex19_fu_47956_p2() {
    gepindex19_fu_47956_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_270_reg_80780.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_270_reg_80780.read()));
}

void krnl_sobel::thread_gepindex1_fu_24519_p2() {
    gepindex1_fu_24519_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_162_reg_71496.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_162_reg_71496.read()));
}

void krnl_sobel::thread_gepindex2007_cast_fu_24862_p1() {
    gepindex2007_cast_fu_24862_p1 = esl_sext<64,14>(gepindex11_fu_24857_p2.read());
}

void krnl_sobel::thread_gepindex2012_cast_fu_24872_p1() {
    gepindex2012_cast_fu_24872_p1 = esl_sext<64,14>(gepindex12_fu_24867_p2.read());
}

void krnl_sobel::thread_gepindex2025_cast_fu_47783_p1() {
    gepindex2025_cast_fu_47783_p1 = esl_sext<64,14>(gepindex13_fu_47778_p2.read());
}

void krnl_sobel::thread_gepindex2030_cast_fu_47809_p1() {
    gepindex2030_cast_fu_47809_p1 = esl_sext<64,14>(gepindex14_fu_47804_p2.read());
}

void krnl_sobel::thread_gepindex2035_cast_fu_47819_p1() {
    gepindex2035_cast_fu_47819_p1 = esl_sext<64,14>(gepindex15_fu_47814_p2.read());
}

void krnl_sobel::thread_gepindex2051_cast_fu_47857_p1() {
    gepindex2051_cast_fu_47857_p1 = esl_sext<64,14>(gepindex16_fu_47852_p2.read());
}

void krnl_sobel::thread_gepindex2056_cast_fu_47867_p1() {
    gepindex2056_cast_fu_47867_p1 = esl_sext<64,14>(gepindex17_fu_47862_p2.read());
}

void krnl_sobel::thread_gepindex2069_cast_fu_47947_p1() {
    gepindex2069_cast_fu_47947_p1 = esl_sext<64,14>(gepindex18_fu_47942_p2.read());
}

void krnl_sobel::thread_gepindex2074_cast_fu_47961_p1() {
    gepindex2074_cast_fu_47961_p1 = esl_sext<64,14>(gepindex19_fu_47956_p2.read());
}

void krnl_sobel::thread_gepindex2079_cast_fu_47971_p1() {
    gepindex2079_cast_fu_47971_p1 = esl_sext<64,14>(gepindex20_fu_47966_p2.read());
}

void krnl_sobel::thread_gepindex2095_cast_fu_48071_p1() {
    gepindex2095_cast_fu_48071_p1 = esl_sext<64,14>(gepindex21_fu_48066_p2.read());
}

void krnl_sobel::thread_gepindex20_fu_47966_p2() {
    gepindex20_fu_47966_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_270_reg_80780.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_270_reg_80780.read()));
}

void krnl_sobel::thread_gepindex2100_cast_fu_48097_p1() {
    gepindex2100_cast_fu_48097_p1 = esl_sext<64,14>(gepindex22_fu_48092_p2.read());
}

void krnl_sobel::thread_gepindex2105_cast_fu_48107_p1() {
    gepindex2105_cast_fu_48107_p1 = esl_sext<64,14>(gepindex23_fu_48102_p2.read());
}

void krnl_sobel::thread_gepindex2121_cast_fu_48145_p1() {
    gepindex2121_cast_fu_48145_p1 = esl_sext<64,14>(gepindex24_fu_48140_p2.read());
}

void krnl_sobel::thread_gepindex2126_cast_fu_48155_p1() {
    gepindex2126_cast_fu_48155_p1 = esl_sext<64,14>(gepindex25_fu_48150_p2.read());
}

void krnl_sobel::thread_gepindex21_fu_48066_p2() {
    gepindex21_fu_48066_p2 = (!ap_const_lv14_E88.is_01() || !tmp_275_reg_80880.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_E88) + sc_biguint<14>(tmp_275_reg_80880.read()));
}

void krnl_sobel::thread_gepindex22_fu_48092_p2() {
    gepindex22_fu_48092_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_275_reg_80880.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_275_reg_80880.read()));
}

void krnl_sobel::thread_gepindex23_fu_48102_p2() {
    gepindex23_fu_48102_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_275_reg_80880.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_275_reg_80880.read()));
}

void krnl_sobel::thread_gepindex24_fu_48140_p2() {
    gepindex24_fu_48140_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_279_reg_80920.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_279_reg_80920.read()));
}

void krnl_sobel::thread_gepindex25_fu_48150_p2() {
    gepindex25_fu_48150_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_279_reg_80920.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_279_reg_80920.read()));
}

void krnl_sobel::thread_gepindex2_fu_24529_p2() {
    gepindex2_fu_24529_p2 = (!ap_const_lv14_E88.is_01() || !tmp_162_reg_71496.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_E88) + sc_biguint<14>(tmp_162_reg_71496.read()));
}

void krnl_sobel::thread_gepindex3_fu_24567_p2() {
    gepindex3_fu_24567_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_193_reg_71536.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_193_reg_71536.read()));
}

void krnl_sobel::thread_gepindex4_fu_24577_p2() {
    gepindex4_fu_24577_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_193_reg_71536.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_193_reg_71536.read()));
}

void krnl_sobel::thread_gepindex5_fu_24659_p2() {
    gepindex5_fu_24659_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_207_reg_71577.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_207_reg_71577.read()));
}

void krnl_sobel::thread_gepindex6_fu_24673_p2() {
    gepindex6_fu_24673_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_207_reg_71577.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_207_reg_71577.read()));
}

void krnl_sobel::thread_gepindex7_fu_24683_p2() {
    gepindex7_fu_24683_p2 = (!ap_const_lv14_E88.is_01() || !tmp_207_reg_71577.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_E88) + sc_biguint<14>(tmp_207_reg_71577.read()));
}

void krnl_sobel::thread_gepindex8_fu_24783_p2() {
    gepindex8_fu_24783_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_221_reg_71666.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_221_reg_71666.read()));
}

void krnl_sobel::thread_gepindex9_fu_24809_p2() {
    gepindex9_fu_24809_p2 = (!ap_const_lv14_1E88.is_01() || !tmp_221_reg_71666.read().is_01())? sc_lv<14>(): (sc_biguint<14>(ap_const_lv14_1E88) + sc_biguint<14>(tmp_221_reg_71666.read()));
}

void krnl_sobel::thread_gepindex_cast_fu_24498_p1() {
    gepindex_cast_fu_24498_p1 = esl_sext<64,14>(gepindex_fu_24493_p2.read());
}

void krnl_sobel::thread_gepindex_fu_24493_p2() {
    gepindex_fu_24493_p2 = (!ap_const_lv14_2E88.is_01() || !tmp_162_reg_71496.read().is_01())? sc_lv<14>(): (sc_bigint<14>(ap_const_lv14_2E88) + sc_biguint<14>(tmp_162_reg_71496.read()));
}

void krnl_sobel::thread_gmem_ARADDR() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3703.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_19_reg_89658.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2955.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_16_reg_80657.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2815.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_15_reg_80598.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2677.read()) && 
                !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero3_fu_47464_p2.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = arg_in_pixels_i_0_sum2_cast_fu_47445_p1.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2526.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_13_reg_80467.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2386.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_12_reg_80418.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2112.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_9_reg_80380.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1538.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_11_reg_71449.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1398.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_10_reg_71390.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1259.read()) && 
                !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero2_fu_24179_p2.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = arg_in_pixels_i_0_sum1_cast_fu_24169_p1.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1115.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_7_reg_71226.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state975.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_6_reg_71170.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state837.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())))) {
        gmem_ARADDR = gmem_addr_5_reg_71102.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state700.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_3_reg_71071.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state293.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARADDR = gmem_addr_4_reg_70988.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state9.read()) && 
                 esl_seteq<1,1,1>(tmp_6_fu_23263_p2.read(), ap_const_lv1_0) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1252.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, tmp_66_fu_24094_p2.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())))) {
        gmem_ARADDR = arg_in_pixels_reg_70720.read();
    } else {
        gmem_ARADDR = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void krnl_sobel::thread_gmem_ARLEN() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2815.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARLEN = tmp_209_reg_80569.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1398.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARLEN = tmp_131_reg_71363.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1252.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, tmp_66_fu_24094_p2.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARLEN = tmp_41_reg_70833.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state975.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2386.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())))) {
        gmem_ARLEN = tmp_69_reg_71125.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state293.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state700.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state837.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1115.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1259.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero2_fu_24179_p2.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1538.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2112.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2526.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2677.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero3_fu_47464_p2.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2955.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3703.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())))) {
        gmem_ARLEN = ap_const_lv32_1;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state9.read()) && 
                esl_seteq<1,1,1>(tmp_6_fu_23263_p2.read(), ap_const_lv1_0) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read()))) {
        gmem_ARLEN = tmp_41_fu_23288_p1.read();
    } else {
        gmem_ARLEN =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_gmem_ARVALID() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state9.read()) && 
          esl_seteq<1,1,1>(tmp_6_fu_23263_p2.read(), ap_const_lv1_0) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state293.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state700.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state837.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state975.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1115.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1252.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, tmp_66_fu_24094_p2.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1259.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero2_fu_24179_p2.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1398.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1538.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2112.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2386.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2526.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2677.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero3_fu_47464_p2.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2815.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2955.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3703.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_ARREADY.read())))) {
        gmem_ARVALID = ap_const_logic_1;
    } else {
        gmem_ARVALID = ap_const_logic_0;
    }
}

void krnl_sobel::thread_gmem_AWADDR() {
    if (esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) {
        if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3838.read())) {
            gmem_AWADDR = gmem_addr_19_reg_89658.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3564.read())) {
            gmem_AWADDR = gmem_addr_18_reg_89581.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3430.read())) {
            gmem_AWADDR = gmem_addr_17_reg_89540.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state428.read())) {
            gmem_AWADDR = gmem_addr_4_reg_70988.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state154.read())) {
            gmem_AWADDR = gmem_addr_1_reg_70911.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read())) {
            gmem_AWADDR = gmem_addr_reg_70867.read();
        } else {
            gmem_AWADDR = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
        }
    } else {
        gmem_AWADDR = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void krnl_sobel::thread_gmem_AWLEN() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3564.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read()))) {
        gmem_AWLEN = tmp_261_reg_89556.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state154.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read()))) {
        gmem_AWLEN = tmp_36_reg_70886.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state428.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3430.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3838.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())))) {
        gmem_AWLEN = ap_const_lv32_1;
    } else {
        gmem_AWLEN =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_gmem_AWVALID() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state154.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state428.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3430.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3564.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3838.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_AWREADY.read())))) {
        gmem_AWVALID = ap_const_logic_1;
    } else {
        gmem_AWVALID = ap_const_logic_0;
    }
}

void krnl_sobel::thread_gmem_BREADY() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state152.read()) && 
          !esl_seteq<1,1,1>(gmem_BVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state291.read()) && 
          !esl_seteq<1,1,1>(gmem_BVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3701.read()) && 
          !esl_seteq<1,1,1>(gmem_BVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3563.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero4_reg_89530.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state3563_blk.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state561.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond4_reg_70974.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state561_blk.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3971.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond27_reg_89644.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state3971_blk.read())))) {
        gmem_BREADY = ap_const_logic_1;
    } else {
        gmem_BREADY = ap_const_logic_0;
    }
}

void krnl_sobel::thread_gmem_RREADY() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond2_reg_71045.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state696_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond7_reg_71195.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1110_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond14_reg_71413.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1533_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond11_reg_80358.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2108_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond18_reg_80436.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2521_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond22_reg_80621.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2950_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state834.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2246.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state971.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1249.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1393.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2382.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2660.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2811.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1672.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3089.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state427.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3837.read()) && 
          !esl_seteq<1,1,1>(gmem_RVALID.read(), ap_const_logic_0)))) {
        gmem_RREADY = ap_const_logic_1;
    } else {
        gmem_RREADY = ap_const_logic_0;
    }
}

void krnl_sobel::thread_gmem_WDATA() {
    if (esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) {
        if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3839.read())) {
            gmem_WDATA = set_part2_reg_89690.read();
        } else if (ap_condition_sig_4480.read()) {
            gmem_WDATA = set_part1_fu_70566_p5.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3431.read())) {
            gmem_WDATA = predata1_reg_89571.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state429.read())) {
            gmem_WDATA = set_part8_reg_71020.read();
        } else if (ap_condition_sig_4184.read()) {
            gmem_WDATA = set_part4_fu_23547_p5.read();
        } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state20.read())) {
            gmem_WDATA = predata_reg_70896.read();
        } else {
            gmem_WDATA =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
        }
    } else {
        gmem_WDATA =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_gmem_WSTRB() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3839.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read()))) {
        gmem_WSTRB = mask3_reg_89695.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3431.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read()))) {
        gmem_WSTRB = mask2_reg_89576.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state429.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read()))) {
        gmem_WSTRB = mask1_reg_71025.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp0_iter1_exitcond_reg_70937.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter2.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp7_iter1_exitcond26_reg_89607.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())))) {
        gmem_WSTRB = ap_const_lv4_F;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state20.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read()))) {
        gmem_WSTRB = mask_reg_70901.read();
    } else {
        gmem_WSTRB =  (sc_lv<4>) ("XXXX");
    }
}

void krnl_sobel::thread_gmem_WVALID() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state20.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp0_iter1_exitcond_reg_70937.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state429.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3431.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp7_iter1_exitcond26_reg_89607.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3839.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_0, ap_reg_ioackin_gmem_WREADY.read())))) {
        gmem_WVALID = ap_const_logic_1;
    } else {
        gmem_WVALID = ap_const_logic_0;
    }
}

void krnl_sobel::thread_gmem_blk_n_AR() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state9.read()) && 
          esl_seteq<1,1,1>(tmp_6_fu_23263_p2.read(), ap_const_lv1_0)) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1252.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, tmp_66_fu_24094_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state293.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state700.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state837.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state975.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1115.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1259.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero2_fu_24179_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1398.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1538.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2112.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2386.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2526.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2677.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero3_fu_47464_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2815.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2955.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3703.read()))) {
        gmem_blk_n_AR = m_axi_gmem_ARREADY.read();
    } else {
        gmem_blk_n_AR = ap_const_logic_1;
    }
}

void krnl_sobel::thread_gmem_blk_n_AW() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state154.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state428.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3430.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3564.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3838.read()))) {
        gmem_blk_n_AW = m_axi_gmem_AWREADY.read();
    } else {
        gmem_blk_n_AW = ap_const_logic_1;
    }
}

void krnl_sobel::thread_gmem_blk_n_B() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state152.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state291.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state561.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond4_reg_70974.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3563.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero4_reg_89530.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3701.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3971.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond27_reg_89644.read())))) {
        gmem_blk_n_B = m_axi_gmem_BVALID.read();
    } else {
        gmem_blk_n_B = ap_const_logic_1;
    }
}

void krnl_sobel::thread_gmem_blk_n_R() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond2_reg_71045.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond11_reg_80358.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state427.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state834.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state971.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2382.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond7_reg_71195.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1249.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1393.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond14_reg_71413.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1672.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2246.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond18_reg_80436.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2660.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2811.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond22_reg_80621.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3089.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3837.read()))) {
        gmem_blk_n_R = m_axi_gmem_RVALID.read();
    } else {
        gmem_blk_n_R = ap_const_logic_1;
    }
}

void krnl_sobel::thread_gmem_blk_n_W() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state20.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp0_iter1_exitcond_reg_70937.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state429.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3431.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp7_iter1_exitcond26_reg_89607.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3839.read()))) {
        gmem_blk_n_W = m_axi_gmem_WREADY.read();
    } else {
        gmem_blk_n_W = ap_const_logic_1;
    }
}

void krnl_sobel::thread_grp_fu_22839_opcode() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3389.read()))) {
        grp_fu_22839_opcode = ap_const_lv2_1;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1695.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3112.read()))) {
        grp_fu_22839_opcode = ap_const_lv2_0;
    } else {
        grp_fu_22839_opcode =  (sc_lv<2>) ("XX");
    }
}

void krnl_sobel::thread_grp_fu_22839_p0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3389.read())) {
        grp_fu_22839_p0 = p_089_reg2mem_0_i_i_reg_22776.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read())) {
        grp_fu_22839_p0 = maxg_0_reg2mem729_0_i_i_fu_914.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1695.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3112.read()))) {
        grp_fu_22839_p0 = reg_23085.read();
    } else {
        grp_fu_22839_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22839_p1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3389.read()))) {
        grp_fu_22839_p1 = ming_0_reg2mem731_0_i_i_fu_918.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1695.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3112.read()))) {
        grp_fu_22839_p1 = reg_23090.read();
    } else {
        grp_fu_22839_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22853_p0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3106.read())) {
        grp_fu_22853_p0 = tmp_185_reg_80988.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1689.read())) {
        grp_fu_22853_p0 = tmp_109_reg_71774.read();
    } else {
        grp_fu_22853_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22856_p0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3106.read())) {
        grp_fu_22856_p0 = tmp_188_reg_80993.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1689.read())) {
        grp_fu_22856_p0 = tmp_112_reg_71779.read();
    } else {
        grp_fu_22856_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22859_opcode() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1972.read())) {
        grp_fu_22859_opcode = ap_const_lv5_2;
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1704.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, or_cond879_i_i_fu_25002_p2.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1970.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, demorgan_fu_46686_p2.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3121.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_0, or_cond887_i_i_fu_48285_p2.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3387.read()) && 
                 !esl_seteq<1,1,1>(ap_const_lv1_0, demorgan1_fu_69982_p2.read())))) {
        grp_fu_22859_opcode = ap_const_lv5_1;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1703.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3120.read()))) {
        grp_fu_22859_opcode = ap_const_lv5_4;
    } else {
        grp_fu_22859_opcode =  (sc_lv<5>) ("XXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22859_p0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3387.read())) {
        grp_fu_22859_p0 = x_i_i8_i_i_i23_i_i_fu_70024_p1.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3120.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3121.read()))) {
        grp_fu_22859_p0 = reg_23117.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1972.read())) {
        grp_fu_22859_p0 = p_0107_reg2mem651_0_i_i_reg_12706.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1970.read())) {
        grp_fu_22859_p0 = x_i_i8_i_i_i_i_i_fu_46728_p1.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1703.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1704.read()))) {
        grp_fu_22859_p0 = reg_23095.read();
    } else {
        grp_fu_22859_p0 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22859_p1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1972.read())) {
        grp_fu_22859_p1 = maxg_0_reg2mem729_0_i_i_fu_914.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1703.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1704.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1970.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3120.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3121.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3387.read()))) {
        grp_fu_22859_p1 = ap_const_lv32_0;
    } else {
        grp_fu_22859_p1 =  (sc_lv<32>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_grp_fu_22900_p2() {
    grp_fu_22900_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !tmp_cast2_reg_71035.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) - sc_biguint<32>(tmp_cast2_reg_71035.read()));
}

void krnl_sobel::thread_grp_fu_22904_p2() {
    grp_fu_22904_p2 = (!tmp_5_reg_70799.read().is_01() || !ap_const_lv2_1.is_01())? sc_lv<1>(): sc_lv<1>(tmp_5_reg_70799.read() == ap_const_lv2_1);
}

void krnl_sobel::thread_grp_fu_22909_p2() {
    grp_fu_22909_p2 = (!tmp_5_reg_70799.read().is_01() || !ap_const_lv2_2.is_01())? sc_lv<1>(): sc_lv<1>(tmp_5_reg_70799.read() == ap_const_lv2_2);
}

void krnl_sobel::thread_grp_fu_22914_p2() {
    grp_fu_22914_p2 = (!ap_const_lv32_FFFFFFFF.is_01() || !szrow_0_reg2mem_0_i_i_reg_70759.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFF) + sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()));
}

void krnl_sobel::thread_grp_fu_22919_p2() {
    grp_fu_22919_p2 = (!prealign_wr_cnt_reg_71108.read().is_01() || !ap_const_lv3_1.is_01())? sc_lv<1>(): sc_lv<1>(prealign_wr_cnt_reg_71108.read() == ap_const_lv3_1);
}

void krnl_sobel::thread_grp_fu_22924_p2() {
    grp_fu_22924_p2 = (!prealign_wr_cnt_reg_71108.read().is_01() || !ap_const_lv3_2.is_01())? sc_lv<1>(): sc_lv<1>(prealign_wr_cnt_reg_71108.read() == ap_const_lv3_2);
}

void krnl_sobel::thread_grp_fu_23124_p2() {
    grp_fu_23124_p2 = (!reg_22982.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(reg_22982.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void krnl_sobel::thread_grp_fu_23143_p2() {
    grp_fu_23143_p2 = (!reg_22982.read().is_01() || !ap_const_lv32_2.is_01())? sc_lv<32>(): (sc_biguint<32>(reg_22982.read()) + sc_biguint<32>(ap_const_lv32_2));
}

void krnl_sobel::thread_grp_fu_23184_p2() {
    grp_fu_23184_p2 = (!ap_const_lv64_0.is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(ap_const_lv64_0) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_grp_fu_23274_ce() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state9.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state9_io_blk.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state15.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state10.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state11.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state12.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state13.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state14.read()))) {
        grp_fu_23274_ce = ap_const_logic_1;
    } else {
        grp_fu_23274_ce = ap_const_logic_0;
    }
}

void krnl_sobel::thread_grp_fu_23274_p0() {
    grp_fu_23274_p0 =  (sc_lv<31>) (y_0_reg2mem737_0_i_i_cast_fu_23259_p1.read());
}

void krnl_sobel::thread_grp_fu_24109_ce() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1252.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1252_io_blk.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1258.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1253.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1254.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1255.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1256.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1257.read()))) {
        grp_fu_24109_ce = ap_const_logic_1;
    } else {
        grp_fu_24109_ce = ap_const_logic_0;
    }
}

void krnl_sobel::thread_grp_fu_24109_p0() {
    grp_fu_24109_p0 =  (sc_lv<31>) (grp_fu_24109_p00.read());
}

void krnl_sobel::thread_grp_fu_24109_p00() {
    grp_fu_24109_p00 = esl_zext<32,31>(tmp_67_fu_24099_p2.read());
}

void krnl_sobel::thread_grp_fu_47377_p0() {
    grp_fu_47377_p0 =  (sc_lv<31>) (grp_fu_47377_p00.read());
}

void krnl_sobel::thread_grp_fu_47377_p00() {
    grp_fu_47377_p00 = esl_zext<32,31>(tmp_153_fu_47367_p2.read());
}

void krnl_sobel::thread_grp_fu_47755_p0() {
    grp_fu_47755_p0 =  (sc_lv<31>) (y3_0_reg2mem641_0_i_i_cast_reg_80506.read());
}

void krnl_sobel::thread_grp_fu_70685_p0() {
    grp_fu_70685_p0 =  (sc_lv<16>) (tmp_184_fu_48207_p1.read());
}

void krnl_sobel::thread_grp_fu_70685_p1() {
    grp_fu_70685_p1 =  (sc_lv<16>) (tmp_184_fu_48207_p1.read());
}

void krnl_sobel::thread_grp_fu_70691_p0() {
    grp_fu_70691_p0 =  (sc_lv<16>) (tmp_108_fu_24924_p1.read());
}

void krnl_sobel::thread_grp_fu_70691_p1() {
    grp_fu_70691_p1 =  (sc_lv<16>) (tmp_108_fu_24924_p1.read());
}

void krnl_sobel::thread_grp_fu_70697_p0() {
    grp_fu_70697_p0 =  (sc_lv<16>) (tmp_111_fu_24928_p1.read());
}

void krnl_sobel::thread_grp_fu_70697_p1() {
    grp_fu_70697_p1 =  (sc_lv<16>) (tmp_111_fu_24928_p1.read());
}

void krnl_sobel::thread_grp_fu_70703_p0() {
    grp_fu_70703_p0 =  (sc_lv<16>) (tmp_187_fu_48211_p1.read());
}

void krnl_sobel::thread_grp_fu_70703_p1() {
    grp_fu_70703_p1 =  (sc_lv<16>) (tmp_187_fu_48211_p1.read());
}

void krnl_sobel::thread_icmp1_fu_46578_p2() {
    icmp1_fu_46578_p2 = (!tmp_4792_fu_46568_p4.read().is_01() || !ap_const_lv39_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4792_fu_46568_p4.read() != ap_const_lv39_0);
}

void krnl_sobel::thread_icmp2_fu_46840_p2() {
    icmp2_fu_46840_p2 = (!tmp_4799_reg_80318.read().is_01() || !ap_const_lv3_0.is_01())? sc_lv<1>(): (sc_bigint<3>(tmp_4799_reg_80318.read()) > sc_bigint<3>(ap_const_lv3_0));
}

void krnl_sobel::thread_icmp3_fu_69746_p2() {
    icmp3_fu_69746_p2 = (!tmp_4915_fu_69736_p4.read().is_01() || !ap_const_lv38_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4915_fu_69736_p4.read() != ap_const_lv38_0);
}

void krnl_sobel::thread_icmp4_fu_69874_p2() {
    icmp4_fu_69874_p2 = (!tmp_4920_fu_69864_p4.read().is_01() || !ap_const_lv39_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4920_fu_69864_p4.read() != ap_const_lv39_0);
}

void krnl_sobel::thread_icmp5_fu_70136_p2() {
    icmp5_fu_70136_p2 = (!tmp_4925_reg_89467.read().is_01() || !ap_const_lv3_0.is_01())? sc_lv<1>(): (sc_bigint<3>(tmp_4925_reg_89467.read()) > sc_bigint<3>(ap_const_lv3_0));
}

void krnl_sobel::thread_icmp_fu_46450_p2() {
    icmp_fu_46450_p2 = (!tmp_4786_fu_46440_p4.read().is_01() || !ap_const_lv38_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4786_fu_46440_p4.read() != ap_const_lv38_0);
}

void krnl_sobel::thread_indvar1_phi_fu_2669_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond2_reg_71045.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read()))) {
        indvar1_phi_fu_2669_p4 = indvar_next1_reg_71049.read();
    } else {
        indvar1_phi_fu_2669_p4 = indvar1_reg_2665.read();
    }
}

void krnl_sobel::thread_indvar2_phi_fu_2736_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond7_reg_71195.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read()))) {
        indvar2_phi_fu_2736_p4 = indvar_next2_reg_71199.read();
    } else {
        indvar2_phi_fu_2736_p4 = indvar2_reg_2732.read();
    }
}

void krnl_sobel::thread_indvar3_phi_fu_12728_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond11_reg_80358.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read()))) {
        indvar3_phi_fu_12728_p4 = indvar_next3_reg_80362.read();
    } else {
        indvar3_phi_fu_12728_p4 = indvar3_reg_12724.read();
    }
}

void krnl_sobel::thread_indvar4_phi_fu_2850_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond14_reg_71413.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read()))) {
        indvar4_phi_fu_2850_p4 = indvar_next4_reg_71417.read();
    } else {
        indvar4_phi_fu_2850_p4 = indvar4_reg_2846.read();
    }
}

void krnl_sobel::thread_indvar5_phi_fu_12795_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond18_reg_80436.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read()))) {
        indvar5_phi_fu_12795_p4 = indvar_next5_reg_80440.read();
    } else {
        indvar5_phi_fu_12795_p4 = indvar5_reg_12791.read();
    }
}

void krnl_sobel::thread_indvar6_phi_fu_12919_p4() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond22_reg_80621.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read()))) {
        indvar6_phi_fu_12919_p4 = indvar_next6_reg_80625.read();
    } else {
        indvar6_phi_fu_12919_p4 = indvar6_reg_12915.read();
    }
}

void krnl_sobel::thread_indvar7_phi_fu_22832_p4() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond26_reg_89607.read()))) {
        indvar7_phi_fu_22832_p4 = indvar_next7_reg_89611.read();
    } else {
        indvar7_phi_fu_22832_p4 = indvar7_reg_22828.read();
    }
}

void krnl_sobel::thread_indvar_next1_fu_23672_p2() {
    indvar_next1_fu_23672_p2 = (!indvar1_phi_fu_2669_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar1_phi_fu_2669_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next2_fu_23930_p2() {
    indvar_next2_fu_23930_p2 = (!indvar2_phi_fu_2736_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar2_phi_fu_2736_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next3_fu_47070_p2() {
    indvar_next3_fu_47070_p2 = (!indvar3_phi_fu_12728_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar3_phi_fu_12728_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next4_fu_24316_p2() {
    indvar_next4_fu_24316_p2 = (!indvar4_phi_fu_2850_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar4_phi_fu_2850_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next5_fu_47233_p2() {
    indvar_next5_fu_47233_p2 = (!indvar5_phi_fu_12795_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar5_phi_fu_12795_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next6_fu_47602_p2() {
    indvar_next6_fu_47602_p2 = (!indvar6_phi_fu_12919_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar6_phi_fu_12919_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next7_fu_70513_p2() {
    indvar_next7_fu_70513_p2 = (!indvar7_phi_fu_22832_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar7_phi_fu_22832_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_next_fu_23494_p2() {
    indvar_next_fu_23494_p2 = (!indvar_phi_fu_2658_p4.read().is_01() || !ap_const_lv30_1.is_01())? sc_lv<30>(): (sc_biguint<30>(indvar_phi_fu_2658_p4.read()) + sc_biguint<30>(ap_const_lv30_1));
}

void krnl_sobel::thread_indvar_phi_fu_2658_p4() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_reg_70937.read()))) {
        indvar_phi_fu_2658_p4 = indvar_next_reg_70941.read();
    } else {
        indvar_phi_fu_2658_p4 = indvar_reg_2654.read();
    }
}

void krnl_sobel::thread_indvars_iv_next1_fu_23656_p2() {
    indvars_iv_next1_fu_23656_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !indvars_iv1_reg_2596.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) + sc_biguint<32>(indvars_iv1_reg_2596.read()));
}

void krnl_sobel::thread_indvars_iv_next2_fu_24469_p2() {
    indvars_iv_next2_fu_24469_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !indvars_iv2_reg_2743.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) + sc_biguint<32>(indvars_iv2_reg_2743.read()));
}

void krnl_sobel::thread_indvars_iv_next3_fu_70680_p2() {
    indvars_iv_next3_fu_70680_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !indvars_iv3_reg_12802.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) + sc_biguint<32>(indvars_iv3_reg_12802.read()));
}

void krnl_sobel::thread_indvars_iv_next_fu_70675_p2() {
    indvars_iv_next_fu_70675_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !indvars_iv_reg_12812.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) + sc_biguint<32>(indvars_iv_reg_12812.read()));
}

void krnl_sobel::thread_isNeg_fu_70234_p3() {
    isNeg_fu_70234_p3 = sh_assign_fu_70228_p2.read().range(8, 8);
}

void krnl_sobel::thread_krnl_sobel_resbuf_addr1_fu_70527_p2() {
    krnl_sobel_resbuf_addr1_fu_70527_p2 = (!krnl_sobel_resbuf_mult1_fu_70519_p3.read().is_01() || !p_ph_cast_reg_89586.read().is_01())? sc_lv<32>(): (sc_biguint<32>(krnl_sobel_resbuf_mult1_fu_70519_p3.read()) + sc_biguint<32>(p_ph_cast_reg_89586.read()));
}

void krnl_sobel::thread_krnl_sobel_resbuf_addr_fu_23508_p2() {
    krnl_sobel_resbuf_addr_fu_23508_p2 = (!krnl_sobel_resbuf_mult_fu_23500_p3.read().is_01() || !p_ph1_cast_reg_70916.read().is_01())? sc_lv<32>(): (sc_biguint<32>(krnl_sobel_resbuf_mult_fu_23500_p3.read()) + sc_biguint<32>(p_ph1_cast_reg_70916.read()));
}

void krnl_sobel::thread_krnl_sobel_resbuf_mult1_fu_70519_p3() {
    krnl_sobel_resbuf_mult1_fu_70519_p3 = esl_concat<30,2>(indvar7_phi_fu_22832_p4.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_krnl_sobel_resbuf_mult_fu_23500_p3() {
    krnl_sobel_resbuf_mult_fu_23500_p3 = esl_concat<30,2>(indvar_phi_fu_2658_p4.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_krnl_sobel_rowbuf0_mult1_fu_47076_p3() {
    krnl_sobel_rowbuf0_mult1_fu_47076_p3 = esl_concat<30,2>(indvar3_phi_fu_12728_p4.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_krnl_sobel_rowbuf0_mult_fu_23678_p3() {
    krnl_sobel_rowbuf0_mult_fu_23678_p3 = esl_concat<30,2>(indvar1_phi_fu_2669_p4.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_krnl_sobel_rowbuf1_addr1_fu_47239_p3() {
    krnl_sobel_rowbuf1_addr1_fu_47239_p3 = esl_concat<30,2>(indvar5_phi_fu_12795_p4.read(), p_ph10_reg_12755.read());
}

void krnl_sobel::thread_krnl_sobel_rowbuf1_addr_fu_23936_p3() {
    krnl_sobel_rowbuf1_addr_fu_23936_p3 = esl_concat<30,2>(indvar2_phi_fu_2736_p4.read(), p_ph4_reg_2696.read());
}

void krnl_sobel::thread_krnl_sobel_rowbuf2_addr1_fu_47608_p3() {
    krnl_sobel_rowbuf2_addr1_fu_47608_p3 = esl_concat<30,2>(indvar6_phi_fu_12919_p4.read(), p_ph13_reg_12893.read());
}

void krnl_sobel::thread_krnl_sobel_rowbuf2_addr_fu_24322_p3() {
    krnl_sobel_rowbuf2_addr_fu_24322_p3 = esl_concat<30,2>(indvar4_phi_fu_2850_p4.read(), p_ph7_reg_2810.read());
}

void krnl_sobel::thread_loc_V_1_fu_70220_p1() {
    loc_V_1_fu_70220_p1 = p_Val2_s_fu_70207_p1.read().range(23-1, 0);
}

void krnl_sobel::thread_loc_V_fu_70210_p4() {
    loc_V_fu_70210_p4 = p_Val2_s_fu_70207_p1.read().range(30, 23);
}

void krnl_sobel::thread_lower_bound1_cast_fu_70449_p1() {
    lower_bound1_cast_fu_70449_p1 = esl_zext<32,5>(lower_bound1_fu_70442_p3.read());
}

void krnl_sobel::thread_lower_bound1_fu_70442_p3() {
    lower_bound1_fu_70442_p3 = esl_concat<2,3>(tmp_260_reg_89518.read(), ap_const_lv3_0);
}

void krnl_sobel::thread_lower_bound_cast_fu_23426_p1() {
    lower_bound_cast_fu_23426_p1 = esl_zext<32,5>(lower_bound_fu_23419_p3.read());
}

void krnl_sobel::thread_lower_bound_fu_23419_p3() {
    lower_bound_fu_23419_p3 = esl_concat<2,3>(tmp_28_reg_70838.read(), ap_const_lv3_0);
}

void krnl_sobel::thread_m_i7_i_i_i53_1_reg2mem_0_i_i_fu_70146_p3() {
    m_i7_i_i_i53_1_reg2mem_0_i_i_fu_70146_p3 = (!tmp_501_fu_70141_p2.read()[0].is_01())? sc_lv<23>(): ((tmp_501_fu_70141_p2.read()[0].to_bool())? ap_const_lv23_0: tmp_4923_reg_89431.read());
}

void krnl_sobel::thread_m_i7_i_i_i_1_reg2mem_0_i_i_fu_46850_p3() {
    m_i7_i_i_i_1_reg2mem_0_i_i_fu_46850_p3 = (!tmp_414_fu_46845_p2.read()[0].is_01())? sc_lv<23>(): ((tmp_414_fu_46845_p2.read()[0].to_bool())? ap_const_lv23_0: tmp_4797_reg_80282.read());
}

void krnl_sobel::thread_mask1_fu_23650_p2() {
    mask1_fu_23650_p2 = (!mask_shtamt1_fu_23645_p2.read().is_01())? sc_lv<4>(): ap_const_lv4_F >> (unsigned short)mask_shtamt1_fu_23645_p2.read().to_uint();
}

void krnl_sobel::thread_mask2_fu_70462_p2() {
    mask2_fu_70462_p2 = (!mask_shtamt2_fu_70459_p1.read().is_01())? sc_lv<4>(): ap_const_lv4_F << (unsigned short)mask_shtamt2_fu_70459_p1.read().to_uint();
}

void krnl_sobel::thread_mask3_fu_70669_p2() {
    mask3_fu_70669_p2 = (!mask_shtamt3_fu_70664_p2.read().is_01())? sc_lv<4>(): ap_const_lv4_F >> (unsigned short)mask_shtamt3_fu_70664_p2.read().to_uint();
}

void krnl_sobel::thread_mask_fu_23439_p2() {
    mask_fu_23439_p2 = (!mask_shtamt_fu_23436_p1.read().is_01())? sc_lv<4>(): ap_const_lv4_F << (unsigned short)mask_shtamt_fu_23436_p1.read().to_uint();
}

void krnl_sobel::thread_mask_shtamt1_fu_23645_p2() {
    mask_shtamt1_fu_23645_p2 = (!ap_const_lv4_4.is_01() || !tmp_63_reg_71005.read().is_01())? sc_lv<4>(): (sc_biguint<4>(ap_const_lv4_4) - sc_biguint<4>(tmp_63_reg_71005.read()));
}

void krnl_sobel::thread_mask_shtamt2_fu_70459_p1() {
    mask_shtamt2_fu_70459_p1 = esl_zext<4,2>(tmp_260_reg_89518.read());
}

void krnl_sobel::thread_mask_shtamt3_fu_70664_p2() {
    mask_shtamt3_fu_70664_p2 = (!ap_const_lv4_4.is_01() || !tmp_267_reg_89675.read().is_01())? sc_lv<4>(): (sc_biguint<4>(ap_const_lv4_4) - sc_biguint<4>(tmp_267_reg_89675.read()));
}

void krnl_sobel::thread_mask_shtamt_fu_23436_p1() {
    mask_shtamt_fu_23436_p1 = esl_zext<4,2>(tmp_28_reg_70838.read());
}

void krnl_sobel::thread_maxg_1_reg2mem723_0_i_i_to_int_fu_46941_p1() {
    maxg_1_reg2mem723_0_i_i_to_int_fu_46941_p1 = reg_23107.read();
}

void krnl_sobel::thread_maxg_2_reg2mem649_0_i_i_fu_46992_p3() {
    maxg_2_reg2mem649_0_i_i_fu_46992_p3 = (!tmp_424_fu_46987_p2.read()[0].is_01())? sc_lv<32>(): ((tmp_424_fu_46987_p2.read()[0].to_bool())? p_0107_reg2mem651_0_i_i_reg_12706.read(): reg_23107.read());
}

void krnl_sobel::thread_mem_index_gep1_fu_24539_p2() {
    mem_index_gep1_fu_24539_p2 = (!tmp_155_reg_71483.read().is_01() || !mem_index_phi_cast_reg_71305.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_155_reg_71483.read()) + sc_biguint<16>(mem_index_phi_cast_reg_71305.read()));
}

void krnl_sobel::thread_mem_index_gep2_fu_24591_p2() {
    mem_index_gep2_fu_24591_p2 = (!tmp_199_fu_24587_p1.read().is_01() || !mem_index_phi160_cast_reg_71298.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_199_fu_24587_p1.read()) + sc_biguint<16>(mem_index_phi160_cast_reg_71298.read()));
}

void krnl_sobel::thread_mem_index_gep3_fu_24720_p2() {
    mem_index_gep3_fu_24720_p2 = (!tmp_218_fu_24716_p1.read().is_01() || !mem_index_phi160_cast_reg_71298.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_218_fu_24716_p1.read()) + sc_biguint<16>(mem_index_phi160_cast_reg_71298.read()));
}

void krnl_sobel::thread_mem_index_gep4_fu_24829_p2() {
    mem_index_gep4_fu_24829_p2 = (!tmp_218_reg_71653.read().is_01() || !mem_index_phi_cast_reg_71305.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_218_reg_71653.read()) + sc_biguint<16>(mem_index_phi_cast_reg_71305.read()));
}

void krnl_sobel::thread_mem_index_gep5_fu_47746_p2() {
    mem_index_gep5_fu_47746_p2 = (!tmp_255_fu_47742_p1.read().is_01() || !mem_index_phi303_cast_reg_80493.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_255_fu_47742_p1.read()) + sc_biguint<16>(mem_index_phi303_cast_reg_80493.read()));
}

void krnl_sobel::thread_mem_index_gep6_fu_47824_p2() {
    mem_index_gep6_fu_47824_p2 = (!tmp_255_reg_80691.read().is_01() || !mem_index_phi302_cast_reg_80500.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_255_reg_80691.read()) + sc_biguint<16>(mem_index_phi302_cast_reg_80500.read()));
}

void krnl_sobel::thread_mem_index_gep7_fu_47876_p2() {
    mem_index_gep7_fu_47876_p2 = (!tmp_269_fu_47872_p1.read().is_01() || !mem_index_phi303_cast_reg_80493.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_269_fu_47872_p1.read()) + sc_biguint<16>(mem_index_phi303_cast_reg_80493.read()));
}

void krnl_sobel::thread_mem_index_gep8_fu_48003_p2() {
    mem_index_gep8_fu_48003_p2 = (!tmp_274_fu_47999_p1.read().is_01() || !mem_index_phi303_cast_reg_80493.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_274_fu_47999_p1.read()) + sc_biguint<16>(mem_index_phi303_cast_reg_80493.read()));
}

void krnl_sobel::thread_mem_index_gep9_fu_48112_p2() {
    mem_index_gep9_fu_48112_p2 = (!tmp_274_reg_80867.read().is_01() || !mem_index_phi302_cast_reg_80500.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_274_reg_80867.read()) + sc_biguint<16>(mem_index_phi302_cast_reg_80500.read()));
}

void krnl_sobel::thread_mem_index_gep_fu_24460_p2() {
    mem_index_gep_fu_24460_p2 = (!tmp_155_fu_24456_p1.read().is_01() || !mem_index_phi160_cast_reg_71298.read().is_01())? sc_lv<16>(): (sc_biguint<16>(tmp_155_fu_24456_p1.read()) + sc_biguint<16>(mem_index_phi160_cast_reg_71298.read()));
}

void krnl_sobel::thread_mem_index_phi160_cast_fu_24082_p1() {
    mem_index_phi160_cast_fu_24082_p1 = esl_zext<16,14>(mem_index_phi1_reg_2753.read());
}

void krnl_sobel::thread_mem_index_phi302_cast_fu_47354_p1() {
    mem_index_phi302_cast_fu_47354_p1 = esl_zext<16,14>(mem_index_phi3_reg_12833.read());
}

void krnl_sobel::thread_mem_index_phi303_cast_fu_47350_p1() {
    mem_index_phi303_cast_fu_47350_p1 = esl_zext<16,14>(mem_index_phi2_reg_12822.read());
}

void krnl_sobel::thread_mem_index_phi_cast_fu_24086_p1() {
    mem_index_phi_cast_fu_24086_p1 = esl_zext<16,14>(mem_index_phi_reg_2764.read());
}

void krnl_sobel::thread_ming_1_reg2mem725_0_i_i_to_int_fu_47000_p1() {
    ming_1_reg2mem725_0_i_i_to_int_fu_47000_p1 = reg_23112.read();
}

void krnl_sobel::thread_ming_2_reg2mem647_0_i_i_fu_47047_p3() {
    ming_2_reg2mem647_0_i_i_fu_47047_p3 = (!tmp_430_fu_47042_p2.read()[0].is_01())? sc_lv<32>(): ((tmp_430_fu_47042_p2.read()[0].to_bool())? p_0107_reg2mem651_0_i_i_reg_12706.read(): reg_23112.read());
}

void krnl_sobel::thread_mod_ne_zero1_fu_23793_p2() {
    mod_ne_zero1_fu_23793_p2 = (!tmp_5_reg_70799.read().is_01() || !ap_const_lv2_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_5_reg_70799.read() != ap_const_lv2_0);
}

void krnl_sobel::thread_mod_ne_zero2_fu_24179_p2() {
    mod_ne_zero2_fu_24179_p2 = (!tmp_130_reg_71324.read().is_01() || !ap_const_lv2_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_130_reg_71324.read() != ap_const_lv2_0);
}

void krnl_sobel::thread_mod_ne_zero3_fu_47464_p2() {
    mod_ne_zero3_fu_47464_p2 = (!tmp_208_reg_80524.read().is_01() || !ap_const_lv2_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_208_reg_80524.read() != ap_const_lv2_0);
}

void krnl_sobel::thread_mod_ne_zero4_fu_70342_p2() {
    mod_ne_zero4_fu_70342_p2 = (!tmp_260_fu_70328_p1.read().is_01() || !ap_const_lv2_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_260_fu_70328_p1.read() != ap_const_lv2_0);
}

void krnl_sobel::thread_mod_ne_zero_fu_23360_p2() {
    mod_ne_zero_fu_23360_p2 = (!tmp_28_reg_70838.read().is_01() || !ap_const_lv2_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_28_reg_70838.read() != ap_const_lv2_0);
}

void krnl_sobel::thread_newSel151_cast_fu_46656_p1() {
    newSel151_cast_fu_46656_p1 = esl_zext<64,63>(newSel2_fu_46648_p3.read());
}

void krnl_sobel::thread_newSel153_cast_fu_69928_p1() {
    newSel153_cast_fu_69928_p1 = esl_zext<63,62>(newSel3_fu_69920_p3.read());
}

void krnl_sobel::thread_newSel157_cast_fu_69952_p1() {
    newSel157_cast_fu_69952_p1 = esl_zext<64,63>(newSel5_fu_69944_p3.read());
}

void krnl_sobel::thread_newSel1_fu_46642_p3() {
    newSel1_fu_46642_p3 = (!rnd_i_i_i_i_0_reg2mem675_0_i_i_reg_12676.read()[0].is_01())? sc_lv<63>(): ((rnd_i_i_i_i_0_reg2mem675_0_i_i_reg_12676.read()[0].to_bool())? tmp_217_reg_80243.read(): ux_i_i_i_i_i_i_1_cast_cast_reg_80232.read());
}

void krnl_sobel::thread_newSel2_fu_46648_p3() {
    newSel2_fu_46648_p3 = (!or_cond_fu_46636_p2.read()[0].is_01())? sc_lv<63>(): ((or_cond_fu_46636_p2.read()[0].to_bool())? newSel_cast_fu_46632_p1.read(): newSel1_fu_46642_p3.read());
}

void krnl_sobel::thread_newSel3_fu_69920_p3() {
    newSel3_fu_69920_p3 = (!sel_tmp3_fu_69915_p2.read()[0].is_01())? sc_lv<62>(): ((sel_tmp3_fu_69915_p2.read()[0].to_bool())? tmp_342_cast_cast_fu_69890_p4.read(): ux_i_i_i_i24_i_i_1_reg_22713.read());
}

void krnl_sobel::thread_newSel4_fu_69938_p3() {
    newSel4_fu_69938_p3 = (!rnd_i_i_i_i29_0_reg2mem589_0_i_reg_22746.read()[0].is_01())? sc_lv<63>(): ((rnd_i_i_i_i29_0_reg2mem589_0_i_reg_22746.read()[0].to_bool())? tmp_340_reg_89392.read(): ux_i_i_i_i24_i_i_1_cast_cast_reg_89381.read());
}

void krnl_sobel::thread_newSel5_fu_69944_p3() {
    newSel5_fu_69944_p3 = (!or_cond1_fu_69932_p2.read()[0].is_01())? sc_lv<63>(): ((or_cond1_fu_69932_p2.read()[0].to_bool())? newSel153_cast_fu_69928_p1.read(): newSel4_fu_69938_p3.read());
}

void krnl_sobel::thread_newSel_cast_fu_46632_p1() {
    newSel_cast_fu_46632_p1 = esl_zext<63,62>(newSel_fu_46624_p3.read());
}

void krnl_sobel::thread_newSel_fu_46624_p3() {
    newSel_fu_46624_p3 = (!sel_tmp7_fu_46619_p2.read()[0].is_01())? sc_lv<62>(): ((sel_tmp7_fu_46619_p2.read()[0].to_bool())? tmp_223_cast_cast_fu_46594_p4.read(): ux_i_i_i_i_i_i_1_reg_12643.read());
}

void krnl_sobel::thread_not_1_fu_46755_p2() {
    not_1_fu_46755_p2 = (!tmp_231_cast_mask_fu_46747_p3.read().is_01() || !ap_const_lv31_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_231_cast_mask_fu_46747_p3.read() == ap_const_lv31_FF);
}

void krnl_sobel::thread_not_s_fu_70051_p2() {
    not_s_fu_70051_p2 = (!tmp_346_cast_mask_fu_70043_p3.read().is_01() || !ap_const_lv31_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_346_cast_mask_fu_70043_p3.read() == ap_const_lv31_FF);
}

void krnl_sobel::thread_notlhs1_fu_24970_p2() {
    notlhs1_fu_24970_p2 = (!p_0111_0_i_i_fu_24960_p3.read().is_01() || !ap_const_lv31_7F800000.is_01())? sc_lv<1>(): sc_lv<1>(p_0111_0_i_i_fu_24960_p3.read() == ap_const_lv31_7F800000);
}

void krnl_sobel::thread_notlhs2_fu_24987_p2() {
    notlhs2_fu_24987_p2 = (!tmp_233_reg_71801.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_233_reg_71801.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs3_fu_47018_p2() {
    notlhs3_fu_47018_p2 = (!tmp_425_fu_47004_p4.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_425_fu_47004_p4.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs4_fu_48270_p2() {
    notlhs4_fu_48270_p2 = (!tmp_284_reg_81015.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_284_reg_81015.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs5_fu_70111_p2() {
    notlhs5_fu_70111_p2 = (!tmp_4922_reg_89426.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4922_reg_89426.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs6_fu_46815_p2() {
    notlhs6_fu_46815_p2 = (!tmp_4796_reg_80277.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4796_reg_80277.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs7_fu_46929_p2() {
    notlhs7_fu_46929_p2 = (!tmp_416_fu_46915_p4.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_416_fu_46915_p4.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs8_fu_46963_p2() {
    notlhs8_fu_46963_p2 = (!tmp_418_fu_46945_p4.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(tmp_418_fu_46945_p4.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_notlhs_fu_48253_p2() {
    notlhs_fu_48253_p2 = (!p_095_0_i_i_fu_48243_p3.read().is_01() || !ap_const_lv31_7F800000.is_01())? sc_lv<1>(): sc_lv<1>(p_095_0_i_i_fu_48243_p3.read() == ap_const_lv31_7F800000);
}

void krnl_sobel::thread_notrhs1_fu_24976_p2() {
    notrhs1_fu_24976_p2 = (!tmp_230_reg_71789.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_230_reg_71789.read() != ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs2_fu_24954_p2() {
    notrhs2_fu_24954_p2 = (!tmp_230_fu_24936_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_230_fu_24936_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs3_fu_47024_p2() {
    notrhs3_fu_47024_p2 = (!tmp_4806_fu_47014_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4806_fu_47014_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs4_fu_48237_p2() {
    notrhs4_fu_48237_p2 = (!tmp_282_fu_48219_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_282_fu_48219_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs5_fu_70037_p2() {
    notrhs5_fu_70037_p2 = (!tmp_4923_fu_70004_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4923_fu_70004_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs6_fu_46741_p2() {
    notrhs6_fu_46741_p2 = (!tmp_4797_fu_46708_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4797_fu_46708_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs7_fu_46935_p2() {
    notrhs7_fu_46935_p2 = (!tmp_4804_fu_46925_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4804_fu_46925_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs8_fu_46969_p2() {
    notrhs8_fu_46969_p2 = (!tmp_4805_fu_46955_p1.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_4805_fu_46955_p1.read() == ap_const_lv23_0);
}

void krnl_sobel::thread_notrhs_fu_48259_p2() {
    notrhs_fu_48259_p2 = (!tmp_282_reg_81003.read().is_01() || !ap_const_lv23_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_282_reg_81003.read() != ap_const_lv23_0);
}

void krnl_sobel::thread_or_cond1_30_fu_25017_p2() {
    or_cond1_30_fu_25017_p2 = (tmp_129_reg_71832.read() | tmp_134_fu_25013_p2.read());
}

void krnl_sobel::thread_or_cond1_fu_69932_p2() {
    or_cond1_fu_69932_p2 = (sel_tmp3_fu_69915_p2.read() | sel_tmp_fu_69899_p2.read());
}

void krnl_sobel::thread_or_cond2_fu_48300_p2() {
    or_cond2_fu_48300_p2 = (tmp_206_reg_81046.read() | tmp_211_fu_48296_p2.read());
}

void krnl_sobel::thread_or_cond3_fu_70131_p2() {
    or_cond3_fu_70131_p2 = (tmp145_fu_70126_p2.read() | tmp_351_reg_89441.read());
}

void krnl_sobel::thread_or_cond879_i_i_fu_25002_p2() {
    or_cond879_i_i_fu_25002_p2 = (or_cond_not_i_i_fu_24981_p2.read() | tmp_128_fu_24997_p2.read());
}

void krnl_sobel::thread_or_cond886_not_i_i_fu_48264_p2() {
    or_cond886_not_i_i_fu_48264_p2 = (notrhs_fu_48259_p2.read() & notlhs_fu_48253_p2.read());
}

void krnl_sobel::thread_or_cond887_i_i_fu_48285_p2() {
    or_cond887_i_i_fu_48285_p2 = (or_cond886_not_i_i_fu_48264_p2.read() | tmp_196_fu_48280_p2.read());
}

void krnl_sobel::thread_or_cond_32_fu_46835_p2() {
    or_cond_32_fu_46835_p2 = (tmp139_fu_46830_p2.read() | tmp_236_reg_80292.read());
}

void krnl_sobel::thread_or_cond_fu_46636_p2() {
    or_cond_fu_46636_p2 = (sel_tmp7_fu_46619_p2.read() | sel_tmp2_fu_46603_p2.read());
}

void krnl_sobel::thread_or_cond_not_i_i_fu_24981_p2() {
    or_cond_not_i_i_fu_24981_p2 = (notrhs1_fu_24976_p2.read() & notlhs1_fu_24970_p2.read());
}

void krnl_sobel::thread_p_0107_reg2mem651_0_i_i_to_int_fu_46911_p1() {
    p_0107_reg2mem651_0_i_i_to_int_fu_46911_p1 = p_0107_reg2mem651_0_i_i_reg_12706.read();
}

void krnl_sobel::thread_p_0110_0_reg2mem_0_i_i_cast_fu_24967_p1() {
    p_0110_0_reg2mem_0_i_i_cast_fu_24967_p1 = esl_zext<24,23>(tmp_230_reg_71789.read());
}

void krnl_sobel::thread_p_0111_0_i_i_fu_24960_p3() {
    p_0111_0_i_i_fu_24960_p3 = esl_concat<8,23>(tmp_233_reg_71801.read(), ap_const_lv23_0);
}

void krnl_sobel::thread_p_0124_reg2mem_0_i_i_cast_fu_46733_p1() {
    p_0124_reg2mem_0_i_i_cast_fu_46733_p1 = esl_sext<10,9>(tmp_388_reg_79443.read());
}

void krnl_sobel::thread_p_0146_0_reg2mem_0_i_i_cast_fu_46761_p1() {
    p_0146_0_reg2mem_0_i_i_cast_fu_46761_p1 = esl_zext<10,8>(tmp_4796_fu_46704_p1.read());
}

void krnl_sobel::thread_p_0158_reg2mem_0_i_i_sum_cast_fu_24284_p1() {
    p_0158_reg2mem_0_i_i_sum_cast_fu_24284_p1 = esl_zext<64,63>(p_0158_reg2mem_0_i_i_sum_fu_24279_p2.read());
}

void krnl_sobel::thread_p_0158_reg2mem_0_i_i_sum_fu_24279_p2() {
    p_0158_reg2mem_0_i_i_sum_fu_24279_p2 = (!tmp_86_cast_fu_24275_p1.read().is_01() || !arg_in_pixels_i_0_sum1_reg_71330.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_86_cast_fu_24275_p1.read()) + sc_biguint<63>(arg_in_pixels_i_0_sum1_reg_71330.read()));
}

void krnl_sobel::thread_p_0161_reg2mem_0_i_i_sum_cast_fu_23898_p1() {
    p_0161_reg2mem_0_i_i_sum_cast_fu_23898_p1 = esl_zext<64,63>(p_0161_reg2mem_0_i_i_sum_fu_23893_p2.read());
}

void krnl_sobel::thread_p_0161_reg2mem_0_i_i_sum_fu_23893_p2() {
    p_0161_reg2mem_0_i_i_sum_fu_23893_p2 = (!tmp_47_cast_fu_23889_p1.read().is_01() || !arg_in_pixels_i_0_sum_reg_71090.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_47_cast_fu_23889_p1.read()) + sc_biguint<63>(arg_in_pixels_i_0_sum_reg_71090.read()));
}

void krnl_sobel::thread_p_0167_reg2mem_0_i_i_sum_cast_fu_23458_p1() {
    p_0167_reg2mem_0_i_i_sum_cast_fu_23458_p1 = esl_zext<64,63>(p_0167_reg2mem_0_i_i_sum_fu_23453_p2.read());
}

void krnl_sobel::thread_p_0167_reg2mem_0_i_i_sum_fu_23453_p2() {
    p_0167_reg2mem_0_i_i_sum_fu_23453_p2 = (!tmp_10_cast_fu_23449_p1.read().is_01() || !arg_out_pixels_i_0_sum1_reg_70862.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_10_cast_fu_23449_p1.read()) + sc_biguint<63>(arg_out_pixels_i_0_sum1_reg_70862.read()));
}

void krnl_sobel::thread_p_020_0_reg2mem_0_i_i_cast_fu_70057_p1() {
    p_020_0_reg2mem_0_i_i_cast_fu_70057_p1 = esl_zext<10,8>(tmp_4922_fu_70000_p1.read());
}

void krnl_sobel::thread_p_047_reg2mem_0_i_i_sum_cast_fu_70477_p1() {
    p_047_reg2mem_0_i_i_sum_cast_fu_70477_p1 = esl_zext<64,63>(p_047_reg2mem_0_i_i_sum_fu_70472_p2.read());
}

void krnl_sobel::thread_p_047_reg2mem_0_i_i_sum_fu_70472_p2() {
    p_047_reg2mem_0_i_i_sum_fu_70472_p2 = (!tmp_243_cast_fu_70468_p1.read().is_01() || !arg_out_pixels_i_0_sum_reg_89535.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_243_cast_fu_70468_p1.read()) + sc_biguint<63>(arg_out_pixels_i_0_sum_reg_89535.read()));
}

void krnl_sobel::thread_p_048_0_reg2mem_0_i_i_fu_48317_p3() {
    p_048_0_reg2mem_0_i_i_fu_48317_p3 = (!tmp_216_fu_48305_p2.read()[0].is_01())? sc_lv<24>(): ((tmp_216_fu_48305_p2.read()[0].to_bool())? p_094_0_reg2mem_0_i_i_cast_reg_81033.read(): p_reg2mem292_0_i_i_fu_48310_p3.read());
}

void krnl_sobel::thread_p_068_0_reg2mem_0_i_i_fu_25034_p3() {
    p_068_0_reg2mem_0_i_i_fu_25034_p3 = (!tmp_136_fu_25022_p2.read()[0].is_01())? sc_lv<24>(): ((tmp_136_fu_25022_p2.read()[0].to_bool())? p_0110_0_reg2mem_0_i_i_cast_reg_71819.read(): p_reg2mem477_0_i_i_fu_25027_p3.read());
}

void krnl_sobel::thread_p_078_reg2mem_0_i_i_sum_cast_fu_47209_p1() {
    p_078_reg2mem_0_i_i_sum_cast_fu_47209_p1 = esl_zext<64,63>(p_078_reg2mem_0_i_i_sum_fu_47204_p2.read());
}

void krnl_sobel::thread_p_078_reg2mem_0_i_i_sum_fu_47204_p2() {
    p_078_reg2mem_0_i_i_sum_fu_47204_p2 = (!arg_in_pixels_i_0_sum_reg_71090.read().is_01() || !tmp_110_cast_fu_47200_p1.read().is_01())? sc_lv<63>(): (sc_biguint<63>(arg_in_pixels_i_0_sum_reg_71090.read()) + sc_biguint<63>(tmp_110_cast_fu_47200_p1.read()));
}

void krnl_sobel::thread_p_081_reg2mem_0_i_i_sum_cast_fu_47570_p1() {
    p_081_reg2mem_0_i_i_sum_cast_fu_47570_p1 = esl_zext<64,63>(p_081_reg2mem_0_i_i_sum_fu_47565_p2.read());
}

void krnl_sobel::thread_p_081_reg2mem_0_i_i_sum_fu_47565_p2() {
    p_081_reg2mem_0_i_i_sum_fu_47565_p2 = (!tmp_184_cast_fu_47561_p1.read().is_01() || !arg_in_pixels_i_0_sum2_reg_80531.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_184_cast_fu_47561_p1.read()) + sc_biguint<63>(arg_in_pixels_i_0_sum2_reg_80531.read()));
}

void krnl_sobel::thread_p_094_0_reg2mem_0_i_i_cast_fu_48250_p1() {
    p_094_0_reg2mem_0_i_i_cast_fu_48250_p1 = esl_zext<24,23>(tmp_282_reg_81003.read());
}

void krnl_sobel::thread_p_095_0_i_i_fu_48243_p3() {
    p_095_0_i_i_fu_48243_p3 = esl_concat<8,23>(tmp_284_reg_81015.read(), ap_const_lv23_0);
}

void krnl_sobel::thread_p_0_reg2mem_0_i_i_cast_fu_70029_p1() {
    p_0_reg2mem_0_i_i_cast_fu_70029_p1 = esl_sext<10,9>(tmp_482_reg_88592.read());
}

void krnl_sobel::thread_p_10_fu_27685_p3() {
    p_10_fu_27685_p3 = (!tmp_1008_fu_27677_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1008_fu_27677_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_11_fu_50969_p3() {
    p_11_fu_50969_p3 = (!tmp_1045_fu_50961_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1045_fu_50961_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_12_fu_28089_p3() {
    p_12_fu_28089_p3 = (!tmp_1100_fu_28081_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1100_fu_28081_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_13_fu_51374_p3() {
    p_13_fu_51374_p3 = (!tmp_1137_fu_51366_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1137_fu_51366_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_143_reg2mem615_0_i_i_2_cast_fu_49376_p1() {
    p_143_reg2mem615_0_i_i_2_cast_fu_49376_p1 = esl_zext<64,63>(p_143_reg2mem615_0_i_i_2_reg_13509.read());
}

void krnl_sobel::thread_p_14_fu_28493_p3() {
    p_14_fu_28493_p3 = (!tmp_1192_fu_28485_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1192_fu_28485_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_10_cast_fu_44660_p1() {
    p_157_reg2mem681_0_i_i_10_cast_fu_44660_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_10_reg_79628.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_10_fu_44643_p3() {
    p_157_reg2mem681_0_i_i_10_fu_44643_p3 = (!tmp_4717_fu_44620_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4717_fu_44620_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_s_reg_79611.read(): tmp_4716_fu_44616_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_11_cast_fu_44713_p1() {
    p_157_reg2mem681_0_i_i_11_cast_fu_44713_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_11_reg_79645.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_11_fu_44696_p3() {
    p_157_reg2mem681_0_i_i_11_fu_44696_p3 = (!tmp_4719_fu_44673_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4719_fu_44673_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_10_reg_79628.read(): tmp_4718_fu_44669_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_12_cast_fu_44766_p1() {
    p_157_reg2mem681_0_i_i_12_cast_fu_44766_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_12_reg_79662.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_12_fu_44749_p3() {
    p_157_reg2mem681_0_i_i_12_fu_44749_p3 = (!tmp_4721_fu_44726_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4721_fu_44726_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_11_reg_79645.read(): tmp_4720_fu_44722_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_13_cast_fu_44819_p1() {
    p_157_reg2mem681_0_i_i_13_cast_fu_44819_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_13_reg_79679.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_13_fu_44802_p3() {
    p_157_reg2mem681_0_i_i_13_fu_44802_p3 = (!tmp_4723_fu_44779_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4723_fu_44779_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_12_reg_79662.read(): tmp_4722_fu_44775_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_14_cast_fu_44872_p1() {
    p_157_reg2mem681_0_i_i_14_cast_fu_44872_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_14_reg_79696.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_14_fu_44855_p3() {
    p_157_reg2mem681_0_i_i_14_fu_44855_p3 = (!tmp_4725_fu_44832_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4725_fu_44832_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_13_reg_79679.read(): tmp_4724_fu_44828_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_15_cast_fu_44925_p1() {
    p_157_reg2mem681_0_i_i_15_cast_fu_44925_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_15_reg_79713.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_15_fu_44908_p3() {
    p_157_reg2mem681_0_i_i_15_fu_44908_p3 = (!tmp_4727_fu_44885_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4727_fu_44885_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_14_reg_79696.read(): tmp_4726_fu_44881_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_16_cast_fu_44978_p1() {
    p_157_reg2mem681_0_i_i_16_cast_fu_44978_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_16_reg_79730.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_16_fu_44961_p3() {
    p_157_reg2mem681_0_i_i_16_fu_44961_p3 = (!tmp_4729_fu_44938_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4729_fu_44938_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_15_reg_79713.read(): tmp_4728_fu_44934_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_17_cast_fu_45031_p1() {
    p_157_reg2mem681_0_i_i_17_cast_fu_45031_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_17_reg_79747.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_17_fu_45014_p3() {
    p_157_reg2mem681_0_i_i_17_fu_45014_p3 = (!tmp_4731_fu_44991_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4731_fu_44991_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_16_reg_79730.read(): tmp_4730_fu_44987_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_18_cast_fu_45084_p1() {
    p_157_reg2mem681_0_i_i_18_cast_fu_45084_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_18_reg_79764.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_18_fu_45067_p3() {
    p_157_reg2mem681_0_i_i_18_fu_45067_p3 = (!tmp_4733_fu_45044_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4733_fu_45044_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_17_reg_79747.read(): tmp_4732_fu_45040_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_19_cast_fu_45137_p1() {
    p_157_reg2mem681_0_i_i_19_cast_fu_45137_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_19_reg_79781.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_19_fu_45120_p3() {
    p_157_reg2mem681_0_i_i_19_fu_45120_p3 = (!tmp_4735_fu_45097_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4735_fu_45097_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_18_reg_79764.read(): tmp_4734_fu_45093_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_1_cast_fu_44109_p1() {
    p_157_reg2mem681_0_i_i_1_cast_fu_44109_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_1_reg_79455.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_1_fu_44064_p3() {
    p_157_reg2mem681_0_i_i_1_fu_44064_p3 = (!tmp_4696_fu_44056_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4696_fu_44056_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_reg_79432.read(): tmp_4695_fu_44052_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_20_cast_fu_45190_p1() {
    p_157_reg2mem681_0_i_i_20_cast_fu_45190_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_20_reg_79798.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_20_fu_45173_p3() {
    p_157_reg2mem681_0_i_i_20_fu_45173_p3 = (!tmp_4737_fu_45150_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4737_fu_45150_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_19_reg_79781.read(): tmp_4736_fu_45146_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_21_cast_fu_45243_p1() {
    p_157_reg2mem681_0_i_i_21_cast_fu_45243_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_21_reg_79815.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_21_fu_45226_p3() {
    p_157_reg2mem681_0_i_i_21_fu_45226_p3 = (!tmp_4739_fu_45203_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4739_fu_45203_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_20_reg_79798.read(): tmp_4738_fu_45199_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_22_cast_fu_45296_p1() {
    p_157_reg2mem681_0_i_i_22_cast_fu_45296_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_22_reg_79832.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_22_fu_45279_p3() {
    p_157_reg2mem681_0_i_i_22_fu_45279_p3 = (!tmp_4741_fu_45256_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4741_fu_45256_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_21_reg_79815.read(): tmp_4740_fu_45252_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_23_cast_fu_45349_p1() {
    p_157_reg2mem681_0_i_i_23_cast_fu_45349_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_23_reg_79849.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_23_fu_45332_p3() {
    p_157_reg2mem681_0_i_i_23_fu_45332_p3 = (!tmp_4743_fu_45309_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4743_fu_45309_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_22_reg_79832.read(): tmp_4742_fu_45305_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_24_cast_fu_45402_p1() {
    p_157_reg2mem681_0_i_i_24_cast_fu_45402_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_24_reg_79866.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_24_fu_45385_p3() {
    p_157_reg2mem681_0_i_i_24_fu_45385_p3 = (!tmp_4745_fu_45362_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4745_fu_45362_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_23_reg_79849.read(): tmp_4744_fu_45358_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_25_cast_fu_45455_p1() {
    p_157_reg2mem681_0_i_i_25_cast_fu_45455_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_25_reg_79883.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_25_fu_45438_p3() {
    p_157_reg2mem681_0_i_i_25_fu_45438_p3 = (!tmp_4747_fu_45415_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4747_fu_45415_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_24_reg_79866.read(): tmp_4746_fu_45411_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_26_cast_fu_45508_p1() {
    p_157_reg2mem681_0_i_i_26_cast_fu_45508_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_26_reg_79900.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_26_fu_45491_p3() {
    p_157_reg2mem681_0_i_i_26_fu_45491_p3 = (!tmp_4749_fu_45468_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4749_fu_45468_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_25_reg_79883.read(): tmp_4748_fu_45464_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_27_cast_fu_45561_p1() {
    p_157_reg2mem681_0_i_i_27_cast_fu_45561_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_27_reg_79917.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_27_fu_45544_p3() {
    p_157_reg2mem681_0_i_i_27_fu_45544_p3 = (!tmp_4751_fu_45521_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4751_fu_45521_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_26_reg_79900.read(): tmp_4750_fu_45517_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_28_cast_fu_45614_p1() {
    p_157_reg2mem681_0_i_i_28_cast_fu_45614_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_28_reg_79934.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_28_fu_45597_p3() {
    p_157_reg2mem681_0_i_i_28_fu_45597_p3 = (!tmp_4753_fu_45574_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4753_fu_45574_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_27_reg_79917.read(): tmp_4752_fu_45570_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_29_cast_fu_45667_p1() {
    p_157_reg2mem681_0_i_i_29_cast_fu_45667_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_29_reg_79951.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_29_fu_45650_p3() {
    p_157_reg2mem681_0_i_i_29_fu_45650_p3 = (!tmp_4755_fu_45627_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4755_fu_45627_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_28_reg_79934.read(): tmp_4754_fu_45623_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_2_cast_fu_44170_p1() {
    p_157_reg2mem681_0_i_i_2_cast_fu_44170_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_2_reg_79476.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_2_fu_44158_p3() {
    p_157_reg2mem681_0_i_i_2_fu_44158_p3 = (!tmp_4699_fu_44122_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4699_fu_44122_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_1_reg_79455.read(): tmp_4698_fu_44118_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_30_cast_fu_45720_p1() {
    p_157_reg2mem681_0_i_i_30_cast_fu_45720_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_30_reg_79968.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_30_fu_45703_p3() {
    p_157_reg2mem681_0_i_i_30_fu_45703_p3 = (!tmp_4757_fu_45680_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4757_fu_45680_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_29_reg_79951.read(): tmp_4756_fu_45676_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_31_cast_fu_45773_p1() {
    p_157_reg2mem681_0_i_i_31_cast_fu_45773_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_31_reg_79985.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_31_fu_45756_p3() {
    p_157_reg2mem681_0_i_i_31_fu_45756_p3 = (!tmp_4759_fu_45733_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4759_fu_45733_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_30_reg_79968.read(): tmp_4758_fu_45729_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_32_cast_fu_45826_p1() {
    p_157_reg2mem681_0_i_i_32_cast_fu_45826_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_32_reg_80002.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_32_fu_45809_p3() {
    p_157_reg2mem681_0_i_i_32_fu_45809_p3 = (!tmp_4761_fu_45786_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4761_fu_45786_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_31_reg_79985.read(): tmp_4760_fu_45782_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_33_cast_fu_45879_p1() {
    p_157_reg2mem681_0_i_i_33_cast_fu_45879_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_33_reg_80019.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_33_fu_45862_p3() {
    p_157_reg2mem681_0_i_i_33_fu_45862_p3 = (!tmp_4763_fu_45839_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4763_fu_45839_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_32_reg_80002.read(): tmp_4762_fu_45835_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_34_cast_fu_45932_p1() {
    p_157_reg2mem681_0_i_i_34_cast_fu_45932_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_34_reg_80036.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_34_fu_45915_p3() {
    p_157_reg2mem681_0_i_i_34_fu_45915_p3 = (!tmp_4765_fu_45892_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4765_fu_45892_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_33_reg_80019.read(): tmp_4764_fu_45888_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_35_cast_fu_45985_p1() {
    p_157_reg2mem681_0_i_i_35_cast_fu_45985_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_35_reg_80053.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_35_fu_45968_p3() {
    p_157_reg2mem681_0_i_i_35_fu_45968_p3 = (!tmp_4767_fu_45945_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4767_fu_45945_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_34_reg_80036.read(): tmp_4766_fu_45941_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_36_cast_fu_46038_p1() {
    p_157_reg2mem681_0_i_i_36_cast_fu_46038_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_36_reg_80070.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_36_fu_46021_p3() {
    p_157_reg2mem681_0_i_i_36_fu_46021_p3 = (!tmp_4769_fu_45998_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4769_fu_45998_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_35_reg_80053.read(): tmp_4768_fu_45994_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_37_cast_fu_46091_p1() {
    p_157_reg2mem681_0_i_i_37_cast_fu_46091_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_37_reg_80087.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_37_fu_46074_p3() {
    p_157_reg2mem681_0_i_i_37_fu_46074_p3 = (!tmp_4771_fu_46051_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4771_fu_46051_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_36_reg_80070.read(): tmp_4770_fu_46047_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_38_cast_fu_46144_p1() {
    p_157_reg2mem681_0_i_i_38_cast_fu_46144_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_38_reg_80104.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_38_fu_46127_p3() {
    p_157_reg2mem681_0_i_i_38_fu_46127_p3 = (!tmp_4773_fu_46104_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4773_fu_46104_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_37_reg_80087.read(): tmp_4772_fu_46100_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_39_cast_fu_46197_p1() {
    p_157_reg2mem681_0_i_i_39_cast_fu_46197_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_39_reg_80121.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_39_fu_46180_p3() {
    p_157_reg2mem681_0_i_i_39_fu_46180_p3 = (!tmp_4775_fu_46157_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4775_fu_46157_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_38_reg_80104.read(): tmp_4774_fu_46153_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_3_cast_fu_44223_p1() {
    p_157_reg2mem681_0_i_i_3_cast_fu_44223_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_3_reg_79497.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_3_fu_44211_p3() {
    p_157_reg2mem681_0_i_i_3_fu_44211_p3 = (!tmp_4701_fu_44183_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4701_fu_44183_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_2_reg_79476.read(): tmp_4700_fu_44179_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_40_cast_fu_46250_p1() {
    p_157_reg2mem681_0_i_i_40_cast_fu_46250_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_40_reg_80138.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_40_fu_46233_p3() {
    p_157_reg2mem681_0_i_i_40_fu_46233_p3 = (!tmp_4777_fu_46210_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4777_fu_46210_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_39_reg_80121.read(): tmp_4776_fu_46206_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_41_cast_fu_46303_p1() {
    p_157_reg2mem681_0_i_i_41_cast_fu_46303_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_41_reg_80155.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_41_fu_46286_p3() {
    p_157_reg2mem681_0_i_i_41_fu_46286_p3 = (!tmp_4779_fu_46263_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4779_fu_46263_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_40_reg_80138.read(): tmp_4778_fu_46259_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_42_cast_fu_46356_p1() {
    p_157_reg2mem681_0_i_i_42_cast_fu_46356_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_42_reg_80172.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_42_fu_46339_p3() {
    p_157_reg2mem681_0_i_i_42_fu_46339_p3 = (!tmp_4781_fu_46316_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4781_fu_46316_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_41_reg_80155.read(): tmp_4780_fu_46312_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_43_cast_fu_46407_p1() {
    p_157_reg2mem681_0_i_i_43_cast_fu_46407_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_43_fu_46401_p3.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_43_fu_46401_p3() {
    p_157_reg2mem681_0_i_i_43_fu_46401_p3 = (!tmp_4783_reg_80188.read()[0].is_01())? sc_lv<60>(): ((tmp_4783_reg_80188.read()[0].to_bool())? p_157_reg2mem681_0_i_i_42_reg_80172.read(): tmp_4782_fu_46398_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_4_cast_fu_44289_p1() {
    p_157_reg2mem681_0_i_i_4_cast_fu_44289_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_4_reg_79509.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_4_fu_44272_p3() {
    p_157_reg2mem681_0_i_i_4_fu_44272_p3 = (!tmp_4703_fu_44236_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4703_fu_44236_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_3_reg_79497.read(): tmp_4702_fu_44232_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_5_cast_fu_44342_p1() {
    p_157_reg2mem681_0_i_i_5_cast_fu_44342_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_5_reg_79526.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_5_fu_44325_p3() {
    p_157_reg2mem681_0_i_i_5_fu_44325_p3 = (!tmp_4705_fu_44302_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4705_fu_44302_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_4_reg_79509.read(): tmp_4704_fu_44298_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_6_cast_fu_44395_p1() {
    p_157_reg2mem681_0_i_i_6_cast_fu_44395_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_6_reg_79543.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_6_fu_44378_p3() {
    p_157_reg2mem681_0_i_i_6_fu_44378_p3 = (!tmp_4707_fu_44355_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4707_fu_44355_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_5_reg_79526.read(): tmp_4706_fu_44351_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_7_cast_fu_44448_p1() {
    p_157_reg2mem681_0_i_i_7_cast_fu_44448_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_7_reg_79560.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_7_fu_44431_p3() {
    p_157_reg2mem681_0_i_i_7_fu_44431_p3 = (!tmp_4709_fu_44408_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4709_fu_44408_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_6_reg_79543.read(): tmp_4708_fu_44404_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_8_cast_fu_44501_p1() {
    p_157_reg2mem681_0_i_i_8_cast_fu_44501_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_8_reg_79577.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_8_fu_44484_p3() {
    p_157_reg2mem681_0_i_i_8_fu_44484_p3 = (!tmp_4711_fu_44461_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4711_fu_44461_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_7_reg_79560.read(): tmp_4710_fu_44457_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_9_cast_fu_44554_p1() {
    p_157_reg2mem681_0_i_i_9_cast_fu_44554_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_9_reg_79594.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_9_fu_44537_p3() {
    p_157_reg2mem681_0_i_i_9_fu_44537_p3 = (!tmp_4713_fu_44514_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4713_fu_44514_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_8_reg_79577.read(): tmp_4712_fu_44510_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_cast_31_fu_44607_p1() {
    p_157_reg2mem681_0_i_i_cast_31_fu_44607_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_s_reg_79611.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_cast_fu_44043_p1() {
    p_157_reg2mem681_0_i_i_cast_fu_44043_p1 = esl_zext<61,60>(p_157_reg2mem681_0_i_i_reg_79432.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_fu_44009_p3() {
    p_157_reg2mem681_0_i_i_fu_44009_p3 = (!tmp_4693_fu_43993_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4693_fu_43993_p3.read()[0].to_bool())? tmp_178_cast_fu_43972_p3.read(): tmp_4692_fu_43989_p1.read());
}

void krnl_sobel::thread_p_157_reg2mem681_0_i_i_s_fu_44590_p3() {
    p_157_reg2mem681_0_i_i_s_fu_44590_p3 = (!tmp_4715_fu_44567_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4715_fu_44567_p3.read()[0].to_bool())? p_157_reg2mem681_0_i_i_9_reg_79594.read(): tmp_4714_fu_44563_p1.read());
}

void krnl_sobel::thread_p_15_fu_51779_p3() {
    p_15_fu_51779_p3 = (!tmp_1229_fu_51771_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1229_fu_51771_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_164_reg2mem697_0_i_i_2_cast_fu_26093_p1() {
    p_164_reg2mem697_0_i_i_2_cast_fu_26093_p1 = esl_zext<64,63>(p_164_reg2mem697_0_i_i_2_reg_3439.read());
}

void krnl_sobel::thread_p_16_fu_28897_p3() {
    p_16_fu_28897_p3 = (!tmp_1284_fu_28889_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1284_fu_28889_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_17_fu_52183_p3() {
    p_17_fu_52183_p3 = (!tmp_1321_fu_52175_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1321_fu_52175_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_18_fu_29302_p3() {
    p_18_fu_29302_p3 = (!tmp_1376_fu_29294_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1376_fu_29294_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_19_fu_52587_p3() {
    p_19_fu_52587_p3 = (!tmp_1413_fu_52579_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1413_fu_52579_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_1_cast_cast_fu_48521_p3() {
    p_1_cast_cast_fu_48521_p3 = (!tmp_328_0_s_fu_48515_p2.read()[0].is_01())? sc_lv<6>(): ((tmp_328_0_s_fu_48515_p2.read()[0].to_bool())? ap_const_lv6_18: ap_const_lv6_19);
}

void krnl_sobel::thread_p_1_fu_50565_p3() {
    p_1_fu_50565_p3 = (!tmp_953_fu_50557_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_953_fu_50557_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_10_cast_fu_67956_p1() {
    p_1_reg2mem599_0_i_i_10_cast_fu_67956_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_10_reg_88771.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_10_fu_67932_p3() {
    p_1_reg2mem599_0_i_i_10_fu_67932_p3 = (!tmp_4847_fu_67916_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4847_fu_67916_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_s_reg_88754.read(): tmp_4846_fu_67912_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_11_cast_fu_68009_p1() {
    p_1_reg2mem599_0_i_i_11_cast_fu_68009_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_11_reg_88788.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_11_fu_67985_p3() {
    p_1_reg2mem599_0_i_i_11_fu_67985_p3 = (!tmp_4849_fu_67969_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4849_fu_67969_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_10_reg_88771.read(): tmp_4848_fu_67965_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_12_cast_fu_68062_p1() {
    p_1_reg2mem599_0_i_i_12_cast_fu_68062_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_12_reg_88805.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_12_fu_68038_p3() {
    p_1_reg2mem599_0_i_i_12_fu_68038_p3 = (!tmp_4851_fu_68022_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4851_fu_68022_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_11_reg_88788.read(): tmp_4850_fu_68018_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_13_cast_fu_68115_p1() {
    p_1_reg2mem599_0_i_i_13_cast_fu_68115_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_13_reg_88822.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_13_fu_68091_p3() {
    p_1_reg2mem599_0_i_i_13_fu_68091_p3 = (!tmp_4853_fu_68075_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4853_fu_68075_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_12_reg_88805.read(): tmp_4852_fu_68071_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_14_cast_fu_68168_p1() {
    p_1_reg2mem599_0_i_i_14_cast_fu_68168_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_14_reg_88839.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_14_fu_68144_p3() {
    p_1_reg2mem599_0_i_i_14_fu_68144_p3 = (!tmp_4855_fu_68128_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4855_fu_68128_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_13_reg_88822.read(): tmp_4854_fu_68124_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_15_cast_fu_68221_p1() {
    p_1_reg2mem599_0_i_i_15_cast_fu_68221_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_15_reg_88856.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_15_fu_68197_p3() {
    p_1_reg2mem599_0_i_i_15_fu_68197_p3 = (!tmp_4857_fu_68181_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4857_fu_68181_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_14_reg_88839.read(): tmp_4856_fu_68177_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_16_cast_fu_68274_p1() {
    p_1_reg2mem599_0_i_i_16_cast_fu_68274_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_16_reg_88873.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_16_fu_68250_p3() {
    p_1_reg2mem599_0_i_i_16_fu_68250_p3 = (!tmp_4859_fu_68234_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4859_fu_68234_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_15_reg_88856.read(): tmp_4858_fu_68230_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_17_cast_fu_68327_p1() {
    p_1_reg2mem599_0_i_i_17_cast_fu_68327_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_17_reg_88890.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_17_fu_68303_p3() {
    p_1_reg2mem599_0_i_i_17_fu_68303_p3 = (!tmp_4861_fu_68287_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4861_fu_68287_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_16_reg_88873.read(): tmp_4860_fu_68283_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_18_cast_fu_68380_p1() {
    p_1_reg2mem599_0_i_i_18_cast_fu_68380_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_18_reg_88907.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_18_fu_68356_p3() {
    p_1_reg2mem599_0_i_i_18_fu_68356_p3 = (!tmp_4863_fu_68340_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4863_fu_68340_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_17_reg_88890.read(): tmp_4862_fu_68336_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_19_cast_fu_68433_p1() {
    p_1_reg2mem599_0_i_i_19_cast_fu_68433_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_19_reg_88924.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_19_fu_68409_p3() {
    p_1_reg2mem599_0_i_i_19_fu_68409_p3 = (!tmp_4865_fu_68393_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4865_fu_68393_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_18_reg_88907.read(): tmp_4864_fu_68389_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_1_cast_fu_67367_p1() {
    p_1_reg2mem599_0_i_i_1_cast_fu_67367_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_1_reg_88604.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_1_fu_67360_p3() {
    p_1_reg2mem599_0_i_i_1_fu_67360_p3 = (!tmp_4826_fu_67352_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4826_fu_67352_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_reg_88575.read(): tmp_4825_fu_67348_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_20_cast_fu_68486_p1() {
    p_1_reg2mem599_0_i_i_20_cast_fu_68486_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_20_reg_88941.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_20_fu_68462_p3() {
    p_1_reg2mem599_0_i_i_20_fu_68462_p3 = (!tmp_4867_fu_68446_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4867_fu_68446_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_19_reg_88924.read(): tmp_4866_fu_68442_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_21_cast_fu_68539_p1() {
    p_1_reg2mem599_0_i_i_21_cast_fu_68539_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_21_reg_88958.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_21_fu_68515_p3() {
    p_1_reg2mem599_0_i_i_21_fu_68515_p3 = (!tmp_4869_fu_68499_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4869_fu_68499_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_20_reg_88941.read(): tmp_4868_fu_68495_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_22_cast_fu_68592_p1() {
    p_1_reg2mem599_0_i_i_22_cast_fu_68592_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_22_reg_88975.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_22_fu_68568_p3() {
    p_1_reg2mem599_0_i_i_22_fu_68568_p3 = (!tmp_4871_fu_68552_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4871_fu_68552_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_21_reg_88958.read(): tmp_4870_fu_68548_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_23_cast_fu_68645_p1() {
    p_1_reg2mem599_0_i_i_23_cast_fu_68645_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_23_reg_88992.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_23_fu_68621_p3() {
    p_1_reg2mem599_0_i_i_23_fu_68621_p3 = (!tmp_4873_fu_68605_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4873_fu_68605_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_22_reg_88975.read(): tmp_4872_fu_68601_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_24_cast_fu_68698_p1() {
    p_1_reg2mem599_0_i_i_24_cast_fu_68698_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_24_reg_89009.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_24_fu_68674_p3() {
    p_1_reg2mem599_0_i_i_24_fu_68674_p3 = (!tmp_4875_fu_68658_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4875_fu_68658_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_23_reg_88992.read(): tmp_4874_fu_68654_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_25_cast_fu_68751_p1() {
    p_1_reg2mem599_0_i_i_25_cast_fu_68751_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_25_reg_89026.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_25_fu_68727_p3() {
    p_1_reg2mem599_0_i_i_25_fu_68727_p3 = (!tmp_4877_fu_68711_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4877_fu_68711_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_24_reg_89009.read(): tmp_4876_fu_68707_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_26_cast_fu_68804_p1() {
    p_1_reg2mem599_0_i_i_26_cast_fu_68804_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_26_reg_89043.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_26_fu_68780_p3() {
    p_1_reg2mem599_0_i_i_26_fu_68780_p3 = (!tmp_4879_fu_68764_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4879_fu_68764_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_25_reg_89026.read(): tmp_4878_fu_68760_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_27_cast_fu_68857_p1() {
    p_1_reg2mem599_0_i_i_27_cast_fu_68857_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_27_reg_89060.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_27_fu_68833_p3() {
    p_1_reg2mem599_0_i_i_27_fu_68833_p3 = (!tmp_4881_fu_68817_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4881_fu_68817_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_26_reg_89043.read(): tmp_4880_fu_68813_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_28_cast_fu_68910_p1() {
    p_1_reg2mem599_0_i_i_28_cast_fu_68910_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_28_reg_89077.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_28_fu_68886_p3() {
    p_1_reg2mem599_0_i_i_28_fu_68886_p3 = (!tmp_4883_fu_68870_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4883_fu_68870_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_27_reg_89060.read(): tmp_4882_fu_68866_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_29_cast_fu_68963_p1() {
    p_1_reg2mem599_0_i_i_29_cast_fu_68963_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_29_reg_89094.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_29_fu_68939_p3() {
    p_1_reg2mem599_0_i_i_29_fu_68939_p3 = (!tmp_4885_fu_68923_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4885_fu_68923_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_28_reg_89077.read(): tmp_4884_fu_68919_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_2_cast_fu_67461_p1() {
    p_1_reg2mem599_0_i_i_2_cast_fu_67461_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_2_reg_88625.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_2_fu_67454_p3() {
    p_1_reg2mem599_0_i_i_2_fu_67454_p3 = (!tmp_4829_fu_67418_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4829_fu_67418_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_1_reg_88604.read(): tmp_4828_fu_67414_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_30_cast_fu_69016_p1() {
    p_1_reg2mem599_0_i_i_30_cast_fu_69016_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_30_reg_89111.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_30_fu_68992_p3() {
    p_1_reg2mem599_0_i_i_30_fu_68992_p3 = (!tmp_4887_fu_68976_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4887_fu_68976_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_29_reg_89094.read(): tmp_4886_fu_68972_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_31_cast_fu_69069_p1() {
    p_1_reg2mem599_0_i_i_31_cast_fu_69069_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_31_reg_89128.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_31_fu_69045_p3() {
    p_1_reg2mem599_0_i_i_31_fu_69045_p3 = (!tmp_4889_fu_69029_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4889_fu_69029_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_30_reg_89111.read(): tmp_4888_fu_69025_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_32_cast_fu_69122_p1() {
    p_1_reg2mem599_0_i_i_32_cast_fu_69122_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_32_reg_89145.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_32_fu_69098_p3() {
    p_1_reg2mem599_0_i_i_32_fu_69098_p3 = (!tmp_4891_fu_69082_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4891_fu_69082_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_31_reg_89128.read(): tmp_4890_fu_69078_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_33_cast_fu_69175_p1() {
    p_1_reg2mem599_0_i_i_33_cast_fu_69175_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_33_reg_89162.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_33_fu_69151_p3() {
    p_1_reg2mem599_0_i_i_33_fu_69151_p3 = (!tmp_4893_fu_69135_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4893_fu_69135_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_32_reg_89145.read(): tmp_4892_fu_69131_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_34_cast_fu_69228_p1() {
    p_1_reg2mem599_0_i_i_34_cast_fu_69228_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_34_reg_89179.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_34_fu_69204_p3() {
    p_1_reg2mem599_0_i_i_34_fu_69204_p3 = (!tmp_4895_fu_69188_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4895_fu_69188_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_33_reg_89162.read(): tmp_4894_fu_69184_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_35_cast_fu_69281_p1() {
    p_1_reg2mem599_0_i_i_35_cast_fu_69281_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_35_reg_89196.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_35_fu_69257_p3() {
    p_1_reg2mem599_0_i_i_35_fu_69257_p3 = (!tmp_4897_fu_69241_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4897_fu_69241_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_34_reg_89179.read(): tmp_4896_fu_69237_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_36_cast_fu_69334_p1() {
    p_1_reg2mem599_0_i_i_36_cast_fu_69334_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_36_reg_89213.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_36_fu_69310_p3() {
    p_1_reg2mem599_0_i_i_36_fu_69310_p3 = (!tmp_4899_fu_69294_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4899_fu_69294_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_35_reg_89196.read(): tmp_4898_fu_69290_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_37_cast_fu_69387_p1() {
    p_1_reg2mem599_0_i_i_37_cast_fu_69387_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_37_reg_89230.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_37_fu_69363_p3() {
    p_1_reg2mem599_0_i_i_37_fu_69363_p3 = (!tmp_4901_fu_69347_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4901_fu_69347_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_36_reg_89213.read(): tmp_4900_fu_69343_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_38_cast_fu_69440_p1() {
    p_1_reg2mem599_0_i_i_38_cast_fu_69440_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_38_reg_89247.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_38_fu_69416_p3() {
    p_1_reg2mem599_0_i_i_38_fu_69416_p3 = (!tmp_4903_fu_69400_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4903_fu_69400_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_37_reg_89230.read(): tmp_4902_fu_69396_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_39_cast_fu_69493_p1() {
    p_1_reg2mem599_0_i_i_39_cast_fu_69493_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_39_reg_89264.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_39_fu_69469_p3() {
    p_1_reg2mem599_0_i_i_39_fu_69469_p3 = (!tmp_4905_fu_69453_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4905_fu_69453_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_38_reg_89247.read(): tmp_4904_fu_69449_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_3_cast_fu_67514_p1() {
    p_1_reg2mem599_0_i_i_3_cast_fu_67514_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_3_reg_88646.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_3_fu_67507_p3() {
    p_1_reg2mem599_0_i_i_3_fu_67507_p3 = (!tmp_4831_fu_67479_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4831_fu_67479_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_2_reg_88625.read(): tmp_4830_fu_67475_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_40_cast_fu_69546_p1() {
    p_1_reg2mem599_0_i_i_40_cast_fu_69546_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_40_reg_89281.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_40_fu_69522_p3() {
    p_1_reg2mem599_0_i_i_40_fu_69522_p3 = (!tmp_4907_fu_69506_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4907_fu_69506_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_39_reg_89264.read(): tmp_4906_fu_69502_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_41_cast_fu_69599_p1() {
    p_1_reg2mem599_0_i_i_41_cast_fu_69599_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_41_reg_89298.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_41_fu_69575_p3() {
    p_1_reg2mem599_0_i_i_41_fu_69575_p3 = (!tmp_4909_fu_69559_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4909_fu_69559_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_40_reg_89281.read(): tmp_4908_fu_69555_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_42_cast_fu_69652_p1() {
    p_1_reg2mem599_0_i_i_42_cast_fu_69652_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_42_reg_89315.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_42_fu_69628_p3() {
    p_1_reg2mem599_0_i_i_42_fu_69628_p3 = (!tmp_4911_fu_69612_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4911_fu_69612_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_41_reg_89298.read(): tmp_4910_fu_69608_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_43_cast_fu_69703_p1() {
    p_1_reg2mem599_0_i_i_43_cast_fu_69703_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_43_fu_69697_p3.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_43_fu_69697_p3() {
    p_1_reg2mem599_0_i_i_43_fu_69697_p3 = (!tmp_4913_reg_89337.read()[0].is_01())? sc_lv<60>(): ((tmp_4913_reg_89337.read()[0].to_bool())? p_1_reg2mem599_0_i_i_42_reg_89315.read(): tmp_4912_fu_69694_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_4_cast_fu_67585_p1() {
    p_1_reg2mem599_0_i_i_4_cast_fu_67585_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_4_reg_88652.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_4_fu_67560_p3() {
    p_1_reg2mem599_0_i_i_4_fu_67560_p3 = (!tmp_4833_fu_67532_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4833_fu_67532_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_3_reg_88646.read(): tmp_4832_fu_67528_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_5_cast_fu_67638_p1() {
    p_1_reg2mem599_0_i_i_5_cast_fu_67638_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_5_reg_88669.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_5_fu_67614_p3() {
    p_1_reg2mem599_0_i_i_5_fu_67614_p3 = (!tmp_4835_fu_67598_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4835_fu_67598_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_4_reg_88652.read(): tmp_4834_fu_67594_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_6_cast_fu_67691_p1() {
    p_1_reg2mem599_0_i_i_6_cast_fu_67691_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_6_reg_88686.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_6_fu_67667_p3() {
    p_1_reg2mem599_0_i_i_6_fu_67667_p3 = (!tmp_4837_fu_67651_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4837_fu_67651_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_5_reg_88669.read(): tmp_4836_fu_67647_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_7_cast_fu_67744_p1() {
    p_1_reg2mem599_0_i_i_7_cast_fu_67744_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_7_reg_88703.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_7_fu_67720_p3() {
    p_1_reg2mem599_0_i_i_7_fu_67720_p3 = (!tmp_4839_fu_67704_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4839_fu_67704_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_6_reg_88686.read(): tmp_4838_fu_67700_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_8_cast_fu_67797_p1() {
    p_1_reg2mem599_0_i_i_8_cast_fu_67797_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_8_reg_88720.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_8_fu_67773_p3() {
    p_1_reg2mem599_0_i_i_8_fu_67773_p3 = (!tmp_4841_fu_67757_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4841_fu_67757_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_7_reg_88703.read(): tmp_4840_fu_67753_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_9_cast_fu_67850_p1() {
    p_1_reg2mem599_0_i_i_9_cast_fu_67850_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_9_reg_88737.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_9_fu_67826_p3() {
    p_1_reg2mem599_0_i_i_9_fu_67826_p3 = (!tmp_4843_fu_67810_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4843_fu_67810_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_8_reg_88720.read(): tmp_4842_fu_67806_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_cast_42_fu_67903_p1() {
    p_1_reg2mem599_0_i_i_cast_42_fu_67903_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_s_reg_88754.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_cast_fu_67339_p1() {
    p_1_reg2mem599_0_i_i_cast_fu_67339_p1 = esl_zext<61,60>(p_1_reg2mem599_0_i_i_reg_88575.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_fu_67297_p3() {
    p_1_reg2mem599_0_i_i_fu_67297_p3 = (!tmp_4823_fu_67289_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4823_fu_67289_p3.read()[0].to_bool())? tmp_313_cast_fu_67268_p3.read(): tmp_4822_fu_67285_p1.read());
}

void krnl_sobel::thread_p_1_reg2mem599_0_i_i_s_fu_67879_p3() {
    p_1_reg2mem599_0_i_i_s_fu_67879_p3 = (!tmp_4845_fu_67863_p3.read()[0].is_01())? sc_lv<60>(): ((tmp_4845_fu_67863_p3.read()[0].to_bool())? p_1_reg2mem599_0_i_i_9_reg_88737.read(): tmp_4844_fu_67859_p1.read());
}

void krnl_sobel::thread_p_20_fu_29706_p3() {
    p_20_fu_29706_p3 = (!tmp_1468_fu_29698_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1468_fu_29698_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_21_fu_52991_p3() {
    p_21_fu_52991_p3 = (!tmp_1505_fu_52983_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1505_fu_52983_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_22_fu_30110_p3() {
    p_22_fu_30110_p3 = (!tmp_1560_fu_30102_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1560_fu_30102_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_23_fu_53395_p3() {
    p_23_fu_53395_p3 = (!tmp_1597_fu_53387_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1597_fu_53387_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_24_fu_30514_p3() {
    p_24_fu_30514_p3 = (!tmp_1652_fu_30506_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1652_fu_30506_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_25_fu_53800_p3() {
    p_25_fu_53800_p3 = (!tmp_1689_fu_53792_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1689_fu_53792_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_26_fu_30918_p3() {
    p_26_fu_30918_p3 = (!tmp_1744_fu_30910_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1744_fu_30910_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_27_fu_54205_p3() {
    p_27_fu_54205_p3 = (!tmp_1781_fu_54197_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1781_fu_54197_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_28_fu_31323_p3() {
    p_28_fu_31323_p3 = (!tmp_1836_fu_31315_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1836_fu_31315_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_29_fu_54609_p3() {
    p_29_fu_54609_p3 = (!tmp_1873_fu_54601_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1873_fu_54601_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_2_fu_25643_p3() {
    p_2_fu_25643_p3 = (!tmp_548_fu_25635_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_548_fu_25635_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_30_fu_31728_p3() {
    p_30_fu_31728_p3 = (!tmp_1928_fu_31720_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1928_fu_31720_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_31_fu_55014_p3() {
    p_31_fu_55014_p3 = (!tmp_1965_fu_55006_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_1965_fu_55006_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_32_fu_32133_p3() {
    p_32_fu_32133_p3 = (!tmp_2020_fu_32125_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2020_fu_32125_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_33_fu_55418_p3() {
    p_33_fu_55418_p3 = (!tmp_2057_fu_55410_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2057_fu_55410_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_34_fu_32537_p3() {
    p_34_fu_32537_p3 = (!tmp_2112_fu_32529_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2112_fu_32529_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_35_fu_55822_p3() {
    p_35_fu_55822_p3 = (!tmp_2149_fu_55814_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2149_fu_55814_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_36_fu_32941_p3() {
    p_36_fu_32941_p3 = (!tmp_2204_fu_32933_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2204_fu_32933_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_37_fu_56226_p3() {
    p_37_fu_56226_p3 = (!tmp_2241_fu_56218_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2241_fu_56218_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_38_fu_33346_p3() {
    p_38_fu_33346_p3 = (!tmp_2296_fu_33338_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2296_fu_33338_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_39_fu_56631_p3() {
    p_39_fu_56631_p3 = (!tmp_2333_fu_56623_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2333_fu_56623_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_3_fu_48926_p3() {
    p_3_fu_48926_p3 = (!tmp_585_fu_48918_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_585_fu_48918_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_40_fu_33750_p3() {
    p_40_fu_33750_p3 = (!tmp_2388_fu_33742_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2388_fu_33742_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_41_fu_57036_p3() {
    p_41_fu_57036_p3 = (!tmp_2425_fu_57028_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2425_fu_57028_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_42_fu_34154_p3() {
    p_42_fu_34154_p3 = (!tmp_2480_fu_34146_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2480_fu_34146_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_43_fu_57441_p3() {
    p_43_fu_57441_p3 = (!tmp_2517_fu_57433_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2517_fu_57433_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_44_fu_34558_p3() {
    p_44_fu_34558_p3 = (!tmp_2572_fu_34550_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2572_fu_34550_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_45_fu_57846_p3() {
    p_45_fu_57846_p3 = (!tmp_2609_fu_57838_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2609_fu_57838_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_46_fu_34963_p3() {
    p_46_fu_34963_p3 = (!tmp_2664_fu_34955_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2664_fu_34955_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_47_fu_58251_p3() {
    p_47_fu_58251_p3 = (!tmp_2701_fu_58243_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2701_fu_58243_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_48_fu_35367_p3() {
    p_48_fu_35367_p3 = (!tmp_2756_fu_35359_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2756_fu_35359_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_49_fu_58656_p3() {
    p_49_fu_58656_p3 = (!tmp_2793_fu_58648_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2793_fu_58648_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_4_fu_26052_p3() {
    p_4_fu_26052_p3 = (!tmp_640_fu_26044_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_640_fu_26044_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_50_fu_35771_p3() {
    p_50_fu_35771_p3 = (!tmp_2848_fu_35763_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2848_fu_35763_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_51_fu_59061_p3() {
    p_51_fu_59061_p3 = (!tmp_2885_fu_59053_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2885_fu_59053_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_52_fu_36175_p3() {
    p_52_fu_36175_p3 = (!tmp_2940_fu_36167_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2940_fu_36167_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_53_fu_59466_p3() {
    p_53_fu_59466_p3 = (!tmp_2977_fu_59458_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_2977_fu_59458_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_54_fu_36580_p3() {
    p_54_fu_36580_p3 = (!tmp_3032_fu_36572_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3032_fu_36572_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_55_fu_59871_p3() {
    p_55_fu_59871_p3 = (!tmp_3069_fu_59863_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3069_fu_59863_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_56_fu_36984_p3() {
    p_56_fu_36984_p3 = (!tmp_3124_fu_36976_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3124_fu_36976_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_57_fu_60276_p3() {
    p_57_fu_60276_p3 = (!tmp_3161_fu_60268_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3161_fu_60268_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_58_fu_37388_p3() {
    p_58_fu_37388_p3 = (!tmp_3216_fu_37380_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3216_fu_37380_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_59_fu_60681_p3() {
    p_59_fu_60681_p3 = (!tmp_3253_fu_60673_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3253_fu_60673_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_5_fu_49335_p3() {
    p_5_fu_49335_p3 = (!tmp_677_fu_49327_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_677_fu_49327_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_60_fu_37792_p3() {
    p_60_fu_37792_p3 = (!tmp_3308_fu_37784_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3308_fu_37784_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_61_fu_61086_p3() {
    p_61_fu_61086_p3 = (!tmp_3345_fu_61078_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3345_fu_61078_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_62_fu_38196_p3() {
    p_62_fu_38196_p3 = (!tmp_3400_fu_38188_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3400_fu_38188_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_63_fu_61491_p3() {
    p_63_fu_61491_p3 = (!tmp_3437_fu_61483_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3437_fu_61483_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_64_fu_38600_p3() {
    p_64_fu_38600_p3 = (!tmp_3492_fu_38592_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3492_fu_38592_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_65_fu_61896_p3() {
    p_65_fu_61896_p3 = (!tmp_3529_fu_61888_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3529_fu_61888_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_66_fu_39004_p3() {
    p_66_fu_39004_p3 = (!tmp_3584_fu_38996_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3584_fu_38996_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_67_fu_62301_p3() {
    p_67_fu_62301_p3 = (!tmp_3621_fu_62293_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3621_fu_62293_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_68_fu_39409_p3() {
    p_68_fu_39409_p3 = (!tmp_3676_fu_39401_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3676_fu_39401_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_69_fu_62705_p3() {
    p_69_fu_62705_p3 = (!tmp_3713_fu_62697_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3713_fu_62697_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_6_fu_26465_p3() {
    p_6_fu_26465_p3 = (!tmp_732_fu_26457_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_732_fu_26457_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_70_fu_39813_p3() {
    p_70_fu_39813_p3 = (!tmp_3768_fu_39805_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3768_fu_39805_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_71_fu_63110_p3() {
    p_71_fu_63110_p3 = (!tmp_3805_fu_63102_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3805_fu_63102_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_72_fu_40217_p3() {
    p_72_fu_40217_p3 = (!tmp_3860_fu_40209_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3860_fu_40209_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_73_fu_63514_p3() {
    p_73_fu_63514_p3 = (!tmp_3897_fu_63506_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3897_fu_63506_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_74_fu_40621_p3() {
    p_74_fu_40621_p3 = (!tmp_3952_fu_40613_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3952_fu_40613_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_75_fu_63919_p3() {
    p_75_fu_63919_p3 = (!tmp_3989_fu_63911_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_3989_fu_63911_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_76_fu_41025_p3() {
    p_76_fu_41025_p3 = (!tmp_4044_fu_41017_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4044_fu_41017_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_77_fu_64324_p3() {
    p_77_fu_64324_p3 = (!tmp_4081_fu_64316_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4081_fu_64316_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_78_fu_41430_p3() {
    p_78_fu_41430_p3 = (!tmp_4136_fu_41422_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4136_fu_41422_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_79_fu_64728_p3() {
    p_79_fu_64728_p3 = (!tmp_4173_fu_64720_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4173_fu_64720_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_7_fu_49748_p3() {
    p_7_fu_49748_p3 = (!tmp_769_fu_49740_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_769_fu_49740_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_80_fu_41834_p3() {
    p_80_fu_41834_p3 = (!tmp_4228_fu_41826_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4228_fu_41826_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_81_fu_65132_p3() {
    p_81_fu_65132_p3 = (!tmp_4265_fu_65124_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4265_fu_65124_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_82_fu_42239_p3() {
    p_82_fu_42239_p3 = (!tmp_4320_fu_42231_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4320_fu_42231_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_83_fu_65536_p3() {
    p_83_fu_65536_p3 = (!tmp_4357_fu_65528_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4357_fu_65528_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_84_fu_42643_p3() {
    p_84_fu_42643_p3 = (!tmp_4412_fu_42635_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4412_fu_42635_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_85_fu_65941_p3() {
    p_85_fu_65941_p3 = (!tmp_4449_fu_65933_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4449_fu_65933_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_86_fu_43048_p3() {
    p_86_fu_43048_p3 = (!tmp_4504_fu_43040_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4504_fu_43040_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_87_fu_66345_p3() {
    p_87_fu_66345_p3 = (!tmp_4541_fu_66337_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4541_fu_66337_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_88_fu_43453_p3() {
    p_88_fu_43453_p3 = (!tmp_4596_fu_43445_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4596_fu_43445_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_89_fu_66750_p3() {
    p_89_fu_66750_p3 = (!tmp_4633_fu_66742_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4633_fu_66742_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_8_fu_26877_p3() {
    p_8_fu_26877_p3 = (!tmp_824_fu_26869_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_824_fu_26869_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_90_fu_43858_p3() {
    p_90_fu_43858_p3 = (!tmp_4688_fu_43850_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4688_fu_43850_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_91_fu_67154_p3() {
    p_91_fu_67154_p3 = (!tmp_4819_fu_67146_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_4819_fu_67146_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_9_fu_50160_p3() {
    p_9_fu_50160_p3 = (!tmp_861_fu_50152_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_861_fu_50152_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_Result_s_fu_70260_p3() {
    p_Result_s_fu_70260_p3 = esl_concat<1,23>(ap_const_lv1_1, loc_V_1_reg_89497.read());
}

void krnl_sobel::thread_p_Val2_s_fu_70207_p1() {
    p_Val2_s_fu_70207_p1 = x_assign_reg_89492.read();
}

void krnl_sobel::thread_p_cast_cast_fu_25238_p3() {
    p_cast_cast_fu_25238_p3 = (!tmp_194_0_s_fu_25232_p2.read()[0].is_01())? sc_lv<6>(): ((tmp_194_0_s_fu_25232_p2.read()[0].to_bool())? ap_const_lv6_18: ap_const_lv6_19);
}

void krnl_sobel::thread_p_neg1_fu_67230_p2() {
    p_neg1_fu_67230_p2 = (!ap_const_lv64_0.is_01() || !F_i_i_i73_0_i_i_reg_88544.read().is_01())? sc_lv<64>(): (sc_biguint<64>(ap_const_lv64_0) - sc_biguint<64>(F_i_i_i73_0_i_i_reg_88544.read()));
}

void krnl_sobel::thread_p_neg_fu_43934_p2() {
    p_neg_fu_43934_p2 = (!ap_const_lv64_0.is_01() || !F_i_i_i_0_i_i_reg_79395.read().is_01())? sc_lv<64>(): (sc_biguint<64>(ap_const_lv64_0) - sc_biguint<64>(F_i_i_i_0_i_i_reg_79395.read()));
}

void krnl_sobel::thread_p_neg_t1_fu_67248_p2() {
    p_neg_t1_fu_67248_p2 = (!ap_const_lv64_0.is_01() || !tmp_431_fu_67245_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(ap_const_lv64_0) - sc_biguint<64>(tmp_431_fu_67245_p1.read()));
}

void krnl_sobel::thread_p_neg_t_fu_43952_p2() {
    p_neg_t_fu_43952_p2 = (!ap_const_lv64_0.is_01() || !tmp_321_fu_43949_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(ap_const_lv64_0) - sc_biguint<64>(tmp_321_fu_43949_p1.read()));
}

void krnl_sobel::thread_p_ph11_phi_fu_12740_p8() {
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2385.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, break_cond4_reg_80410.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, break_cond5_reg_80414.read()))) {
        p_ph11_phi_fu_12740_p8 = ap_const_lv1_1;
    } else {
        p_ph11_phi_fu_12740_p8 = p_ph11_reg_12735.read();
    }
}

void krnl_sobel::thread_p_ph14_phi_fu_12864_p8() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2814.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero3_reg_80559.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, break_cond6_reg_80590.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, break_cond7_reg_80594.read()))) {
        p_ph14_phi_fu_12864_p8 = ap_const_lv1_1;
    } else {
        p_ph14_phi_fu_12864_p8 = p_ph14_reg_12859.read();
    }
}

void krnl_sobel::thread_p_ph16_phi_fu_22798_p4() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3563.read()) && 
         !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero4_reg_89530.read()))) {
        p_ph16_phi_fu_22798_p4 = ap_const_lv1_1;
    } else {
        p_ph16_phi_fu_22798_p4 = p_ph16_reg_22794.read();
    }
}

void krnl_sobel::thread_p_ph1_cast_fu_23468_p1() {
    p_ph1_cast_fu_23468_p1 = esl_zext<32,3>(p_ph1_reg_2643.read());
}

void krnl_sobel::thread_p_ph5_phi_fu_2681_p8() {
    if ((!esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state974.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, break_cond_reg_71147.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, break_cond1_reg_71156.read()))) {
        p_ph5_phi_fu_2681_p8 = ap_const_lv1_1;
    } else {
        p_ph5_phi_fu_2681_p8 = p_ph5_reg_2676.read();
    }
}

void krnl_sobel::thread_p_ph_cast_fu_70487_p1() {
    p_ph_cast_fu_70487_p1 = esl_zext<32,3>(p_ph_reg_22807.read());
}

void krnl_sobel::thread_p_reg2mem161_0_reg2mem_0_i_i_fu_69752_p2() {
    p_reg2mem161_0_reg2mem_0_i_i_fu_69752_p2 = (!e_i10_i_i_i26_0_reg2mem593_0_i_reg_22723.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(e_i10_i_i_i26_0_reg2mem593_0_i_reg_22723.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_p_reg2mem165_0_reg2mem_0_i_i_fu_46680_p2() {
    p_reg2mem165_0_reg2mem_0_i_i_fu_46680_p2 = (!e_i10_i_i_i_3_reg2mem665_0_i_i_reg_12697.read().is_01() || !ap_const_lv32_0.is_01())? sc_lv<1>(): sc_lv<1>(e_i10_i_i_i_3_reg2mem665_0_i_i_reg_12697.read() == ap_const_lv32_0);
}

void krnl_sobel::thread_p_reg2mem169_0_reg2mem_0_i_i_fu_46456_p2() {
    p_reg2mem169_0_reg2mem_0_i_i_fu_46456_p2 = (!e_i10_i_i_i_0_reg2mem671_0_i_i_reg_12653.read().is_01() || !ap_const_lv8_FF.is_01())? sc_lv<1>(): sc_lv<1>(e_i10_i_i_i_0_reg2mem671_0_i_i_reg_12653.read() != ap_const_lv8_FF);
}

void krnl_sobel::thread_p_reg2mem177_0_reg2mem_0_i_i_fu_69758_p2() {
    p_reg2mem177_0_reg2mem_0_i_i_fu_69758_p2 = (icmp3_fu_69746_p2.read() & p_reg2mem161_0_reg2mem_0_i_i_fu_69752_p2.read());
}

void krnl_sobel::thread_p_reg2mem185_0_reg2mem_0_i_i_fu_46462_p2() {
    p_reg2mem185_0_reg2mem_0_i_i_fu_46462_p2 = (icmp_fu_46450_p2.read() & p_reg2mem169_0_reg2mem_0_i_i_fu_46456_p2.read());
}

void krnl_sobel::thread_p_reg2mem189_0_i_i_fu_70067_p2() {
    p_reg2mem189_0_i_i_fu_70067_p2 = (!p_020_0_reg2mem_0_i_i_cast_fu_70057_p1.read().is_01() || !tmp146_fu_70061_p2.read().is_01())? sc_lv<10>(): (sc_biguint<10>(p_020_0_reg2mem_0_i_i_cast_fu_70057_p1.read()) + sc_biguint<10>(tmp146_fu_70061_p2.read()));
}

void krnl_sobel::thread_p_reg2mem210_0_i_i_fu_69988_p2() {
    p_reg2mem210_0_i_i_fu_69988_p2 = (!ap_const_lv32_FFFFFFFF.is_01() || !e_i10_i_i_i26_3_reg2mem583_0_i_2_reg_22767.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFF) + sc_biguint<32>(e_i10_i_i_i26_3_reg2mem583_0_i_2_reg_22767.read()));
}

void krnl_sobel::thread_p_reg2mem214_0_i_i_fu_69884_p2() {
    p_reg2mem214_0_i_i_fu_69884_p2 = (!ap_const_lv9_1.is_01() || !e_i10_i_i_i26_0_reg2mem593_0_i_1_fu_69880_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(ap_const_lv9_1) + sc_biguint<9>(e_i10_i_i_i26_0_reg2mem593_0_i_1_fu_69880_p1.read()));
}

void krnl_sobel::thread_p_reg2mem216_0_i_i_fu_69796_p2() {
    p_reg2mem216_0_i_i_fu_69796_p2 = (!ap_const_lv8_1.is_01() || !e_i10_i_i_i26_0_reg2mem593_0_i_reg_22723.read().is_01())? sc_lv<8>(): (sc_biguint<8>(ap_const_lv8_1) + sc_biguint<8>(e_i10_i_i_i26_0_reg2mem593_0_i_reg_22723.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_10_fu_67927_p2() {
    p_reg2mem231_0_i_i_10_fu_67927_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_45_reg_88760.read().is_01() || !tmp_326_1_cast_fu_67924_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_45_reg_88760.read()) + sc_biguint<62>(tmp_326_1_cast_fu_67924_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_11_fu_67980_p2() {
    p_reg2mem231_0_i_i_11_fu_67980_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_10_reg_88777.read().is_01() || !tmp_326_10_cast_fu_67977_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_10_reg_88777.read()) + sc_biguint<62>(tmp_326_10_cast_fu_67977_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_12_fu_68033_p2() {
    p_reg2mem231_0_i_i_12_fu_68033_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_11_reg_88794.read().is_01() || !tmp_326_11_cast_fu_68030_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_11_reg_88794.read()) + sc_biguint<62>(tmp_326_11_cast_fu_68030_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_13_fu_68086_p2() {
    p_reg2mem231_0_i_i_13_fu_68086_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_12_reg_88811.read().is_01() || !tmp_326_12_cast_fu_68083_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_12_reg_88811.read()) + sc_biguint<62>(tmp_326_12_cast_fu_68083_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_14_fu_68139_p2() {
    p_reg2mem231_0_i_i_14_fu_68139_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_13_reg_88828.read().is_01() || !tmp_326_13_cast_fu_68136_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_13_reg_88828.read()) + sc_biguint<62>(tmp_326_13_cast_fu_68136_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_15_fu_68192_p2() {
    p_reg2mem231_0_i_i_15_fu_68192_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_14_reg_88845.read().is_01() || !tmp_326_14_cast_fu_68189_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_14_reg_88845.read()) + sc_biguint<62>(tmp_326_14_cast_fu_68189_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_16_fu_68245_p2() {
    p_reg2mem231_0_i_i_16_fu_68245_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_15_reg_88862.read().is_01() || !tmp_326_15_cast_fu_68242_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_15_reg_88862.read()) + sc_biguint<62>(tmp_326_15_cast_fu_68242_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_17_fu_68298_p2() {
    p_reg2mem231_0_i_i_17_fu_68298_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_16_reg_88879.read().is_01() || !tmp_326_16_cast_fu_68295_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_16_reg_88879.read()) + sc_biguint<62>(tmp_326_16_cast_fu_68295_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_18_fu_68351_p2() {
    p_reg2mem231_0_i_i_18_fu_68351_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_17_reg_88896.read().is_01() || !tmp_326_17_cast_fu_68348_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_17_reg_88896.read()) + sc_biguint<62>(tmp_326_17_cast_fu_68348_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_19_fu_68404_p2() {
    p_reg2mem231_0_i_i_19_fu_68404_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_18_reg_88913.read().is_01() || !tmp_326_18_cast_fu_68401_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_18_reg_88913.read()) + sc_biguint<62>(tmp_326_18_cast_fu_68401_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_1_fu_67381_p3() {
    p_reg2mem231_0_i_i_1_fu_67381_p3 = (!tmp_4827_fu_67377_p2.read()[0].is_01())? sc_lv<59>(): ((tmp_4827_fu_67377_p2.read()[0].to_bool())? tmp_374_fu_67370_p3.read(): ap_const_lv59_600000000000000);
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_20_fu_68457_p2() {
    p_reg2mem231_0_i_i_20_fu_68457_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_19_reg_88930.read().is_01() || !tmp_326_19_cast_fu_68454_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_19_reg_88930.read()) + sc_biguint<62>(tmp_326_19_cast_fu_68454_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_21_fu_68510_p2() {
    p_reg2mem231_0_i_i_21_fu_68510_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_20_reg_88947.read().is_01() || !tmp_326_20_cast_fu_68507_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_20_reg_88947.read()) + sc_biguint<62>(tmp_326_20_cast_fu_68507_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_22_fu_68563_p2() {
    p_reg2mem231_0_i_i_22_fu_68563_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_21_reg_88964.read().is_01() || !tmp_326_21_cast_fu_68560_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_21_reg_88964.read()) + sc_biguint<62>(tmp_326_21_cast_fu_68560_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_23_fu_68616_p2() {
    p_reg2mem231_0_i_i_23_fu_68616_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_22_reg_88981.read().is_01() || !tmp_326_22_cast_fu_68613_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_22_reg_88981.read()) + sc_biguint<62>(tmp_326_22_cast_fu_68613_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_24_fu_68669_p2() {
    p_reg2mem231_0_i_i_24_fu_68669_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_23_reg_88998.read().is_01() || !tmp_326_23_cast_fu_68666_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_23_reg_88998.read()) + sc_biguint<62>(tmp_326_23_cast_fu_68666_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_25_fu_68722_p2() {
    p_reg2mem231_0_i_i_25_fu_68722_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_24_reg_89015.read().is_01() || !tmp_326_24_cast_fu_68719_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_24_reg_89015.read()) + sc_biguint<62>(tmp_326_24_cast_fu_68719_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_26_fu_68775_p2() {
    p_reg2mem231_0_i_i_26_fu_68775_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_25_reg_89032.read().is_01() || !tmp_326_25_cast_fu_68772_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_25_reg_89032.read()) + sc_biguint<62>(tmp_326_25_cast_fu_68772_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_27_fu_68828_p2() {
    p_reg2mem231_0_i_i_27_fu_68828_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_26_reg_89049.read().is_01() || !tmp_326_26_cast_fu_68825_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_26_reg_89049.read()) + sc_biguint<62>(tmp_326_26_cast_fu_68825_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_28_fu_68881_p2() {
    p_reg2mem231_0_i_i_28_fu_68881_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_27_reg_89066.read().is_01() || !tmp_326_27_cast_fu_68878_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_27_reg_89066.read()) + sc_biguint<62>(tmp_326_27_cast_fu_68878_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_29_fu_68934_p2() {
    p_reg2mem231_0_i_i_29_fu_68934_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_28_reg_89083.read().is_01() || !tmp_326_28_cast_fu_68931_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_28_reg_89083.read()) + sc_biguint<62>(tmp_326_28_cast_fu_68931_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_2_fu_67448_p2() {
    p_reg2mem231_0_i_i_2_fu_67448_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_1_fu_67404_p1.read().is_01() || !tmp_326_2_cast_fu_67444_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_1_fu_67404_p1.read()) + sc_biguint<62>(tmp_326_2_cast_fu_67444_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_30_fu_68987_p2() {
    p_reg2mem231_0_i_i_30_fu_68987_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_29_reg_89100.read().is_01() || !tmp_326_29_cast_fu_68984_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_29_reg_89100.read()) + sc_biguint<62>(tmp_326_29_cast_fu_68984_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_31_fu_69040_p2() {
    p_reg2mem231_0_i_i_31_fu_69040_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_30_reg_89117.read().is_01() || !tmp_326_30_cast_fu_69037_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_30_reg_89117.read()) + sc_biguint<62>(tmp_326_30_cast_fu_69037_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_32_fu_69093_p2() {
    p_reg2mem231_0_i_i_32_fu_69093_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_31_reg_89134.read().is_01() || !tmp_326_31_cast_fu_69090_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_31_reg_89134.read()) + sc_biguint<62>(tmp_326_31_cast_fu_69090_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_33_fu_69146_p2() {
    p_reg2mem231_0_i_i_33_fu_69146_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_32_reg_89151.read().is_01() || !tmp_326_32_cast_fu_69143_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_32_reg_89151.read()) + sc_biguint<62>(tmp_326_32_cast_fu_69143_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_34_fu_69199_p2() {
    p_reg2mem231_0_i_i_34_fu_69199_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_33_reg_89168.read().is_01() || !tmp_326_33_cast_fu_69196_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_33_reg_89168.read()) + sc_biguint<62>(tmp_326_33_cast_fu_69196_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_35_fu_69252_p2() {
    p_reg2mem231_0_i_i_35_fu_69252_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_34_reg_89185.read().is_01() || !tmp_326_34_cast_fu_69249_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_34_reg_89185.read()) + sc_biguint<62>(tmp_326_34_cast_fu_69249_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_36_fu_69305_p2() {
    p_reg2mem231_0_i_i_36_fu_69305_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_35_reg_89202.read().is_01() || !tmp_326_35_cast_fu_69302_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_35_reg_89202.read()) + sc_biguint<62>(tmp_326_35_cast_fu_69302_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_37_fu_69358_p2() {
    p_reg2mem231_0_i_i_37_fu_69358_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_36_reg_89219.read().is_01() || !tmp_326_36_cast_fu_69355_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_36_reg_89219.read()) + sc_biguint<62>(tmp_326_36_cast_fu_69355_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_38_fu_69411_p2() {
    p_reg2mem231_0_i_i_38_fu_69411_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_37_reg_89236.read().is_01() || !tmp_326_37_cast_fu_69408_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_37_reg_89236.read()) + sc_biguint<62>(tmp_326_37_cast_fu_69408_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_39_fu_69464_p2() {
    p_reg2mem231_0_i_i_39_fu_69464_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_38_reg_89253.read().is_01() || !tmp_326_38_cast_fu_69461_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_38_reg_89253.read()) + sc_biguint<62>(tmp_326_38_cast_fu_69461_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_3_fu_67501_p2() {
    p_reg2mem231_0_i_i_3_fu_67501_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_2_fu_67464_p3.read().is_01() || !tmp_326_3_cast_fu_67497_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_2_fu_67464_p3.read()) + sc_biguint<62>(tmp_326_3_cast_fu_67497_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_40_fu_69517_p2() {
    p_reg2mem231_0_i_i_40_fu_69517_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_39_reg_89270.read().is_01() || !tmp_326_39_cast_fu_69514_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_39_reg_89270.read()) + sc_biguint<62>(tmp_326_39_cast_fu_69514_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_41_fu_69570_p2() {
    p_reg2mem231_0_i_i_41_fu_69570_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_40_reg_89287.read().is_01() || !tmp_326_40_cast_fu_69567_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_40_reg_89287.read()) + sc_biguint<62>(tmp_326_40_cast_fu_69567_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_42_fu_69623_p2() {
    p_reg2mem231_0_i_i_42_fu_69623_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_41_reg_89304.read().is_01() || !tmp_326_41_cast_fu_69620_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_41_reg_89304.read()) + sc_biguint<62>(tmp_326_41_cast_fu_69620_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_43_fu_69672_p2() {
    p_reg2mem231_0_i_i_43_fu_69672_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_42_reg_89321.read().is_01() || !tmp_326_42_cast_fu_69669_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_42_reg_89321.read()) + sc_biguint<62>(tmp_326_42_cast_fu_69669_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_44_fu_69724_p2() {
    p_reg2mem231_0_i_i_44_fu_69724_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_43_reg_89342.read().is_01() || !tmp_326_43_cast_fu_69721_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_43_reg_89342.read()) + sc_biguint<62>(tmp_326_43_cast_fu_69721_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_4_fu_67554_p2() {
    p_reg2mem231_0_i_i_4_fu_67554_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_3_fu_67517_p3.read().is_01() || !tmp_326_4_cast_fu_67550_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_3_fu_67517_p3.read()) + sc_biguint<62>(tmp_326_4_cast_fu_67550_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_5_fu_67609_p2() {
    p_reg2mem231_0_i_i_5_fu_67609_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_4_reg_88658.read().is_01() || !tmp_326_5_cast_fu_67606_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_4_reg_88658.read()) + sc_biguint<62>(tmp_326_5_cast_fu_67606_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_6_fu_67662_p2() {
    p_reg2mem231_0_i_i_6_fu_67662_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_5_reg_88675.read().is_01() || !tmp_326_6_cast_fu_67659_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_5_reg_88675.read()) + sc_biguint<62>(tmp_326_6_cast_fu_67659_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_7_fu_67715_p2() {
    p_reg2mem231_0_i_i_7_fu_67715_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_6_reg_88692.read().is_01() || !tmp_326_7_cast_fu_67712_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_6_reg_88692.read()) + sc_biguint<62>(tmp_326_7_cast_fu_67712_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_8_fu_67768_p2() {
    p_reg2mem231_0_i_i_8_fu_67768_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_7_reg_88709.read().is_01() || !tmp_326_8_cast_fu_67765_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_7_reg_88709.read()) + sc_biguint<62>(tmp_326_8_cast_fu_67765_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_9_fu_67821_p2() {
    p_reg2mem231_0_i_i_9_fu_67821_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_8_reg_88726.read().is_01() || !tmp_326_9_cast_fu_67818_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_8_reg_88726.read()) + sc_biguint<62>(tmp_326_9_cast_fu_67818_p1.read()));
}

void krnl_sobel::thread_p_reg2mem231_0_i_i_s_fu_67874_p2() {
    p_reg2mem231_0_i_i_s_fu_67874_p2 = (!y_i16_i_i_i20_1_reg2mem597_0_i_9_reg_88743.read().is_01() || !tmp_326_cast_fu_67871_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i20_1_reg2mem597_0_i_9_reg_88743.read()) + sc_biguint<62>(tmp_326_cast_fu_67871_p1.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_10_fu_53021_p2() {
    p_reg2mem270_0_i_i_10_fu_53021_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_46_reg_15191.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_46_reg_15191.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_11_fu_53426_p2() {
    p_reg2mem270_0_i_i_11_fu_53426_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_10_reg_15400.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_10_reg_15400.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_12_fu_53831_p2() {
    p_reg2mem270_0_i_i_12_fu_53831_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_11_reg_15609.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_11_reg_15609.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_13_fu_54235_p2() {
    p_reg2mem270_0_i_i_13_fu_54235_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_12_reg_15818.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_12_reg_15818.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_14_fu_54640_p2() {
    p_reg2mem270_0_i_i_14_fu_54640_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_13_reg_16027.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_13_reg_16027.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_15_fu_55044_p2() {
    p_reg2mem270_0_i_i_15_fu_55044_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_14_reg_16236.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_14_reg_16236.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_16_fu_55448_p2() {
    p_reg2mem270_0_i_i_16_fu_55448_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_15_reg_16445.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_15_reg_16445.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_17_fu_55852_p2() {
    p_reg2mem270_0_i_i_17_fu_55852_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_16_reg_16654.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_16_reg_16654.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_18_fu_56257_p2() {
    p_reg2mem270_0_i_i_18_fu_56257_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_17_reg_16863.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_17_reg_16863.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_19_fu_56662_p2() {
    p_reg2mem270_0_i_i_19_fu_56662_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_18_reg_17072.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_18_reg_17072.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_1_fu_48961_p2() {
    p_reg2mem270_0_i_i_1_fu_48961_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_reg_13099.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_reg_13099.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_20_fu_57067_p2() {
    p_reg2mem270_0_i_i_20_fu_57067_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_19_reg_17281.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_19_reg_17281.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_21_fu_57472_p2() {
    p_reg2mem270_0_i_i_21_fu_57472_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_20_reg_17490.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_20_reg_17490.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_22_fu_57877_p2() {
    p_reg2mem270_0_i_i_22_fu_57877_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_21_reg_17699.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_21_reg_17699.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_23_fu_58282_p2() {
    p_reg2mem270_0_i_i_23_fu_58282_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_22_reg_17908.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_22_reg_17908.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_24_fu_58687_p2() {
    p_reg2mem270_0_i_i_24_fu_58687_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_23_reg_18117.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_23_reg_18117.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_25_fu_59092_p2() {
    p_reg2mem270_0_i_i_25_fu_59092_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_24_reg_18326.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_24_reg_18326.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_26_fu_59497_p2() {
    p_reg2mem270_0_i_i_26_fu_59497_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_25_reg_18535.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_25_reg_18535.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_27_fu_59902_p2() {
    p_reg2mem270_0_i_i_27_fu_59902_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_26_reg_18744.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_26_reg_18744.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_28_fu_60307_p2() {
    p_reg2mem270_0_i_i_28_fu_60307_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_27_reg_18953.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_27_reg_18953.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_29_fu_60712_p2() {
    p_reg2mem270_0_i_i_29_fu_60712_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_28_reg_19162.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_28_reg_19162.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_2_fu_49370_p2() {
    p_reg2mem270_0_i_i_2_fu_49370_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_1_reg_13310.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_1_reg_13310.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_30_fu_61117_p2() {
    p_reg2mem270_0_i_i_30_fu_61117_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_29_reg_19371.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_29_reg_19371.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_31_fu_61522_p2() {
    p_reg2mem270_0_i_i_31_fu_61522_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_30_reg_19580.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_30_reg_19580.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_32_fu_61927_p2() {
    p_reg2mem270_0_i_i_32_fu_61927_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_31_reg_19789.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_31_reg_19789.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_33_fu_62331_p2() {
    p_reg2mem270_0_i_i_33_fu_62331_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_32_reg_19998.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_32_reg_19998.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_34_fu_62736_p2() {
    p_reg2mem270_0_i_i_34_fu_62736_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_33_reg_20207.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_33_reg_20207.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_35_fu_63140_p2() {
    p_reg2mem270_0_i_i_35_fu_63140_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_34_reg_20416.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_34_reg_20416.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_36_fu_63545_p2() {
    p_reg2mem270_0_i_i_36_fu_63545_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_35_reg_20625.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_35_reg_20625.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_37_fu_63950_p2() {
    p_reg2mem270_0_i_i_37_fu_63950_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_36_reg_20834.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_36_reg_20834.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_38_fu_64354_p2() {
    p_reg2mem270_0_i_i_38_fu_64354_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_37_reg_21043.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_37_reg_21043.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_39_fu_64758_p2() {
    p_reg2mem270_0_i_i_39_fu_64758_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_38_reg_21252.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_38_reg_21252.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_3_fu_49786_p2() {
    p_reg2mem270_0_i_i_3_fu_49786_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_2_reg_13520.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_2_reg_13520.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_40_fu_65162_p2() {
    p_reg2mem270_0_i_i_40_fu_65162_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_39_reg_21461.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_39_reg_21461.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_41_fu_65567_p2() {
    p_reg2mem270_0_i_i_41_fu_65567_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_40_reg_21670.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_40_reg_21670.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_42_fu_65971_p2() {
    p_reg2mem270_0_i_i_42_fu_65971_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_41_reg_21879.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_41_reg_21879.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_43_fu_66376_p2() {
    p_reg2mem270_0_i_i_43_fu_66376_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_42_reg_22088.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_42_reg_22088.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_44_fu_66780_p2() {
    p_reg2mem270_0_i_i_44_fu_66780_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_43_reg_22297.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_43_reg_22297.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_45_fu_67173_p2() {
    p_reg2mem270_0_i_i_45_fu_67173_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_44_reg_22505.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_44_reg_22505.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_4_fu_50191_p2() {
    p_reg2mem270_0_i_i_4_fu_50191_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_3_reg_13728.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_3_reg_13728.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_5_fu_50595_p2() {
    p_reg2mem270_0_i_i_5_fu_50595_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_4_reg_13937.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_4_reg_13937.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_6_fu_51000_p2() {
    p_reg2mem270_0_i_i_6_fu_51000_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_5_reg_14146.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_5_reg_14146.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_7_fu_51405_p2() {
    p_reg2mem270_0_i_i_7_fu_51405_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_6_reg_14355.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_6_reg_14355.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_8_fu_51809_p2() {
    p_reg2mem270_0_i_i_8_fu_51809_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_7_reg_14564.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_7_reg_14564.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_9_fu_52213_p2() {
    p_reg2mem270_0_i_i_9_fu_52213_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_8_reg_14773.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_8_reg_14773.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem270_0_i_i_s_fu_52617_p2() {
    p_reg2mem270_0_i_i_s_fu_52617_p2 = (!y_i17_i_i_i11_1_reg2mem613_0_i_9_reg_14982.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i11_1_reg2mem613_0_i_9_reg_14982.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_10_fu_53015_p2() {
    p_reg2mem272_0_i_i_10_fu_53015_p2 = (!p_143_reg2mem615_0_i_i_s_reg_15180.read().is_01() || !tmp_338_10_fu_53010_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_s_reg_15180.read()) + sc_biguint<64>(tmp_338_10_fu_53010_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_11_fu_53420_p2() {
    p_reg2mem272_0_i_i_11_fu_53420_p2 = (!p_143_reg2mem615_0_i_i_10_reg_15389.read().is_01() || !tmp_338_11_fu_53414_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_10_reg_15389.read()) + sc_biguint<64>(tmp_338_11_fu_53414_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_12_fu_53825_p2() {
    p_reg2mem272_0_i_i_12_fu_53825_p2 = (!p_143_reg2mem615_0_i_i_11_reg_15598.read().is_01() || !tmp_338_12_fu_53819_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_11_reg_15598.read()) + sc_biguint<64>(tmp_338_12_fu_53819_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_13_fu_54229_p2() {
    p_reg2mem272_0_i_i_13_fu_54229_p2 = (!p_143_reg2mem615_0_i_i_12_reg_15807.read().is_01() || !tmp_338_13_fu_54224_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_12_reg_15807.read()) + sc_biguint<64>(tmp_338_13_fu_54224_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_14_fu_54634_p2() {
    p_reg2mem272_0_i_i_14_fu_54634_p2 = (!p_143_reg2mem615_0_i_i_13_reg_16016.read().is_01() || !tmp_338_14_fu_54628_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_13_reg_16016.read()) + sc_biguint<64>(tmp_338_14_fu_54628_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_15_fu_55038_p2() {
    p_reg2mem272_0_i_i_15_fu_55038_p2 = (!p_143_reg2mem615_0_i_i_14_reg_16225.read().is_01() || !tmp_338_15_fu_55033_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_14_reg_16225.read()) + sc_biguint<64>(tmp_338_15_fu_55033_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_16_fu_55442_p2() {
    p_reg2mem272_0_i_i_16_fu_55442_p2 = (!p_143_reg2mem615_0_i_i_15_reg_16434.read().is_01() || !tmp_338_16_fu_55437_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_15_reg_16434.read()) + sc_biguint<64>(tmp_338_16_fu_55437_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_17_fu_55846_p2() {
    p_reg2mem272_0_i_i_17_fu_55846_p2 = (!p_143_reg2mem615_0_i_i_16_reg_16643.read().is_01() || !tmp_338_17_fu_55841_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_16_reg_16643.read()) + sc_biguint<64>(tmp_338_17_fu_55841_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_18_fu_56251_p2() {
    p_reg2mem272_0_i_i_18_fu_56251_p2 = (!p_143_reg2mem615_0_i_i_17_reg_16852.read().is_01() || !tmp_338_18_fu_56245_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_17_reg_16852.read()) + sc_biguint<64>(tmp_338_18_fu_56245_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_19_fu_56656_p2() {
    p_reg2mem272_0_i_i_19_fu_56656_p2 = (!p_143_reg2mem615_0_i_i_18_reg_17061.read().is_01() || !tmp_338_19_fu_56650_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_18_reg_17061.read()) + sc_biguint<64>(tmp_338_19_fu_56650_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_1_fu_48955_p2() {
    p_reg2mem272_0_i_i_1_fu_48955_p2 = (!p_143_reg2mem615_0_i_i_reg_13089.read().is_01() || !tmp_338_1_fu_48949_p2.read().is_01())? sc_lv<63>(): (sc_biguint<63>(p_143_reg2mem615_0_i_i_reg_13089.read()) + sc_biguint<63>(tmp_338_1_fu_48949_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_20_fu_57061_p2() {
    p_reg2mem272_0_i_i_20_fu_57061_p2 = (!p_143_reg2mem615_0_i_i_19_reg_17270.read().is_01() || !tmp_338_20_fu_57055_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_19_reg_17270.read()) + sc_biguint<64>(tmp_338_20_fu_57055_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_21_fu_57466_p2() {
    p_reg2mem272_0_i_i_21_fu_57466_p2 = (!p_143_reg2mem615_0_i_i_20_reg_17479.read().is_01() || !tmp_338_21_fu_57460_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_20_reg_17479.read()) + sc_biguint<64>(tmp_338_21_fu_57460_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_22_fu_57871_p2() {
    p_reg2mem272_0_i_i_22_fu_57871_p2 = (!p_143_reg2mem615_0_i_i_21_reg_17688.read().is_01() || !tmp_338_22_fu_57865_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_21_reg_17688.read()) + sc_biguint<64>(tmp_338_22_fu_57865_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_23_fu_58276_p2() {
    p_reg2mem272_0_i_i_23_fu_58276_p2 = (!p_143_reg2mem615_0_i_i_22_reg_17897.read().is_01() || !tmp_338_23_fu_58270_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_22_reg_17897.read()) + sc_biguint<64>(tmp_338_23_fu_58270_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_24_fu_58681_p2() {
    p_reg2mem272_0_i_i_24_fu_58681_p2 = (!p_143_reg2mem615_0_i_i_23_reg_18106.read().is_01() || !tmp_338_24_fu_58675_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_23_reg_18106.read()) + sc_biguint<64>(tmp_338_24_fu_58675_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_25_fu_59086_p2() {
    p_reg2mem272_0_i_i_25_fu_59086_p2 = (!p_143_reg2mem615_0_i_i_24_reg_18315.read().is_01() || !tmp_338_25_fu_59080_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_24_reg_18315.read()) + sc_biguint<64>(tmp_338_25_fu_59080_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_26_fu_59491_p2() {
    p_reg2mem272_0_i_i_26_fu_59491_p2 = (!p_143_reg2mem615_0_i_i_25_reg_18524.read().is_01() || !tmp_338_26_fu_59485_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_25_reg_18524.read()) + sc_biguint<64>(tmp_338_26_fu_59485_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_27_fu_59896_p2() {
    p_reg2mem272_0_i_i_27_fu_59896_p2 = (!p_143_reg2mem615_0_i_i_26_reg_18733.read().is_01() || !tmp_338_27_fu_59890_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_26_reg_18733.read()) + sc_biguint<64>(tmp_338_27_fu_59890_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_28_fu_60301_p2() {
    p_reg2mem272_0_i_i_28_fu_60301_p2 = (!p_143_reg2mem615_0_i_i_27_reg_18942.read().is_01() || !tmp_338_28_fu_60295_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_27_reg_18942.read()) + sc_biguint<64>(tmp_338_28_fu_60295_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_29_fu_60706_p2() {
    p_reg2mem272_0_i_i_29_fu_60706_p2 = (!p_143_reg2mem615_0_i_i_28_reg_19151.read().is_01() || !tmp_338_29_fu_60700_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_28_reg_19151.read()) + sc_biguint<64>(tmp_338_29_fu_60700_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_2_fu_49364_p2() {
    p_reg2mem272_0_i_i_2_fu_49364_p2 = (!p_143_reg2mem615_0_i_i_1_reg_13299.read().is_01() || !tmp_338_2_fu_49358_p2.read().is_01())? sc_lv<63>(): (sc_biguint<63>(p_143_reg2mem615_0_i_i_1_reg_13299.read()) + sc_biguint<63>(tmp_338_2_fu_49358_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_30_fu_61111_p2() {
    p_reg2mem272_0_i_i_30_fu_61111_p2 = (!p_143_reg2mem615_0_i_i_29_reg_19360.read().is_01() || !tmp_338_30_fu_61105_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_29_reg_19360.read()) + sc_biguint<64>(tmp_338_30_fu_61105_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_31_fu_61516_p2() {
    p_reg2mem272_0_i_i_31_fu_61516_p2 = (!p_143_reg2mem615_0_i_i_30_reg_19569.read().is_01() || !tmp_338_31_fu_61510_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_30_reg_19569.read()) + sc_biguint<64>(tmp_338_31_fu_61510_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_32_fu_61921_p2() {
    p_reg2mem272_0_i_i_32_fu_61921_p2 = (!p_143_reg2mem615_0_i_i_31_reg_19778.read().is_01() || !tmp_338_32_fu_61915_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_31_reg_19778.read()) + sc_biguint<64>(tmp_338_32_fu_61915_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_33_fu_62325_p2() {
    p_reg2mem272_0_i_i_33_fu_62325_p2 = (!p_143_reg2mem615_0_i_i_32_reg_19987.read().is_01() || !tmp_338_33_fu_62320_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_32_reg_19987.read()) + sc_biguint<64>(tmp_338_33_fu_62320_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_34_fu_62730_p2() {
    p_reg2mem272_0_i_i_34_fu_62730_p2 = (!p_143_reg2mem615_0_i_i_33_reg_20196.read().is_01() || !tmp_338_34_fu_62724_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_33_reg_20196.read()) + sc_biguint<64>(tmp_338_34_fu_62724_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_35_fu_63134_p2() {
    p_reg2mem272_0_i_i_35_fu_63134_p2 = (!p_143_reg2mem615_0_i_i_34_reg_20405.read().is_01() || !tmp_338_35_fu_63129_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_34_reg_20405.read()) + sc_biguint<64>(tmp_338_35_fu_63129_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_36_fu_63539_p2() {
    p_reg2mem272_0_i_i_36_fu_63539_p2 = (!p_143_reg2mem615_0_i_i_35_reg_20614.read().is_01() || !tmp_338_36_fu_63533_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_35_reg_20614.read()) + sc_biguint<64>(tmp_338_36_fu_63533_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_37_fu_63944_p2() {
    p_reg2mem272_0_i_i_37_fu_63944_p2 = (!p_143_reg2mem615_0_i_i_36_reg_20823.read().is_01() || !tmp_338_37_fu_63938_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_36_reg_20823.read()) + sc_biguint<64>(tmp_338_37_fu_63938_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_38_fu_64348_p2() {
    p_reg2mem272_0_i_i_38_fu_64348_p2 = (!p_143_reg2mem615_0_i_i_37_reg_21032.read().is_01() || !tmp_338_38_fu_64343_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_37_reg_21032.read()) + sc_biguint<64>(tmp_338_38_fu_64343_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_39_fu_64752_p2() {
    p_reg2mem272_0_i_i_39_fu_64752_p2 = (!p_143_reg2mem615_0_i_i_38_reg_21241.read().is_01() || !tmp_338_39_fu_64747_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_38_reg_21241.read()) + sc_biguint<64>(tmp_338_39_fu_64747_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_3_fu_49781_p2() {
    p_reg2mem272_0_i_i_3_fu_49781_p2 = (!tmp_338_3_cast_fu_49777_p1.read().is_01() || !p_143_reg2mem615_0_i_i_2_cast_reg_81511.read().is_01())? sc_lv<64>(): (sc_biguint<64>(tmp_338_3_cast_fu_49777_p1.read()) + sc_biguint<64>(p_143_reg2mem615_0_i_i_2_cast_reg_81511.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_40_fu_65156_p2() {
    p_reg2mem272_0_i_i_40_fu_65156_p2 = (!p_143_reg2mem615_0_i_i_39_reg_21450.read().is_01() || !tmp_338_40_fu_65151_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_39_reg_21450.read()) + sc_biguint<64>(tmp_338_40_fu_65151_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_41_fu_65561_p2() {
    p_reg2mem272_0_i_i_41_fu_65561_p2 = (!p_143_reg2mem615_0_i_i_40_reg_21659.read().is_01() || !tmp_338_41_fu_65555_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_40_reg_21659.read()) + sc_biguint<64>(tmp_338_41_fu_65555_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_42_fu_65965_p2() {
    p_reg2mem272_0_i_i_42_fu_65965_p2 = (!p_143_reg2mem615_0_i_i_41_reg_21868.read().is_01() || !tmp_338_42_fu_65960_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_41_reg_21868.read()) + sc_biguint<64>(tmp_338_42_fu_65960_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_43_fu_66370_p2() {
    p_reg2mem272_0_i_i_43_fu_66370_p2 = (!p_143_reg2mem615_0_i_i_42_reg_22077.read().is_01() || !tmp_338_43_fu_66364_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_42_reg_22077.read()) + sc_biguint<64>(tmp_338_43_fu_66364_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_44_fu_66774_p2() {
    p_reg2mem272_0_i_i_44_fu_66774_p2 = (!p_143_reg2mem615_0_i_i_43_reg_22286.read().is_01() || !tmp_338_44_fu_66769_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_43_reg_22286.read()) + sc_biguint<64>(tmp_338_44_fu_66769_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_4_fu_50185_p2() {
    p_reg2mem272_0_i_i_4_fu_50185_p2 = (!p_143_reg2mem615_0_i_i_3_reg_13718.read().is_01() || !tmp_338_4_fu_50179_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_3_reg_13718.read()) + sc_biguint<64>(tmp_338_4_fu_50179_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_5_fu_50589_p2() {
    p_reg2mem272_0_i_i_5_fu_50589_p2 = (!p_143_reg2mem615_0_i_i_4_reg_13926.read().is_01() || !tmp_338_5_fu_50584_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_4_reg_13926.read()) + sc_biguint<64>(tmp_338_5_fu_50584_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_6_fu_50994_p2() {
    p_reg2mem272_0_i_i_6_fu_50994_p2 = (!p_143_reg2mem615_0_i_i_5_reg_14135.read().is_01() || !tmp_338_6_fu_50988_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_5_reg_14135.read()) + sc_biguint<64>(tmp_338_6_fu_50988_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_7_fu_51399_p2() {
    p_reg2mem272_0_i_i_7_fu_51399_p2 = (!p_143_reg2mem615_0_i_i_6_reg_14344.read().is_01() || !tmp_338_7_fu_51393_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_6_reg_14344.read()) + sc_biguint<64>(tmp_338_7_fu_51393_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_8_fu_51803_p2() {
    p_reg2mem272_0_i_i_8_fu_51803_p2 = (!p_143_reg2mem615_0_i_i_7_reg_14553.read().is_01() || !tmp_338_8_fu_51798_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_7_reg_14553.read()) + sc_biguint<64>(tmp_338_8_fu_51798_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_9_fu_52207_p2() {
    p_reg2mem272_0_i_i_9_fu_52207_p2 = (!p_143_reg2mem615_0_i_i_8_reg_14762.read().is_01() || !tmp_338_9_fu_52202_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_8_reg_14762.read()) + sc_biguint<64>(tmp_338_9_fu_52202_p2.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_fu_48553_p2() {
    p_reg2mem272_0_i_i_fu_48553_p2 = (!p_reg2mem288_0_i_i_cast_reg_81102.read().is_01() || !tmp_338_cast_fu_48549_p1.read().is_01())? sc_lv<63>(): (sc_biguint<63>(p_reg2mem288_0_i_i_cast_reg_81102.read()) + sc_biguint<63>(tmp_338_cast_fu_48549_p1.read()));
}

void krnl_sobel::thread_p_reg2mem272_0_i_i_s_fu_52611_p2() {
    p_reg2mem272_0_i_i_s_fu_52611_p2 = (!p_143_reg2mem615_0_i_i_9_reg_14971.read().is_01() || !tmp_338_s_fu_52606_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_143_reg2mem615_0_i_i_9_reg_14971.read()) + sc_biguint<64>(tmp_338_s_fu_52606_p2.read()));
}

void krnl_sobel::thread_p_reg2mem288_0_i_i_cast2_fu_48342_p3() {
    p_reg2mem288_0_i_i_cast2_fu_48342_p3 = esl_concat<1,38>(tmp_288_fu_48339_p1.read(), ap_const_lv38_0);
}

void krnl_sobel::thread_p_reg2mem288_0_i_i_cast_fu_48350_p1() {
    p_reg2mem288_0_i_i_cast_fu_48350_p1 = esl_zext<63,62>(p_reg2mem288_0_i_i_fu_48332_p3.read());
}

void krnl_sobel::thread_p_reg2mem288_0_i_i_fu_48332_p3() {
    p_reg2mem288_0_i_i_fu_48332_p3 = esl_concat<24,38>(p_048_0_reg2mem_0_i_i_reg_81059.read(), ap_const_lv38_0);
}

void krnl_sobel::thread_p_reg2mem292_0_i_i_fu_48310_p3() {
    p_reg2mem292_0_i_i_fu_48310_p3 = esl_concat<1,23>(ap_const_lv1_1, tmp_282_reg_81003.read());
}

void krnl_sobel::thread_p_reg2mem313_0_i_i_1_cast_fu_47989_p1() {
    p_reg2mem313_0_i_i_1_cast_fu_47989_p1 = esl_zext<11,10>(p_reg2mem313_0_i_i_1_fu_47984_p2.read());
}

void krnl_sobel::thread_p_reg2mem313_0_i_i_1_fu_47984_p2() {
    p_reg2mem313_0_i_i_1_fu_47984_p2 = (!tmp144_cast_fu_47980_p1.read().is_01() || !tmp_274_cast_reg_80817.read().is_01())? sc_lv<10>(): (sc_biguint<10>(tmp144_cast_fu_47980_p1.read()) + sc_biguint<10>(tmp_274_cast_reg_80817.read()));
}

void krnl_sobel::thread_p_reg2mem313_0_i_i_2_cast_fu_48204_p1() {
    p_reg2mem313_0_i_i_2_cast_fu_48204_p1 = esl_sext<16,11>(p_reg2mem313_0_i_i_2_reg_80971.read());
}

void krnl_sobel::thread_p_reg2mem313_0_i_i_2_fu_48195_p2() {
    p_reg2mem313_0_i_i_2_fu_48195_p2 = (!tmp_278_2_fu_48190_p2.read().is_01() || !tmp_267_2_cast_fu_48164_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_278_2_fu_48190_p2.read()) - sc_biguint<11>(tmp_267_2_cast_fu_48164_p1.read()));
}

void krnl_sobel::thread_p_reg2mem315_0_i_i_1_fu_48041_p2() {
    p_reg2mem315_0_i_i_1_fu_48041_p2 = (!tmp_270_1_fu_48036_p2.read().is_01() || !tmp_268_1_cast_fu_48032_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_270_1_fu_48036_p2.read()) + sc_biguint<11>(tmp_268_1_cast_fu_48032_p1.read()));
}

void krnl_sobel::thread_p_reg2mem315_0_i_i_2_cast_fu_48201_p1() {
    p_reg2mem315_0_i_i_2_cast_fu_48201_p1 = esl_sext<16,11>(p_reg2mem315_0_i_i_2_reg_80966.read());
}

void krnl_sobel::thread_p_reg2mem315_0_i_i_2_fu_48172_p2() {
    p_reg2mem315_0_i_i_2_fu_48172_p2 = (!tmp_269_2_fu_48168_p2.read().is_01() || !tmp_267_2_cast_fu_48164_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_269_2_fu_48168_p2.read()) + sc_biguint<11>(tmp_267_2_cast_fu_48164_p1.read()));
}

void krnl_sobel::thread_p_reg2mem315_0_i_i_cast_fu_47918_p1() {
    p_reg2mem315_0_i_i_cast_fu_47918_p1 = esl_sext<11,9>(p_reg2mem315_0_i_i_fu_47913_p2.read());
}

void krnl_sobel::thread_p_reg2mem315_0_i_i_fu_47913_p2() {
    p_reg2mem315_0_i_i_fu_47913_p2 = (!tmp_267_cast_fu_47909_p1.read().is_01() || !tmp_261_cast_reg_80755.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_267_cast_fu_47909_p1.read()) - sc_biguint<9>(tmp_261_cast_reg_80755.read()));
}

void krnl_sobel::thread_p_reg2mem374_0_i_i_fu_46771_p2() {
    p_reg2mem374_0_i_i_fu_46771_p2 = (!p_0146_0_reg2mem_0_i_i_cast_fu_46761_p1.read().is_01() || !tmp140_fu_46765_p2.read().is_01())? sc_lv<10>(): (sc_biguint<10>(p_0146_0_reg2mem_0_i_i_cast_fu_46761_p1.read()) + sc_biguint<10>(tmp140_fu_46765_p2.read()));
}

void krnl_sobel::thread_p_reg2mem395_0_i_i_fu_46692_p2() {
    p_reg2mem395_0_i_i_fu_46692_p2 = (!ap_const_lv32_FFFFFFFF.is_01() || !e_i10_i_i_i_3_reg2mem665_0_i_i_reg_12697.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFF) + sc_biguint<32>(e_i10_i_i_i_3_reg2mem665_0_i_i_reg_12697.read()));
}

void krnl_sobel::thread_p_reg2mem399_0_i_i_fu_46588_p2() {
    p_reg2mem399_0_i_i_fu_46588_p2 = (!ap_const_lv9_1.is_01() || !e_i10_i_i_i_0_reg2mem671_0_i_i_1_fu_46584_p1.read().is_01())? sc_lv<9>(): (sc_biguint<9>(ap_const_lv9_1) + sc_biguint<9>(e_i10_i_i_i_0_reg2mem671_0_i_i_1_fu_46584_p1.read()));
}

void krnl_sobel::thread_p_reg2mem401_0_i_i_fu_46500_p2() {
    p_reg2mem401_0_i_i_fu_46500_p2 = (!ap_const_lv8_1.is_01() || !e_i10_i_i_i_0_reg2mem671_0_i_i_reg_12653.read().is_01())? sc_lv<8>(): (sc_biguint<8>(ap_const_lv8_1) + sc_biguint<8>(e_i10_i_i_i_0_reg2mem671_0_i_i_reg_12653.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_10_fu_44631_p2() {
    p_reg2mem416_0_i_i_10_fu_44631_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_45_reg_79605.read().is_01() || !tmp_192_1_cast_fu_44628_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_45_reg_79605.read()) + sc_biguint<62>(tmp_192_1_cast_fu_44628_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_11_fu_44684_p2() {
    p_reg2mem416_0_i_i_11_fu_44684_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_10_reg_79622.read().is_01() || !tmp_192_10_cast_fu_44681_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_10_reg_79622.read()) + sc_biguint<62>(tmp_192_10_cast_fu_44681_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_12_fu_44737_p2() {
    p_reg2mem416_0_i_i_12_fu_44737_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_11_reg_79639.read().is_01() || !tmp_192_11_cast_fu_44734_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_11_reg_79639.read()) + sc_biguint<62>(tmp_192_11_cast_fu_44734_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_13_fu_44790_p2() {
    p_reg2mem416_0_i_i_13_fu_44790_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_12_reg_79656.read().is_01() || !tmp_192_12_cast_fu_44787_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_12_reg_79656.read()) + sc_biguint<62>(tmp_192_12_cast_fu_44787_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_14_fu_44843_p2() {
    p_reg2mem416_0_i_i_14_fu_44843_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_13_reg_79673.read().is_01() || !tmp_192_13_cast_fu_44840_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_13_reg_79673.read()) + sc_biguint<62>(tmp_192_13_cast_fu_44840_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_15_fu_44896_p2() {
    p_reg2mem416_0_i_i_15_fu_44896_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_14_reg_79690.read().is_01() || !tmp_192_14_cast_fu_44893_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_14_reg_79690.read()) + sc_biguint<62>(tmp_192_14_cast_fu_44893_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_16_fu_44949_p2() {
    p_reg2mem416_0_i_i_16_fu_44949_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_15_reg_79707.read().is_01() || !tmp_192_15_cast_fu_44946_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_15_reg_79707.read()) + sc_biguint<62>(tmp_192_15_cast_fu_44946_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_17_fu_45002_p2() {
    p_reg2mem416_0_i_i_17_fu_45002_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_16_reg_79724.read().is_01() || !tmp_192_16_cast_fu_44999_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_16_reg_79724.read()) + sc_biguint<62>(tmp_192_16_cast_fu_44999_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_18_fu_45055_p2() {
    p_reg2mem416_0_i_i_18_fu_45055_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_17_reg_79741.read().is_01() || !tmp_192_17_cast_fu_45052_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_17_reg_79741.read()) + sc_biguint<62>(tmp_192_17_cast_fu_45052_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_19_fu_45108_p2() {
    p_reg2mem416_0_i_i_19_fu_45108_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_18_reg_79758.read().is_01() || !tmp_192_18_cast_fu_45105_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_18_reg_79758.read()) + sc_biguint<62>(tmp_192_18_cast_fu_45105_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_1_fu_44082_p3() {
    p_reg2mem416_0_i_i_1_fu_44082_p3 = (!tmp_4697_fu_44078_p2.read()[0].is_01())? sc_lv<59>(): ((tmp_4697_fu_44078_p2.read()[0].to_bool())? tmp_256_fu_44071_p3.read(): ap_const_lv59_600000000000000);
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_20_fu_45161_p2() {
    p_reg2mem416_0_i_i_20_fu_45161_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_19_reg_79775.read().is_01() || !tmp_192_19_cast_fu_45158_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_19_reg_79775.read()) + sc_biguint<62>(tmp_192_19_cast_fu_45158_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_21_fu_45214_p2() {
    p_reg2mem416_0_i_i_21_fu_45214_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_20_reg_79792.read().is_01() || !tmp_192_20_cast_fu_45211_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_20_reg_79792.read()) + sc_biguint<62>(tmp_192_20_cast_fu_45211_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_22_fu_45267_p2() {
    p_reg2mem416_0_i_i_22_fu_45267_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_21_reg_79809.read().is_01() || !tmp_192_21_cast_fu_45264_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_21_reg_79809.read()) + sc_biguint<62>(tmp_192_21_cast_fu_45264_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_23_fu_45320_p2() {
    p_reg2mem416_0_i_i_23_fu_45320_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_22_reg_79826.read().is_01() || !tmp_192_22_cast_fu_45317_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_22_reg_79826.read()) + sc_biguint<62>(tmp_192_22_cast_fu_45317_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_24_fu_45373_p2() {
    p_reg2mem416_0_i_i_24_fu_45373_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_23_reg_79843.read().is_01() || !tmp_192_23_cast_fu_45370_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_23_reg_79843.read()) + sc_biguint<62>(tmp_192_23_cast_fu_45370_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_25_fu_45426_p2() {
    p_reg2mem416_0_i_i_25_fu_45426_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_24_reg_79860.read().is_01() || !tmp_192_24_cast_fu_45423_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_24_reg_79860.read()) + sc_biguint<62>(tmp_192_24_cast_fu_45423_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_26_fu_45479_p2() {
    p_reg2mem416_0_i_i_26_fu_45479_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_25_reg_79877.read().is_01() || !tmp_192_25_cast_fu_45476_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_25_reg_79877.read()) + sc_biguint<62>(tmp_192_25_cast_fu_45476_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_27_fu_45532_p2() {
    p_reg2mem416_0_i_i_27_fu_45532_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_26_reg_79894.read().is_01() || !tmp_192_26_cast_fu_45529_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_26_reg_79894.read()) + sc_biguint<62>(tmp_192_26_cast_fu_45529_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_28_fu_45585_p2() {
    p_reg2mem416_0_i_i_28_fu_45585_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_27_reg_79911.read().is_01() || !tmp_192_27_cast_fu_45582_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_27_reg_79911.read()) + sc_biguint<62>(tmp_192_27_cast_fu_45582_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_29_fu_45638_p2() {
    p_reg2mem416_0_i_i_29_fu_45638_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_28_reg_79928.read().is_01() || !tmp_192_28_cast_fu_45635_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_28_reg_79928.read()) + sc_biguint<62>(tmp_192_28_cast_fu_45635_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_2_fu_44152_p2() {
    p_reg2mem416_0_i_i_2_fu_44152_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_fu_44105_p1.read().is_01() || !tmp_192_2_cast_fu_44148_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_fu_44105_p1.read()) + sc_biguint<62>(tmp_192_2_cast_fu_44148_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_30_fu_45691_p2() {
    p_reg2mem416_0_i_i_30_fu_45691_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_29_reg_79945.read().is_01() || !tmp_192_29_cast_fu_45688_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_29_reg_79945.read()) + sc_biguint<62>(tmp_192_29_cast_fu_45688_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_31_fu_45744_p2() {
    p_reg2mem416_0_i_i_31_fu_45744_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_30_reg_79962.read().is_01() || !tmp_192_30_cast_fu_45741_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_30_reg_79962.read()) + sc_biguint<62>(tmp_192_30_cast_fu_45741_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_32_fu_45797_p2() {
    p_reg2mem416_0_i_i_32_fu_45797_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_31_reg_79979.read().is_01() || !tmp_192_31_cast_fu_45794_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_31_reg_79979.read()) + sc_biguint<62>(tmp_192_31_cast_fu_45794_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_33_fu_45850_p2() {
    p_reg2mem416_0_i_i_33_fu_45850_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_32_reg_79996.read().is_01() || !tmp_192_32_cast_fu_45847_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_32_reg_79996.read()) + sc_biguint<62>(tmp_192_32_cast_fu_45847_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_34_fu_45903_p2() {
    p_reg2mem416_0_i_i_34_fu_45903_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_33_reg_80013.read().is_01() || !tmp_192_33_cast_fu_45900_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_33_reg_80013.read()) + sc_biguint<62>(tmp_192_33_cast_fu_45900_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_35_fu_45956_p2() {
    p_reg2mem416_0_i_i_35_fu_45956_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_34_reg_80030.read().is_01() || !tmp_192_34_cast_fu_45953_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_34_reg_80030.read()) + sc_biguint<62>(tmp_192_34_cast_fu_45953_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_36_fu_46009_p2() {
    p_reg2mem416_0_i_i_36_fu_46009_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_35_reg_80047.read().is_01() || !tmp_192_35_cast_fu_46006_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_35_reg_80047.read()) + sc_biguint<62>(tmp_192_35_cast_fu_46006_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_37_fu_46062_p2() {
    p_reg2mem416_0_i_i_37_fu_46062_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_36_reg_80064.read().is_01() || !tmp_192_36_cast_fu_46059_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_36_reg_80064.read()) + sc_biguint<62>(tmp_192_36_cast_fu_46059_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_38_fu_46115_p2() {
    p_reg2mem416_0_i_i_38_fu_46115_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_37_reg_80081.read().is_01() || !tmp_192_37_cast_fu_46112_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_37_reg_80081.read()) + sc_biguint<62>(tmp_192_37_cast_fu_46112_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_39_fu_46168_p2() {
    p_reg2mem416_0_i_i_39_fu_46168_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_38_reg_80098.read().is_01() || !tmp_192_38_cast_fu_46165_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_38_reg_80098.read()) + sc_biguint<62>(tmp_192_38_cast_fu_46165_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_3_fu_44205_p2() {
    p_reg2mem416_0_i_i_3_fu_44205_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_2_fu_44165_p3.read().is_01() || !tmp_192_3_cast_fu_44201_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_2_fu_44165_p3.read()) + sc_biguint<62>(tmp_192_3_cast_fu_44201_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_40_fu_46221_p2() {
    p_reg2mem416_0_i_i_40_fu_46221_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_39_reg_80115.read().is_01() || !tmp_192_39_cast_fu_46218_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_39_reg_80115.read()) + sc_biguint<62>(tmp_192_39_cast_fu_46218_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_41_fu_46274_p2() {
    p_reg2mem416_0_i_i_41_fu_46274_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_40_reg_80132.read().is_01() || !tmp_192_40_cast_fu_46271_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_40_reg_80132.read()) + sc_biguint<62>(tmp_192_40_cast_fu_46271_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_42_fu_46327_p2() {
    p_reg2mem416_0_i_i_42_fu_46327_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_41_reg_80149.read().is_01() || !tmp_192_41_cast_fu_46324_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_41_reg_80149.read()) + sc_biguint<62>(tmp_192_41_cast_fu_46324_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_43_fu_46376_p2() {
    p_reg2mem416_0_i_i_43_fu_46376_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_42_reg_80166.read().is_01() || !tmp_192_42_cast_fu_46373_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_42_reg_80166.read()) + sc_biguint<62>(tmp_192_42_cast_fu_46373_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_44_fu_46428_p2() {
    p_reg2mem416_0_i_i_44_fu_46428_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_43_reg_80193.read().is_01() || !tmp_192_43_cast_fu_46425_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_43_reg_80193.read()) + sc_biguint<62>(tmp_192_43_cast_fu_46425_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_4_fu_44258_p2() {
    p_reg2mem416_0_i_i_4_fu_44258_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_3_fu_44218_p3.read().is_01() || !tmp_192_4_cast_fu_44254_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_3_fu_44218_p3.read()) + sc_biguint<62>(tmp_192_4_cast_fu_44254_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_5_fu_44313_p2() {
    p_reg2mem416_0_i_i_5_fu_44313_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_4_reg_79503.read().is_01() || !tmp_192_5_cast_fu_44310_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_4_reg_79503.read()) + sc_biguint<62>(tmp_192_5_cast_fu_44310_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_6_fu_44366_p2() {
    p_reg2mem416_0_i_i_6_fu_44366_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_5_reg_79520.read().is_01() || !tmp_192_6_cast_fu_44363_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_5_reg_79520.read()) + sc_biguint<62>(tmp_192_6_cast_fu_44363_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_7_fu_44419_p2() {
    p_reg2mem416_0_i_i_7_fu_44419_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_6_reg_79537.read().is_01() || !tmp_192_7_cast_fu_44416_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_6_reg_79537.read()) + sc_biguint<62>(tmp_192_7_cast_fu_44416_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_8_fu_44472_p2() {
    p_reg2mem416_0_i_i_8_fu_44472_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_7_reg_79554.read().is_01() || !tmp_192_8_cast_fu_44469_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_7_reg_79554.read()) + sc_biguint<62>(tmp_192_8_cast_fu_44469_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_9_fu_44525_p2() {
    p_reg2mem416_0_i_i_9_fu_44525_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_8_reg_79571.read().is_01() || !tmp_192_9_cast_fu_44522_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_8_reg_79571.read()) + sc_biguint<62>(tmp_192_9_cast_fu_44522_p1.read()));
}

void krnl_sobel::thread_p_reg2mem416_0_i_i_s_fu_44578_p2() {
    p_reg2mem416_0_i_i_s_fu_44578_p2 = (!y_i16_i_i_i_1_reg2mem679_0_i_i_9_reg_79588.read().is_01() || !tmp_192_cast_fu_44575_p1.read().is_01())? sc_lv<62>(): (sc_biguint<62>(y_i16_i_i_i_1_reg2mem679_0_i_i_9_reg_79588.read()) + sc_biguint<62>(tmp_192_cast_fu_44575_p1.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_10_fu_29736_p2() {
    p_reg2mem455_0_i_i_10_fu_29736_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_46_reg_5121.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_46_reg_5121.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_11_fu_30140_p2() {
    p_reg2mem455_0_i_i_11_fu_30140_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_10_reg_5330.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_10_reg_5330.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_12_fu_30544_p2() {
    p_reg2mem455_0_i_i_12_fu_30544_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_11_reg_5539.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_11_reg_5539.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_13_fu_30949_p2() {
    p_reg2mem455_0_i_i_13_fu_30949_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_12_reg_5748.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_12_reg_5748.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_14_fu_31354_p2() {
    p_reg2mem455_0_i_i_14_fu_31354_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_13_reg_5957.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_13_reg_5957.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_15_fu_31759_p2() {
    p_reg2mem455_0_i_i_15_fu_31759_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_14_reg_6166.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_14_reg_6166.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_16_fu_32163_p2() {
    p_reg2mem455_0_i_i_16_fu_32163_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_15_reg_6375.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_15_reg_6375.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_17_fu_32567_p2() {
    p_reg2mem455_0_i_i_17_fu_32567_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_16_reg_6584.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_16_reg_6584.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_18_fu_32972_p2() {
    p_reg2mem455_0_i_i_18_fu_32972_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_17_reg_6793.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_17_reg_6793.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_19_fu_33376_p2() {
    p_reg2mem455_0_i_i_19_fu_33376_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_18_reg_7002.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_18_reg_7002.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_1_fu_25678_p2() {
    p_reg2mem455_0_i_i_1_fu_25678_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_reg_3029.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_reg_3029.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_20_fu_33780_p2() {
    p_reg2mem455_0_i_i_20_fu_33780_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_19_reg_7211.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_19_reg_7211.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_21_fu_34184_p2() {
    p_reg2mem455_0_i_i_21_fu_34184_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_20_reg_7420.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_20_reg_7420.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_22_fu_34589_p2() {
    p_reg2mem455_0_i_i_22_fu_34589_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_21_reg_7629.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_21_reg_7629.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_23_fu_34993_p2() {
    p_reg2mem455_0_i_i_23_fu_34993_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_22_reg_7838.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_22_reg_7838.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_24_fu_35397_p2() {
    p_reg2mem455_0_i_i_24_fu_35397_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_23_reg_8047.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_23_reg_8047.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_25_fu_35801_p2() {
    p_reg2mem455_0_i_i_25_fu_35801_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_24_reg_8256.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_24_reg_8256.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_26_fu_36206_p2() {
    p_reg2mem455_0_i_i_26_fu_36206_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_25_reg_8465.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_25_reg_8465.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_27_fu_36610_p2() {
    p_reg2mem455_0_i_i_27_fu_36610_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_26_reg_8674.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_26_reg_8674.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_28_fu_37014_p2() {
    p_reg2mem455_0_i_i_28_fu_37014_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_27_reg_8883.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_27_reg_8883.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_29_fu_37418_p2() {
    p_reg2mem455_0_i_i_29_fu_37418_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_28_reg_9092.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_28_reg_9092.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_2_fu_26087_p2() {
    p_reg2mem455_0_i_i_2_fu_26087_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_1_reg_3240.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_1_reg_3240.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_30_fu_37822_p2() {
    p_reg2mem455_0_i_i_30_fu_37822_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_29_reg_9301.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_29_reg_9301.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_31_fu_38226_p2() {
    p_reg2mem455_0_i_i_31_fu_38226_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_30_reg_9510.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_30_reg_9510.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_32_fu_38630_p2() {
    p_reg2mem455_0_i_i_32_fu_38630_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_31_reg_9719.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_31_reg_9719.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_33_fu_39035_p2() {
    p_reg2mem455_0_i_i_33_fu_39035_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_32_reg_9928.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_32_reg_9928.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_34_fu_39439_p2() {
    p_reg2mem455_0_i_i_34_fu_39439_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_33_reg_10137.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_33_reg_10137.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_35_fu_39843_p2() {
    p_reg2mem455_0_i_i_35_fu_39843_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_34_reg_10346.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_34_reg_10346.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_36_fu_40247_p2() {
    p_reg2mem455_0_i_i_36_fu_40247_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_35_reg_10555.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_35_reg_10555.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_37_fu_40651_p2() {
    p_reg2mem455_0_i_i_37_fu_40651_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_36_reg_10764.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_36_reg_10764.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_38_fu_41056_p2() {
    p_reg2mem455_0_i_i_38_fu_41056_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_37_reg_10973.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_37_reg_10973.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_39_fu_41460_p2() {
    p_reg2mem455_0_i_i_39_fu_41460_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_38_reg_11182.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_38_reg_11182.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_3_fu_26503_p2() {
    p_reg2mem455_0_i_i_3_fu_26503_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_2_reg_3450.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_2_reg_3450.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_40_fu_41865_p2() {
    p_reg2mem455_0_i_i_40_fu_41865_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_39_reg_11391.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_39_reg_11391.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_41_fu_42269_p2() {
    p_reg2mem455_0_i_i_41_fu_42269_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_40_reg_11600.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_40_reg_11600.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_42_fu_42674_p2() {
    p_reg2mem455_0_i_i_42_fu_42674_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_41_reg_11809.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_41_reg_11809.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_43_fu_43079_p2() {
    p_reg2mem455_0_i_i_43_fu_43079_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_42_reg_12018.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_42_reg_12018.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_44_fu_43484_p2() {
    p_reg2mem455_0_i_i_44_fu_43484_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_43_reg_12227.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_43_reg_12227.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_45_fu_43877_p2() {
    p_reg2mem455_0_i_i_45_fu_43877_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_44_reg_12435.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_44_reg_12435.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_4_fu_26907_p2() {
    p_reg2mem455_0_i_i_4_fu_26907_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_3_reg_3658.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_3_reg_3658.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_5_fu_27311_p2() {
    p_reg2mem455_0_i_i_5_fu_27311_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_4_reg_3867.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_4_reg_3867.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_6_fu_27715_p2() {
    p_reg2mem455_0_i_i_6_fu_27715_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_5_reg_4076.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_5_reg_4076.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_7_fu_28119_p2() {
    p_reg2mem455_0_i_i_7_fu_28119_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_6_reg_4285.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_6_reg_4285.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_8_fu_28523_p2() {
    p_reg2mem455_0_i_i_8_fu_28523_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_7_reg_4494.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_7_reg_4494.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_9_fu_28928_p2() {
    p_reg2mem455_0_i_i_9_fu_28928_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_8_reg_4703.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_8_reg_4703.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem455_0_i_i_s_fu_29332_p2() {
    p_reg2mem455_0_i_i_s_fu_29332_p2 = (!y_i17_i_i_i_1_reg2mem695_0_i_i_9_reg_4912.read().is_01() || !reg_23102.read().is_01())? sc_lv<64>(): (sc_biguint<64>(y_i17_i_i_i_1_reg2mem695_0_i_i_9_reg_4912.read()) - sc_biguint<64>(reg_23102.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_10_fu_29730_p2() {
    p_reg2mem457_0_i_i_10_fu_29730_p2 = (!p_164_reg2mem697_0_i_i_s_reg_5110.read().is_01() || !tmp_207_10_fu_29725_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_s_reg_5110.read()) + sc_biguint<64>(tmp_207_10_fu_29725_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_11_fu_30134_p2() {
    p_reg2mem457_0_i_i_11_fu_30134_p2 = (!p_164_reg2mem697_0_i_i_10_reg_5319.read().is_01() || !tmp_207_11_fu_30129_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_10_reg_5319.read()) + sc_biguint<64>(tmp_207_11_fu_30129_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_12_fu_30538_p2() {
    p_reg2mem457_0_i_i_12_fu_30538_p2 = (!p_164_reg2mem697_0_i_i_11_reg_5528.read().is_01() || !tmp_207_12_fu_30533_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_11_reg_5528.read()) + sc_biguint<64>(tmp_207_12_fu_30533_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_13_fu_30943_p2() {
    p_reg2mem457_0_i_i_13_fu_30943_p2 = (!p_164_reg2mem697_0_i_i_12_reg_5737.read().is_01() || !tmp_207_13_fu_30937_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_12_reg_5737.read()) + sc_biguint<64>(tmp_207_13_fu_30937_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_14_fu_31348_p2() {
    p_reg2mem457_0_i_i_14_fu_31348_p2 = (!p_164_reg2mem697_0_i_i_13_reg_5946.read().is_01() || !tmp_207_14_fu_31342_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_13_reg_5946.read()) + sc_biguint<64>(tmp_207_14_fu_31342_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_15_fu_31753_p2() {
    p_reg2mem457_0_i_i_15_fu_31753_p2 = (!p_164_reg2mem697_0_i_i_14_reg_6155.read().is_01() || !tmp_207_15_fu_31747_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_14_reg_6155.read()) + sc_biguint<64>(tmp_207_15_fu_31747_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_16_fu_32157_p2() {
    p_reg2mem457_0_i_i_16_fu_32157_p2 = (!p_164_reg2mem697_0_i_i_15_reg_6364.read().is_01() || !tmp_207_16_fu_32152_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_15_reg_6364.read()) + sc_biguint<64>(tmp_207_16_fu_32152_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_17_fu_32561_p2() {
    p_reg2mem457_0_i_i_17_fu_32561_p2 = (!p_164_reg2mem697_0_i_i_16_reg_6573.read().is_01() || !tmp_207_17_fu_32556_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_16_reg_6573.read()) + sc_biguint<64>(tmp_207_17_fu_32556_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_18_fu_32966_p2() {
    p_reg2mem457_0_i_i_18_fu_32966_p2 = (!p_164_reg2mem697_0_i_i_17_reg_6782.read().is_01() || !tmp_207_18_fu_32960_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_17_reg_6782.read()) + sc_biguint<64>(tmp_207_18_fu_32960_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_19_fu_33370_p2() {
    p_reg2mem457_0_i_i_19_fu_33370_p2 = (!p_164_reg2mem697_0_i_i_18_reg_6991.read().is_01() || !tmp_207_19_fu_33365_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_18_reg_6991.read()) + sc_biguint<64>(tmp_207_19_fu_33365_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_1_fu_25672_p2() {
    p_reg2mem457_0_i_i_1_fu_25672_p2 = (!p_164_reg2mem697_0_i_i_reg_3019.read().is_01() || !tmp_207_1_fu_25666_p2.read().is_01())? sc_lv<63>(): (sc_biguint<63>(p_164_reg2mem697_0_i_i_reg_3019.read()) + sc_biguint<63>(tmp_207_1_fu_25666_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_20_fu_33774_p2() {
    p_reg2mem457_0_i_i_20_fu_33774_p2 = (!p_164_reg2mem697_0_i_i_19_reg_7200.read().is_01() || !tmp_207_20_fu_33769_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_19_reg_7200.read()) + sc_biguint<64>(tmp_207_20_fu_33769_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_21_fu_34178_p2() {
    p_reg2mem457_0_i_i_21_fu_34178_p2 = (!p_164_reg2mem697_0_i_i_20_reg_7409.read().is_01() || !tmp_207_21_fu_34173_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_20_reg_7409.read()) + sc_biguint<64>(tmp_207_21_fu_34173_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_22_fu_34583_p2() {
    p_reg2mem457_0_i_i_22_fu_34583_p2 = (!p_164_reg2mem697_0_i_i_21_reg_7618.read().is_01() || !tmp_207_22_fu_34577_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_21_reg_7618.read()) + sc_biguint<64>(tmp_207_22_fu_34577_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_23_fu_34987_p2() {
    p_reg2mem457_0_i_i_23_fu_34987_p2 = (!p_164_reg2mem697_0_i_i_22_reg_7827.read().is_01() || !tmp_207_23_fu_34982_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_22_reg_7827.read()) + sc_biguint<64>(tmp_207_23_fu_34982_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_24_fu_35391_p2() {
    p_reg2mem457_0_i_i_24_fu_35391_p2 = (!p_164_reg2mem697_0_i_i_23_reg_8036.read().is_01() || !tmp_207_24_fu_35386_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_23_reg_8036.read()) + sc_biguint<64>(tmp_207_24_fu_35386_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_25_fu_35795_p2() {
    p_reg2mem457_0_i_i_25_fu_35795_p2 = (!p_164_reg2mem697_0_i_i_24_reg_8245.read().is_01() || !tmp_207_25_fu_35790_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_24_reg_8245.read()) + sc_biguint<64>(tmp_207_25_fu_35790_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_26_fu_36200_p2() {
    p_reg2mem457_0_i_i_26_fu_36200_p2 = (!p_164_reg2mem697_0_i_i_25_reg_8454.read().is_01() || !tmp_207_26_fu_36194_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_25_reg_8454.read()) + sc_biguint<64>(tmp_207_26_fu_36194_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_27_fu_36604_p2() {
    p_reg2mem457_0_i_i_27_fu_36604_p2 = (!p_164_reg2mem697_0_i_i_26_reg_8663.read().is_01() || !tmp_207_27_fu_36599_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_26_reg_8663.read()) + sc_biguint<64>(tmp_207_27_fu_36599_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_28_fu_37008_p2() {
    p_reg2mem457_0_i_i_28_fu_37008_p2 = (!p_164_reg2mem697_0_i_i_27_reg_8872.read().is_01() || !tmp_207_28_fu_37003_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_27_reg_8872.read()) + sc_biguint<64>(tmp_207_28_fu_37003_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_29_fu_37412_p2() {
    p_reg2mem457_0_i_i_29_fu_37412_p2 = (!p_164_reg2mem697_0_i_i_28_reg_9081.read().is_01() || !tmp_207_29_fu_37407_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_28_reg_9081.read()) + sc_biguint<64>(tmp_207_29_fu_37407_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_2_fu_26081_p2() {
    p_reg2mem457_0_i_i_2_fu_26081_p2 = (!p_164_reg2mem697_0_i_i_1_reg_3229.read().is_01() || !tmp_207_2_fu_26075_p2.read().is_01())? sc_lv<63>(): (sc_biguint<63>(p_164_reg2mem697_0_i_i_1_reg_3229.read()) + sc_biguint<63>(tmp_207_2_fu_26075_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_30_fu_37816_p2() {
    p_reg2mem457_0_i_i_30_fu_37816_p2 = (!p_164_reg2mem697_0_i_i_29_reg_9290.read().is_01() || !tmp_207_30_fu_37811_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_29_reg_9290.read()) + sc_biguint<64>(tmp_207_30_fu_37811_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_31_fu_38220_p2() {
    p_reg2mem457_0_i_i_31_fu_38220_p2 = (!p_164_reg2mem697_0_i_i_30_reg_9499.read().is_01() || !tmp_207_31_fu_38215_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_30_reg_9499.read()) + sc_biguint<64>(tmp_207_31_fu_38215_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_32_fu_38624_p2() {
    p_reg2mem457_0_i_i_32_fu_38624_p2 = (!p_164_reg2mem697_0_i_i_31_reg_9708.read().is_01() || !tmp_207_32_fu_38619_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_31_reg_9708.read()) + sc_biguint<64>(tmp_207_32_fu_38619_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_33_fu_39029_p2() {
    p_reg2mem457_0_i_i_33_fu_39029_p2 = (!p_164_reg2mem697_0_i_i_32_reg_9917.read().is_01() || !tmp_207_33_fu_39023_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_32_reg_9917.read()) + sc_biguint<64>(tmp_207_33_fu_39023_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_34_fu_39433_p2() {
    p_reg2mem457_0_i_i_34_fu_39433_p2 = (!p_164_reg2mem697_0_i_i_33_reg_10126.read().is_01() || !tmp_207_34_fu_39428_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_33_reg_10126.read()) + sc_biguint<64>(tmp_207_34_fu_39428_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_35_fu_39837_p2() {
    p_reg2mem457_0_i_i_35_fu_39837_p2 = (!p_164_reg2mem697_0_i_i_34_reg_10335.read().is_01() || !tmp_207_35_fu_39832_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_34_reg_10335.read()) + sc_biguint<64>(tmp_207_35_fu_39832_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_36_fu_40241_p2() {
    p_reg2mem457_0_i_i_36_fu_40241_p2 = (!p_164_reg2mem697_0_i_i_35_reg_10544.read().is_01() || !tmp_207_36_fu_40236_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_35_reg_10544.read()) + sc_biguint<64>(tmp_207_36_fu_40236_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_37_fu_40645_p2() {
    p_reg2mem457_0_i_i_37_fu_40645_p2 = (!p_164_reg2mem697_0_i_i_36_reg_10753.read().is_01() || !tmp_207_37_fu_40640_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_36_reg_10753.read()) + sc_biguint<64>(tmp_207_37_fu_40640_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_38_fu_41050_p2() {
    p_reg2mem457_0_i_i_38_fu_41050_p2 = (!p_164_reg2mem697_0_i_i_37_reg_10962.read().is_01() || !tmp_207_38_fu_41044_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_37_reg_10962.read()) + sc_biguint<64>(tmp_207_38_fu_41044_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_39_fu_41454_p2() {
    p_reg2mem457_0_i_i_39_fu_41454_p2 = (!p_164_reg2mem697_0_i_i_38_reg_11171.read().is_01() || !tmp_207_39_fu_41449_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_38_reg_11171.read()) + sc_biguint<64>(tmp_207_39_fu_41449_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_3_fu_26498_p2() {
    p_reg2mem457_0_i_i_3_fu_26498_p2 = (!tmp_207_3_cast_fu_26494_p1.read().is_01() || !p_164_reg2mem697_0_i_i_2_cast_reg_72297.read().is_01())? sc_lv<64>(): (sc_biguint<64>(tmp_207_3_cast_fu_26494_p1.read()) + sc_biguint<64>(p_164_reg2mem697_0_i_i_2_cast_reg_72297.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_40_fu_41859_p2() {
    p_reg2mem457_0_i_i_40_fu_41859_p2 = (!p_164_reg2mem697_0_i_i_39_reg_11380.read().is_01() || !tmp_207_40_fu_41853_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_39_reg_11380.read()) + sc_biguint<64>(tmp_207_40_fu_41853_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_41_fu_42263_p2() {
    p_reg2mem457_0_i_i_41_fu_42263_p2 = (!p_164_reg2mem697_0_i_i_40_reg_11589.read().is_01() || !tmp_207_41_fu_42258_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_40_reg_11589.read()) + sc_biguint<64>(tmp_207_41_fu_42258_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_42_fu_42668_p2() {
    p_reg2mem457_0_i_i_42_fu_42668_p2 = (!p_164_reg2mem697_0_i_i_41_reg_11798.read().is_01() || !tmp_207_42_fu_42662_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_41_reg_11798.read()) + sc_biguint<64>(tmp_207_42_fu_42662_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_43_fu_43073_p2() {
    p_reg2mem457_0_i_i_43_fu_43073_p2 = (!p_164_reg2mem697_0_i_i_42_reg_12007.read().is_01() || !tmp_207_43_fu_43067_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_42_reg_12007.read()) + sc_biguint<64>(tmp_207_43_fu_43067_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_44_fu_43478_p2() {
    p_reg2mem457_0_i_i_44_fu_43478_p2 = (!p_164_reg2mem697_0_i_i_43_reg_12216.read().is_01() || !tmp_207_44_fu_43472_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_43_reg_12216.read()) + sc_biguint<64>(tmp_207_44_fu_43472_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_4_fu_26901_p2() {
    p_reg2mem457_0_i_i_4_fu_26901_p2 = (!p_164_reg2mem697_0_i_i_3_reg_3648.read().is_01() || !tmp_207_4_fu_26896_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_3_reg_3648.read()) + sc_biguint<64>(tmp_207_4_fu_26896_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_5_fu_27305_p2() {
    p_reg2mem457_0_i_i_5_fu_27305_p2 = (!p_164_reg2mem697_0_i_i_4_reg_3856.read().is_01() || !tmp_207_5_fu_27300_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_4_reg_3856.read()) + sc_biguint<64>(tmp_207_5_fu_27300_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_6_fu_27709_p2() {
    p_reg2mem457_0_i_i_6_fu_27709_p2 = (!p_164_reg2mem697_0_i_i_5_reg_4065.read().is_01() || !tmp_207_6_fu_27704_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_5_reg_4065.read()) + sc_biguint<64>(tmp_207_6_fu_27704_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_7_fu_28113_p2() {
    p_reg2mem457_0_i_i_7_fu_28113_p2 = (!p_164_reg2mem697_0_i_i_6_reg_4274.read().is_01() || !tmp_207_7_fu_28108_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_6_reg_4274.read()) + sc_biguint<64>(tmp_207_7_fu_28108_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_8_fu_28517_p2() {
    p_reg2mem457_0_i_i_8_fu_28517_p2 = (!p_164_reg2mem697_0_i_i_7_reg_4483.read().is_01() || !tmp_207_8_fu_28512_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_7_reg_4483.read()) + sc_biguint<64>(tmp_207_8_fu_28512_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_9_fu_28922_p2() {
    p_reg2mem457_0_i_i_9_fu_28922_p2 = (!p_164_reg2mem697_0_i_i_8_reg_4692.read().is_01() || !tmp_207_9_fu_28916_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_8_reg_4692.read()) + sc_biguint<64>(tmp_207_9_fu_28916_p2.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_fu_25270_p2() {
    p_reg2mem457_0_i_i_fu_25270_p2 = (!p_reg2mem473_0_i_i_cast_reg_71888.read().is_01() || !tmp_527_cast_fu_25266_p1.read().is_01())? sc_lv<63>(): (sc_biguint<63>(p_reg2mem473_0_i_i_cast_reg_71888.read()) + sc_biguint<63>(tmp_527_cast_fu_25266_p1.read()));
}

void krnl_sobel::thread_p_reg2mem457_0_i_i_s_fu_29326_p2() {
    p_reg2mem457_0_i_i_s_fu_29326_p2 = (!p_164_reg2mem697_0_i_i_9_reg_4901.read().is_01() || !tmp_207_s_fu_29321_p2.read().is_01())? sc_lv<64>(): (sc_biguint<64>(p_164_reg2mem697_0_i_i_9_reg_4901.read()) + sc_biguint<64>(tmp_207_s_fu_29321_p2.read()));
}

void krnl_sobel::thread_p_reg2mem473_0_i_i_cast2_fu_25059_p3() {
    p_reg2mem473_0_i_i_cast2_fu_25059_p3 = esl_concat<1,38>(tmp_250_fu_25056_p1.read(), ap_const_lv38_0);
}

void krnl_sobel::thread_p_reg2mem473_0_i_i_cast_fu_25067_p1() {
    p_reg2mem473_0_i_i_cast_fu_25067_p1 = esl_zext<63,62>(p_reg2mem473_0_i_i_fu_25049_p3.read());
}

void krnl_sobel::thread_p_reg2mem473_0_i_i_fu_25049_p3() {
    p_reg2mem473_0_i_i_fu_25049_p3 = esl_concat<24,38>(p_068_0_reg2mem_0_i_i_reg_71845.read(), ap_const_lv38_0);
}

void krnl_sobel::thread_p_reg2mem477_0_i_i_fu_25027_p3() {
    p_reg2mem477_0_i_i_fu_25027_p3 = esl_concat<1,23>(ap_const_lv1_1, tmp_230_reg_71789.read());
}

void krnl_sobel::thread_p_reg2mem498_0_i_i_1_cast_fu_24706_p1() {
    p_reg2mem498_0_i_i_1_cast_fu_24706_p1 = esl_zext<11,10>(p_reg2mem498_0_i_i_1_fu_24701_p2.read());
}

void krnl_sobel::thread_p_reg2mem498_0_i_i_1_fu_24701_p2() {
    p_reg2mem498_0_i_i_1_fu_24701_p2 = (!tmp138_cast_fu_24697_p1.read().is_01() || !tmp_150_cast_reg_71608.read().is_01())? sc_lv<10>(): (sc_biguint<10>(tmp138_cast_fu_24697_p1.read()) + sc_biguint<10>(tmp_150_cast_reg_71608.read()));
}

void krnl_sobel::thread_p_reg2mem498_0_i_i_2_cast_fu_24921_p1() {
    p_reg2mem498_0_i_i_2_cast_fu_24921_p1 = esl_sext<16,11>(p_reg2mem498_0_i_i_2_reg_71757.read());
}

void krnl_sobel::thread_p_reg2mem498_0_i_i_2_fu_24912_p2() {
    p_reg2mem498_0_i_i_2_fu_24912_p2 = (!tmp_154_2_fu_24907_p2.read().is_01() || !tmp_143_2_cast_fu_24881_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_154_2_fu_24907_p2.read()) - sc_biguint<11>(tmp_143_2_cast_fu_24881_p1.read()));
}

void krnl_sobel::thread_p_reg2mem500_0_i_i_1_fu_24758_p2() {
    p_reg2mem500_0_i_i_1_fu_24758_p2 = (!tmp_146_1_fu_24753_p2.read().is_01() || !tmp_144_1_cast_fu_24749_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_146_1_fu_24753_p2.read()) + sc_biguint<11>(tmp_144_1_cast_fu_24749_p1.read()));
}

void krnl_sobel::thread_p_reg2mem500_0_i_i_2_cast_fu_24918_p1() {
    p_reg2mem500_0_i_i_2_cast_fu_24918_p1 = esl_sext<16,11>(p_reg2mem500_0_i_i_2_reg_71752.read());
}

void krnl_sobel::thread_p_reg2mem500_0_i_i_2_fu_24889_p2() {
    p_reg2mem500_0_i_i_2_fu_24889_p2 = (!tmp_145_2_fu_24885_p2.read().is_01() || !tmp_143_2_cast_fu_24881_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_145_2_fu_24885_p2.read()) + sc_biguint<11>(tmp_143_2_cast_fu_24881_p1.read()));
}

void krnl_sobel::thread_p_reg2mem500_0_i_i_cast_fu_24639_p1() {
    p_reg2mem500_0_i_i_cast_fu_24639_p1 = esl_sext<11,9>(p_reg2mem500_0_i_i_fu_24634_p2.read());
}

void krnl_sobel::thread_p_reg2mem500_0_i_i_fu_24634_p2() {
    p_reg2mem500_0_i_i_fu_24634_p2 = (!tmp_524_cast_fu_24630_p1.read().is_01() || !tmp_522_cast_reg_71552.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_524_cast_fu_24630_p1.read()) - sc_biguint<9>(tmp_522_cast_reg_71552.read()));
}

void krnl_sobel::thread_p_reg2mem546_0_i_i_fu_23268_p2() {
    p_reg2mem546_0_i_i_fu_23268_p2 = (!y_0_reg2mem737_0_i_i_reg_2608.read().is_01() || !ap_const_lv31_1.is_01())? sc_lv<31>(): (sc_biguint<31>(y_0_reg2mem737_0_i_i_reg_2608.read()) + sc_biguint<31>(ap_const_lv31_1));
}

void krnl_sobel::thread_p_reg2mem567_0_i_i_fu_23240_p2() {
    p_reg2mem567_0_i_i_fu_23240_p2 = (!i_0_reg2mem739_0_i_i_reg_2585.read().is_01() || !ap_const_lv13_1.is_01())? sc_lv<13>(): (sc_biguint<13>(i_0_reg2mem739_0_i_i_reg_2585.read()) + sc_biguint<13>(ap_const_lv13_1));
}

void krnl_sobel::thread_p_reg2mem_0_reg2mem_0_i_i_fu_69976_p2() {
    p_reg2mem_0_reg2mem_0_i_i_fu_69976_p2 = (!e_i10_i_i_i26_3_reg2mem583_0_i_2_reg_22767.read().is_01() || !ap_const_lv32_0.is_01())? sc_lv<1>(): sc_lv<1>(e_i10_i_i_i26_3_reg2mem583_0_i_2_reg_22767.read() == ap_const_lv32_0);
}

void krnl_sobel::thread_p_s_fu_27281_p3() {
    p_s_fu_27281_p3 = (!tmp_916_fu_27273_p3.read()[0].is_01())? sc_lv<6>(): ((tmp_916_fu_27273_p3.read()[0].to_bool())? ap_const_lv6_2F: ap_const_lv6_2E);
}

void krnl_sobel::thread_p_shl1_cast_fu_24737_p1() {
    p_shl1_cast_fu_24737_p1 = esl_zext<11,9>(p_shl1_fu_24729_p3.read());
}

void krnl_sobel::thread_p_shl1_fu_24729_p3() {
    p_shl1_fu_24729_p3 = esl_concat<8,1>(phi_load2_reg_2889.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_p_shl2_cast_fu_48020_p1() {
    p_shl2_cast_fu_48020_p1 = esl_zext<11,9>(p_shl2_fu_48012_p3.read());
}

void krnl_sobel::thread_p_shl2_fu_48012_p3() {
    p_shl2_fu_48012_p3 = esl_concat<8,1>(phi_load7_reg_12958.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_p_shl3_cast_fu_48186_p1() {
    p_shl3_cast_fu_48186_p1 = esl_zext<11,9>(p_shl3_fu_48178_p3.read());
}

void krnl_sobel::thread_p_shl3_fu_48178_p3() {
    p_shl3_fu_48178_p3 = esl_concat<8,1>(phi_load9_reg_12980.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_p_shl_cast_fu_24903_p1() {
    p_shl_cast_fu_24903_p1 = esl_zext<11,9>(p_shl_fu_24895_p3.read());
}

void krnl_sobel::thread_p_shl_fu_24895_p3() {
    p_shl_fu_24895_p3 = esl_concat<8,1>(phi_load4_reg_2911.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_pos_1_address0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1729.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3146.read()))) {
        pos_1_address0 = ap_const_lv6_2E;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_address0 = ap_const_lv6_2C;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()))) {
        pos_1_address0 = ap_const_lv6_2A;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()))) {
        pos_1_address0 = ap_const_lv6_28;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()))) {
        pos_1_address0 = ap_const_lv6_26;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()))) {
        pos_1_address0 = ap_const_lv6_24;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()))) {
        pos_1_address0 = ap_const_lv6_22;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()))) {
        pos_1_address0 = ap_const_lv6_20;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()))) {
        pos_1_address0 = ap_const_lv6_1E;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()))) {
        pos_1_address0 = ap_const_lv6_1C;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()))) {
        pos_1_address0 = ap_const_lv6_1A;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()))) {
        pos_1_address0 = ap_const_lv6_18;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()))) {
        pos_1_address0 = ap_const_lv6_16;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()))) {
        pos_1_address0 = ap_const_lv6_14;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()))) {
        pos_1_address0 = ap_const_lv6_12;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()))) {
        pos_1_address0 = ap_const_lv6_10;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()))) {
        pos_1_address0 = ap_const_lv6_E;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()))) {
        pos_1_address0 = ap_const_lv6_C;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()))) {
        pos_1_address0 = ap_const_lv6_A;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()))) {
        pos_1_address0 = ap_const_lv6_8;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()))) {
        pos_1_address0 = ap_const_lv6_6;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()))) {
        pos_1_address0 = ap_const_lv6_4;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()))) {
        pos_1_address0 = ap_const_lv6_2;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()))) {
        pos_1_address0 = ap_const_lv6_0;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3328.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_44_fu_66764_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3320.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_42_fu_65955_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3312.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_40_fu_65146_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3304.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_38_fu_64338_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3296.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_36_fu_63528_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3288.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_34_fu_62719_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3280.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_32_fu_61910_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3272.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_30_fu_61100_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3264.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_28_fu_60290_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3256.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_26_fu_59480_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3248.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_24_fu_58670_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3240.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_22_fu_57860_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3232.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_20_fu_57050_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3224.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_18_fu_56240_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3216.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_16_fu_55432_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3208.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_14_fu_54623_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3200.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_12_fu_53814_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3192.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_10_fu_53005_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3184.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_9_fu_52197_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3176.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_7_fu_51388_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3168.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_5_fu_50579_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3160.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_3_fu_49762_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3152.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_337_1_fu_48940_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1911.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_44_fu_43467_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1903.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_42_fu_42657_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1895.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_40_fu_41848_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1887.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_38_fu_41039_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1879.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_36_fu_40231_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1871.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_34_fu_39423_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1863.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_32_fu_38614_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1855.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_30_fu_37806_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1847.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_28_fu_36998_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1839.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_26_fu_36189_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1831.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_24_fu_35381_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1823.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_22_fu_34572_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1815.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_20_fu_33764_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1807.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_18_fu_32955_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1799.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_16_fu_32147_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1791.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_14_fu_31337_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1783.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_12_fu_30528_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1775.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_10_fu_29720_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1767.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_9_fu_28911_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1759.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_7_fu_28103_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1751.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_5_fu_27295_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1743.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_3_fu_26479_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1735.read())) {
        pos_1_address0 =  (sc_lv<6>) (tmp_206_1_fu_25657_p1.read());
    } else {
        pos_1_address0 =  (sc_lv<6>) ("XXXXXX");
    }
}

void krnl_sobel::thread_pos_1_address1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_address1 = ap_const_lv6_2D;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()))) {
        pos_1_address1 = ap_const_lv6_2B;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()))) {
        pos_1_address1 = ap_const_lv6_29;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()))) {
        pos_1_address1 = ap_const_lv6_27;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()))) {
        pos_1_address1 = ap_const_lv6_25;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()))) {
        pos_1_address1 = ap_const_lv6_23;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()))) {
        pos_1_address1 = ap_const_lv6_21;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()))) {
        pos_1_address1 = ap_const_lv6_1F;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()))) {
        pos_1_address1 = ap_const_lv6_1D;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()))) {
        pos_1_address1 = ap_const_lv6_1B;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()))) {
        pos_1_address1 = ap_const_lv6_19;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()))) {
        pos_1_address1 = ap_const_lv6_17;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()))) {
        pos_1_address1 = ap_const_lv6_15;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()))) {
        pos_1_address1 = ap_const_lv6_13;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()))) {
        pos_1_address1 = ap_const_lv6_11;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()))) {
        pos_1_address1 = ap_const_lv6_F;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()))) {
        pos_1_address1 = ap_const_lv6_D;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()))) {
        pos_1_address1 = ap_const_lv6_B;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()))) {
        pos_1_address1 = ap_const_lv6_9;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()))) {
        pos_1_address1 = ap_const_lv6_7;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()))) {
        pos_1_address1 = ap_const_lv6_5;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()))) {
        pos_1_address1 = ap_const_lv6_3;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()))) {
        pos_1_address1 = ap_const_lv6_1;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3332.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_339_s_fu_67168_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3324.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_43_fu_66359_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3316.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_41_fu_65550_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3308.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_39_fu_64742_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3300.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_37_fu_63933_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3292.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_35_fu_63124_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3284.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_33_fu_62315_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3276.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_31_fu_61505_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3268.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_29_fu_60695_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3260.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_27_fu_59885_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3252.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_25_fu_59075_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3244.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_23_fu_58265_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3236.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_21_fu_57455_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3228.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_19_fu_56645_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3220.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_17_fu_55836_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3212.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_15_fu_55028_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3204.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_13_fu_54219_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3196.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_11_fu_53409_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3188.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_s_fu_52601_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3180.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_8_fu_51793_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3172.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_6_fu_50983_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3164.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_4_fu_50174_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3156.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_337_2_fu_49349_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3148.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_248_fu_48535_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1915.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_208_s_fu_43872_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1907.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_43_fu_43062_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1899.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_41_fu_42253_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1891.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_39_fu_41444_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1883.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_37_fu_40635_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1875.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_35_fu_39827_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1867.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_33_fu_39018_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1859.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_31_fu_38210_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1851.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_29_fu_37402_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1843.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_27_fu_36594_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1835.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_25_fu_35785_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1827.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_23_fu_34977_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1819.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_21_fu_34168_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1811.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_19_fu_33360_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1803.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_17_fu_32551_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1795.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_15_fu_31742_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1787.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_13_fu_30932_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1779.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_11_fu_30124_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1771.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_s_fu_29316_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1763.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_8_fu_28507_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1755.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_6_fu_27699_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1747.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_4_fu_26891_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1739.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_206_2_fu_26066_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1731.read())) {
        pos_1_address1 =  (sc_lv<6>) (tmp_244_fu_25252_p1.read());
    } else {
        pos_1_address1 =  (sc_lv<6>) ("XXXXXX");
    }
}

void krnl_sobel::thread_pos_1_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1729.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1735.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1743.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1751.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1759.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1767.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1775.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1783.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1791.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1799.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1807.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1815.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1823.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1831.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1839.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1847.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1855.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1863.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1871.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1879.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1887.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1895.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1903.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1911.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3146.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3152.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3160.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3168.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3176.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3184.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3192.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3200.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3208.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3216.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3224.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3232.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3240.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3248.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3256.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3264.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3272.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3280.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3288.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3296.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3304.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3312.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3320.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3328.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_ce0 = ap_const_logic_1;
    } else {
        pos_1_ce0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_pos_1_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1731.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1739.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1747.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1755.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1763.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1771.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1779.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1787.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1795.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1803.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1811.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1819.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1827.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1835.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1843.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1851.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1859.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1867.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1875.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1883.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1891.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1899.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1907.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1915.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3148.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3156.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3164.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3172.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3180.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3188.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3196.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3204.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3212.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3220.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3228.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3236.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3244.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3252.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3260.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3268.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3276.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3284.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3292.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3300.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3308.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3316.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3324.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3332.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_ce1 = ap_const_logic_1;
    } else {
        pos_1_ce1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_pos_1_d0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1729.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3146.read()))) {
        pos_1_d0 = ap_const_lv64_17154;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_d0 = ap_const_lv64_5C552;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()))) {
        pos_1_d0 = ap_const_lv64_171547;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()))) {
        pos_1_d0 = ap_const_lv64_5C551E;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()))) {
        pos_1_d0 = ap_const_lv64_1715476;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()))) {
        pos_1_d0 = ap_const_lv64_5C551D9;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()))) {
        pos_1_d0 = ap_const_lv64_17154765;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()))) {
        pos_1_d0 = ap_const_lv64_5C551D94;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()))) {
        pos_1_d0 = ap_const_lv64_171547650;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()))) {
        pos_1_d0 = ap_const_lv64_5C551D91D;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()))) {
        pos_1_d0 = ap_const_lv64_1715476249;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()))) {
        pos_1_d0 = ap_const_lv64_5C551D6683;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()))) {
        pos_1_d0 = ap_const_lv64_1715473700F;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()))) {
        pos_1_d0 = ap_const_lv64_5C551AB2054;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()))) {
        pos_1_d0 = ap_const_lv64_171544828311;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()))) {
        pos_1_d0 = ap_const_lv64_5C54EF6A3E09;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()))) {
        pos_1_d0 = ap_const_lv64_1715193B17D36;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()))) {
        pos_1_d0 = ap_const_lv64_5C523B0A86FF2;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()))) {
        pos_1_d0 = ap_const_lv64_1712653743F454;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()))) {
        pos_1_d0 = ap_const_lv64_5C2711B5EAB1DD;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()))) {
        pos_1_d0 = ap_const_lv64_16E79685C2D2299;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()))) {
        pos_1_d0 = ap_const_lv64_598FDBEB244C59F;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()))) {
        pos_1_d0 = ap_const_lv64_149A784BCD1B8AFE;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()))) {
        pos_1_d0 = ap_const_lv64_4000000000000000;
    } else {
        pos_1_d0 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void krnl_sobel::thread_pos_1_d1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A9;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA4;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A8F;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA3B;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A8ED;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA3B3;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A8ECA;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA3B29;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A8EC9A;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA3B1DD;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A8EBECC;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA3A70B2;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A8E11ACD;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()))) {
        pos_1_d1 = ap_const_lv64_B8AA2F9EB96;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()))) {
        pos_1_d1 = ap_const_lv64_2E2A833FB72C;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()))) {
        pos_1_d1 = ap_const_lv64_B8A982801725;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()))) {
        pos_1_d1 = ap_const_lv64_2E29D623F4A6C;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()))) {
        pos_1_d1 = ap_const_lv64_B89EB17BCABE2;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()))) {
        pos_1_d1 = ap_const_lv64_2E1F07FE14EACA;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()))) {
        pos_1_d1 = ap_const_lv64_B7F285B778428C;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()))) {
        pos_1_d1 = ap_const_lv64_2D75A6EB1DFB0E6;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()))) {
        pos_1_d1 = ap_const_lv64_AE00D1CFDEB43D0;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()))) {
        pos_1_d1 = ap_const_lv64_2570068E7EF5A1E8;
    } else {
        pos_1_d1 = "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    }
}

void krnl_sobel::thread_pos_1_we0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1729.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3146.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, tmp_138_fu_25044_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, tmp_220_fu_48327_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_we0 = ap_const_logic_1;
    } else {
        pos_1_we0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_pos_1_we1() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1706.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, tmp_138_fu_25044_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1707.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1708.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1709.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1710.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1711.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1712.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1713.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1714.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1715.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1716.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1717.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1718.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1719.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1720.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1721.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1722.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1723.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1724.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1725.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1726.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1727.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1728.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3123.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, tmp_220_fu_48327_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3124.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3125.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3126.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3127.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3128.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3129.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3130.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3131.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3132.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3133.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3134.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3135.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3136.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3137.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3138.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3139.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3140.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3141.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3142.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3143.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3144.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3145.read()))) {
        pos_1_we1 = ap_const_logic_1;
    } else {
        pos_1_we1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_prealign_rd_cnt1_cast_fu_70379_p1() {
    prealign_rd_cnt1_cast_fu_70379_p1 = esl_zext<32,3>(prealign_rd_cnt1_fu_70373_p2.read());
}

void krnl_sobel::thread_prealign_rd_cnt1_fu_70373_p2() {
    prealign_rd_cnt1_fu_70373_p2 = (!ap_const_lv3_4.is_01() || !arg_out_pixels_i_0_mod1_cast_fu_70370_p1.read().is_01())? sc_lv<3>(): (sc_bigint<3>(ap_const_lv3_4) - sc_biguint<3>(arg_out_pixels_i_0_mod1_cast_fu_70370_p1.read()));
}

void krnl_sobel::thread_prealign_rd_cnt_cast_fu_23357_p1() {
    prealign_rd_cnt_cast_fu_23357_p1 = esl_zext<32,3>(prealign_rd_cnt_reg_70850.read());
}

void krnl_sobel::thread_prealign_rd_cnt_fu_23311_p2() {
    prealign_rd_cnt_fu_23311_p2 = (!ap_const_lv3_4.is_01() || !arg_out_pixels_i_0_mod_cast_fu_23307_p1.read().is_01())? sc_lv<3>(): (sc_bigint<3>(ap_const_lv3_4) - sc_biguint<3>(arg_out_pixels_i_0_mod_cast_fu_23307_p1.read()));
}

void krnl_sobel::thread_prealign_wr_cnt1_fu_24145_p2() {
    prealign_wr_cnt1_fu_24145_p2 = (!ap_const_lv3_4.is_01() || !arg_in_pixels_i_0_mod_cast_fu_24141_p1.read().is_01())? sc_lv<3>(): (sc_bigint<3>(ap_const_lv3_4) - sc_biguint<3>(arg_in_pixels_i_0_mod_cast_fu_24141_p1.read()));
}

void krnl_sobel::thread_prealign_wr_cnt2_fu_47458_p2() {
    prealign_wr_cnt2_fu_47458_p2 = (!ap_const_lv3_4.is_01() || !arg_in_pixels_i_0_mod1_cast_fu_47455_p1.read().is_01())? sc_lv<3>(): (sc_bigint<3>(ap_const_lv3_4) - sc_biguint<3>(arg_in_pixels_i_0_mod1_cast_fu_47455_p1.read()));
}

void krnl_sobel::thread_prealign_wr_cnt_fu_23788_p2() {
    prealign_wr_cnt_fu_23788_p2 = (!ap_const_lv3_4.is_01() || !tmp_cast_21_reg_71040.read().is_01())? sc_lv<3>(): (sc_bigint<3>(ap_const_lv3_4) - sc_biguint<3>(tmp_cast_21_reg_71040.read()));
}

void krnl_sobel::thread_predata1_fu_70453_p2() {
    predata1_fu_70453_p2 = (!lower_bound1_cast_fu_70449_p1.read().is_01())? sc_lv<32>(): set_part_fu_70438_p1.read() << (unsigned short)lower_bound1_cast_fu_70449_p1.read().to_uint();
}

void krnl_sobel::thread_predata_fu_23430_p2() {
    predata_fu_23430_p2 = (!lower_bound_cast_fu_23426_p1.read().is_01())? sc_lv<32>(): set_part9_fu_23415_p1.read() << (unsigned short)lower_bound_cast_fu_23426_p1.read().to_uint();
}

void krnl_sobel::thread_r_V_1_fu_70287_p2() {
    r_V_1_fu_70287_p2 = (!tmp_368_fu_70277_p1.read().is_01())? sc_lv<54>(): tmp_365_fu_70267_p1.read() << (unsigned short)tmp_368_fu_70277_p1.read().to_uint();
}

void krnl_sobel::thread_r_V_fu_70281_p2() {
    r_V_fu_70281_p2 = (!sh_assign_1_cast_cast_fu_70274_p1.read().is_01())? sc_lv<24>(): p_Result_s_fu_70260_p3.read() >> (unsigned short)sh_assign_1_cast_cast_fu_70274_p1.read().to_uint();
}

void krnl_sobel::thread_rd_cnt_burst1_cast_fu_23835_p1() {
    rd_cnt_burst1_cast_fu_23835_p1 = esl_zext<31,30>(rd_cnt_burst1_fu_23821_p4.read());
}

void krnl_sobel::thread_rd_cnt_burst1_fu_23821_p4() {
    rd_cnt_burst1_fu_23821_p4 = buffer_cnt_dec1_fu_23816_p2.read().range(31, 2);
}

void krnl_sobel::thread_rd_cnt_burst2_cast_fu_24220_p1() {
    rd_cnt_burst2_cast_fu_24220_p1 = esl_zext<31,30>(rd_cnt_burst2_fu_24206_p4.read());
}

void krnl_sobel::thread_rd_cnt_burst2_fu_24206_p4() {
    rd_cnt_burst2_fu_24206_p4 = buffer_cnt_dec2_fu_24201_p2.read().range(31, 2);
}

void krnl_sobel::thread_rd_cnt_burst3_cast_fu_47506_p1() {
    rd_cnt_burst3_cast_fu_47506_p1 = esl_zext<31,30>(rd_cnt_burst3_fu_47492_p4.read());
}

void krnl_sobel::thread_rd_cnt_burst3_fu_47492_p4() {
    rd_cnt_burst3_fu_47492_p4 = buffer_cnt_dec3_fu_47487_p2.read().range(31, 2);
}

void krnl_sobel::thread_rd_cnt_burst_fu_23279_p4() {
    rd_cnt_burst_fu_23279_p4 = szrow_0_reg2mem_0_i_i_reg_70759.read().range(31, 2);
}

void krnl_sobel::thread_rd_pre_shift1_fu_24235_p2() {
    rd_pre_shift1_fu_24235_p2 = (!tmp_75_cast_fu_24231_p1.read().is_01())? sc_lv<32>(): reg_22986.read() >> (unsigned short)tmp_75_cast_fu_24231_p1.read().to_uint();
}

void krnl_sobel::thread_rd_pre_shift2_fu_47170_p2() {
    rd_pre_shift2_fu_47170_p2 = (!tmp_105_cast_fu_47166_p1.read().is_01())? sc_lv<32>(): reg_22986.read() >> (unsigned short)tmp_105_cast_fu_47166_p1.read().to_uint();
}

void krnl_sobel::thread_rd_pre_shift3_fu_47521_p2() {
    rd_pre_shift3_fu_47521_p2 = (!tmp_181_cast_fu_47517_p1.read().is_01())? sc_lv<32>(): reg_22986.read() >> (unsigned short)tmp_181_cast_fu_47517_p1.read().to_uint();
}

void krnl_sobel::thread_rd_pre_shift_fu_23850_p2() {
    rd_pre_shift_fu_23850_p2 = (!tmp_46_cast_fu_23846_p1.read().is_01())? sc_lv<32>(): reg_22986.read() >> (unsigned short)tmp_46_cast_fu_23846_p1.read().to_uint();
}

void krnl_sobel::thread_read_cnt_dec1_fu_70423_p2() {
    read_cnt_dec1_fu_70423_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !prealign_rd_cnt1_cast_fu_70379_p1.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) - sc_biguint<32>(prealign_rd_cnt1_cast_fu_70379_p1.read()));
}

void krnl_sobel::thread_read_cnt_dec_fu_23445_p2() {
    read_cnt_dec_fu_23445_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !prealign_rd_cnt_cast_reg_70872.read().is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) - sc_biguint<32>(prealign_rd_cnt_cast_reg_70872.read()));
}

void krnl_sobel::thread_resbuf_address0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2.read())) {
        resbuf_address0 =  (sc_lv<12>) (tmp_3_fu_23246_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3836.read())) {
        resbuf_address0 =  (sc_lv<12>) (tmp_238_fu_70627_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter1.read()))) {
        resbuf_address0 =  (sc_lv<12>) (tmp_231_fu_70561_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3566_pp7_stage1.read()))) {
        resbuf_address0 =  (sc_lv<12>) (tmp_228_fu_70547_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3428.read())) {
        resbuf_address0 = ap_const_lv12_2;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state426.read())) {
        resbuf_address0 =  (sc_lv<12>) (tmp_34_fu_23618_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        resbuf_address0 =  (sc_lv<12>) (tmp_27_fu_23542_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state156_pp0_stage1.read()))) {
        resbuf_address0 =  (sc_lv<12>) (tmp_25_fu_23528_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read())) {
        resbuf_address0 = ap_const_lv12_1;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state16.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3427.read()))) {
        resbuf_address0 = ap_const_lv12_0;
    } else {
        resbuf_address0 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_resbuf_address1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3420.read())) {
        resbuf_address1 =  (sc_lv<12>) (tmp_259_1_reg_80822.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3836.read())) {
        resbuf_address1 =  (sc_lv<12>) (tmp_240_fu_70637_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3835.read())) {
        resbuf_address1 =  (sc_lv<12>) (tmp_234_fu_70614_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter1.read()))) {
        resbuf_address1 =  (sc_lv<12>) (tmp_222_fu_70552_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3566_pp7_stage1.read()))) {
        resbuf_address1 =  (sc_lv<12>) (tmp_225_fu_70537_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3428.read())) {
        resbuf_address1 = ap_const_lv12_1;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state426.read())) {
        resbuf_address1 =  (sc_lv<12>) (tmp_32_fu_23608_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state425.read())) {
        resbuf_address1 =  (sc_lv<12>) (tmp_30_fu_23595_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        resbuf_address1 =  (sc_lv<12>) (tmp_21_fu_23533_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state156_pp0_stage1.read()))) {
        resbuf_address1 =  (sc_lv<12>) (tmp_23_fu_23518_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read())) {
        resbuf_address1 = ap_const_lv12_2;
    } else {
        resbuf_address1 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_resbuf_ce0() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read()) && 
          !esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state159_io_blk.read()))) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state426.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3428.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter2.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state3569_io_blk.read()))) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3836.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state16.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3427.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state156_pp0_stage1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3566_pp7_stage1.read())))) {
        resbuf_ce0 = ap_const_logic_1;
    } else {
        resbuf_ce0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_resbuf_ce1() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state17.read()) && 
          !esl_seteq<1,1,1>(ap_const_logic_0, ap_sig_ioackin_gmem_AWREADY.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state155_pp0_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter2.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state159_io_blk.read()))) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state426.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3428.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3565_pp7_stage0.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter2.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state3569_io_blk.read()))) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3836.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state425.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3835.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3420.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state156_pp0_stage1.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp7_iter0.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3566_pp7_stage1.read())))) {
        resbuf_ce1 = ap_const_logic_1;
    } else {
        resbuf_ce1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_resbuf_we0() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond1_fu_23234_p2.read())))) {
        resbuf_we0 = ap_const_logic_1;
    } else {
        resbuf_we0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_resbuf_we1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3420.read()))) {
        resbuf_we1 = ap_const_logic_1;
    } else {
        resbuf_we1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_result_V_fu_70315_p3() {
    result_V_fu_70315_p3 = (!isNeg_reg_89502.read()[0].is_01())? sc_lv<8>(): ((isNeg_reg_89502.read()[0].to_bool())? tmp_503_fu_70301_p1.read(): tmp_504_fu_70305_p4.read());
}

void krnl_sobel::thread_rowbuf0_address0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read())) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_87_fu_47154_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read())) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_81_fu_47144_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()))) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_78_fu_47107_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read()))) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_74_fu_47088_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state836.read())) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_40_fu_23761_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read())) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_29_fu_23751_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_18_fu_23709_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read()))) {
        rowbuf0_address0 =  (sc_lv<12>) (tmp_14_fu_23690_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3097.read())) {
        rowbuf0_address0 =  (sc_lv<12>) (gepindex2069_cast_fu_47947_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1680.read())) {
        rowbuf0_address0 =  (sc_lv<12>) (gepindex1965_cast_fu_24688_p1.read());
    } else {
        rowbuf0_address0 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf0_address1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read())) {
        rowbuf0_address1 =  (sc_lv<12>) (tmp_85_fu_47149_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()))) {
        rowbuf0_address1 =  (sc_lv<12>) (tmp_80_fu_47117_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read()))) {
        rowbuf0_address1 =  (sc_lv<12>) (tmp_76_fu_47097_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read())) {
        rowbuf0_address1 =  (sc_lv<12>) (tmp_38_fu_23756_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        rowbuf0_address1 =  (sc_lv<12>) (tmp_20_fu_23719_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read()))) {
        rowbuf0_address1 =  (sc_lv<12>) (tmp_16_fu_23699_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3099.read())) {
        rowbuf0_address1 =  (sc_lv<12>) (gepindex2095_cast_fu_48071_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3093.read())) {
        rowbuf0_address1 =  (sc_lv<12>) (gepindex2025_cast_fu_47783_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1682.read())) {
        rowbuf0_address1 =  (sc_lv<12>) (gepindex1991_cast_fu_24824_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1676.read())) {
        rowbuf0_address1 =  (sc_lv<12>) (gepindex1929_cast_fu_24534_p1.read());
    } else {
        rowbuf0_address1 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf0_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state836.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1680.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3097.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2248_io_blk.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state696_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2108_blk.read()))))) {
        rowbuf0_ce0 = ap_const_logic_1;
    } else {
        rowbuf0_ce0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf0_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1676.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1682.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3093.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3099.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state696_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2108_blk.read()))))) {
        rowbuf0_ce1 = ap_const_logic_1;
    } else {
        rowbuf0_ce1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf0_d0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read())) {
        rowbuf0_d0 = tmp_141_reg_80386.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read()))) {
        rowbuf0_d0 = tmp_135_reg_80375.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state836.read()))) {
        rowbuf0_d0 = reg_22986.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read())) {
        rowbuf0_d0 = tmp_60_reg_71077.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read())))) {
        rowbuf0_d0 = reg_22966.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read()))) {
        rowbuf0_d0 = tmp_47_reg_71062.read();
    } else {
        rowbuf0_d0 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf0_d1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read()))) {
        rowbuf0_d1 = reg_22986.read().range(15, 8);
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read())))) {
        rowbuf0_d1 = reg_22974.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read())))) {
        rowbuf0_d1 = reg_22958.read();
    } else {
        rowbuf0_d1 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf0_we0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond2_reg_71045.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond11_reg_80358.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state836.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond3_reg_71067.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_71082.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_reg_71086.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state696_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp1_iter1_exitcond2_reg_71045.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2108_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp4_iter1_exitcond11_reg_80358.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2248.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond3_reg_71067.read()) && 
          !esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2248_io_blk.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond12_reg_80391.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond13_reg_80395.read())))) {
        rowbuf0_we0 = ap_const_logic_1;
    } else {
        rowbuf0_we0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf0_we1() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state835.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, grp_fu_22904_p2.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_0, grp_fu_22904_p2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2247.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond2_reg_71045.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state695_pp1_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond11_reg_80358.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2107_pp4_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state696_pp1_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state696_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp1_iter1_exitcond2_reg_71045.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2108_pp4_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp4_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2108_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp4_iter1_exitcond11_reg_80358.read())))) {
        rowbuf0_we1 = ap_const_logic_1;
    } else {
        rowbuf0_we1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf1_address0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_143_fu_47345_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_123_fu_47316_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()))) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_118_fu_47270_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read()))) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_114_fu_47251_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read())) {
        rowbuf1_address0 = ap_const_lv12_1;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_57_fu_24027_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()))) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_54_fu_23977_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read()))) {
        rowbuf1_address0 =  (sc_lv<12>) (tmp_50_fu_23957_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state974.read())) {
        rowbuf1_address0 = ap_const_lv12_2;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read())) {
        rowbuf1_address0 = ap_const_lv12_0;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3099.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (gepindex2100_cast_fu_48097_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3095.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (gepindex2051_cast_fu_47857_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1684.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (gepindex2012_cast_fu_24872_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1680.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (gepindex1960_cast_fu_24678_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1676.read())) {
        rowbuf1_address0 =  (sc_lv<12>) (gepindex1924_cast_fu_24524_p1.read());
    } else {
        rowbuf1_address0 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf1_address1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_140_fu_47330_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()))) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_120_fu_47280_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read()))) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_116_fu_47260_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2385.read())) {
        rowbuf1_address1 = ap_const_lv12_2;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read())) {
        rowbuf1_address1 = ap_const_lv12_0;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1251.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_59_fu_24042_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_55_fu_24013_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()))) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_52_fu_23967_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read()))) {
        rowbuf1_address1 =  (sc_lv<12>) (tmp_48_fu_23948_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read())) {
        rowbuf1_address1 = ap_const_lv12_1;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3101.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (gepindex2121_cast_fu_48145_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3097.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (gepindex2074_cast_fu_47961_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3093.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (gepindex2030_cast_fu_47809_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1682.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (gepindex1986_cast_fu_24814_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1678.read())) {
        rowbuf1_address1 =  (sc_lv<12>) (gepindex1942_cast_fu_24582_p1.read());
    } else {
        rowbuf1_address1 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf1_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state974.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1676.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1680.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1684.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3095.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3099.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1110_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2521_blk.read()))))) {
        rowbuf1_ce0 = ap_const_logic_1;
    } else {
        rowbuf1_ce0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf1_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1251.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1678.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1682.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2385.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3093.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3097.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3101.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1110_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2521_blk.read()))))) {
        rowbuf1_ce1 = ap_const_logic_1;
    } else {
        rowbuf1_ce1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf1_d0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read())) {
        rowbuf1_d0 = reg_22986.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read())) {
        rowbuf1_d0 = tmp_192_reg_80480.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()))) {
        rowbuf1_d0 = reg_22966.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read()))) {
        rowbuf1_d0 = tmp_190_reg_80453.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read())) {
        rowbuf1_d0 = rd_pre_shift2_reg_80399.read().range(15, 8);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read())) {
        rowbuf1_d0 = reg_22986.read().range(15, 8);
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()))) {
        rowbuf1_d0 = reg_22974.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read()))) {
        rowbuf1_d0 = reg_22958.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state974.read())) {
        rowbuf1_d0 = get_part9_reg_71160.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read())) {
        rowbuf1_d0 = tmp_88_reg_71142.read();
    } else {
        rowbuf1_d0 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf1_d1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read())) {
        rowbuf1_d1 = reg_22986.read().range(15, 8);
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()))) {
        rowbuf1_d1 = reg_22974.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read()))) {
        rowbuf1_d1 = reg_22958.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2385.read())) {
        rowbuf1_d1 = rd_pre_shift2_reg_80399.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read())) {
        rowbuf1_d1 = tmp_149_reg_80405.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1251.read())) {
        rowbuf1_d1 = reg_22986.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read())) {
        rowbuf1_d1 = tmp_124_reg_71239.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()))) {
        rowbuf1_d1 = reg_22966.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read()))) {
        rowbuf1_d1 = tmp_113_reg_71212.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read())) {
        rowbuf1_d1 = rd_pre_shift_reg_71136.read().range(15, 8);
    } else {
        rowbuf1_d1 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf1_we0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_fu_24017_p2.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_0, grp_fu_22919_p2.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read()) || 
         (!esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state974.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond_reg_71147.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond1_reg_71156.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond7_reg_71195.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond18_reg_80436.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2662.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond19_reg_80458.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond20_reg_80485.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond21_reg_80489.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1110_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp2_iter1_exitcond7_reg_71195.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2521_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp5_iter1_exitcond18_reg_80436.read())))) {
        rowbuf1_we0 = ap_const_logic_1;
    } else {
        rowbuf1_we0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf1_we1() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state973.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, grp_fu_22919_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1250.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2384.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2661.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond20_fu_47320_p2.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond7_reg_71195.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1109_pp2_stage0.read())) || 
         (!esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero1_reg_71114.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2385.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond4_reg_80410.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond5_reg_80414.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond18_reg_80436.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2520_pp5_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1251.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_71217.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_reg_71244.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond10_reg_71248.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1110_pp2_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1110_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp2_iter1_exitcond7_reg_71195.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2521_pp5_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp5_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2521_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp5_iter1_exitcond18_reg_80436.read())))) {
        rowbuf1_we1 = ap_const_logic_1;
    } else {
        rowbuf1_we1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf2_address0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_172_fu_47707_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()))) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_169_fu_47649_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read()))) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_165_fu_47629_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_99_fu_24421_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()))) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_95_fu_24363_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read()))) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_91_fu_24343_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2814.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1396.read()))) {
        rowbuf2_address0 = ap_const_lv12_2;
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read()))) {
        rowbuf2_address0 = ap_const_lv12_0;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3101.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (gepindex2126_cast_fu_48155_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3098.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_259_1_reg_80822.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3096.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_180_reg_80711.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3093.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (gepindex2035_cast_fu_47819_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1684.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (gepindex2007_cast_fu_24862_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1681.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_135_1_reg_71613.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1679.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (tmp_106_reg_71508.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1676.read())) {
        rowbuf2_address0 =  (sc_lv<12>) (gepindex_cast_fu_24498_p1.read());
    } else {
        rowbuf2_address0 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf2_address1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3091.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_174_fu_47722_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_170_fu_47693_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()))) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_167_fu_47639_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read()))) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_163_fu_47620_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1674.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_101_fu_24436_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_96_fu_24407_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()))) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_93_fu_24353_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read()))) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_89_fu_24334_p1.read());
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read()))) {
        rowbuf2_address1 = ap_const_lv12_1;
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3102.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_259_2_reg_80892.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3099.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (gepindex2105_cast_fu_48107_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3097.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (gepindex2079_cast_fu_47971_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3095.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (gepindex2056_cast_fu_47867_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1685.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (tmp_135_2_reg_71678.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1682.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (gepindex1981_cast_fu_24788_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1680.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (gepindex1955_cast_fu_24664_p1.read());
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1678.read())) {
        rowbuf2_address1 =  (sc_lv<12>) (gepindex1937_cast_fu_24572_p1.read());
    } else {
        rowbuf2_address1 =  (sc_lv<12>) ("XXXXXXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf2_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1679.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3096.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1681.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3098.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1676.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1684.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2814.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3093.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3101.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1396.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1533_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2950_blk.read()))))) {
        rowbuf2_ce0 = ap_const_logic_1;
    } else {
        rowbuf2_ce0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf2_ce1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1685.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3102.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1678.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1680.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1682.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3095.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3097.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3099.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1674.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3091.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1533_blk.read()))) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2950_blk.read()))))) {
        rowbuf2_ce1 = ap_const_logic_1;
    } else {
        rowbuf2_ce1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf2_d0() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2814.read())) {
        rowbuf2_d0 = rd_pre_shift3_reg_80579.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read())) {
        rowbuf2_d0 = tmp_215_reg_80585.read();
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read()))) {
        rowbuf2_d0 = reg_22998.read().range(15, 8);
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read())))) {
        rowbuf2_d0 = reg_22974.read();
    } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read())) || 
                (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
                 esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read())))) {
        rowbuf2_d0 = reg_22958.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1396.read())) {
        rowbuf2_d0 = rd_pre_shift1_reg_71373.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read())) {
        rowbuf2_d0 = tmp_132_reg_71379.read();
    } else {
        rowbuf2_d0 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf2_d1() {
    if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read())) {
        rowbuf2_d1 = tmp_242_reg_80670.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read()))) {
        rowbuf2_d1 = tmp_227_reg_80638.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read())) {
        rowbuf2_d1 = rd_pre_shift3_reg_80579.read().range(15, 8);
    } else if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1674.read()) || 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3091.read()))) {
        rowbuf2_d1 = reg_22998.read().range(23, 16);
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read())) {
        rowbuf2_d1 = tmp_146_reg_71462.read();
    } else if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read())) || 
                (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
                 esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read())))) {
        rowbuf2_d1 = reg_22966.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read()))) {
        rowbuf2_d1 = tmp_144_reg_71430.read();
    } else if (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read())) {
        rowbuf2_d1 = rd_pre_shift1_reg_71373.read().range(15, 8);
    } else {
        rowbuf2_d1 =  (sc_lv<8>) ("XXXXXXXX");
    }
}

void krnl_sobel::thread_rowbuf2_we0() {
    if (((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond16_fu_24411_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond24_fu_47697_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1396.read()) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond14_reg_71413.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2814.read()) && 
          !esl_seteq<1,1,1>(ap_const_lv1_0, mod_ne_zero3_reg_80559.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond6_reg_80590.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond7_reg_80594.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond22_reg_80621.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1533_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp3_iter1_exitcond14_reg_71413.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2950_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp6_iter1_exitcond22_reg_80621.read())))) {
        rowbuf2_we0 = ap_const_logic_1;
    } else {
        rowbuf2_we0 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_rowbuf2_we1() {
    if ((esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1673.read()) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2813.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond6_fu_47531_p2.read())) || 
         esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3090.read()) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond14_reg_71413.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1532_pp3_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond22_reg_80621.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2949_pp6_stage0.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1674.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond15_reg_71435.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond16_reg_71467.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond17_reg_71471.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state3091.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond23_reg_80643.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond24_reg_80675.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, exitcond25_reg_80679.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1533_pp3_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state1533_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp3_iter1_exitcond14_reg_71413.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state2950_pp6_stage1.read()) && 
          esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter1.read()) && 
          !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp6_iter0.read()) && esl_seteq<1,1,1>(ap_const_boolean_1, ap_condition_sig_state2950_blk.read())) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, ap_pipeline_reg_pp6_iter1_exitcond22_reg_80621.read())) || 
         (esl_seteq<1,1,1>(ap_const_lv1_1, ap_CS_fsm_state1395.read()) && 
          esl_seteq<1,1,1>(ap_const_lv1_0, break_cond2_fu_24245_p2.read())))) {
        rowbuf2_we1 = ap_const_logic_1;
    } else {
        rowbuf2_we1 = ap_const_logic_0;
    }
}

void krnl_sobel::thread_sel_tmp1_fu_69909_p2() {
    sel_tmp1_fu_69909_p2 = (rnd_i_i_i_i29_0_reg2mem589_0_i_reg_22746.read() & tmp_336_not_fu_69904_p2.read());
}

void krnl_sobel::thread_sel_tmp2_fu_46603_p2() {
    sel_tmp2_fu_46603_p2 = (tmp_205_reg_80237.read() & rnd_i_i_i_i_0_reg2mem675_0_i_i_reg_12676.read());
}

void krnl_sobel::thread_sel_tmp3_fu_69915_p2() {
    sel_tmp3_fu_69915_p2 = (icmp4_reg_89398.read() & sel_tmp1_fu_69909_p2.read());
}

void krnl_sobel::thread_sel_tmp6_fu_46613_p2() {
    sel_tmp6_fu_46613_p2 = (rnd_i_i_i_i_0_reg2mem675_0_i_i_reg_12676.read() & tmp_205_not_fu_46608_p2.read());
}

void krnl_sobel::thread_sel_tmp7_fu_46619_p2() {
    sel_tmp7_fu_46619_p2 = (icmp1_reg_80249.read() & sel_tmp6_fu_46613_p2.read());
}

void krnl_sobel::thread_sel_tmp_fu_69899_p2() {
    sel_tmp_fu_69899_p2 = (tmp_336_reg_89386.read() & rnd_i_i_i_i29_0_reg2mem589_0_i_reg_22746.read());
}

void krnl_sobel::thread_set_part1_fu_70566_p5() {
    set_part1_fu_70566_p5 = esl_concat<24,8>(esl_concat<16,8>(esl_concat<8,8>(reg_22954.read(), reg_22944.read()), reg_22939.read()), reg_22949.read());
}

void krnl_sobel::thread_set_part2_fu_70652_p5() {
    set_part2_fu_70652_p5 = esl_partset<32,32,24,32,32>(gmem_RDATA.read(), tmp_241_fu_70642_p4.read(), ap_const_lv32_0, ap_const_lv32_17);
}

void krnl_sobel::thread_set_part4_fu_23547_p5() {
    set_part4_fu_23547_p5 = esl_concat<24,8>(esl_concat<16,8>(esl_concat<8,8>(reg_22954.read(), reg_22944.read()), reg_22939.read()), reg_22949.read());
}

void krnl_sobel::thread_set_part8_fu_23633_p5() {
    set_part8_fu_23633_p5 = esl_partset<32,32,24,32,32>(gmem_RDATA.read(), tmp_35_fu_23623_p4.read(), ap_const_lv32_0, ap_const_lv32_17);
}

void krnl_sobel::thread_set_part9_fu_23415_p1() {
    set_part9_fu_23415_p1 = esl_zext<32,24>(tmp_13_fu_23405_p4.read());
}

void krnl_sobel::thread_set_part_fu_70438_p1() {
    set_part_fu_70438_p1 = esl_zext<32,24>(tmp_212_fu_70428_p4.read());
}

void krnl_sobel::thread_sh_assign_1_cast_cast_fu_70274_p1() {
    sh_assign_1_cast_cast_fu_70274_p1 = esl_sext<24,9>(sh_assign_1_reg_89507.read());
}

void krnl_sobel::thread_sh_assign_1_cast_fu_70271_p1() {
    sh_assign_1_cast_fu_70271_p1 = esl_sext<32,9>(sh_assign_1_reg_89507.read());
}

void krnl_sobel::thread_sh_assign_1_fu_70252_p3() {
    sh_assign_1_fu_70252_p3 = (!isNeg_fu_70234_p3.read()[0].is_01())? sc_lv<9>(): ((isNeg_fu_70234_p3.read()[0].to_bool())? tmp_367_cast_fu_70248_p1.read(): sh_assign_fu_70228_p2.read());
}

void krnl_sobel::thread_sh_assign_fu_70228_p2() {
    sh_assign_fu_70228_p2 = (!ap_const_lv9_181.is_01() || !tmp_366_cast_fu_70224_p1.read().is_01())? sc_lv<9>(): (sc_bigint<9>(ap_const_lv9_181) + sc_biguint<9>(tmp_366_cast_fu_70224_p1.read()));
}

void krnl_sobel::thread_src_ptr_inc120_sum1_fu_23994_p2() {
    src_ptr_inc120_sum1_fu_23994_p2 = (!arg_in_pixels_i_0_sum_cast_reg_71096.read().is_01() || !tmp135_cast_fu_23991_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(arg_in_pixels_i_0_sum_cast_reg_71096.read()) + sc_biguint<64>(tmp135_cast_fu_23991_p1.read()));
}

void krnl_sobel::thread_src_ptr_inc194_sum1_fu_24387_p2() {
    src_ptr_inc194_sum1_fu_24387_p2 = (!tmp136_cast_fu_24381_p1.read().is_01() || !tmp137_cast_fu_24384_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(tmp136_cast_fu_24381_p1.read()) + sc_biguint<64>(tmp137_cast_fu_24384_p1.read()));
}

void krnl_sobel::thread_src_ptr_inc270_sum1_cast_fu_47130_p1() {
    src_ptr_inc270_sum1_cast_fu_47130_p1 = esl_zext<64,63>(src_ptr_inc270_sum1_fu_47125_p2.read());
}

void krnl_sobel::thread_src_ptr_inc270_sum1_fu_47125_p2() {
    src_ptr_inc270_sum1_fu_47125_p2 = (!tmp_cast_reg_70709.read().is_01() || !tmp_84_cast_fu_47122_p1.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_cast_reg_70709.read()) + sc_biguint<63>(tmp_84_cast_fu_47122_p1.read()));
}

void krnl_sobel::thread_src_ptr_inc348_sum1_fu_47297_p2() {
    src_ptr_inc348_sum1_fu_47297_p2 = (!arg_in_pixels_i_0_sum_cast_reg_71096.read().is_01() || !tmp141_cast_fu_47294_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(arg_in_pixels_i_0_sum_cast_reg_71096.read()) + sc_biguint<64>(tmp141_cast_fu_47294_p1.read()));
}

void krnl_sobel::thread_src_ptr_inc426_sum1_fu_47673_p2() {
    src_ptr_inc426_sum1_fu_47673_p2 = (!tmp142_cast_fu_47667_p1.read().is_01() || !tmp143_cast_fu_47670_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(tmp142_cast_fu_47667_p1.read()) + sc_biguint<64>(tmp143_cast_fu_47670_p1.read()));
}

void krnl_sobel::thread_src_ptr_inc_sum1_cast_fu_23737_p1() {
    src_ptr_inc_sum1_cast_fu_23737_p1 = esl_zext<64,63>(src_ptr_inc_sum1_fu_23732_p2.read());
}

void krnl_sobel::thread_src_ptr_inc_sum1_fu_23732_p2() {
    src_ptr_inc_sum1_fu_23732_p2 = (!tmp_cast_reg_70709.read().is_01() || !tmp_29_cast_fu_23729_p1.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_cast_reg_70709.read()) + sc_biguint<63>(tmp_29_cast_fu_23729_p1.read()));
}

void krnl_sobel::thread_tmp133_cast_fu_23573_p1() {
    tmp133_cast_fu_23573_p1 = esl_zext<64,63>(tmp1_reg_70978.read());
}

void krnl_sobel::thread_tmp134_cast_fu_23576_p1() {
    tmp134_cast_fu_23576_p1 = esl_zext<64,31>(tmp2_reg_70983.read());
}

void krnl_sobel::thread_tmp135_cast_fu_23991_p1() {
    tmp135_cast_fu_23991_p1 = esl_zext<64,31>(tmp3_reg_71221.read());
}

void krnl_sobel::thread_tmp135_fu_47290_p2() {
    tmp135_fu_47290_p2 = (!tmp_110_cast1_reg_80424.read().is_01() || !rd_cnt_burst1_cast_reg_71130.read().is_01())? sc_lv<31>(): (sc_biguint<31>(tmp_110_cast1_reg_80424.read()) + sc_biguint<31>(rd_cnt_burst1_cast_reg_71130.read()));
}

void krnl_sobel::thread_tmp136_cast_fu_24381_p1() {
    tmp136_cast_fu_24381_p1 = esl_zext<64,63>(tmp4_reg_71439.read());
}

void krnl_sobel::thread_tmp136_fu_47659_p2() {
    tmp136_fu_47659_p2 = (!tmp_163_cast_reg_80537.read().is_01() || !tmp_cast_reg_70709.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_163_cast_reg_80537.read()) + sc_biguint<63>(tmp_cast_reg_70709.read()));
}

void krnl_sobel::thread_tmp137_cast_fu_24384_p1() {
    tmp137_cast_fu_24384_p1 = esl_zext<64,31>(tmp5_reg_71444.read());
}

void krnl_sobel::thread_tmp137_fu_47663_p2() {
    tmp137_fu_47663_p2 = (!tmp_184_cast1_reg_80604.read().is_01() || !rd_cnt_burst3_cast_reg_80574.read().is_01())? sc_lv<31>(): (sc_biguint<31>(tmp_184_cast1_reg_80604.read()) + sc_biguint<31>(rd_cnt_burst3_cast_reg_80574.read()));
}

void krnl_sobel::thread_tmp138_cast_fu_24697_p1() {
    tmp138_cast_fu_24697_p1 = esl_zext<10,9>(tmp6_fu_24693_p2.read());
}

void krnl_sobel::thread_tmp138_fu_47976_p2() {
    tmp138_fu_47976_p2 = (!tmp_261_cast_reg_80755.read().is_01() || !tmp_267_cast_reg_80807.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_261_cast_reg_80755.read()) + sc_biguint<9>(tmp_267_cast_reg_80807.read()));
}

void krnl_sobel::thread_tmp139_fu_46830_p2() {
    tmp139_fu_46830_p2 = (tmp_408_fu_46825_p2.read() | not_1_reg_80307.read());
}

void krnl_sobel::thread_tmp140_fu_46765_p2() {
    tmp140_fu_46765_p2 = (!ap_const_lv10_381.is_01() || !p_0124_reg2mem_0_i_i_cast_fu_46733_p1.read().is_01())? sc_lv<10>(): (sc_bigint<10>(ap_const_lv10_381) + sc_bigint<10>(p_0124_reg2mem_0_i_i_cast_fu_46733_p1.read()));
}

void krnl_sobel::thread_tmp141_cast_fu_47294_p1() {
    tmp141_cast_fu_47294_p1 = esl_zext<64,31>(tmp135_reg_80462.read());
}

void krnl_sobel::thread_tmp142_cast_fu_47667_p1() {
    tmp142_cast_fu_47667_p1 = esl_zext<64,63>(tmp136_reg_80647.read());
}

void krnl_sobel::thread_tmp143_cast_fu_47670_p1() {
    tmp143_cast_fu_47670_p1 = esl_zext<64,31>(tmp137_reg_80652.read());
}

void krnl_sobel::thread_tmp144_cast_fu_47980_p1() {
    tmp144_cast_fu_47980_p1 = esl_zext<10,9>(tmp138_fu_47976_p2.read());
}

void krnl_sobel::thread_tmp145_fu_70126_p2() {
    tmp145_fu_70126_p2 = (tmp_495_fu_70121_p2.read() | not_s_reg_89456.read());
}

void krnl_sobel::thread_tmp146_fu_70061_p2() {
    tmp146_fu_70061_p2 = (!ap_const_lv10_381.is_01() || !p_0_reg2mem_0_i_i_cast_fu_70029_p1.read().is_01())? sc_lv<10>(): (sc_bigint<10>(ap_const_lv10_381) + sc_bigint<10>(p_0_reg2mem_0_i_i_cast_fu_70029_p1.read()));
}

void krnl_sobel::thread_tmp147_cast_fu_70592_p1() {
    tmp147_cast_fu_70592_p1 = esl_zext<64,63>(tmp147_reg_89648.read());
}

void krnl_sobel::thread_tmp147_fu_70584_p2() {
    tmp147_fu_70584_p2 = (!tmp_1_cast_reg_70743.read().is_01() || !tmp_167_cast_reg_80542.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_1_cast_reg_70743.read()) + sc_biguint<63>(tmp_167_cast_reg_80542.read()));
}

void krnl_sobel::thread_tmp148_cast_fu_70595_p1() {
    tmp148_cast_fu_70595_p1 = esl_zext<64,31>(tmp148_reg_89653.read());
}

void krnl_sobel::thread_tmp148_fu_70588_p2() {
    tmp148_fu_70588_p2 = (!wr_cnt_burst1_cast_reg_89561.read().is_01() || !tmp_243_cast1_reg_89591.read().is_01())? sc_lv<31>(): (sc_biguint<31>(wr_cnt_burst1_cast_reg_89561.read()) + sc_biguint<31>(tmp_243_cast1_reg_89591.read()));
}

void krnl_sobel::thread_tmp1_fu_23565_p2() {
    tmp1_fu_23565_p2 = (!tmp_1_cast_reg_70743.read().is_01() || !tmp_5_cast_reg_70857.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_1_cast_reg_70743.read()) + sc_biguint<63>(tmp_5_cast_reg_70857.read()));
}

void krnl_sobel::thread_tmp2_fu_23569_p2() {
    tmp2_fu_23569_p2 = (!wr_cnt_burst_cast_reg_70891.read().is_01() || !tmp_10_cast1_reg_70921.read().is_01())? sc_lv<31>(): (sc_biguint<31>(wr_cnt_burst_cast_reg_70891.read()) + sc_biguint<31>(tmp_10_cast1_reg_70921.read()));
}

void krnl_sobel::thread_tmp3_fu_23987_p2() {
    tmp3_fu_23987_p2 = (!tmp_47_cast1_reg_71176.read().is_01() || !rd_cnt_burst1_cast_reg_71130.read().is_01())? sc_lv<31>(): (sc_biguint<31>(tmp_47_cast1_reg_71176.read()) + sc_biguint<31>(rd_cnt_burst1_cast_reg_71130.read()));
}

void krnl_sobel::thread_tmp4_fu_24373_p2() {
    tmp4_fu_24373_p2 = (!tmp_69_cast_reg_71343.read().is_01() || !tmp_cast_reg_70709.read().is_01())? sc_lv<63>(): (sc_biguint<63>(tmp_69_cast_reg_71343.read()) + sc_biguint<63>(tmp_cast_reg_70709.read()));
}

void krnl_sobel::thread_tmp5_fu_24377_p2() {
    tmp5_fu_24377_p2 = (!tmp_86_cast1_reg_71396.read().is_01() || !rd_cnt_burst2_cast_reg_71368.read().is_01())? sc_lv<31>(): (sc_biguint<31>(tmp_86_cast1_reg_71396.read()) + sc_biguint<31>(rd_cnt_burst2_cast_reg_71368.read()));
}

void krnl_sobel::thread_tmp6_fu_24693_p2() {
    tmp6_fu_24693_p2 = (!tmp_522_cast_reg_71552.read().is_01() || !tmp_524_cast_reg_71598.read().is_01())? sc_lv<9>(): (sc_biguint<9>(tmp_522_cast_reg_71552.read()) + sc_biguint<9>(tmp_524_cast_reg_71598.read()));
}

void krnl_sobel::thread_tmp_1000_fu_27645_p3() {
    tmp_1000_fu_27645_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1001_fu_50785_p3() {
    tmp_1001_fu_50785_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1002_fu_27653_p3() {
    tmp_1002_fu_27653_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1003_fu_50793_p3() {
    tmp_1003_fu_50793_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1004_fu_27661_p3() {
    tmp_1004_fu_27661_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1005_fu_50801_p3() {
    tmp_1005_fu_50801_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1006_fu_27669_p3() {
    tmp_1006_fu_27669_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1007_fu_50809_p3() {
    tmp_1007_fu_50809_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1008_fu_27677_p3() {
    tmp_1008_fu_27677_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1009_fu_50817_p3() {
    tmp_1009_fu_50817_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(34, 34);
}

void krnl_sobel::thread_tmp_100_fu_24431_p2() {
    tmp_100_fu_24431_p2 = (!done_cnt4_reg_71455.read().is_01() || !ap_const_lv32_2.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt4_reg_71455.read()) + sc_biguint<32>(ap_const_lv32_2));
}

void krnl_sobel::thread_tmp_1010_fu_27721_p3() {
    tmp_1010_fu_27721_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1011_fu_50825_p3() {
    tmp_1011_fu_50825_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1012_fu_27729_p3() {
    tmp_1012_fu_27729_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1013_fu_50833_p3() {
    tmp_1013_fu_50833_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1014_fu_27737_p3() {
    tmp_1014_fu_27737_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1015_fu_50841_p3() {
    tmp_1015_fu_50841_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1016_fu_27745_p3() {
    tmp_1016_fu_27745_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1017_fu_50849_p3() {
    tmp_1017_fu_50849_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1018_fu_27753_p3() {
    tmp_1018_fu_27753_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1019_fu_50857_p3() {
    tmp_1019_fu_50857_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(29, 29);
}

void krnl_sobel::thread_tmp_101_fu_24436_p1() {
    tmp_101_fu_24436_p1 = esl_sext<64,32>(tmp_100_fu_24431_p2.read());
}

void krnl_sobel::thread_tmp_1020_fu_27761_p3() {
    tmp_1020_fu_27761_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1021_fu_50865_p3() {
    tmp_1021_fu_50865_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1022_fu_27769_p3() {
    tmp_1022_fu_27769_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1023_fu_50873_p3() {
    tmp_1023_fu_50873_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(27, 27);
}

}

