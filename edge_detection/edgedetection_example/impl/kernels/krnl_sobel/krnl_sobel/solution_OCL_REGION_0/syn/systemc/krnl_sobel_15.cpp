#include "krnl_sobel.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void krnl_sobel::thread_tmp_794_fu_26749_p3() {
    tmp_794_fu_26749_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(31, 31);
}

void krnl_sobel::thread_tmp_795_fu_49888_p3() {
    tmp_795_fu_49888_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(49, 49);
}

void krnl_sobel::thread_tmp_796_fu_26757_p3() {
    tmp_796_fu_26757_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(30, 30);
}

void krnl_sobel::thread_tmp_797_fu_49896_p3() {
    tmp_797_fu_49896_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(48, 48);
}

void krnl_sobel::thread_tmp_798_fu_26765_p3() {
    tmp_798_fu_26765_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(29, 29);
}

void krnl_sobel::thread_tmp_799_fu_49904_p3() {
    tmp_799_fu_49904_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(47, 47);
}

void krnl_sobel::thread_tmp_79_fu_47112_p2() {
    tmp_79_fu_47112_p2 = (ap_pipeline_reg_pp4_iter1_krnl_sobel_rowbuf0_mult1_reg_80367.read() | ap_const_lv32_3);
}

void krnl_sobel::thread_tmp_800_fu_26773_p3() {
    tmp_800_fu_26773_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(28, 28);
}

void krnl_sobel::thread_tmp_801_fu_49912_p3() {
    tmp_801_fu_49912_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(46, 46);
}

void krnl_sobel::thread_tmp_802_fu_26781_p3() {
    tmp_802_fu_26781_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(27, 27);
}

void krnl_sobel::thread_tmp_803_fu_49920_p3() {
    tmp_803_fu_49920_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(45, 45);
}

void krnl_sobel::thread_tmp_804_fu_26789_p3() {
    tmp_804_fu_26789_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(26, 26);
}

void krnl_sobel::thread_tmp_805_fu_49928_p3() {
    tmp_805_fu_49928_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(44, 44);
}

void krnl_sobel::thread_tmp_806_fu_26797_p3() {
    tmp_806_fu_26797_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(25, 25);
}

void krnl_sobel::thread_tmp_807_fu_49936_p3() {
    tmp_807_fu_49936_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(43, 43);
}

void krnl_sobel::thread_tmp_808_fu_26805_p3() {
    tmp_808_fu_26805_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(24, 24);
}

void krnl_sobel::thread_tmp_809_fu_49944_p3() {
    tmp_809_fu_49944_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(42, 42);
}

void krnl_sobel::thread_tmp_80_fu_47117_p1() {
    tmp_80_fu_47117_p1 = esl_sext<64,32>(tmp_79_fu_47112_p2.read());
}

void krnl_sobel::thread_tmp_810_fu_26813_p3() {
    tmp_810_fu_26813_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(23, 23);
}

void krnl_sobel::thread_tmp_811_fu_49952_p3() {
    tmp_811_fu_49952_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(41, 41);
}

void krnl_sobel::thread_tmp_812_fu_26821_p3() {
    tmp_812_fu_26821_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(22, 22);
}

void krnl_sobel::thread_tmp_813_fu_49960_p3() {
    tmp_813_fu_49960_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(40, 40);
}

void krnl_sobel::thread_tmp_814_fu_26829_p3() {
    tmp_814_fu_26829_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(21, 21);
}

void krnl_sobel::thread_tmp_815_fu_49968_p3() {
    tmp_815_fu_49968_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(39, 39);
}

void krnl_sobel::thread_tmp_816_fu_26837_p3() {
    tmp_816_fu_26837_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(20, 20);
}

void krnl_sobel::thread_tmp_817_fu_49976_p3() {
    tmp_817_fu_49976_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(38, 38);
}

void krnl_sobel::thread_tmp_818_fu_26845_p3() {
    tmp_818_fu_26845_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(19, 19);
}

void krnl_sobel::thread_tmp_819_fu_49984_p3() {
    tmp_819_fu_49984_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(37, 37);
}

void krnl_sobel::thread_tmp_81_fu_47144_p1() {
    tmp_81_fu_47144_p1 = esl_sext<64,32>(reg_22982.read());
}

void krnl_sobel::thread_tmp_820_fu_26853_p3() {
    tmp_820_fu_26853_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(18, 18);
}

void krnl_sobel::thread_tmp_821_fu_49992_p3() {
    tmp_821_fu_49992_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(36, 36);
}

void krnl_sobel::thread_tmp_822_fu_26861_p3() {
    tmp_822_fu_26861_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(17, 17);
}

void krnl_sobel::thread_tmp_823_fu_50000_p3() {
    tmp_823_fu_50000_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(35, 35);
}

void krnl_sobel::thread_tmp_824_fu_26869_p3() {
    tmp_824_fu_26869_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(16, 16);
}

void krnl_sobel::thread_tmp_825_fu_50008_p3() {
    tmp_825_fu_50008_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(34, 34);
}

void krnl_sobel::thread_tmp_826_fu_26913_p3() {
    tmp_826_fu_26913_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(61, 61);
}

void krnl_sobel::thread_tmp_827_fu_50016_p3() {
    tmp_827_fu_50016_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(33, 33);
}

void krnl_sobel::thread_tmp_828_fu_26921_p3() {
    tmp_828_fu_26921_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(60, 60);
}

void krnl_sobel::thread_tmp_829_fu_50024_p3() {
    tmp_829_fu_50024_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(32, 32);
}

void krnl_sobel::thread_tmp_82_fu_24298_p3() {
    tmp_82_fu_24298_p3 = esl_concat<30,2>(rd_cnt_burst2_reg_71357.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_tmp_830_fu_26929_p3() {
    tmp_830_fu_26929_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(59, 59);
}

void krnl_sobel::thread_tmp_831_fu_50032_p3() {
    tmp_831_fu_50032_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(31, 31);
}

void krnl_sobel::thread_tmp_832_fu_26937_p3() {
    tmp_832_fu_26937_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(58, 58);
}

void krnl_sobel::thread_tmp_833_fu_50040_p3() {
    tmp_833_fu_50040_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(30, 30);
}

void krnl_sobel::thread_tmp_834_fu_26945_p3() {
    tmp_834_fu_26945_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(57, 57);
}

void krnl_sobel::thread_tmp_835_fu_50048_p3() {
    tmp_835_fu_50048_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(29, 29);
}

void krnl_sobel::thread_tmp_836_fu_26953_p3() {
    tmp_836_fu_26953_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(56, 56);
}

void krnl_sobel::thread_tmp_837_fu_50056_p3() {
    tmp_837_fu_50056_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(28, 28);
}

void krnl_sobel::thread_tmp_838_fu_26961_p3() {
    tmp_838_fu_26961_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(55, 55);
}

void krnl_sobel::thread_tmp_839_fu_50064_p3() {
    tmp_839_fu_50064_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(27, 27);
}

void krnl_sobel::thread_tmp_83_fu_24305_p2() {
    tmp_83_fu_24305_p2 = (!p_ph9_reg_2832.read().is_01() || !tmp_82_fu_24298_p3.read().is_01())? sc_lv<32>(): (sc_biguint<32>(p_ph9_reg_2832.read()) - sc_biguint<32>(tmp_82_fu_24298_p3.read()));
}

void krnl_sobel::thread_tmp_840_fu_26969_p3() {
    tmp_840_fu_26969_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(54, 54);
}

void krnl_sobel::thread_tmp_841_fu_50072_p3() {
    tmp_841_fu_50072_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(26, 26);
}

void krnl_sobel::thread_tmp_842_fu_26977_p3() {
    tmp_842_fu_26977_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(53, 53);
}

void krnl_sobel::thread_tmp_843_fu_50080_p3() {
    tmp_843_fu_50080_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(25, 25);
}

void krnl_sobel::thread_tmp_844_fu_26985_p3() {
    tmp_844_fu_26985_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(52, 52);
}

void krnl_sobel::thread_tmp_845_fu_50088_p3() {
    tmp_845_fu_50088_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(24, 24);
}

void krnl_sobel::thread_tmp_846_fu_26993_p3() {
    tmp_846_fu_26993_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(51, 51);
}

void krnl_sobel::thread_tmp_847_fu_50096_p3() {
    tmp_847_fu_50096_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(23, 23);
}

void krnl_sobel::thread_tmp_848_fu_27001_p3() {
    tmp_848_fu_27001_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(50, 50);
}

void krnl_sobel::thread_tmp_849_fu_50104_p3() {
    tmp_849_fu_50104_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(22, 22);
}

void krnl_sobel::thread_tmp_84_cast_fu_47122_p1() {
    tmp_84_cast_fu_47122_p1 = esl_zext<63,30>(rd_cnt_burst_reg_70824.read());
}

void krnl_sobel::thread_tmp_850_fu_27009_p3() {
    tmp_850_fu_27009_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(49, 49);
}

void krnl_sobel::thread_tmp_851_fu_50112_p3() {
    tmp_851_fu_50112_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(21, 21);
}

void krnl_sobel::thread_tmp_852_fu_27017_p3() {
    tmp_852_fu_27017_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(48, 48);
}

void krnl_sobel::thread_tmp_853_fu_50120_p3() {
    tmp_853_fu_50120_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(20, 20);
}

void krnl_sobel::thread_tmp_854_fu_27025_p3() {
    tmp_854_fu_27025_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(47, 47);
}

void krnl_sobel::thread_tmp_855_fu_50128_p3() {
    tmp_855_fu_50128_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(19, 19);
}

void krnl_sobel::thread_tmp_856_fu_27033_p3() {
    tmp_856_fu_27033_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(46, 46);
}

void krnl_sobel::thread_tmp_857_fu_50136_p3() {
    tmp_857_fu_50136_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(18, 18);
}

void krnl_sobel::thread_tmp_858_fu_27041_p3() {
    tmp_858_fu_27041_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(45, 45);
}

void krnl_sobel::thread_tmp_859_fu_50144_p3() {
    tmp_859_fu_50144_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(17, 17);
}

void krnl_sobel::thread_tmp_85_fu_47149_p1() {
    tmp_85_fu_47149_p1 = esl_sext<64,32>(grp_fu_23124_p2.read());
}

void krnl_sobel::thread_tmp_860_fu_27049_p3() {
    tmp_860_fu_27049_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(44, 44);
}

void krnl_sobel::thread_tmp_861_fu_50152_p3() {
    tmp_861_fu_50152_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(16, 16);
}

void krnl_sobel::thread_tmp_862_fu_27057_p3() {
    tmp_862_fu_27057_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(43, 43);
}

void krnl_sobel::thread_tmp_863_fu_50197_p3() {
    tmp_863_fu_50197_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(61, 61);
}

void krnl_sobel::thread_tmp_864_fu_27065_p3() {
    tmp_864_fu_27065_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(42, 42);
}

void krnl_sobel::thread_tmp_865_fu_50205_p3() {
    tmp_865_fu_50205_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(60, 60);
}

void krnl_sobel::thread_tmp_866_fu_27073_p3() {
    tmp_866_fu_27073_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(41, 41);
}

void krnl_sobel::thread_tmp_867_fu_50213_p3() {
    tmp_867_fu_50213_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(59, 59);
}

void krnl_sobel::thread_tmp_868_fu_27081_p3() {
    tmp_868_fu_27081_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(40, 40);
}

void krnl_sobel::thread_tmp_869_fu_50221_p3() {
    tmp_869_fu_50221_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(58, 58);
}

void krnl_sobel::thread_tmp_86_cast1_fu_24294_p1() {
    tmp_86_cast1_fu_24294_p1 = esl_zext<31,1>(p_ph8_reg_2790.read());
}

void krnl_sobel::thread_tmp_86_cast_fu_24275_p1() {
    tmp_86_cast_fu_24275_p1 = esl_zext<63,1>(p_ph8_reg_2790.read());
}

void krnl_sobel::thread_tmp_870_fu_27089_p3() {
    tmp_870_fu_27089_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(39, 39);
}

void krnl_sobel::thread_tmp_871_fu_50229_p3() {
    tmp_871_fu_50229_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(57, 57);
}

void krnl_sobel::thread_tmp_872_fu_27097_p3() {
    tmp_872_fu_27097_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(38, 38);
}

void krnl_sobel::thread_tmp_873_fu_50237_p3() {
    tmp_873_fu_50237_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(56, 56);
}

void krnl_sobel::thread_tmp_874_fu_27105_p3() {
    tmp_874_fu_27105_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(37, 37);
}

void krnl_sobel::thread_tmp_875_fu_50245_p3() {
    tmp_875_fu_50245_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(55, 55);
}

void krnl_sobel::thread_tmp_876_fu_27113_p3() {
    tmp_876_fu_27113_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(36, 36);
}

void krnl_sobel::thread_tmp_877_fu_50253_p3() {
    tmp_877_fu_50253_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(54, 54);
}

void krnl_sobel::thread_tmp_878_fu_27121_p3() {
    tmp_878_fu_27121_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(35, 35);
}

void krnl_sobel::thread_tmp_879_fu_50261_p3() {
    tmp_879_fu_50261_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(53, 53);
}

void krnl_sobel::thread_tmp_87_fu_47154_p1() {
    tmp_87_fu_47154_p1 = esl_sext<64,32>(grp_fu_23143_p2.read());
}

void krnl_sobel::thread_tmp_880_fu_27129_p3() {
    tmp_880_fu_27129_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(34, 34);
}

void krnl_sobel::thread_tmp_881_fu_50269_p3() {
    tmp_881_fu_50269_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(52, 52);
}

void krnl_sobel::thread_tmp_882_fu_27137_p3() {
    tmp_882_fu_27137_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(33, 33);
}

void krnl_sobel::thread_tmp_883_fu_50277_p3() {
    tmp_883_fu_50277_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(51, 51);
}

void krnl_sobel::thread_tmp_884_fu_27145_p3() {
    tmp_884_fu_27145_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(32, 32);
}

void krnl_sobel::thread_tmp_885_fu_50285_p3() {
    tmp_885_fu_50285_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(50, 50);
}

void krnl_sobel::thread_tmp_886_fu_27153_p3() {
    tmp_886_fu_27153_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(31, 31);
}

void krnl_sobel::thread_tmp_887_fu_50293_p3() {
    tmp_887_fu_50293_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(49, 49);
}

void krnl_sobel::thread_tmp_888_fu_27161_p3() {
    tmp_888_fu_27161_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(30, 30);
}

void krnl_sobel::thread_tmp_889_fu_50301_p3() {
    tmp_889_fu_50301_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(48, 48);
}

void krnl_sobel::thread_tmp_88_fu_23856_p1() {
    tmp_88_fu_23856_p1 = rd_pre_shift_fu_23850_p2.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_890_fu_27169_p3() {
    tmp_890_fu_27169_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(29, 29);
}

void krnl_sobel::thread_tmp_891_fu_50309_p3() {
    tmp_891_fu_50309_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(47, 47);
}

void krnl_sobel::thread_tmp_892_fu_27177_p3() {
    tmp_892_fu_27177_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(28, 28);
}

void krnl_sobel::thread_tmp_893_fu_50317_p3() {
    tmp_893_fu_50317_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(46, 46);
}

void krnl_sobel::thread_tmp_894_fu_27185_p3() {
    tmp_894_fu_27185_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(27, 27);
}

void krnl_sobel::thread_tmp_895_fu_50325_p3() {
    tmp_895_fu_50325_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(45, 45);
}

void krnl_sobel::thread_tmp_896_fu_27193_p3() {
    tmp_896_fu_27193_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(26, 26);
}

void krnl_sobel::thread_tmp_897_fu_50333_p3() {
    tmp_897_fu_50333_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(44, 44);
}

void krnl_sobel::thread_tmp_898_fu_27201_p3() {
    tmp_898_fu_27201_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(25, 25);
}

void krnl_sobel::thread_tmp_899_fu_50341_p3() {
    tmp_899_fu_50341_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(43, 43);
}

void krnl_sobel::thread_tmp_89_fu_24334_p1() {
    tmp_89_fu_24334_p1 = esl_sext<64,32>(krnl_sobel_rowbuf2_addr_reg_71422.read());
}

void krnl_sobel::thread_tmp_8_cast_fu_23365_p3() {
    tmp_8_cast_fu_23365_p3 = (!mod_ne_zero_fu_23360_p2.read()[0].is_01())? sc_lv<3>(): ((mod_ne_zero_fu_23360_p2.read()[0].to_bool())? ap_const_lv3_7: ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_900_fu_27209_p3() {
    tmp_900_fu_27209_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(24, 24);
}

void krnl_sobel::thread_tmp_901_fu_50349_p3() {
    tmp_901_fu_50349_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(42, 42);
}

void krnl_sobel::thread_tmp_902_fu_27217_p3() {
    tmp_902_fu_27217_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(23, 23);
}

void krnl_sobel::thread_tmp_903_fu_50357_p3() {
    tmp_903_fu_50357_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(41, 41);
}

void krnl_sobel::thread_tmp_904_fu_27225_p3() {
    tmp_904_fu_27225_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(22, 22);
}

void krnl_sobel::thread_tmp_905_fu_50365_p3() {
    tmp_905_fu_50365_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(40, 40);
}

void krnl_sobel::thread_tmp_906_fu_27233_p3() {
    tmp_906_fu_27233_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(21, 21);
}

void krnl_sobel::thread_tmp_907_fu_50373_p3() {
    tmp_907_fu_50373_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(39, 39);
}

void krnl_sobel::thread_tmp_908_fu_27241_p3() {
    tmp_908_fu_27241_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(20, 20);
}

void krnl_sobel::thread_tmp_909_fu_50381_p3() {
    tmp_909_fu_50381_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(38, 38);
}

void krnl_sobel::thread_tmp_90_fu_24338_p2() {
    tmp_90_fu_24338_p2 = (!ap_const_lv32_1.is_01() || !krnl_sobel_rowbuf2_addr_reg_71422.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_1) + sc_biguint<32>(krnl_sobel_rowbuf2_addr_reg_71422.read()));
}

void krnl_sobel::thread_tmp_910_fu_27249_p3() {
    tmp_910_fu_27249_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(19, 19);
}

void krnl_sobel::thread_tmp_911_fu_50389_p3() {
    tmp_911_fu_50389_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(37, 37);
}

void krnl_sobel::thread_tmp_912_fu_27257_p3() {
    tmp_912_fu_27257_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(18, 18);
}

void krnl_sobel::thread_tmp_913_fu_50397_p3() {
    tmp_913_fu_50397_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(36, 36);
}

void krnl_sobel::thread_tmp_914_fu_27265_p3() {
    tmp_914_fu_27265_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(17, 17);
}

void krnl_sobel::thread_tmp_915_fu_50405_p3() {
    tmp_915_fu_50405_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(35, 35);
}

void krnl_sobel::thread_tmp_916_fu_27273_p3() {
    tmp_916_fu_27273_p3 = p_164_reg2mem697_0_i_i_4_reg_3856.read().range(16, 16);
}

void krnl_sobel::thread_tmp_917_fu_50413_p3() {
    tmp_917_fu_50413_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(34, 34);
}

void krnl_sobel::thread_tmp_918_fu_27317_p3() {
    tmp_918_fu_27317_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(61, 61);
}

void krnl_sobel::thread_tmp_919_fu_50421_p3() {
    tmp_919_fu_50421_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(33, 33);
}

void krnl_sobel::thread_tmp_91_fu_24343_p1() {
    tmp_91_fu_24343_p1 = esl_sext<64,32>(tmp_90_fu_24338_p2.read());
}

void krnl_sobel::thread_tmp_920_fu_27325_p3() {
    tmp_920_fu_27325_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(60, 60);
}

void krnl_sobel::thread_tmp_921_fu_50429_p3() {
    tmp_921_fu_50429_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(32, 32);
}

void krnl_sobel::thread_tmp_922_fu_27333_p3() {
    tmp_922_fu_27333_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(59, 59);
}

void krnl_sobel::thread_tmp_923_fu_50437_p3() {
    tmp_923_fu_50437_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(31, 31);
}

void krnl_sobel::thread_tmp_924_fu_27341_p3() {
    tmp_924_fu_27341_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(58, 58);
}

void krnl_sobel::thread_tmp_925_fu_50445_p3() {
    tmp_925_fu_50445_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(30, 30);
}

void krnl_sobel::thread_tmp_926_fu_27349_p3() {
    tmp_926_fu_27349_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(57, 57);
}

void krnl_sobel::thread_tmp_927_fu_50453_p3() {
    tmp_927_fu_50453_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(29, 29);
}

void krnl_sobel::thread_tmp_928_fu_27357_p3() {
    tmp_928_fu_27357_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(56, 56);
}

void krnl_sobel::thread_tmp_929_fu_50461_p3() {
    tmp_929_fu_50461_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(28, 28);
}

void krnl_sobel::thread_tmp_92_fu_24348_p2() {
    tmp_92_fu_24348_p2 = (!ap_const_lv32_2.is_01() || !ap_pipeline_reg_pp3_iter1_krnl_sobel_rowbuf2_addr_reg_71422.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_2) + sc_biguint<32>(ap_pipeline_reg_pp3_iter1_krnl_sobel_rowbuf2_addr_reg_71422.read()));
}

void krnl_sobel::thread_tmp_930_fu_27365_p3() {
    tmp_930_fu_27365_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(55, 55);
}

void krnl_sobel::thread_tmp_931_fu_50469_p3() {
    tmp_931_fu_50469_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(27, 27);
}

void krnl_sobel::thread_tmp_932_fu_27373_p3() {
    tmp_932_fu_27373_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(54, 54);
}

void krnl_sobel::thread_tmp_933_fu_50477_p3() {
    tmp_933_fu_50477_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(26, 26);
}

void krnl_sobel::thread_tmp_934_fu_27381_p3() {
    tmp_934_fu_27381_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(53, 53);
}

void krnl_sobel::thread_tmp_935_fu_50485_p3() {
    tmp_935_fu_50485_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(25, 25);
}

void krnl_sobel::thread_tmp_936_fu_27389_p3() {
    tmp_936_fu_27389_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(52, 52);
}

void krnl_sobel::thread_tmp_937_fu_50493_p3() {
    tmp_937_fu_50493_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(24, 24);
}

void krnl_sobel::thread_tmp_938_fu_27397_p3() {
    tmp_938_fu_27397_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(51, 51);
}

void krnl_sobel::thread_tmp_939_fu_50501_p3() {
    tmp_939_fu_50501_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(23, 23);
}

void krnl_sobel::thread_tmp_93_fu_24353_p1() {
    tmp_93_fu_24353_p1 = esl_sext<64,32>(tmp_92_fu_24348_p2.read());
}

void krnl_sobel::thread_tmp_940_fu_27405_p3() {
    tmp_940_fu_27405_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(50, 50);
}

void krnl_sobel::thread_tmp_941_fu_50509_p3() {
    tmp_941_fu_50509_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(22, 22);
}

void krnl_sobel::thread_tmp_942_fu_27413_p3() {
    tmp_942_fu_27413_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(49, 49);
}

void krnl_sobel::thread_tmp_943_fu_50517_p3() {
    tmp_943_fu_50517_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(21, 21);
}

void krnl_sobel::thread_tmp_944_fu_27421_p3() {
    tmp_944_fu_27421_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(48, 48);
}

void krnl_sobel::thread_tmp_945_fu_50525_p3() {
    tmp_945_fu_50525_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(20, 20);
}

void krnl_sobel::thread_tmp_946_fu_27429_p3() {
    tmp_946_fu_27429_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(47, 47);
}

void krnl_sobel::thread_tmp_947_fu_50533_p3() {
    tmp_947_fu_50533_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(19, 19);
}

void krnl_sobel::thread_tmp_948_fu_27437_p3() {
    tmp_948_fu_27437_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(46, 46);
}

void krnl_sobel::thread_tmp_949_fu_50541_p3() {
    tmp_949_fu_50541_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(18, 18);
}

void krnl_sobel::thread_tmp_94_fu_24358_p2() {
    tmp_94_fu_24358_p2 = (!ap_const_lv32_3.is_01() || !ap_pipeline_reg_pp3_iter1_krnl_sobel_rowbuf2_addr_reg_71422.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_3) + sc_biguint<32>(ap_pipeline_reg_pp3_iter1_krnl_sobel_rowbuf2_addr_reg_71422.read()));
}

void krnl_sobel::thread_tmp_950_fu_27445_p3() {
    tmp_950_fu_27445_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(45, 45);
}

void krnl_sobel::thread_tmp_951_fu_50549_p3() {
    tmp_951_fu_50549_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(17, 17);
}

void krnl_sobel::thread_tmp_952_fu_27453_p3() {
    tmp_952_fu_27453_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(44, 44);
}

void krnl_sobel::thread_tmp_953_fu_50557_p3() {
    tmp_953_fu_50557_p3 = p_143_reg2mem615_0_i_i_4_reg_13926.read().range(16, 16);
}

void krnl_sobel::thread_tmp_954_fu_27461_p3() {
    tmp_954_fu_27461_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(43, 43);
}

void krnl_sobel::thread_tmp_955_fu_50601_p3() {
    tmp_955_fu_50601_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(61, 61);
}

void krnl_sobel::thread_tmp_956_fu_27469_p3() {
    tmp_956_fu_27469_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(42, 42);
}

void krnl_sobel::thread_tmp_957_fu_50609_p3() {
    tmp_957_fu_50609_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(60, 60);
}

void krnl_sobel::thread_tmp_958_fu_27477_p3() {
    tmp_958_fu_27477_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(41, 41);
}

void krnl_sobel::thread_tmp_959_fu_50617_p3() {
    tmp_959_fu_50617_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(59, 59);
}

void krnl_sobel::thread_tmp_95_fu_24363_p1() {
    tmp_95_fu_24363_p1 = esl_sext<64,32>(tmp_94_fu_24358_p2.read());
}

void krnl_sobel::thread_tmp_960_fu_27485_p3() {
    tmp_960_fu_27485_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(40, 40);
}

void krnl_sobel::thread_tmp_961_fu_50625_p3() {
    tmp_961_fu_50625_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(58, 58);
}

void krnl_sobel::thread_tmp_962_fu_27493_p3() {
    tmp_962_fu_27493_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(39, 39);
}

void krnl_sobel::thread_tmp_963_fu_50633_p3() {
    tmp_963_fu_50633_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(57, 57);
}

void krnl_sobel::thread_tmp_964_fu_27501_p3() {
    tmp_964_fu_27501_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(38, 38);
}

void krnl_sobel::thread_tmp_965_fu_50641_p3() {
    tmp_965_fu_50641_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(56, 56);
}

void krnl_sobel::thread_tmp_966_fu_27509_p3() {
    tmp_966_fu_27509_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(37, 37);
}

void krnl_sobel::thread_tmp_967_fu_50649_p3() {
    tmp_967_fu_50649_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(55, 55);
}

void krnl_sobel::thread_tmp_968_fu_27517_p3() {
    tmp_968_fu_27517_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(36, 36);
}

void krnl_sobel::thread_tmp_969_fu_50657_p3() {
    tmp_969_fu_50657_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(54, 54);
}

void krnl_sobel::thread_tmp_96_fu_24407_p1() {
    tmp_96_fu_24407_p1 = esl_sext<64,32>(done_cnt4_reg_71455.read());
}

void krnl_sobel::thread_tmp_970_fu_27525_p3() {
    tmp_970_fu_27525_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(35, 35);
}

void krnl_sobel::thread_tmp_971_fu_50665_p3() {
    tmp_971_fu_50665_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(53, 53);
}

void krnl_sobel::thread_tmp_972_fu_27533_p3() {
    tmp_972_fu_27533_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(34, 34);
}

void krnl_sobel::thread_tmp_973_fu_50673_p3() {
    tmp_973_fu_50673_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(52, 52);
}

void krnl_sobel::thread_tmp_974_fu_27541_p3() {
    tmp_974_fu_27541_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(33, 33);
}

void krnl_sobel::thread_tmp_975_fu_50681_p3() {
    tmp_975_fu_50681_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(51, 51);
}

void krnl_sobel::thread_tmp_976_fu_27549_p3() {
    tmp_976_fu_27549_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(32, 32);
}

void krnl_sobel::thread_tmp_977_fu_50689_p3() {
    tmp_977_fu_50689_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(50, 50);
}

void krnl_sobel::thread_tmp_978_fu_27557_p3() {
    tmp_978_fu_27557_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(31, 31);
}

void krnl_sobel::thread_tmp_979_fu_50697_p3() {
    tmp_979_fu_50697_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(49, 49);
}

void krnl_sobel::thread_tmp_97_fu_47159_p3() {
    tmp_97_fu_47159_p3 = esl_concat<2,3>(tmp_5_reg_70799.read(), ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_980_fu_27565_p3() {
    tmp_980_fu_27565_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(30, 30);
}

void krnl_sobel::thread_tmp_981_fu_50705_p3() {
    tmp_981_fu_50705_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(48, 48);
}

void krnl_sobel::thread_tmp_982_fu_27573_p3() {
    tmp_982_fu_27573_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(29, 29);
}

void krnl_sobel::thread_tmp_983_fu_50713_p3() {
    tmp_983_fu_50713_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(47, 47);
}

void krnl_sobel::thread_tmp_984_fu_27581_p3() {
    tmp_984_fu_27581_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(28, 28);
}

void krnl_sobel::thread_tmp_985_fu_50721_p3() {
    tmp_985_fu_50721_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(46, 46);
}

void krnl_sobel::thread_tmp_986_fu_27589_p3() {
    tmp_986_fu_27589_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(27, 27);
}

void krnl_sobel::thread_tmp_987_fu_50729_p3() {
    tmp_987_fu_50729_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(45, 45);
}

void krnl_sobel::thread_tmp_988_fu_27597_p3() {
    tmp_988_fu_27597_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(26, 26);
}

void krnl_sobel::thread_tmp_989_fu_50737_p3() {
    tmp_989_fu_50737_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(44, 44);
}

void krnl_sobel::thread_tmp_98_fu_24416_p2() {
    tmp_98_fu_24416_p2 = (!done_cnt4_reg_71455.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt4_reg_71455.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void krnl_sobel::thread_tmp_990_fu_27605_p3() {
    tmp_990_fu_27605_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(25, 25);
}

void krnl_sobel::thread_tmp_991_fu_50745_p3() {
    tmp_991_fu_50745_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(43, 43);
}

void krnl_sobel::thread_tmp_992_fu_27613_p3() {
    tmp_992_fu_27613_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(24, 24);
}

void krnl_sobel::thread_tmp_993_fu_50753_p3() {
    tmp_993_fu_50753_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(42, 42);
}

void krnl_sobel::thread_tmp_994_fu_27621_p3() {
    tmp_994_fu_27621_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(23, 23);
}

void krnl_sobel::thread_tmp_995_fu_50761_p3() {
    tmp_995_fu_50761_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(41, 41);
}

void krnl_sobel::thread_tmp_996_fu_27629_p3() {
    tmp_996_fu_27629_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(22, 22);
}

void krnl_sobel::thread_tmp_997_fu_50769_p3() {
    tmp_997_fu_50769_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(40, 40);
}

void krnl_sobel::thread_tmp_998_fu_27637_p3() {
    tmp_998_fu_27637_p3 = p_164_reg2mem697_0_i_i_5_reg_4065.read().range(21, 21);
}

void krnl_sobel::thread_tmp_999_fu_50777_p3() {
    tmp_999_fu_50777_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(39, 39);
}

void krnl_sobel::thread_tmp_99_fu_24421_p1() {
    tmp_99_fu_24421_p1 = esl_sext<64,32>(tmp_98_fu_24416_p2.read());
}

void krnl_sobel::thread_tmp_9_cast_fu_23378_p1() {
    tmp_9_cast_fu_23378_p1 = esl_zext<32,3>(tmp_9_fu_23373_p2.read());
}

void krnl_sobel::thread_tmp_9_fu_23373_p2() {
    tmp_9_fu_23373_p2 = (prealign_rd_cnt_reg_70850.read() & tmp_8_cast_fu_23365_p3.read());
}

void krnl_sobel::thread_tmp_cast2_fu_23661_p1() {
    tmp_cast2_fu_23661_p1 = esl_zext<32,2>(tmp_5_reg_70799.read());
}

void krnl_sobel::thread_tmp_cast_21_fu_23664_p1() {
    tmp_cast_21_fu_23664_p1 = esl_zext<3,2>(tmp_5_reg_70799.read());
}

void krnl_sobel::thread_tmp_cast_fu_23210_p1() {
    tmp_cast_fu_23210_p1 = esl_zext<63,62>(tmp_fu_23196_p4.read());
}

void krnl_sobel::thread_tmp_fu_23196_p4() {
    tmp_fu_23196_p4 = in_pixels.read().range(63, 2);
}

void krnl_sobel::thread_tmp_s_fu_23327_p1() {
    tmp_s_fu_23327_p1 = esl_sext<62,30>(tmp_4_fu_23317_p4.read());
}

void krnl_sobel::thread_ux_i_i_i_i24_i_i_1_cast_cast_fu_69816_p1() {
    ux_i_i_i_i24_i_i_1_cast_cast_fu_69816_p1 = esl_zext<63,62>(ux_i_i_i_i24_i_i_1_reg_22713.read());
}

void krnl_sobel::thread_ux_i_i_i_i_i_i_1_cast_cast_fu_46520_p1() {
    ux_i_i_i_i_i_i_1_cast_cast_fu_46520_p1 = esl_zext<63,62>(ux_i_i_i_i_i_i_1_reg_12643.read());
}

void krnl_sobel::thread_wr_cnt_burst1_cast_fu_70419_p1() {
    wr_cnt_burst1_cast_fu_70419_p1 = esl_zext<31,30>(wr_cnt_burst1_fu_70405_p4.read());
}

void krnl_sobel::thread_wr_cnt_burst1_fu_70405_p4() {
    wr_cnt_burst1_fu_70405_p4 = buffer_cnt_dec4_fu_70400_p2.read().range(31, 2);
}

void krnl_sobel::thread_wr_cnt_burst_cast_fu_23401_p1() {
    wr_cnt_burst_cast_fu_23401_p1 = esl_zext<31,30>(wr_cnt_burst_fu_23387_p4.read());
}

void krnl_sobel::thread_wr_cnt_burst_fu_23387_p4() {
    wr_cnt_burst_fu_23387_p4 = buffer_cnt_dec_fu_23382_p2.read().range(31, 2);
}

void krnl_sobel::thread_write_cnt_dec1_fu_23870_p2() {
    write_cnt_dec1_fu_23870_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !ap_const_lv32_FFFFFFFE.is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) + sc_bigint<32>(ap_const_lv32_FFFFFFFE));
}

void krnl_sobel::thread_write_cnt_dec2_fu_23884_p2() {
    write_cnt_dec2_fu_23884_p2 = (!szrow_0_reg2mem_0_i_i_reg_70759.read().is_01() || !ap_const_lv32_FFFFFFFD.is_01())? sc_lv<32>(): (sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()) + sc_bigint<32>(ap_const_lv32_FFFFFFFD));
}

void krnl_sobel::thread_write_cnt_dec4_fu_24057_p2() {
    write_cnt_dec4_fu_24057_p2 = (!ap_const_lv32_FFFFFFFE.is_01() || !szrow_0_reg2mem_0_i_i_reg_70759.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFE) + sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()));
}

void krnl_sobel::thread_write_cnt_dec5_fu_24062_p2() {
    write_cnt_dec5_fu_24062_p2 = (!ap_const_lv32_FFFFFFFD.is_01() || !szrow_0_reg2mem_0_i_i_reg_70759.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFD) + sc_bigint<32>(szrow_0_reg2mem_0_i_i_reg_70759.read()));
}

void krnl_sobel::thread_x4_0_reg2mem639_0_i_i_cast_fu_47727_p1() {
    x4_0_reg2mem639_0_i_i_cast_fu_47727_p1 = esl_zext<32,31>(x4_0_reg2mem639_0_i_i_reg_12926.read());
}

void krnl_sobel::thread_x_0_reg2mem721_0_i_i_cast_fu_24441_p1() {
    x_0_reg2mem721_0_i_i_cast_fu_24441_p1 = esl_zext<32,31>(x_0_reg2mem721_0_i_i_reg_2857.read());
}

void krnl_sobel::thread_x_i_i5_i_i_i42_i_i_fu_70179_p1() {
    x_i_i5_i_i_i42_i_i_fu_70179_p1 = tmp_358_cast_fu_70175_p1.read();
}

void krnl_sobel::thread_x_i_i5_i_i_i_i_i_fu_46883_p1() {
    x_i_i5_i_i_i_i_i_fu_46883_p1 = tmp_292_cast_fu_46879_p1.read();
}

void krnl_sobel::thread_x_i_i8_i_i_i23_i_i_fu_70024_p1() {
    x_i_i8_i_i_i23_i_i_fu_70024_p1 = tmp_350_cast_fu_70020_p1.read();
}

void krnl_sobel::thread_x_i_i8_i_i_i_i_i_fu_46728_p1() {
    x_i_i8_i_i_i_i_i_fu_46728_p1 = tmp_235_cast_fu_46724_p1.read();
}

void krnl_sobel::thread_x_i_i_i_i55_i_i_assign_1_fu_70203_p1() {
    x_i_i_i_i55_i_i_assign_1_fu_70203_p1 = tmp_4927_fu_70194_p4.read();
}

void krnl_sobel::thread_x_i_i_i_i55_i_i_fu_70183_p3() {
    x_i_i_i_i55_i_i_fu_70183_p3 = (!or_cond3_fu_70131_p2.read()[0].is_01())? sc_lv<32>(): ((or_cond3_fu_70131_p2.read()[0].to_bool())? x_i_i8_i_i_i23_i_i_reg_89436.read(): x_i_i5_i_i_i42_i_i_fu_70179_p1.read());
}

void krnl_sobel::thread_x_i_i_i_i_i_i_assign_1_fu_46907_p1() {
    x_i_i_i_i_i_i_assign_1_fu_46907_p1 = tmp_4801_fu_46898_p4.read();
}

void krnl_sobel::thread_x_i_i_i_i_i_i_fu_46887_p3() {
    x_i_i_i_i_i_i_fu_46887_p3 = (!or_cond_32_fu_46835_p2.read()[0].is_01())? sc_lv<32>(): ((or_cond_32_fu_46835_p2.read()[0].to_bool())? x_i_i8_i_i_i_i_i_reg_80287.read(): x_i_i5_i_i_i_i_i_fu_46883_p1.read());
}

void krnl_sobel::thread_xe_i_i_i70_0_reg2mem_0_i_i_fu_67179_p2() {
    xe_i_i_i70_0_reg2mem_0_i_i_fu_67179_p2 = (!ap_const_lv9_182.is_01() || !tmp_219_reg_81089.read().is_01())? sc_lv<9>(): (sc_bigint<9>(ap_const_lv9_182) + sc_biguint<9>(tmp_219_reg_81089.read()));
}

void krnl_sobel::thread_xe_i_i_i_0_reg2mem_0_i_i_fu_43883_p2() {
    xe_i_i_i_0_reg2mem_0_i_i_fu_43883_p2 = (!ap_const_lv9_182.is_01() || !tmp_137_reg_71875.read().is_01())? sc_lv<9>(): (sc_bigint<9>(ap_const_lv9_182) + sc_biguint<9>(tmp_137_reg_71875.read()));
}

void krnl_sobel::thread_y1_0_reg2mem727_0_i_i_cast_fu_24090_p1() {
    y1_0_reg2mem727_0_i_i_cast_fu_24090_p1 = esl_zext<32,31>(y1_0_reg2mem727_0_i_i_reg_2779.read());
}

void krnl_sobel::thread_y3_0_reg2mem641_0_i_i_cast_fu_47358_p1() {
    y3_0_reg2mem641_0_i_i_cast_fu_47358_p1 = esl_zext<32,31>(y3_0_reg2mem641_0_i_i_reg_12848.read());
}

void krnl_sobel::thread_y_0_reg2mem737_0_i_i_cast_fu_23259_p1() {
    y_0_reg2mem737_0_i_i_cast_fu_23259_p1 = esl_zext<32,31>(y_0_reg2mem737_0_i_i_reg_2608.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_10_fu_67939_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_10_fu_67939_p3 = (!tmp_4847_fu_67916_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4847_fu_67916_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_45_reg_88760.read(): p_reg2mem231_0_i_i_10_fu_67927_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_11_fu_67992_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_11_fu_67992_p3 = (!tmp_4849_fu_67969_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4849_fu_67969_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_10_reg_88777.read(): p_reg2mem231_0_i_i_11_fu_67980_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_12_fu_68045_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_12_fu_68045_p3 = (!tmp_4851_fu_68022_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4851_fu_68022_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_11_reg_88794.read(): p_reg2mem231_0_i_i_12_fu_68033_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_13_fu_68098_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_13_fu_68098_p3 = (!tmp_4853_fu_68075_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4853_fu_68075_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_12_reg_88811.read(): p_reg2mem231_0_i_i_13_fu_68086_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_14_fu_68151_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_14_fu_68151_p3 = (!tmp_4855_fu_68128_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4855_fu_68128_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_13_reg_88828.read(): p_reg2mem231_0_i_i_14_fu_68139_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_15_fu_68204_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_15_fu_68204_p3 = (!tmp_4857_fu_68181_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4857_fu_68181_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_14_reg_88845.read(): p_reg2mem231_0_i_i_15_fu_68192_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_16_fu_68257_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_16_fu_68257_p3 = (!tmp_4859_fu_68234_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4859_fu_68234_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_15_reg_88862.read(): p_reg2mem231_0_i_i_16_fu_68245_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_17_fu_68310_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_17_fu_68310_p3 = (!tmp_4861_fu_68287_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4861_fu_68287_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_16_reg_88879.read(): p_reg2mem231_0_i_i_17_fu_68298_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_18_fu_68363_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_18_fu_68363_p3 = (!tmp_4863_fu_68340_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4863_fu_68340_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_17_reg_88896.read(): p_reg2mem231_0_i_i_18_fu_68351_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_19_fu_68416_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_19_fu_68416_p3 = (!tmp_4865_fu_68393_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4865_fu_68393_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_18_reg_88913.read(): p_reg2mem231_0_i_i_19_fu_68404_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_1_fu_67404_p1() {
    y_i16_i_i_i20_1_reg2mem597_0_i_1_fu_67404_p1 = esl_zext<62,61>(y_i16_i_i_i20_1_reg2mem597_0_i_fu_67396_p3.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_20_fu_68469_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_20_fu_68469_p3 = (!tmp_4867_fu_68446_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4867_fu_68446_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_19_reg_88930.read(): p_reg2mem231_0_i_i_20_fu_68457_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_21_fu_68522_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_21_fu_68522_p3 = (!tmp_4869_fu_68499_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4869_fu_68499_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_20_reg_88947.read(): p_reg2mem231_0_i_i_21_fu_68510_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_22_fu_68575_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_22_fu_68575_p3 = (!tmp_4871_fu_68552_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4871_fu_68552_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_21_reg_88964.read(): p_reg2mem231_0_i_i_22_fu_68563_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_23_fu_68628_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_23_fu_68628_p3 = (!tmp_4873_fu_68605_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4873_fu_68605_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_22_reg_88981.read(): p_reg2mem231_0_i_i_23_fu_68616_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_24_fu_68681_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_24_fu_68681_p3 = (!tmp_4875_fu_68658_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4875_fu_68658_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_23_reg_88998.read(): p_reg2mem231_0_i_i_24_fu_68669_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_25_fu_68734_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_25_fu_68734_p3 = (!tmp_4877_fu_68711_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4877_fu_68711_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_24_reg_89015.read(): p_reg2mem231_0_i_i_25_fu_68722_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_26_fu_68787_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_26_fu_68787_p3 = (!tmp_4879_fu_68764_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4879_fu_68764_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_25_reg_89032.read(): p_reg2mem231_0_i_i_26_fu_68775_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_27_fu_68840_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_27_fu_68840_p3 = (!tmp_4881_fu_68817_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4881_fu_68817_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_26_reg_89049.read(): p_reg2mem231_0_i_i_27_fu_68828_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_28_fu_68893_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_28_fu_68893_p3 = (!tmp_4883_fu_68870_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4883_fu_68870_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_27_reg_89066.read(): p_reg2mem231_0_i_i_28_fu_68881_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_29_fu_68946_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_29_fu_68946_p3 = (!tmp_4885_fu_68923_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4885_fu_68923_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_28_reg_89083.read(): p_reg2mem231_0_i_i_29_fu_68934_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_2_fu_67464_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_2_fu_67464_p3 = (!tmp_4829_reg_88615.read()[0].is_01())? sc_lv<62>(): ((tmp_4829_reg_88615.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_1_reg_88610.read(): p_reg2mem231_0_i_i_2_reg_88620.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_30_fu_68999_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_30_fu_68999_p3 = (!tmp_4887_fu_68976_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4887_fu_68976_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_29_reg_89100.read(): p_reg2mem231_0_i_i_30_fu_68987_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_31_fu_69052_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_31_fu_69052_p3 = (!tmp_4889_fu_69029_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4889_fu_69029_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_30_reg_89117.read(): p_reg2mem231_0_i_i_31_fu_69040_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_32_fu_69105_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_32_fu_69105_p3 = (!tmp_4891_fu_69082_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4891_fu_69082_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_31_reg_89134.read(): p_reg2mem231_0_i_i_32_fu_69093_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_33_fu_69158_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_33_fu_69158_p3 = (!tmp_4893_fu_69135_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4893_fu_69135_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_32_reg_89151.read(): p_reg2mem231_0_i_i_33_fu_69146_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_34_fu_69211_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_34_fu_69211_p3 = (!tmp_4895_fu_69188_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4895_fu_69188_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_33_reg_89168.read(): p_reg2mem231_0_i_i_34_fu_69199_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_35_fu_69264_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_35_fu_69264_p3 = (!tmp_4897_fu_69241_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4897_fu_69241_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_34_reg_89185.read(): p_reg2mem231_0_i_i_35_fu_69252_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_36_fu_69317_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_36_fu_69317_p3 = (!tmp_4899_fu_69294_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4899_fu_69294_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_35_reg_89202.read(): p_reg2mem231_0_i_i_36_fu_69305_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_37_fu_69370_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_37_fu_69370_p3 = (!tmp_4901_fu_69347_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4901_fu_69347_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_36_reg_89219.read(): p_reg2mem231_0_i_i_37_fu_69358_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_38_fu_69423_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_38_fu_69423_p3 = (!tmp_4903_fu_69400_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4903_fu_69400_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_37_reg_89236.read(): p_reg2mem231_0_i_i_38_fu_69411_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_39_fu_69476_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_39_fu_69476_p3 = (!tmp_4905_fu_69453_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4905_fu_69453_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_38_reg_89253.read(): p_reg2mem231_0_i_i_39_fu_69464_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_3_fu_67517_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_3_fu_67517_p3 = (!tmp_4831_reg_88636.read()[0].is_01())? sc_lv<62>(): ((tmp_4831_reg_88636.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_2_reg_88631.read(): p_reg2mem231_0_i_i_3_reg_88641.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_40_fu_69529_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_40_fu_69529_p3 = (!tmp_4907_fu_69506_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4907_fu_69506_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_39_reg_89270.read(): p_reg2mem231_0_i_i_40_fu_69517_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_41_fu_69582_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_41_fu_69582_p3 = (!tmp_4909_fu_69559_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4909_fu_69559_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_40_reg_89287.read(): p_reg2mem231_0_i_i_41_fu_69570_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_42_fu_69635_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_42_fu_69635_p3 = (!tmp_4911_fu_69612_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4911_fu_69612_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_41_reg_89304.read(): p_reg2mem231_0_i_i_42_fu_69623_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_43_fu_69677_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_43_fu_69677_p3 = (!tmp_4913_fu_69661_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4913_fu_69661_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_42_reg_89321.read(): p_reg2mem231_0_i_i_43_fu_69672_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_44_fu_69729_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_44_fu_69729_p3 = (!tmp_4914_fu_69713_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4914_fu_69713_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_43_reg_89342.read(): p_reg2mem231_0_i_i_44_fu_69724_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_45_fu_67886_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_45_fu_67886_p3 = (!tmp_4845_fu_67863_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4845_fu_67863_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_9_reg_88743.read(): p_reg2mem231_0_i_i_s_fu_67874_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_4_fu_67567_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_4_fu_67567_p3 = (!tmp_4833_fu_67532_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4833_fu_67532_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_3_fu_67517_p3.read(): p_reg2mem231_0_i_i_4_fu_67554_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_5_fu_67621_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_5_fu_67621_p3 = (!tmp_4835_fu_67598_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4835_fu_67598_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_4_reg_88658.read(): p_reg2mem231_0_i_i_5_fu_67609_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_6_fu_67674_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_6_fu_67674_p3 = (!tmp_4837_fu_67651_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4837_fu_67651_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_5_reg_88675.read(): p_reg2mem231_0_i_i_6_fu_67662_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_7_fu_67727_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_7_fu_67727_p3 = (!tmp_4839_fu_67704_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4839_fu_67704_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_6_reg_88692.read(): p_reg2mem231_0_i_i_7_fu_67715_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_8_fu_67780_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_8_fu_67780_p3 = (!tmp_4841_fu_67757_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4841_fu_67757_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_7_reg_88709.read(): p_reg2mem231_0_i_i_8_fu_67768_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_9_fu_67833_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_9_fu_67833_p3 = (!tmp_4843_fu_67810_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4843_fu_67810_p3.read()[0].to_bool())? y_i16_i_i_i20_1_reg2mem597_0_i_8_reg_88726.read(): p_reg2mem231_0_i_i_9_fu_67821_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i20_1_reg2mem597_0_i_fu_67396_p3() {
    y_i16_i_i_i20_1_reg2mem597_0_i_fu_67396_p3 = esl_concat<2,59>(tmp_436_fu_67389_p3.read(), p_reg2mem231_0_i_i_1_fu_67381_p3.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_10_fu_44636_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_10_fu_44636_p3 = (!tmp_4717_fu_44620_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4717_fu_44620_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_45_reg_79605.read(): p_reg2mem416_0_i_i_10_fu_44631_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_11_fu_44689_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_11_fu_44689_p3 = (!tmp_4719_fu_44673_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4719_fu_44673_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_10_reg_79622.read(): p_reg2mem416_0_i_i_11_fu_44684_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_12_fu_44742_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_12_fu_44742_p3 = (!tmp_4721_fu_44726_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4721_fu_44726_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_11_reg_79639.read(): p_reg2mem416_0_i_i_12_fu_44737_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_13_fu_44795_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_13_fu_44795_p3 = (!tmp_4723_fu_44779_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4723_fu_44779_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_12_reg_79656.read(): p_reg2mem416_0_i_i_13_fu_44790_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_14_fu_44848_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_14_fu_44848_p3 = (!tmp_4725_fu_44832_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4725_fu_44832_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_13_reg_79673.read(): p_reg2mem416_0_i_i_14_fu_44843_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_15_fu_44901_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_15_fu_44901_p3 = (!tmp_4727_fu_44885_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4727_fu_44885_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_14_reg_79690.read(): p_reg2mem416_0_i_i_15_fu_44896_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_16_fu_44954_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_16_fu_44954_p3 = (!tmp_4729_fu_44938_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4729_fu_44938_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_15_reg_79707.read(): p_reg2mem416_0_i_i_16_fu_44949_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_17_fu_45007_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_17_fu_45007_p3 = (!tmp_4731_fu_44991_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4731_fu_44991_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_16_reg_79724.read(): p_reg2mem416_0_i_i_17_fu_45002_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_18_fu_45060_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_18_fu_45060_p3 = (!tmp_4733_fu_45044_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4733_fu_45044_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_17_reg_79741.read(): p_reg2mem416_0_i_i_18_fu_45055_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_19_fu_45113_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_19_fu_45113_p3 = (!tmp_4735_fu_45097_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4735_fu_45097_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_18_reg_79758.read(): p_reg2mem416_0_i_i_19_fu_45108_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_1_fu_44097_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_1_fu_44097_p3 = esl_concat<2,59>(tmp_257_fu_44090_p3.read(), p_reg2mem416_0_i_i_1_fu_44082_p3.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_20_fu_45166_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_20_fu_45166_p3 = (!tmp_4737_fu_45150_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4737_fu_45150_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_19_reg_79775.read(): p_reg2mem416_0_i_i_20_fu_45161_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_21_fu_45219_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_21_fu_45219_p3 = (!tmp_4739_fu_45203_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4739_fu_45203_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_20_reg_79792.read(): p_reg2mem416_0_i_i_21_fu_45214_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_22_fu_45272_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_22_fu_45272_p3 = (!tmp_4741_fu_45256_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4741_fu_45256_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_21_reg_79809.read(): p_reg2mem416_0_i_i_22_fu_45267_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_23_fu_45325_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_23_fu_45325_p3 = (!tmp_4743_fu_45309_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4743_fu_45309_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_22_reg_79826.read(): p_reg2mem416_0_i_i_23_fu_45320_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_24_fu_45378_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_24_fu_45378_p3 = (!tmp_4745_fu_45362_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4745_fu_45362_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_23_reg_79843.read(): p_reg2mem416_0_i_i_24_fu_45373_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_25_fu_45431_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_25_fu_45431_p3 = (!tmp_4747_fu_45415_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4747_fu_45415_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_24_reg_79860.read(): p_reg2mem416_0_i_i_25_fu_45426_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_26_fu_45484_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_26_fu_45484_p3 = (!tmp_4749_fu_45468_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4749_fu_45468_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_25_reg_79877.read(): p_reg2mem416_0_i_i_26_fu_45479_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_27_fu_45537_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_27_fu_45537_p3 = (!tmp_4751_fu_45521_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4751_fu_45521_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_26_reg_79894.read(): p_reg2mem416_0_i_i_27_fu_45532_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_28_fu_45590_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_28_fu_45590_p3 = (!tmp_4753_fu_45574_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4753_fu_45574_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_27_reg_79911.read(): p_reg2mem416_0_i_i_28_fu_45585_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_29_fu_45643_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_29_fu_45643_p3 = (!tmp_4755_fu_45627_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4755_fu_45627_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_28_reg_79928.read(): p_reg2mem416_0_i_i_29_fu_45638_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_2_fu_44165_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_2_fu_44165_p3 = (!tmp_4699_reg_79466.read()[0].is_01())? sc_lv<62>(): ((tmp_4699_reg_79466.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_reg_79461.read(): p_reg2mem416_0_i_i_2_reg_79471.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_30_fu_45696_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_30_fu_45696_p3 = (!tmp_4757_fu_45680_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4757_fu_45680_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_29_reg_79945.read(): p_reg2mem416_0_i_i_30_fu_45691_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_31_fu_45749_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_31_fu_45749_p3 = (!tmp_4759_fu_45733_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4759_fu_45733_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_30_reg_79962.read(): p_reg2mem416_0_i_i_31_fu_45744_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_32_fu_45802_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_32_fu_45802_p3 = (!tmp_4761_fu_45786_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4761_fu_45786_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_31_reg_79979.read(): p_reg2mem416_0_i_i_32_fu_45797_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_33_fu_45855_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_33_fu_45855_p3 = (!tmp_4763_fu_45839_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4763_fu_45839_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_32_reg_79996.read(): p_reg2mem416_0_i_i_33_fu_45850_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_34_fu_45908_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_34_fu_45908_p3 = (!tmp_4765_fu_45892_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4765_fu_45892_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_33_reg_80013.read(): p_reg2mem416_0_i_i_34_fu_45903_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_35_fu_45961_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_35_fu_45961_p3 = (!tmp_4767_fu_45945_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4767_fu_45945_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_34_reg_80030.read(): p_reg2mem416_0_i_i_35_fu_45956_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_36_fu_46014_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_36_fu_46014_p3 = (!tmp_4769_fu_45998_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4769_fu_45998_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_35_reg_80047.read(): p_reg2mem416_0_i_i_36_fu_46009_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_37_fu_46067_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_37_fu_46067_p3 = (!tmp_4771_fu_46051_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4771_fu_46051_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_36_reg_80064.read(): p_reg2mem416_0_i_i_37_fu_46062_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_38_fu_46120_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_38_fu_46120_p3 = (!tmp_4773_fu_46104_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4773_fu_46104_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_37_reg_80081.read(): p_reg2mem416_0_i_i_38_fu_46115_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_39_fu_46173_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_39_fu_46173_p3 = (!tmp_4775_fu_46157_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4775_fu_46157_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_38_reg_80098.read(): p_reg2mem416_0_i_i_39_fu_46168_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_3_fu_44218_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_3_fu_44218_p3 = (!tmp_4701_reg_79487.read()[0].is_01())? sc_lv<62>(): ((tmp_4701_reg_79487.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_2_reg_79482.read(): p_reg2mem416_0_i_i_3_reg_79492.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_40_fu_46226_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_40_fu_46226_p3 = (!tmp_4777_fu_46210_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4777_fu_46210_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_39_reg_80115.read(): p_reg2mem416_0_i_i_40_fu_46221_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_41_fu_46279_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_41_fu_46279_p3 = (!tmp_4779_fu_46263_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4779_fu_46263_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_40_reg_80132.read(): p_reg2mem416_0_i_i_41_fu_46274_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_42_fu_46332_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_42_fu_46332_p3 = (!tmp_4781_fu_46316_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4781_fu_46316_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_41_reg_80149.read(): p_reg2mem416_0_i_i_42_fu_46327_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_43_fu_46381_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_43_fu_46381_p3 = (!tmp_4783_fu_46365_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4783_fu_46365_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_42_reg_80166.read(): p_reg2mem416_0_i_i_43_fu_46376_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_44_fu_46433_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_44_fu_46433_p3 = (!tmp_4784_fu_46417_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4784_fu_46417_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_43_reg_80193.read(): p_reg2mem416_0_i_i_44_fu_46428_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_45_fu_44583_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_45_fu_44583_p3 = (!tmp_4715_fu_44567_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4715_fu_44567_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_9_reg_79588.read(): p_reg2mem416_0_i_i_s_fu_44578_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_4_fu_44264_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_4_fu_44264_p3 = (!tmp_4703_fu_44236_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4703_fu_44236_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_3_fu_44218_p3.read(): p_reg2mem416_0_i_i_4_fu_44258_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_5_fu_44318_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_5_fu_44318_p3 = (!tmp_4705_fu_44302_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4705_fu_44302_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_4_reg_79503.read(): p_reg2mem416_0_i_i_5_fu_44313_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_6_fu_44371_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_6_fu_44371_p3 = (!tmp_4707_fu_44355_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4707_fu_44355_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_5_reg_79520.read(): p_reg2mem416_0_i_i_6_fu_44366_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_7_fu_44424_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_7_fu_44424_p3 = (!tmp_4709_fu_44408_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4709_fu_44408_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_6_reg_79537.read(): p_reg2mem416_0_i_i_7_fu_44419_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_8_fu_44477_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_8_fu_44477_p3 = (!tmp_4711_fu_44461_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4711_fu_44461_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_7_reg_79554.read(): p_reg2mem416_0_i_i_8_fu_44472_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_9_fu_44530_p3() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_9_fu_44530_p3 = (!tmp_4713_fu_44514_p3.read()[0].is_01())? sc_lv<62>(): ((tmp_4713_fu_44514_p3.read()[0].to_bool())? y_i16_i_i_i_1_reg2mem679_0_i_i_8_reg_79571.read(): p_reg2mem416_0_i_i_9_fu_44525_p2.read());
}

void krnl_sobel::thread_y_i16_i_i_i_1_reg2mem679_0_i_i_fu_44105_p1() {
    y_i16_i_i_i_1_reg2mem679_0_i_i_fu_44105_p1 = esl_zext<62,61>(y_i16_i_i_i_1_reg2mem679_0_i_i_1_fu_44097_p3.read());
}

}

