#include "krnl_sobel.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void krnl_sobel::thread_tmp_1024_fu_27777_p3() {
    tmp_1024_fu_27777_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1025_fu_50881_p3() {
    tmp_1025_fu_50881_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1026_fu_27785_p3() {
    tmp_1026_fu_27785_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1027_fu_50889_p3() {
    tmp_1027_fu_50889_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1028_fu_27793_p3() {
    tmp_1028_fu_27793_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1029_fu_50897_p3() {
    tmp_1029_fu_50897_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(24, 24);
}

void krnl_sobel::thread_tmp_102_fu_47223_p2() {
    tmp_102_fu_47223_p2 = (!p_ph12_reg_12777.read().is_01() || !tmp_45_reg_71181.read().is_01())? sc_lv<32>(): (sc_biguint<32>(p_ph12_reg_12777.read()) - sc_biguint<32>(tmp_45_reg_71181.read()));
}

void krnl_sobel::thread_tmp_1030_fu_27801_p3() {
    tmp_1030_fu_27801_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1031_fu_50905_p3() {
    tmp_1031_fu_50905_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1032_fu_27809_p3() {
    tmp_1032_fu_27809_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1033_fu_50913_p3() {
    tmp_1033_fu_50913_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1034_fu_27817_p3() {
    tmp_1034_fu_27817_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1035_fu_50921_p3() {
    tmp_1035_fu_50921_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1036_fu_27825_p3() {
    tmp_1036_fu_27825_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1037_fu_50929_p3() {
    tmp_1037_fu_50929_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1038_fu_27833_p3() {
    tmp_1038_fu_27833_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1039_fu_50937_p3() {
    tmp_1039_fu_50937_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(19, 19);
}

void krnl_sobel::thread_tmp_103_fu_24445_p2() {
    tmp_103_fu_24445_p2 = (!x_0_reg2mem721_0_i_i_cast_fu_24441_p1.read().is_01() || !tmp_62_reg_71292.read().is_01())? sc_lv<1>(): (sc_bigint<32>(x_0_reg2mem721_0_i_i_cast_fu_24441_p1.read()) < sc_bigint<32>(tmp_62_reg_71292.read()));
}

void krnl_sobel::thread_tmp_1040_fu_27841_p3() {
    tmp_1040_fu_27841_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1041_fu_50945_p3() {
    tmp_1041_fu_50945_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1042_fu_27849_p3() {
    tmp_1042_fu_27849_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1043_fu_50953_p3() {
    tmp_1043_fu_50953_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1044_fu_27857_p3() {
    tmp_1044_fu_27857_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1045_fu_50961_p3() {
    tmp_1045_fu_50961_p3 = p_143_reg2mem615_0_i_i_5_reg_14135.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1046_fu_27865_p3() {
    tmp_1046_fu_27865_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1047_fu_51006_p3() {
    tmp_1047_fu_51006_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1048_fu_27873_p3() {
    tmp_1048_fu_27873_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1049_fu_51014_p3() {
    tmp_1049_fu_51014_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1050_fu_27881_p3() {
    tmp_1050_fu_27881_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1051_fu_51022_p3() {
    tmp_1051_fu_51022_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1052_fu_27889_p3() {
    tmp_1052_fu_27889_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1053_fu_51030_p3() {
    tmp_1053_fu_51030_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1054_fu_27897_p3() {
    tmp_1054_fu_27897_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1055_fu_51038_p3() {
    tmp_1055_fu_51038_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1056_fu_27905_p3() {
    tmp_1056_fu_27905_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1057_fu_51046_p3() {
    tmp_1057_fu_51046_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1058_fu_27913_p3() {
    tmp_1058_fu_27913_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1059_fu_51054_p3() {
    tmp_1059_fu_51054_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(55, 55);
}

void krnl_sobel::thread_tmp_105_cast_fu_47166_p1() {
    tmp_105_cast_fu_47166_p1 = esl_zext<32,5>(tmp_97_fu_47159_p3.read());
}

void krnl_sobel::thread_tmp_105_fu_24450_p2() {
    tmp_105_fu_24450_p2 = (!ap_const_lv31_7FFFFFFF.is_01() || !x_0_reg2mem721_0_i_i_reg_2857.read().is_01())? sc_lv<31>(): (sc_bigint<31>(ap_const_lv31_7FFFFFFF) + sc_biguint<31>(x_0_reg2mem721_0_i_i_reg_2857.read()));
}

void krnl_sobel::thread_tmp_1060_fu_27921_p3() {
    tmp_1060_fu_27921_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1061_fu_51062_p3() {
    tmp_1061_fu_51062_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1062_fu_27929_p3() {
    tmp_1062_fu_27929_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1063_fu_51070_p3() {
    tmp_1063_fu_51070_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1064_fu_27937_p3() {
    tmp_1064_fu_27937_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1065_fu_51078_p3() {
    tmp_1065_fu_51078_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1066_fu_27945_p3() {
    tmp_1066_fu_27945_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1067_fu_51086_p3() {
    tmp_1067_fu_51086_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1068_fu_27953_p3() {
    tmp_1068_fu_27953_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1069_fu_51094_p3() {
    tmp_1069_fu_51094_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(50, 50);
}

void krnl_sobel::thread_tmp_106_fu_24474_p1() {
    tmp_106_fu_24474_p1 = esl_zext<64,31>(tmp_105_reg_71478.read());
}

void krnl_sobel::thread_tmp_1070_fu_27961_p3() {
    tmp_1070_fu_27961_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1071_fu_51102_p3() {
    tmp_1071_fu_51102_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1072_fu_27969_p3() {
    tmp_1072_fu_27969_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1073_fu_51110_p3() {
    tmp_1073_fu_51110_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1074_fu_27977_p3() {
    tmp_1074_fu_27977_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1075_fu_51118_p3() {
    tmp_1075_fu_51118_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1076_fu_27985_p3() {
    tmp_1076_fu_27985_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1077_fu_51126_p3() {
    tmp_1077_fu_51126_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1078_fu_27993_p3() {
    tmp_1078_fu_27993_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1079_fu_51134_p3() {
    tmp_1079_fu_51134_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(45, 45);
}

void krnl_sobel::thread_tmp_107_fu_24643_p3() {
    tmp_107_fu_24643_p3 = esl_concat<8,1>(phi_load1_reg_2880.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_tmp_1080_fu_28001_p3() {
    tmp_1080_fu_28001_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1081_fu_51142_p3() {
    tmp_1081_fu_51142_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1082_fu_28009_p3() {
    tmp_1082_fu_28009_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1083_fu_51150_p3() {
    tmp_1083_fu_51150_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1084_fu_28017_p3() {
    tmp_1084_fu_28017_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1085_fu_51158_p3() {
    tmp_1085_fu_51158_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1086_fu_28025_p3() {
    tmp_1086_fu_28025_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1087_fu_51166_p3() {
    tmp_1087_fu_51166_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1088_fu_28033_p3() {
    tmp_1088_fu_28033_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1089_fu_51174_p3() {
    tmp_1089_fu_51174_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(40, 40);
}

void krnl_sobel::thread_tmp_108_fu_24924_p1() {
    tmp_108_fu_24924_p1 = esl_zext<32,16>(p_reg2mem500_0_i_i_2_cast_fu_24918_p1.read());
}

void krnl_sobel::thread_tmp_1090_fu_28041_p3() {
    tmp_1090_fu_28041_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1091_fu_51182_p3() {
    tmp_1091_fu_51182_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1092_fu_28049_p3() {
    tmp_1092_fu_28049_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1093_fu_51190_p3() {
    tmp_1093_fu_51190_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1094_fu_28057_p3() {
    tmp_1094_fu_28057_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1095_fu_51198_p3() {
    tmp_1095_fu_51198_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1096_fu_28065_p3() {
    tmp_1096_fu_28065_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1097_fu_51206_p3() {
    tmp_1097_fu_51206_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1098_fu_28073_p3() {
    tmp_1098_fu_28073_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1099_fu_51214_p3() {
    tmp_1099_fu_51214_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(35, 35);
}

void krnl_sobel::thread_tmp_10_cast1_fu_23472_p1() {
    tmp_10_cast1_fu_23472_p1 = esl_zext<31,1>(p_ph2_reg_2619.read());
}

void krnl_sobel::thread_tmp_10_cast_fu_23449_p1() {
    tmp_10_cast_fu_23449_p1 = esl_zext<63,1>(p_ph2_reg_2619.read());
}

void krnl_sobel::thread_tmp_10_fu_23335_p1() {
    tmp_10_fu_23335_p1 = esl_sext<62,30>(tmp_8_reg_70845.read());
}

void krnl_sobel::thread_tmp_1100_fu_28081_p3() {
    tmp_1100_fu_28081_p3 = p_164_reg2mem697_0_i_i_6_reg_4274.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1101_fu_51222_p3() {
    tmp_1101_fu_51222_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1102_fu_28125_p3() {
    tmp_1102_fu_28125_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1103_fu_51230_p3() {
    tmp_1103_fu_51230_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1104_fu_28133_p3() {
    tmp_1104_fu_28133_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1105_fu_51238_p3() {
    tmp_1105_fu_51238_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1106_fu_28141_p3() {
    tmp_1106_fu_28141_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1107_fu_51246_p3() {
    tmp_1107_fu_51246_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1108_fu_28149_p3() {
    tmp_1108_fu_28149_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1109_fu_51254_p3() {
    tmp_1109_fu_51254_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(30, 30);
}

void krnl_sobel::thread_tmp_110_cast1_fu_47219_p1() {
    tmp_110_cast1_fu_47219_p1 = esl_zext<31,1>(p_ph11_reg_12735.read());
}

void krnl_sobel::thread_tmp_110_cast_fu_47200_p1() {
    tmp_110_cast_fu_47200_p1 = esl_zext<63,1>(p_ph11_phi_fu_12740_p8.read());
}

void krnl_sobel::thread_tmp_1110_fu_28157_p3() {
    tmp_1110_fu_28157_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1111_fu_51262_p3() {
    tmp_1111_fu_51262_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1112_fu_28165_p3() {
    tmp_1112_fu_28165_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1113_fu_51270_p3() {
    tmp_1113_fu_51270_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1114_fu_28173_p3() {
    tmp_1114_fu_28173_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1115_fu_51278_p3() {
    tmp_1115_fu_51278_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1116_fu_28181_p3() {
    tmp_1116_fu_28181_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1117_fu_51286_p3() {
    tmp_1117_fu_51286_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1118_fu_28189_p3() {
    tmp_1118_fu_28189_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1119_fu_51294_p3() {
    tmp_1119_fu_51294_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(25, 25);
}

void krnl_sobel::thread_tmp_111_fu_24928_p1() {
    tmp_111_fu_24928_p1 = esl_zext<32,16>(p_reg2mem498_0_i_i_2_cast_fu_24921_p1.read());
}

void krnl_sobel::thread_tmp_1120_fu_28197_p3() {
    tmp_1120_fu_28197_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1121_fu_51302_p3() {
    tmp_1121_fu_51302_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1122_fu_28205_p3() {
    tmp_1122_fu_28205_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1123_fu_51310_p3() {
    tmp_1123_fu_51310_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1124_fu_28213_p3() {
    tmp_1124_fu_28213_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1125_fu_51318_p3() {
    tmp_1125_fu_51318_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1126_fu_28221_p3() {
    tmp_1126_fu_28221_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1127_fu_51326_p3() {
    tmp_1127_fu_51326_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1128_fu_28229_p3() {
    tmp_1128_fu_28229_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1129_fu_51334_p3() {
    tmp_1129_fu_51334_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1130_fu_28237_p3() {
    tmp_1130_fu_28237_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1131_fu_51342_p3() {
    tmp_1131_fu_51342_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1132_fu_28245_p3() {
    tmp_1132_fu_28245_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1133_fu_51350_p3() {
    tmp_1133_fu_51350_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1134_fu_28253_p3() {
    tmp_1134_fu_28253_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1135_fu_51358_p3() {
    tmp_1135_fu_51358_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1136_fu_28261_p3() {
    tmp_1136_fu_28261_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1137_fu_51366_p3() {
    tmp_1137_fu_51366_p3 = p_143_reg2mem615_0_i_i_6_reg_14344.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1138_fu_28269_p3() {
    tmp_1138_fu_28269_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1139_fu_51411_p3() {
    tmp_1139_fu_51411_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(61, 61);
}

void krnl_sobel::thread_tmp_113_fu_23944_p1() {
    tmp_113_fu_23944_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1140_fu_28277_p3() {
    tmp_1140_fu_28277_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1141_fu_51419_p3() {
    tmp_1141_fu_51419_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1142_fu_28285_p3() {
    tmp_1142_fu_28285_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1143_fu_51427_p3() {
    tmp_1143_fu_51427_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1144_fu_28293_p3() {
    tmp_1144_fu_28293_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1145_fu_51435_p3() {
    tmp_1145_fu_51435_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1146_fu_28301_p3() {
    tmp_1146_fu_28301_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1147_fu_51443_p3() {
    tmp_1147_fu_51443_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1148_fu_28309_p3() {
    tmp_1148_fu_28309_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1149_fu_51451_p3() {
    tmp_1149_fu_51451_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(56, 56);
}

void krnl_sobel::thread_tmp_114_fu_47251_p1() {
    tmp_114_fu_47251_p1 = esl_sext<64,32>(krnl_sobel_rowbuf1_addr1_reg_80445.read());
}

void krnl_sobel::thread_tmp_1150_fu_28317_p3() {
    tmp_1150_fu_28317_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1151_fu_51459_p3() {
    tmp_1151_fu_51459_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1152_fu_28325_p3() {
    tmp_1152_fu_28325_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1153_fu_51467_p3() {
    tmp_1153_fu_51467_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1154_fu_28333_p3() {
    tmp_1154_fu_28333_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1155_fu_51475_p3() {
    tmp_1155_fu_51475_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1156_fu_28341_p3() {
    tmp_1156_fu_28341_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1157_fu_51483_p3() {
    tmp_1157_fu_51483_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1158_fu_28349_p3() {
    tmp_1158_fu_28349_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1159_fu_51491_p3() {
    tmp_1159_fu_51491_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(51, 51);
}

void krnl_sobel::thread_tmp_115_fu_47255_p2() {
    tmp_115_fu_47255_p2 = (!ap_const_lv32_1.is_01() || !krnl_sobel_rowbuf1_addr1_reg_80445.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_1) + sc_biguint<32>(krnl_sobel_rowbuf1_addr1_reg_80445.read()));
}

void krnl_sobel::thread_tmp_1160_fu_28357_p3() {
    tmp_1160_fu_28357_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1161_fu_51499_p3() {
    tmp_1161_fu_51499_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1162_fu_28365_p3() {
    tmp_1162_fu_28365_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1163_fu_51507_p3() {
    tmp_1163_fu_51507_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1164_fu_28373_p3() {
    tmp_1164_fu_28373_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1165_fu_51515_p3() {
    tmp_1165_fu_51515_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1166_fu_28381_p3() {
    tmp_1166_fu_28381_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1167_fu_51523_p3() {
    tmp_1167_fu_51523_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1168_fu_28389_p3() {
    tmp_1168_fu_28389_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1169_fu_51531_p3() {
    tmp_1169_fu_51531_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(46, 46);
}

void krnl_sobel::thread_tmp_116_fu_47260_p1() {
    tmp_116_fu_47260_p1 = esl_sext<64,32>(tmp_115_fu_47255_p2.read());
}

void krnl_sobel::thread_tmp_1170_fu_28397_p3() {
    tmp_1170_fu_28397_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1171_fu_51539_p3() {
    tmp_1171_fu_51539_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1172_fu_28405_p3() {
    tmp_1172_fu_28405_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1173_fu_51547_p3() {
    tmp_1173_fu_51547_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1174_fu_28413_p3() {
    tmp_1174_fu_28413_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1175_fu_51555_p3() {
    tmp_1175_fu_51555_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1176_fu_28421_p3() {
    tmp_1176_fu_28421_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1177_fu_51563_p3() {
    tmp_1177_fu_51563_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1178_fu_28429_p3() {
    tmp_1178_fu_28429_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1179_fu_51571_p3() {
    tmp_1179_fu_51571_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(41, 41);
}

void krnl_sobel::thread_tmp_117_fu_47265_p2() {
    tmp_117_fu_47265_p2 = (!ap_const_lv32_2.is_01() || !ap_pipeline_reg_pp5_iter1_krnl_sobel_rowbuf1_addr1_reg_80445.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_2) + sc_biguint<32>(ap_pipeline_reg_pp5_iter1_krnl_sobel_rowbuf1_addr1_reg_80445.read()));
}

void krnl_sobel::thread_tmp_1180_fu_28437_p3() {
    tmp_1180_fu_28437_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1181_fu_51579_p3() {
    tmp_1181_fu_51579_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1182_fu_28445_p3() {
    tmp_1182_fu_28445_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1183_fu_51587_p3() {
    tmp_1183_fu_51587_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1184_fu_28453_p3() {
    tmp_1184_fu_28453_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1185_fu_51595_p3() {
    tmp_1185_fu_51595_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1186_fu_28461_p3() {
    tmp_1186_fu_28461_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1187_fu_51603_p3() {
    tmp_1187_fu_51603_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1188_fu_28469_p3() {
    tmp_1188_fu_28469_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1189_fu_51611_p3() {
    tmp_1189_fu_51611_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(36, 36);
}

void krnl_sobel::thread_tmp_118_fu_47270_p1() {
    tmp_118_fu_47270_p1 = esl_sext<64,32>(tmp_117_fu_47265_p2.read());
}

void krnl_sobel::thread_tmp_1190_fu_28477_p3() {
    tmp_1190_fu_28477_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1191_fu_51619_p3() {
    tmp_1191_fu_51619_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1192_fu_28485_p3() {
    tmp_1192_fu_28485_p3 = p_164_reg2mem697_0_i_i_7_reg_4483.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1193_fu_51627_p3() {
    tmp_1193_fu_51627_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1194_fu_28529_p3() {
    tmp_1194_fu_28529_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1195_fu_51635_p3() {
    tmp_1195_fu_51635_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1196_fu_28537_p3() {
    tmp_1196_fu_28537_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1197_fu_51643_p3() {
    tmp_1197_fu_51643_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1198_fu_28545_p3() {
    tmp_1198_fu_28545_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1199_fu_51651_p3() {
    tmp_1199_fu_51651_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(31, 31);
}

void krnl_sobel::thread_tmp_119_fu_47275_p2() {
    tmp_119_fu_47275_p2 = (!ap_const_lv32_3.is_01() || !ap_pipeline_reg_pp5_iter1_krnl_sobel_rowbuf1_addr1_reg_80445.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_3) + sc_biguint<32>(ap_pipeline_reg_pp5_iter1_krnl_sobel_rowbuf1_addr1_reg_80445.read()));
}

void krnl_sobel::thread_tmp_11_fu_23476_p3() {
    tmp_11_fu_23476_p3 = esl_concat<30,2>(wr_cnt_burst_reg_70880.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_tmp_1200_fu_28553_p3() {
    tmp_1200_fu_28553_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1201_fu_51659_p3() {
    tmp_1201_fu_51659_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1202_fu_28561_p3() {
    tmp_1202_fu_28561_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1203_fu_51667_p3() {
    tmp_1203_fu_51667_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1204_fu_28569_p3() {
    tmp_1204_fu_28569_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1205_fu_51675_p3() {
    tmp_1205_fu_51675_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1206_fu_28577_p3() {
    tmp_1206_fu_28577_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1207_fu_51683_p3() {
    tmp_1207_fu_51683_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1208_fu_28585_p3() {
    tmp_1208_fu_28585_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1209_fu_51691_p3() {
    tmp_1209_fu_51691_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(26, 26);
}

void krnl_sobel::thread_tmp_120_fu_47280_p1() {
    tmp_120_fu_47280_p1 = esl_sext<64,32>(tmp_119_fu_47275_p2.read());
}

void krnl_sobel::thread_tmp_1210_fu_28593_p3() {
    tmp_1210_fu_28593_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1211_fu_51699_p3() {
    tmp_1211_fu_51699_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1212_fu_28601_p3() {
    tmp_1212_fu_28601_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1213_fu_51707_p3() {
    tmp_1213_fu_51707_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1214_fu_28609_p3() {
    tmp_1214_fu_28609_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1215_fu_51715_p3() {
    tmp_1215_fu_51715_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1216_fu_28617_p3() {
    tmp_1216_fu_28617_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1217_fu_51723_p3() {
    tmp_1217_fu_51723_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1218_fu_28625_p3() {
    tmp_1218_fu_28625_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1219_fu_51731_p3() {
    tmp_1219_fu_51731_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1220_fu_28633_p3() {
    tmp_1220_fu_28633_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1221_fu_51739_p3() {
    tmp_1221_fu_51739_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1222_fu_28641_p3() {
    tmp_1222_fu_28641_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1223_fu_51747_p3() {
    tmp_1223_fu_51747_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1224_fu_28649_p3() {
    tmp_1224_fu_28649_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1225_fu_51755_p3() {
    tmp_1225_fu_51755_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1226_fu_28657_p3() {
    tmp_1226_fu_28657_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1227_fu_51763_p3() {
    tmp_1227_fu_51763_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1228_fu_28665_p3() {
    tmp_1228_fu_28665_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1229_fu_51771_p3() {
    tmp_1229_fu_51771_p3 = p_143_reg2mem615_0_i_i_7_reg_14553.read().range(16, 16);
}

void krnl_sobel::thread_tmp_122_fu_24932_p1() {
    tmp_122_fu_24932_p1 = reg_23095.read();
}

void krnl_sobel::thread_tmp_1230_fu_28673_p3() {
    tmp_1230_fu_28673_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1231_fu_51815_p3() {
    tmp_1231_fu_51815_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1232_fu_28681_p3() {
    tmp_1232_fu_28681_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1233_fu_51823_p3() {
    tmp_1233_fu_51823_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1234_fu_28689_p3() {
    tmp_1234_fu_28689_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1235_fu_51831_p3() {
    tmp_1235_fu_51831_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1236_fu_28697_p3() {
    tmp_1236_fu_28697_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1237_fu_51839_p3() {
    tmp_1237_fu_51839_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1238_fu_28705_p3() {
    tmp_1238_fu_28705_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1239_fu_51847_p3() {
    tmp_1239_fu_51847_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(57, 57);
}

void krnl_sobel::thread_tmp_123_fu_47316_p1() {
    tmp_123_fu_47316_p1 = esl_sext<64,32>(done_cnt5_reg_80473.read());
}

void krnl_sobel::thread_tmp_1240_fu_28713_p3() {
    tmp_1240_fu_28713_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1241_fu_51855_p3() {
    tmp_1241_fu_51855_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1242_fu_28721_p3() {
    tmp_1242_fu_28721_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1243_fu_51863_p3() {
    tmp_1243_fu_51863_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1244_fu_28729_p3() {
    tmp_1244_fu_28729_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1245_fu_51871_p3() {
    tmp_1245_fu_51871_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1246_fu_28737_p3() {
    tmp_1246_fu_28737_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1247_fu_51879_p3() {
    tmp_1247_fu_51879_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1248_fu_28745_p3() {
    tmp_1248_fu_28745_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1249_fu_51887_p3() {
    tmp_1249_fu_51887_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(52, 52);
}

void krnl_sobel::thread_tmp_124_fu_24009_p1() {
    tmp_124_fu_24009_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1250_fu_28753_p3() {
    tmp_1250_fu_28753_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1251_fu_51895_p3() {
    tmp_1251_fu_51895_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1252_fu_28761_p3() {
    tmp_1252_fu_28761_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1253_fu_51903_p3() {
    tmp_1253_fu_51903_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1254_fu_28769_p3() {
    tmp_1254_fu_28769_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1255_fu_51911_p3() {
    tmp_1255_fu_51911_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1256_fu_28777_p3() {
    tmp_1256_fu_28777_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1257_fu_51919_p3() {
    tmp_1257_fu_51919_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1258_fu_28785_p3() {
    tmp_1258_fu_28785_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1259_fu_51927_p3() {
    tmp_1259_fu_51927_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(47, 47);
}

void krnl_sobel::thread_tmp_125_fu_24047_p2() {
    tmp_125_fu_24047_p2 = (!ap_const_lv32_1.is_01())? sc_lv<32>(): szrow_0_reg2mem_0_i_i_reg_70759.read() << (unsigned short)ap_const_lv32_1.to_uint();
}

void krnl_sobel::thread_tmp_1260_fu_28793_p3() {
    tmp_1260_fu_28793_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1261_fu_51935_p3() {
    tmp_1261_fu_51935_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1262_fu_28801_p3() {
    tmp_1262_fu_28801_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1263_fu_51943_p3() {
    tmp_1263_fu_51943_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1264_fu_28809_p3() {
    tmp_1264_fu_28809_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1265_fu_51951_p3() {
    tmp_1265_fu_51951_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1266_fu_28817_p3() {
    tmp_1266_fu_28817_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1267_fu_51959_p3() {
    tmp_1267_fu_51959_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1268_fu_28825_p3() {
    tmp_1268_fu_28825_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1269_fu_51967_p3() {
    tmp_1269_fu_51967_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(42, 42);
}

void krnl_sobel::thread_tmp_126_fu_24992_p2() {
    tmp_126_fu_24992_p2 = (notrhs2_reg_71809.read() | notlhs2_fu_24987_p2.read());
}

void krnl_sobel::thread_tmp_1270_fu_28833_p3() {
    tmp_1270_fu_28833_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1271_fu_51975_p3() {
    tmp_1271_fu_51975_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1272_fu_28841_p3() {
    tmp_1272_fu_28841_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1273_fu_51983_p3() {
    tmp_1273_fu_51983_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1274_fu_28849_p3() {
    tmp_1274_fu_28849_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1275_fu_51991_p3() {
    tmp_1275_fu_51991_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1276_fu_28857_p3() {
    tmp_1276_fu_28857_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1277_fu_51999_p3() {
    tmp_1277_fu_51999_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1278_fu_28865_p3() {
    tmp_1278_fu_28865_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1279_fu_52007_p3() {
    tmp_1279_fu_52007_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1280_fu_28873_p3() {
    tmp_1280_fu_28873_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1281_fu_52015_p3() {
    tmp_1281_fu_52015_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1282_fu_28881_p3() {
    tmp_1282_fu_28881_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1283_fu_52023_p3() {
    tmp_1283_fu_52023_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1284_fu_28889_p3() {
    tmp_1284_fu_28889_p3 = p_164_reg2mem697_0_i_i_8_reg_4692.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1285_fu_52031_p3() {
    tmp_1285_fu_52031_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1286_fu_28934_p3() {
    tmp_1286_fu_28934_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1287_fu_52039_p3() {
    tmp_1287_fu_52039_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1288_fu_28942_p3() {
    tmp_1288_fu_28942_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1289_fu_52047_p3() {
    tmp_1289_fu_52047_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(32, 32);
}

void krnl_sobel::thread_tmp_128_fu_24997_p2() {
    tmp_128_fu_24997_p2 = (tmp_126_fu_24992_p2.read() & tmp_127_reg_71814.read());
}

void krnl_sobel::thread_tmp_1290_fu_28950_p3() {
    tmp_1290_fu_28950_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1291_fu_52055_p3() {
    tmp_1291_fu_52055_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1292_fu_28958_p3() {
    tmp_1292_fu_28958_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1293_fu_52063_p3() {
    tmp_1293_fu_52063_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1294_fu_28966_p3() {
    tmp_1294_fu_28966_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1295_fu_52071_p3() {
    tmp_1295_fu_52071_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1296_fu_28974_p3() {
    tmp_1296_fu_28974_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1297_fu_52079_p3() {
    tmp_1297_fu_52079_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1298_fu_28982_p3() {
    tmp_1298_fu_28982_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1299_fu_52087_p3() {
    tmp_1299_fu_52087_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(27, 27);
}

void krnl_sobel::thread_tmp_129_fu_25008_p2() {
    tmp_129_fu_25008_p2 = (!tmp_232_reg_71796.read().is_01() || !ap_const_lv31_7F800000.is_01())? sc_lv<1>(): sc_lv<1>(tmp_232_reg_71796.read() == ap_const_lv31_7F800000);
}

void krnl_sobel::thread_tmp_12_fu_23483_p2() {
    tmp_12_fu_23483_p2 = (!p_ph3_reg_2633.read().is_01() || !tmp_11_fu_23476_p3.read().is_01())? sc_lv<32>(): (sc_biguint<32>(p_ph3_reg_2633.read()) - sc_biguint<32>(tmp_11_fu_23476_p3.read()));
}

void krnl_sobel::thread_tmp_1300_fu_28990_p3() {
    tmp_1300_fu_28990_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1301_fu_52095_p3() {
    tmp_1301_fu_52095_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1302_fu_28998_p3() {
    tmp_1302_fu_28998_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1303_fu_52103_p3() {
    tmp_1303_fu_52103_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1304_fu_29006_p3() {
    tmp_1304_fu_29006_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1305_fu_52111_p3() {
    tmp_1305_fu_52111_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1306_fu_29014_p3() {
    tmp_1306_fu_29014_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1307_fu_52119_p3() {
    tmp_1307_fu_52119_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1308_fu_29022_p3() {
    tmp_1308_fu_29022_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1309_fu_52127_p3() {
    tmp_1309_fu_52127_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(22, 22);
}

void krnl_sobel::thread_tmp_130_fu_24114_p1() {
    tmp_130_fu_24114_p1 = grp_fu_24109_p2.read().range(2-1, 0);
}

void krnl_sobel::thread_tmp_1310_fu_29030_p3() {
    tmp_1310_fu_29030_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1311_fu_52135_p3() {
    tmp_1311_fu_52135_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1312_fu_29038_p3() {
    tmp_1312_fu_29038_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1313_fu_52143_p3() {
    tmp_1313_fu_52143_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1314_fu_29046_p3() {
    tmp_1314_fu_29046_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1315_fu_52151_p3() {
    tmp_1315_fu_52151_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1316_fu_29054_p3() {
    tmp_1316_fu_29054_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1317_fu_52159_p3() {
    tmp_1317_fu_52159_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1318_fu_29062_p3() {
    tmp_1318_fu_29062_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1319_fu_52167_p3() {
    tmp_1319_fu_52167_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(17, 17);
}

void krnl_sobel::thread_tmp_131_fu_24216_p1() {
    tmp_131_fu_24216_p1 = esl_zext<32,30>(rd_cnt_burst2_fu_24206_p4.read());
}

void krnl_sobel::thread_tmp_1320_fu_29070_p3() {
    tmp_1320_fu_29070_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1321_fu_52175_p3() {
    tmp_1321_fu_52175_p3 = p_143_reg2mem615_0_i_i_8_reg_14762.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1322_fu_29078_p3() {
    tmp_1322_fu_29078_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1323_fu_52219_p3() {
    tmp_1323_fu_52219_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1324_fu_29086_p3() {
    tmp_1324_fu_29086_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1325_fu_52227_p3() {
    tmp_1325_fu_52227_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1326_fu_29094_p3() {
    tmp_1326_fu_29094_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1327_fu_52235_p3() {
    tmp_1327_fu_52235_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1328_fu_29102_p3() {
    tmp_1328_fu_29102_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1329_fu_52243_p3() {
    tmp_1329_fu_52243_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(58, 58);
}

void krnl_sobel::thread_tmp_132_fu_24241_p1() {
    tmp_132_fu_24241_p1 = rd_pre_shift1_fu_24235_p2.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1330_fu_29110_p3() {
    tmp_1330_fu_29110_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1331_fu_52251_p3() {
    tmp_1331_fu_52251_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1332_fu_29118_p3() {
    tmp_1332_fu_29118_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1333_fu_52259_p3() {
    tmp_1333_fu_52259_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1334_fu_29126_p3() {
    tmp_1334_fu_29126_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1335_fu_52267_p3() {
    tmp_1335_fu_52267_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1336_fu_29134_p3() {
    tmp_1336_fu_29134_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1337_fu_52275_p3() {
    tmp_1337_fu_52275_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1338_fu_29142_p3() {
    tmp_1338_fu_29142_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1339_fu_52283_p3() {
    tmp_1339_fu_52283_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1340_fu_29150_p3() {
    tmp_1340_fu_29150_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1341_fu_52291_p3() {
    tmp_1341_fu_52291_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1342_fu_29158_p3() {
    tmp_1342_fu_29158_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1343_fu_52299_p3() {
    tmp_1343_fu_52299_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1344_fu_29166_p3() {
    tmp_1344_fu_29166_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1345_fu_52307_p3() {
    tmp_1345_fu_52307_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1346_fu_29174_p3() {
    tmp_1346_fu_29174_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1347_fu_52315_p3() {
    tmp_1347_fu_52315_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1348_fu_29182_p3() {
    tmp_1348_fu_29182_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1349_fu_52323_p3() {
    tmp_1349_fu_52323_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(48, 48);
}

void krnl_sobel::thread_tmp_134_2_fu_24710_p2() {
    tmp_134_2_fu_24710_p2 = (!ap_const_lv31_1.is_01() || !x_0_reg2mem721_0_i_i_reg_2857.read().is_01())? sc_lv<31>(): (sc_biguint<31>(ap_const_lv31_1) + sc_biguint<31>(x_0_reg2mem721_0_i_i_reg_2857.read()));
}

void krnl_sobel::thread_tmp_134_fu_25013_p2() {
    tmp_134_fu_25013_p2 = (tmp_126_reg_71824.read() & tmp_133_reg_71837.read());
}

void krnl_sobel::thread_tmp_1350_fu_29190_p3() {
    tmp_1350_fu_29190_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1351_fu_52331_p3() {
    tmp_1351_fu_52331_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1352_fu_29198_p3() {
    tmp_1352_fu_29198_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1353_fu_52339_p3() {
    tmp_1353_fu_52339_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1354_fu_29206_p3() {
    tmp_1354_fu_29206_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1355_fu_52347_p3() {
    tmp_1355_fu_52347_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1356_fu_29214_p3() {
    tmp_1356_fu_29214_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1357_fu_52355_p3() {
    tmp_1357_fu_52355_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1358_fu_29222_p3() {
    tmp_1358_fu_29222_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1359_fu_52363_p3() {
    tmp_1359_fu_52363_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(43, 43);
}

void krnl_sobel::thread_tmp_135_1_fu_24655_p1() {
    tmp_135_1_fu_24655_p1 = esl_zext<64,31>(x_0_reg2mem721_0_i_i_reg_2857.read());
}

void krnl_sobel::thread_tmp_135_2_fu_24764_p1() {
    tmp_135_2_fu_24764_p1 = esl_zext<64,31>(tmp_134_2_reg_71647.read());
}

void krnl_sobel::thread_tmp_135_fu_47084_p1() {
    tmp_135_fu_47084_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1360_fu_29230_p3() {
    tmp_1360_fu_29230_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1361_fu_52371_p3() {
    tmp_1361_fu_52371_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1362_fu_29238_p3() {
    tmp_1362_fu_29238_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1363_fu_52379_p3() {
    tmp_1363_fu_52379_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1364_fu_29246_p3() {
    tmp_1364_fu_29246_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1365_fu_52387_p3() {
    tmp_1365_fu_52387_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1366_fu_29254_p3() {
    tmp_1366_fu_29254_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1367_fu_52395_p3() {
    tmp_1367_fu_52395_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1368_fu_29262_p3() {
    tmp_1368_fu_29262_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1369_fu_52403_p3() {
    tmp_1369_fu_52403_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(38, 38);
}

void krnl_sobel::thread_tmp_136_fu_25022_p2() {
    tmp_136_fu_25022_p2 = (!tmp_233_reg_71801.read().is_01() || !ap_const_lv8_0.is_01())? sc_lv<1>(): sc_lv<1>(tmp_233_reg_71801.read() == ap_const_lv8_0);
}

void krnl_sobel::thread_tmp_1370_fu_29270_p3() {
    tmp_1370_fu_29270_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1371_fu_52411_p3() {
    tmp_1371_fu_52411_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1372_fu_29278_p3() {
    tmp_1372_fu_29278_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1373_fu_52419_p3() {
    tmp_1373_fu_52419_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1374_fu_29286_p3() {
    tmp_1374_fu_29286_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1375_fu_52427_p3() {
    tmp_1375_fu_52427_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1376_fu_29294_p3() {
    tmp_1376_fu_29294_p3 = p_164_reg2mem697_0_i_i_9_reg_4901.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1377_fu_52435_p3() {
    tmp_1377_fu_52435_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1378_fu_29338_p3() {
    tmp_1378_fu_29338_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1379_fu_52443_p3() {
    tmp_1379_fu_52443_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(33, 33);
}

void krnl_sobel::thread_tmp_137_2_cast_fu_24849_p1() {
    tmp_137_2_cast_fu_24849_p1 = esl_zext<11,8>(phi_load3_reg_2900.read());
}

void krnl_sobel::thread_tmp_137_fu_25041_p1() {
    tmp_137_fu_25041_p1 = esl_zext<9,8>(tmp_233_reg_71801.read());
}

void krnl_sobel::thread_tmp_1380_fu_29346_p3() {
    tmp_1380_fu_29346_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1381_fu_52451_p3() {
    tmp_1381_fu_52451_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1382_fu_29354_p3() {
    tmp_1382_fu_29354_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1383_fu_52459_p3() {
    tmp_1383_fu_52459_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1384_fu_29362_p3() {
    tmp_1384_fu_29362_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1385_fu_52467_p3() {
    tmp_1385_fu_52467_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1386_fu_29370_p3() {
    tmp_1386_fu_29370_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1387_fu_52475_p3() {
    tmp_1387_fu_52475_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1388_fu_29378_p3() {
    tmp_1388_fu_29378_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1389_fu_52483_p3() {
    tmp_1389_fu_52483_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(28, 28);
}

void krnl_sobel::thread_tmp_138_fu_25044_p2() {
    tmp_138_fu_25044_p2 = (!p_068_0_reg2mem_0_i_i_reg_71845.read().is_01() || !ap_const_lv24_0.is_01())? sc_lv<1>(): sc_lv<1>(p_068_0_reg2mem_0_i_i_reg_71845.read() == ap_const_lv24_0);
}

void krnl_sobel::thread_tmp_1390_fu_29386_p3() {
    tmp_1390_fu_29386_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1391_fu_52491_p3() {
    tmp_1391_fu_52491_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1392_fu_29394_p3() {
    tmp_1392_fu_29394_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1393_fu_52499_p3() {
    tmp_1393_fu_52499_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1394_fu_29402_p3() {
    tmp_1394_fu_29402_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1395_fu_52507_p3() {
    tmp_1395_fu_52507_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1396_fu_29410_p3() {
    tmp_1396_fu_29410_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1397_fu_52515_p3() {
    tmp_1397_fu_52515_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1398_fu_29418_p3() {
    tmp_1398_fu_29418_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1399_fu_52523_p3() {
    tmp_1399_fu_52523_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(23, 23);
}

void krnl_sobel::thread_tmp_139_fu_47325_p2() {
    tmp_139_fu_47325_p2 = (!done_cnt5_reg_80473.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt5_reg_80473.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void krnl_sobel::thread_tmp_13_fu_23405_p4() {
    tmp_13_fu_23405_p4 = esl_concat<16,8>(esl_concat<8,8>(reg_22949.read(), reg_22944.read()), reg_22939.read());
}

void krnl_sobel::thread_tmp_1400_fu_29426_p3() {
    tmp_1400_fu_29426_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1401_fu_52531_p3() {
    tmp_1401_fu_52531_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1402_fu_29434_p3() {
    tmp_1402_fu_29434_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1403_fu_52539_p3() {
    tmp_1403_fu_52539_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1404_fu_29442_p3() {
    tmp_1404_fu_29442_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1405_fu_52547_p3() {
    tmp_1405_fu_52547_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1406_fu_29450_p3() {
    tmp_1406_fu_29450_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1407_fu_52555_p3() {
    tmp_1407_fu_52555_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1408_fu_29458_p3() {
    tmp_1408_fu_29458_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1409_fu_52563_p3() {
    tmp_1409_fu_52563_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(18, 18);
}

void krnl_sobel::thread_tmp_140_fu_47330_p1() {
    tmp_140_fu_47330_p1 = esl_sext<64,32>(tmp_139_fu_47325_p2.read());
}

void krnl_sobel::thread_tmp_1410_fu_29466_p3() {
    tmp_1410_fu_29466_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1411_fu_52571_p3() {
    tmp_1411_fu_52571_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1412_fu_29474_p3() {
    tmp_1412_fu_29474_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1413_fu_52579_p3() {
    tmp_1413_fu_52579_p3 = p_143_reg2mem615_0_i_i_9_reg_14971.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1414_fu_29482_p3() {
    tmp_1414_fu_29482_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1415_fu_52623_p3() {
    tmp_1415_fu_52623_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1416_fu_29490_p3() {
    tmp_1416_fu_29490_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1417_fu_52631_p3() {
    tmp_1417_fu_52631_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1418_fu_29498_p3() {
    tmp_1418_fu_29498_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1419_fu_52639_p3() {
    tmp_1419_fu_52639_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(59, 59);
}

void krnl_sobel::thread_tmp_141_fu_47140_p1() {
    tmp_141_fu_47140_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1420_fu_29506_p3() {
    tmp_1420_fu_29506_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1421_fu_52647_p3() {
    tmp_1421_fu_52647_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1422_fu_29514_p3() {
    tmp_1422_fu_29514_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1423_fu_52655_p3() {
    tmp_1423_fu_52655_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1424_fu_29522_p3() {
    tmp_1424_fu_29522_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1425_fu_52663_p3() {
    tmp_1425_fu_52663_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1426_fu_29530_p3() {
    tmp_1426_fu_29530_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1427_fu_52671_p3() {
    tmp_1427_fu_52671_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1428_fu_29538_p3() {
    tmp_1428_fu_29538_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1429_fu_52679_p3() {
    tmp_1429_fu_52679_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(54, 54);
}

void krnl_sobel::thread_tmp_142_fu_47340_p2() {
    tmp_142_fu_47340_p2 = (!done_cnt5_reg_80473.read().is_01() || !ap_const_lv32_2.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt5_reg_80473.read()) + sc_biguint<32>(ap_const_lv32_2));
}

void krnl_sobel::thread_tmp_1430_fu_29546_p3() {
    tmp_1430_fu_29546_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1431_fu_52687_p3() {
    tmp_1431_fu_52687_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1432_fu_29554_p3() {
    tmp_1432_fu_29554_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1433_fu_52695_p3() {
    tmp_1433_fu_52695_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1434_fu_29562_p3() {
    tmp_1434_fu_29562_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1435_fu_52703_p3() {
    tmp_1435_fu_52703_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1436_fu_29570_p3() {
    tmp_1436_fu_29570_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1437_fu_52711_p3() {
    tmp_1437_fu_52711_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1438_fu_29578_p3() {
    tmp_1438_fu_29578_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1439_fu_52719_p3() {
    tmp_1439_fu_52719_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(49, 49);
}

void krnl_sobel::thread_tmp_143_2_cast_fu_24881_p1() {
    tmp_143_2_cast_fu_24881_p1 = esl_zext<11,8>(rowbuf2_q1.read());
}

void krnl_sobel::thread_tmp_143_fu_47345_p1() {
    tmp_143_fu_47345_p1 = esl_sext<64,32>(tmp_142_fu_47340_p2.read());
}

void krnl_sobel::thread_tmp_1440_fu_29586_p3() {
    tmp_1440_fu_29586_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1441_fu_52727_p3() {
    tmp_1441_fu_52727_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1442_fu_29594_p3() {
    tmp_1442_fu_29594_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1443_fu_52735_p3() {
    tmp_1443_fu_52735_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1444_fu_29602_p3() {
    tmp_1444_fu_29602_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1445_fu_52743_p3() {
    tmp_1445_fu_52743_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1446_fu_29610_p3() {
    tmp_1446_fu_29610_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1447_fu_52751_p3() {
    tmp_1447_fu_52751_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1448_fu_29618_p3() {
    tmp_1448_fu_29618_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1449_fu_52759_p3() {
    tmp_1449_fu_52759_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(44, 44);
}

void krnl_sobel::thread_tmp_144_1_cast_fu_24749_p1() {
    tmp_144_1_cast_fu_24749_p1 = esl_zext<11,9>(tmp_144_1_fu_24741_p3.read());
}

void krnl_sobel::thread_tmp_144_1_fu_24741_p3() {
    tmp_144_1_fu_24741_p3 = esl_concat<8,1>(rowbuf2_q0.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_tmp_144_fu_24330_p1() {
    tmp_144_fu_24330_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1450_fu_29626_p3() {
    tmp_1450_fu_29626_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1451_fu_52767_p3() {
    tmp_1451_fu_52767_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1452_fu_29634_p3() {
    tmp_1452_fu_29634_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1453_fu_52775_p3() {
    tmp_1453_fu_52775_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1454_fu_29642_p3() {
    tmp_1454_fu_29642_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1455_fu_52783_p3() {
    tmp_1455_fu_52783_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1456_fu_29650_p3() {
    tmp_1456_fu_29650_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1457_fu_52791_p3() {
    tmp_1457_fu_52791_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1458_fu_29658_p3() {
    tmp_1458_fu_29658_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1459_fu_52799_p3() {
    tmp_1459_fu_52799_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(39, 39);
}

void krnl_sobel::thread_tmp_145_2_fu_24885_p2() {
    tmp_145_2_fu_24885_p2 = (!p_reg2mem500_0_i_i_1_reg_71673.read().is_01() || !tmp_137_2_cast_reg_71722.read().is_01())? sc_lv<11>(): (sc_biguint<11>(p_reg2mem500_0_i_i_1_reg_71673.read()) - sc_biguint<11>(tmp_137_2_cast_reg_71722.read()));
}

void krnl_sobel::thread_tmp_1460_fu_29666_p3() {
    tmp_1460_fu_29666_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1461_fu_52807_p3() {
    tmp_1461_fu_52807_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1462_fu_29674_p3() {
    tmp_1462_fu_29674_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1463_fu_52815_p3() {
    tmp_1463_fu_52815_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1464_fu_29682_p3() {
    tmp_1464_fu_29682_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1465_fu_52823_p3() {
    tmp_1465_fu_52823_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1466_fu_29690_p3() {
    tmp_1466_fu_29690_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1467_fu_52831_p3() {
    tmp_1467_fu_52831_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1468_fu_29698_p3() {
    tmp_1468_fu_29698_p3 = p_164_reg2mem697_0_i_i_s_reg_5110.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1469_fu_52839_p3() {
    tmp_1469_fu_52839_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(34, 34);
}

void krnl_sobel::thread_tmp_146_1_fu_24753_p2() {
    tmp_146_1_fu_24753_p2 = (!p_reg2mem500_0_i_i_cast_reg_71603.read().is_01() || !p_shl1_cast_fu_24737_p1.read().is_01())? sc_lv<11>(): (sc_bigint<11>(p_reg2mem500_0_i_i_cast_reg_71603.read()) - sc_biguint<11>(p_shl1_cast_fu_24737_p1.read()));
}

void krnl_sobel::thread_tmp_146_fu_24403_p1() {
    tmp_146_fu_24403_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1470_fu_29742_p3() {
    tmp_1470_fu_29742_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1471_fu_52847_p3() {
    tmp_1471_fu_52847_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1472_fu_29750_p3() {
    tmp_1472_fu_29750_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1473_fu_52855_p3() {
    tmp_1473_fu_52855_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1474_fu_29758_p3() {
    tmp_1474_fu_29758_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1475_fu_52863_p3() {
    tmp_1475_fu_52863_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1476_fu_29766_p3() {
    tmp_1476_fu_29766_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1477_fu_52871_p3() {
    tmp_1477_fu_52871_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1478_fu_29774_p3() {
    tmp_1478_fu_29774_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1479_fu_52879_p3() {
    tmp_1479_fu_52879_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(29, 29);
}

void krnl_sobel::thread_tmp_147_fu_47409_p4() {
    tmp_147_fu_47409_p4 = indvars_iv3_reg_12802.read().range(31, 2);
}

void krnl_sobel::thread_tmp_1480_fu_29782_p3() {
    tmp_1480_fu_29782_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1481_fu_52887_p3() {
    tmp_1481_fu_52887_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1482_fu_29790_p3() {
    tmp_1482_fu_29790_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1483_fu_52895_p3() {
    tmp_1483_fu_52895_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1484_fu_29798_p3() {
    tmp_1484_fu_29798_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1485_fu_52903_p3() {
    tmp_1485_fu_52903_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1486_fu_29806_p3() {
    tmp_1486_fu_29806_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1487_fu_52911_p3() {
    tmp_1487_fu_52911_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1488_fu_29814_p3() {
    tmp_1488_fu_29814_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1489_fu_52919_p3() {
    tmp_1489_fu_52919_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(24, 24);
}

void krnl_sobel::thread_tmp_148_fu_47419_p1() {
    tmp_148_fu_47419_p1 = esl_sext<62,30>(tmp_147_fu_47409_p4.read());
}

void krnl_sobel::thread_tmp_1490_fu_29822_p3() {
    tmp_1490_fu_29822_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1491_fu_52927_p3() {
    tmp_1491_fu_52927_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1492_fu_29830_p3() {
    tmp_1492_fu_29830_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1493_fu_52935_p3() {
    tmp_1493_fu_52935_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1494_fu_29838_p3() {
    tmp_1494_fu_29838_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1495_fu_52943_p3() {
    tmp_1495_fu_52943_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1496_fu_29846_p3() {
    tmp_1496_fu_29846_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1497_fu_52951_p3() {
    tmp_1497_fu_52951_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1498_fu_29854_p3() {
    tmp_1498_fu_29854_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1499_fu_52959_p3() {
    tmp_1499_fu_52959_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(19, 19);
}

void krnl_sobel::thread_tmp_149_fu_47176_p1() {
    tmp_149_fu_47176_p1 = rd_pre_shift2_fu_47170_p2.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_14_fu_23690_p1() {
    tmp_14_fu_23690_p1 = esl_sext<64,32>(krnl_sobel_rowbuf0_mult_reg_71054.read());
}

void krnl_sobel::thread_tmp_1500_fu_29862_p3() {
    tmp_1500_fu_29862_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1501_fu_52967_p3() {
    tmp_1501_fu_52967_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1502_fu_29870_p3() {
    tmp_1502_fu_29870_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1503_fu_52975_p3() {
    tmp_1503_fu_52975_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1504_fu_29878_p3() {
    tmp_1504_fu_29878_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1505_fu_52983_p3() {
    tmp_1505_fu_52983_p3 = p_143_reg2mem615_0_i_i_s_reg_15180.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1506_fu_29886_p3() {
    tmp_1506_fu_29886_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1507_fu_53027_p3() {
    tmp_1507_fu_53027_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1508_fu_29894_p3() {
    tmp_1508_fu_29894_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1509_fu_53035_p3() {
    tmp_1509_fu_53035_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(60, 60);
}

void krnl_sobel::thread_tmp_150_cast_fu_24651_p1() {
    tmp_150_cast_fu_24651_p1 = esl_zext<10,9>(tmp_107_fu_24643_p3.read());
}

void krnl_sobel::thread_tmp_150_fu_47427_p4() {
    tmp_150_fu_47427_p4 = indvars_iv_reg_12812.read().range(31, 2);
}

void krnl_sobel::thread_tmp_1510_fu_29902_p3() {
    tmp_1510_fu_29902_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1511_fu_53043_p3() {
    tmp_1511_fu_53043_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1512_fu_29910_p3() {
    tmp_1512_fu_29910_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1513_fu_53051_p3() {
    tmp_1513_fu_53051_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1514_fu_29918_p3() {
    tmp_1514_fu_29918_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1515_fu_53059_p3() {
    tmp_1515_fu_53059_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1516_fu_29926_p3() {
    tmp_1516_fu_29926_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1517_fu_53067_p3() {
    tmp_1517_fu_53067_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1518_fu_29934_p3() {
    tmp_1518_fu_29934_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1519_fu_53075_p3() {
    tmp_1519_fu_53075_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(55, 55);
}

void krnl_sobel::thread_tmp_151_fu_47437_p1() {
    tmp_151_fu_47437_p1 = esl_sext<62,30>(tmp_150_fu_47427_p4.read());
}

void krnl_sobel::thread_tmp_1520_fu_29942_p3() {
    tmp_1520_fu_29942_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1521_fu_53083_p3() {
    tmp_1521_fu_53083_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1522_fu_29950_p3() {
    tmp_1522_fu_29950_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1523_fu_53091_p3() {
    tmp_1523_fu_53091_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1524_fu_29958_p3() {
    tmp_1524_fu_29958_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1525_fu_53099_p3() {
    tmp_1525_fu_53099_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1526_fu_29966_p3() {
    tmp_1526_fu_29966_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1527_fu_53107_p3() {
    tmp_1527_fu_53107_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1528_fu_29974_p3() {
    tmp_1528_fu_29974_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1529_fu_53115_p3() {
    tmp_1529_fu_53115_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(50, 50);
}

void krnl_sobel::thread_tmp_152_fu_47362_p2() {
    tmp_152_fu_47362_p2 = (!y3_0_reg2mem641_0_i_i_cast_fu_47358_p1.read().is_01() || !tmp_61_reg_71272.read().is_01())? sc_lv<1>(): (sc_bigint<32>(y3_0_reg2mem641_0_i_i_cast_fu_47358_p1.read()) < sc_bigint<32>(tmp_61_reg_71272.read()));
}

void krnl_sobel::thread_tmp_1530_fu_29982_p3() {
    tmp_1530_fu_29982_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1531_fu_53123_p3() {
    tmp_1531_fu_53123_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1532_fu_29990_p3() {
    tmp_1532_fu_29990_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1533_fu_53131_p3() {
    tmp_1533_fu_53131_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1534_fu_29998_p3() {
    tmp_1534_fu_29998_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1535_fu_53139_p3() {
    tmp_1535_fu_53139_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1536_fu_30006_p3() {
    tmp_1536_fu_30006_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1537_fu_53147_p3() {
    tmp_1537_fu_53147_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1538_fu_30014_p3() {
    tmp_1538_fu_30014_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1539_fu_53155_p3() {
    tmp_1539_fu_53155_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(45, 45);
}

void krnl_sobel::thread_tmp_153_2_fu_24877_p2() {
    tmp_153_2_fu_24877_p2 = (!p_reg2mem498_0_i_i_1_cast_reg_71642.read().is_01() || !tmp_137_2_cast_reg_71722.read().is_01())? sc_lv<11>(): (sc_biguint<11>(p_reg2mem498_0_i_i_1_cast_reg_71642.read()) - sc_biguint<11>(tmp_137_2_cast_reg_71722.read()));
}

void krnl_sobel::thread_tmp_153_fu_47367_p2() {
    tmp_153_fu_47367_p2 = (!ap_const_lv31_1.is_01() || !y3_0_reg2mem641_0_i_i_reg_12848.read().is_01())? sc_lv<31>(): (sc_biguint<31>(ap_const_lv31_1) + sc_biguint<31>(y3_0_reg2mem641_0_i_i_reg_12848.read()));
}

void krnl_sobel::thread_tmp_1540_fu_30022_p3() {
    tmp_1540_fu_30022_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1541_fu_53163_p3() {
    tmp_1541_fu_53163_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1542_fu_30030_p3() {
    tmp_1542_fu_30030_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1543_fu_53171_p3() {
    tmp_1543_fu_53171_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1544_fu_30038_p3() {
    tmp_1544_fu_30038_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1545_fu_53179_p3() {
    tmp_1545_fu_53179_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1546_fu_30046_p3() {
    tmp_1546_fu_30046_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1547_fu_53187_p3() {
    tmp_1547_fu_53187_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1548_fu_30054_p3() {
    tmp_1548_fu_30054_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1549_fu_53195_p3() {
    tmp_1549_fu_53195_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(40, 40);
}

void krnl_sobel::thread_tmp_154_2_fu_24907_p2() {
    tmp_154_2_fu_24907_p2 = (!tmp_153_2_reg_71747.read().is_01() || !p_shl_cast_fu_24903_p1.read().is_01())? sc_lv<11>(): (sc_biguint<11>(tmp_153_2_reg_71747.read()) - sc_biguint<11>(p_shl_cast_fu_24903_p1.read()));
}

void krnl_sobel::thread_tmp_1550_fu_30062_p3() {
    tmp_1550_fu_30062_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1551_fu_53203_p3() {
    tmp_1551_fu_53203_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1552_fu_30070_p3() {
    tmp_1552_fu_30070_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1553_fu_53211_p3() {
    tmp_1553_fu_53211_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1554_fu_30078_p3() {
    tmp_1554_fu_30078_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1555_fu_53219_p3() {
    tmp_1555_fu_53219_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1556_fu_30086_p3() {
    tmp_1556_fu_30086_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1557_fu_53227_p3() {
    tmp_1557_fu_53227_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1558_fu_30094_p3() {
    tmp_1558_fu_30094_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1559_fu_53235_p3() {
    tmp_1559_fu_53235_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(35, 35);
}

void krnl_sobel::thread_tmp_155_fu_24456_p1() {
    tmp_155_fu_24456_p1 = tmp_105_fu_24450_p2.read().range(16-1, 0);
}

void krnl_sobel::thread_tmp_1560_fu_30102_p3() {
    tmp_1560_fu_30102_p3 = p_164_reg2mem697_0_i_i_10_reg_5319.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1561_fu_53243_p3() {
    tmp_1561_fu_53243_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1562_fu_30146_p3() {
    tmp_1562_fu_30146_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1563_fu_53251_p3() {
    tmp_1563_fu_53251_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1564_fu_30154_p3() {
    tmp_1564_fu_30154_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1565_fu_53259_p3() {
    tmp_1565_fu_53259_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1566_fu_30162_p3() {
    tmp_1566_fu_30162_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1567_fu_53267_p3() {
    tmp_1567_fu_53267_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1568_fu_30170_p3() {
    tmp_1568_fu_30170_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1569_fu_53275_p3() {
    tmp_1569_fu_53275_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(30, 30);
}

void krnl_sobel::thread_tmp_156_fu_47386_p4() {
    tmp_156_fu_47386_p4 = grp_fu_47377_p2.read().range(31, 2);
}

void krnl_sobel::thread_tmp_1570_fu_30178_p3() {
    tmp_1570_fu_30178_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1571_fu_53283_p3() {
    tmp_1571_fu_53283_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1572_fu_30186_p3() {
    tmp_1572_fu_30186_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1573_fu_53291_p3() {
    tmp_1573_fu_53291_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1574_fu_30194_p3() {
    tmp_1574_fu_30194_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1575_fu_53299_p3() {
    tmp_1575_fu_53299_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1576_fu_30202_p3() {
    tmp_1576_fu_30202_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1577_fu_53307_p3() {
    tmp_1577_fu_53307_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1578_fu_30210_p3() {
    tmp_1578_fu_30210_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1579_fu_53315_p3() {
    tmp_1579_fu_53315_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(25, 25);
}

void krnl_sobel::thread_tmp_157_fu_47396_p1() {
    tmp_157_fu_47396_p1 = esl_sext<62,30>(tmp_156_fu_47386_p4.read());
}

void krnl_sobel::thread_tmp_1580_fu_30218_p3() {
    tmp_1580_fu_30218_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1581_fu_53323_p3() {
    tmp_1581_fu_53323_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1582_fu_30226_p3() {
    tmp_1582_fu_30226_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1583_fu_53331_p3() {
    tmp_1583_fu_53331_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1584_fu_30234_p3() {
    tmp_1584_fu_30234_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1585_fu_53339_p3() {
    tmp_1585_fu_53339_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1586_fu_30242_p3() {
    tmp_1586_fu_30242_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1587_fu_53347_p3() {
    tmp_1587_fu_53347_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1588_fu_30250_p3() {
    tmp_1588_fu_30250_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1589_fu_53355_p3() {
    tmp_1589_fu_53355_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(20, 20);
}

void krnl_sobel::thread_tmp_158_fu_47477_p2() {
    tmp_158_fu_47477_p2 = (prealign_wr_cnt2_fu_47458_p2.read() & tmp_173_cast_fu_47469_p3.read());
}

void krnl_sobel::thread_tmp_1590_fu_30258_p3() {
    tmp_1590_fu_30258_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1591_fu_53363_p3() {
    tmp_1591_fu_53363_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1592_fu_30266_p3() {
    tmp_1592_fu_30266_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1593_fu_53371_p3() {
    tmp_1593_fu_53371_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1594_fu_30274_p3() {
    tmp_1594_fu_30274_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1595_fu_53379_p3() {
    tmp_1595_fu_53379_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1596_fu_30282_p3() {
    tmp_1596_fu_30282_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1597_fu_53387_p3() {
    tmp_1597_fu_53387_p3 = p_143_reg2mem615_0_i_i_10_reg_15389.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1598_fu_30290_p3() {
    tmp_1598_fu_30290_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1599_fu_53432_p3() {
    tmp_1599_fu_53432_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(61, 61);
}

void krnl_sobel::thread_tmp_159_fu_47510_p3() {
    tmp_159_fu_47510_p3 = esl_concat<2,3>(tmp_208_reg_80524.read(), ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_15_fu_23694_p2() {
    tmp_15_fu_23694_p2 = (krnl_sobel_rowbuf0_mult_reg_71054.read() | ap_const_lv32_1);
}

void krnl_sobel::thread_tmp_1600_fu_30298_p3() {
    tmp_1600_fu_30298_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1601_fu_53440_p3() {
    tmp_1601_fu_53440_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1602_fu_30306_p3() {
    tmp_1602_fu_30306_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1603_fu_53448_p3() {
    tmp_1603_fu_53448_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1604_fu_30314_p3() {
    tmp_1604_fu_30314_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1605_fu_53456_p3() {
    tmp_1605_fu_53456_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1606_fu_30322_p3() {
    tmp_1606_fu_30322_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1607_fu_53464_p3() {
    tmp_1607_fu_53464_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1608_fu_30330_p3() {
    tmp_1608_fu_30330_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1609_fu_53472_p3() {
    tmp_1609_fu_53472_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(56, 56);
}

void krnl_sobel::thread_tmp_160_fu_47584_p3() {
    tmp_160_fu_47584_p3 = esl_concat<30,2>(rd_cnt_burst3_reg_80563.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_tmp_1610_fu_30338_p3() {
    tmp_1610_fu_30338_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1611_fu_53480_p3() {
    tmp_1611_fu_53480_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1612_fu_30346_p3() {
    tmp_1612_fu_30346_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1613_fu_53488_p3() {
    tmp_1613_fu_53488_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1614_fu_30354_p3() {
    tmp_1614_fu_30354_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1615_fu_53496_p3() {
    tmp_1615_fu_53496_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1616_fu_30362_p3() {
    tmp_1616_fu_30362_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1617_fu_53504_p3() {
    tmp_1617_fu_53504_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1618_fu_30370_p3() {
    tmp_1618_fu_30370_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1619_fu_53512_p3() {
    tmp_1619_fu_53512_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(51, 51);
}

void krnl_sobel::thread_tmp_161_fu_47591_p2() {
    tmp_161_fu_47591_p2 = (!p_ph15_reg_12879.read().is_01() || !tmp_160_fu_47584_p3.read().is_01())? sc_lv<32>(): (sc_biguint<32>(p_ph15_reg_12879.read()) - sc_biguint<32>(tmp_160_fu_47584_p3.read()));
}

void krnl_sobel::thread_tmp_1620_fu_30378_p3() {
    tmp_1620_fu_30378_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1621_fu_53520_p3() {
    tmp_1621_fu_53520_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1622_fu_30386_p3() {
    tmp_1622_fu_30386_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1623_fu_53528_p3() {
    tmp_1623_fu_53528_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1624_fu_30394_p3() {
    tmp_1624_fu_30394_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1625_fu_53536_p3() {
    tmp_1625_fu_53536_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1626_fu_30402_p3() {
    tmp_1626_fu_30402_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1627_fu_53544_p3() {
    tmp_1627_fu_53544_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1628_fu_30410_p3() {
    tmp_1628_fu_30410_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1629_fu_53552_p3() {
    tmp_1629_fu_53552_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(46, 46);
}

void krnl_sobel::thread_tmp_162_fu_24465_p1() {
    tmp_162_fu_24465_p1 = mem_index_gep_fu_24460_p2.read().range(14-1, 0);
}

void krnl_sobel::thread_tmp_1630_fu_30418_p3() {
    tmp_1630_fu_30418_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1631_fu_53560_p3() {
    tmp_1631_fu_53560_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1632_fu_30426_p3() {
    tmp_1632_fu_30426_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1633_fu_53568_p3() {
    tmp_1633_fu_53568_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1634_fu_30434_p3() {
    tmp_1634_fu_30434_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1635_fu_53576_p3() {
    tmp_1635_fu_53576_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1636_fu_30442_p3() {
    tmp_1636_fu_30442_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1637_fu_53584_p3() {
    tmp_1637_fu_53584_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1638_fu_30450_p3() {
    tmp_1638_fu_30450_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1639_fu_53592_p3() {
    tmp_1639_fu_53592_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(41, 41);
}

void krnl_sobel::thread_tmp_163_cast_fu_47423_p1() {
    tmp_163_cast_fu_47423_p1 = esl_zext<63,62>(tmp_148_fu_47419_p1.read());
}

void krnl_sobel::thread_tmp_163_fu_47620_p1() {
    tmp_163_fu_47620_p1 = esl_sext<64,32>(krnl_sobel_rowbuf2_addr1_reg_80630.read());
}

void krnl_sobel::thread_tmp_1640_fu_30458_p3() {
    tmp_1640_fu_30458_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1641_fu_53600_p3() {
    tmp_1641_fu_53600_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1642_fu_30466_p3() {
    tmp_1642_fu_30466_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1643_fu_53608_p3() {
    tmp_1643_fu_53608_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1644_fu_30474_p3() {
    tmp_1644_fu_30474_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1645_fu_53616_p3() {
    tmp_1645_fu_53616_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1646_fu_30482_p3() {
    tmp_1646_fu_30482_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1647_fu_53624_p3() {
    tmp_1647_fu_53624_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1648_fu_30490_p3() {
    tmp_1648_fu_30490_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1649_fu_53632_p3() {
    tmp_1649_fu_53632_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(36, 36);
}

void krnl_sobel::thread_tmp_164_fu_47624_p2() {
    tmp_164_fu_47624_p2 = (!ap_const_lv32_1.is_01() || !krnl_sobel_rowbuf2_addr1_reg_80630.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_1) + sc_biguint<32>(krnl_sobel_rowbuf2_addr1_reg_80630.read()));
}

void krnl_sobel::thread_tmp_1650_fu_30498_p3() {
    tmp_1650_fu_30498_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1651_fu_53640_p3() {
    tmp_1651_fu_53640_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1652_fu_30506_p3() {
    tmp_1652_fu_30506_p3 = p_164_reg2mem697_0_i_i_11_reg_5528.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1653_fu_53648_p3() {
    tmp_1653_fu_53648_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1654_fu_30550_p3() {
    tmp_1654_fu_30550_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1655_fu_53656_p3() {
    tmp_1655_fu_53656_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1656_fu_30558_p3() {
    tmp_1656_fu_30558_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1657_fu_53664_p3() {
    tmp_1657_fu_53664_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1658_fu_30566_p3() {
    tmp_1658_fu_30566_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1659_fu_53672_p3() {
    tmp_1659_fu_53672_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(31, 31);
}

void krnl_sobel::thread_tmp_165_fu_47629_p1() {
    tmp_165_fu_47629_p1 = esl_sext<64,32>(tmp_164_fu_47624_p2.read());
}

void krnl_sobel::thread_tmp_1660_fu_30574_p3() {
    tmp_1660_fu_30574_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1661_fu_53680_p3() {
    tmp_1661_fu_53680_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1662_fu_30582_p3() {
    tmp_1662_fu_30582_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1663_fu_53688_p3() {
    tmp_1663_fu_53688_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1664_fu_30590_p3() {
    tmp_1664_fu_30590_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1665_fu_53696_p3() {
    tmp_1665_fu_53696_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1666_fu_30598_p3() {
    tmp_1666_fu_30598_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1667_fu_53704_p3() {
    tmp_1667_fu_53704_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1668_fu_30606_p3() {
    tmp_1668_fu_30606_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1669_fu_53712_p3() {
    tmp_1669_fu_53712_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(26, 26);
}

void krnl_sobel::thread_tmp_166_fu_47634_p2() {
    tmp_166_fu_47634_p2 = (!ap_const_lv32_2.is_01() || !ap_pipeline_reg_pp6_iter1_krnl_sobel_rowbuf2_addr1_reg_80630.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_2) + sc_biguint<32>(ap_pipeline_reg_pp6_iter1_krnl_sobel_rowbuf2_addr1_reg_80630.read()));
}

void krnl_sobel::thread_tmp_1670_fu_30614_p3() {
    tmp_1670_fu_30614_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1671_fu_53720_p3() {
    tmp_1671_fu_53720_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1672_fu_30622_p3() {
    tmp_1672_fu_30622_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1673_fu_53728_p3() {
    tmp_1673_fu_53728_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1674_fu_30630_p3() {
    tmp_1674_fu_30630_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1675_fu_53736_p3() {
    tmp_1675_fu_53736_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1676_fu_30638_p3() {
    tmp_1676_fu_30638_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1677_fu_53744_p3() {
    tmp_1677_fu_53744_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1678_fu_30646_p3() {
    tmp_1678_fu_30646_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1679_fu_53752_p3() {
    tmp_1679_fu_53752_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(21, 21);
}

void krnl_sobel::thread_tmp_167_cast_fu_47441_p1() {
    tmp_167_cast_fu_47441_p1 = esl_zext<63,62>(tmp_151_fu_47437_p1.read());
}

void krnl_sobel::thread_tmp_167_fu_47639_p1() {
    tmp_167_fu_47639_p1 = esl_sext<64,32>(tmp_166_fu_47634_p2.read());
}

void krnl_sobel::thread_tmp_1680_fu_30654_p3() {
    tmp_1680_fu_30654_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1681_fu_53760_p3() {
    tmp_1681_fu_53760_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1682_fu_30662_p3() {
    tmp_1682_fu_30662_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1683_fu_53768_p3() {
    tmp_1683_fu_53768_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1684_fu_30670_p3() {
    tmp_1684_fu_30670_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1685_fu_53776_p3() {
    tmp_1685_fu_53776_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1686_fu_30678_p3() {
    tmp_1686_fu_30678_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1687_fu_53784_p3() {
    tmp_1687_fu_53784_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1688_fu_30686_p3() {
    tmp_1688_fu_30686_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1689_fu_53792_p3() {
    tmp_1689_fu_53792_p3 = p_143_reg2mem615_0_i_i_11_reg_15598.read().range(16, 16);
}

void krnl_sobel::thread_tmp_168_fu_47644_p2() {
    tmp_168_fu_47644_p2 = (!ap_const_lv32_3.is_01() || !ap_pipeline_reg_pp6_iter1_krnl_sobel_rowbuf2_addr1_reg_80630.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_3) + sc_biguint<32>(ap_pipeline_reg_pp6_iter1_krnl_sobel_rowbuf2_addr1_reg_80630.read()));
}

void krnl_sobel::thread_tmp_1690_fu_30694_p3() {
    tmp_1690_fu_30694_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1691_fu_53837_p3() {
    tmp_1691_fu_53837_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1692_fu_30702_p3() {
    tmp_1692_fu_30702_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1693_fu_53845_p3() {
    tmp_1693_fu_53845_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1694_fu_30710_p3() {
    tmp_1694_fu_30710_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1695_fu_53853_p3() {
    tmp_1695_fu_53853_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1696_fu_30718_p3() {
    tmp_1696_fu_30718_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1697_fu_53861_p3() {
    tmp_1697_fu_53861_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1698_fu_30726_p3() {
    tmp_1698_fu_30726_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1699_fu_53869_p3() {
    tmp_1699_fu_53869_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(57, 57);
}

void krnl_sobel::thread_tmp_169_fu_47649_p1() {
    tmp_169_fu_47649_p1 = esl_sext<64,32>(tmp_168_fu_47644_p2.read());
}

void krnl_sobel::thread_tmp_16_fu_23699_p1() {
    tmp_16_fu_23699_p1 = esl_sext<64,32>(tmp_15_fu_23694_p2.read());
}

void krnl_sobel::thread_tmp_1700_fu_30734_p3() {
    tmp_1700_fu_30734_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1701_fu_53877_p3() {
    tmp_1701_fu_53877_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1702_fu_30742_p3() {
    tmp_1702_fu_30742_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1703_fu_53885_p3() {
    tmp_1703_fu_53885_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1704_fu_30750_p3() {
    tmp_1704_fu_30750_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1705_fu_53893_p3() {
    tmp_1705_fu_53893_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1706_fu_30758_p3() {
    tmp_1706_fu_30758_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1707_fu_53901_p3() {
    tmp_1707_fu_53901_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1708_fu_30766_p3() {
    tmp_1708_fu_30766_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1709_fu_53909_p3() {
    tmp_1709_fu_53909_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(52, 52);
}

void krnl_sobel::thread_tmp_170_fu_47693_p1() {
    tmp_170_fu_47693_p1 = esl_sext<64,32>(done_cnt6_reg_80663.read());
}

void krnl_sobel::thread_tmp_1710_fu_30774_p3() {
    tmp_1710_fu_30774_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1711_fu_53917_p3() {
    tmp_1711_fu_53917_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1712_fu_30782_p3() {
    tmp_1712_fu_30782_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1713_fu_53925_p3() {
    tmp_1713_fu_53925_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1714_fu_30790_p3() {
    tmp_1714_fu_30790_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1715_fu_53933_p3() {
    tmp_1715_fu_53933_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1716_fu_30798_p3() {
    tmp_1716_fu_30798_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1717_fu_53941_p3() {
    tmp_1717_fu_53941_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1718_fu_30806_p3() {
    tmp_1718_fu_30806_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1719_fu_53949_p3() {
    tmp_1719_fu_53949_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(47, 47);
}

void krnl_sobel::thread_tmp_171_fu_47702_p2() {
    tmp_171_fu_47702_p2 = (!done_cnt6_reg_80663.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt6_reg_80663.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void krnl_sobel::thread_tmp_1720_fu_30814_p3() {
    tmp_1720_fu_30814_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1721_fu_53957_p3() {
    tmp_1721_fu_53957_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1722_fu_30822_p3() {
    tmp_1722_fu_30822_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1723_fu_53965_p3() {
    tmp_1723_fu_53965_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1724_fu_30830_p3() {
    tmp_1724_fu_30830_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1725_fu_53973_p3() {
    tmp_1725_fu_53973_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1726_fu_30838_p3() {
    tmp_1726_fu_30838_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1727_fu_53981_p3() {
    tmp_1727_fu_53981_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1728_fu_30846_p3() {
    tmp_1728_fu_30846_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1729_fu_53989_p3() {
    tmp_1729_fu_53989_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(42, 42);
}

void krnl_sobel::thread_tmp_172_fu_47707_p1() {
    tmp_172_fu_47707_p1 = esl_sext<64,32>(tmp_171_fu_47702_p2.read());
}

void krnl_sobel::thread_tmp_1730_fu_30854_p3() {
    tmp_1730_fu_30854_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1731_fu_53997_p3() {
    tmp_1731_fu_53997_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1732_fu_30862_p3() {
    tmp_1732_fu_30862_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1733_fu_54005_p3() {
    tmp_1733_fu_54005_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1734_fu_30870_p3() {
    tmp_1734_fu_30870_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1735_fu_54013_p3() {
    tmp_1735_fu_54013_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1736_fu_30878_p3() {
    tmp_1736_fu_30878_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1737_fu_54021_p3() {
    tmp_1737_fu_54021_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1738_fu_30886_p3() {
    tmp_1738_fu_30886_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1739_fu_54029_p3() {
    tmp_1739_fu_54029_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(37, 37);
}

void krnl_sobel::thread_tmp_173_cast_fu_47469_p3() {
    tmp_173_cast_fu_47469_p3 = (!mod_ne_zero3_fu_47464_p2.read()[0].is_01())? sc_lv<3>(): ((mod_ne_zero3_fu_47464_p2.read()[0].to_bool())? ap_const_lv3_7: ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_173_fu_47717_p2() {
    tmp_173_fu_47717_p2 = (!done_cnt6_reg_80663.read().is_01() || !ap_const_lv32_2.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt6_reg_80663.read()) + sc_biguint<32>(ap_const_lv32_2));
}

void krnl_sobel::thread_tmp_1740_fu_30894_p3() {
    tmp_1740_fu_30894_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1741_fu_54037_p3() {
    tmp_1741_fu_54037_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1742_fu_30902_p3() {
    tmp_1742_fu_30902_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1743_fu_54045_p3() {
    tmp_1743_fu_54045_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1744_fu_30910_p3() {
    tmp_1744_fu_30910_p3 = p_164_reg2mem697_0_i_i_12_reg_5737.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1745_fu_54053_p3() {
    tmp_1745_fu_54053_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1746_fu_30955_p3() {
    tmp_1746_fu_30955_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1747_fu_54061_p3() {
    tmp_1747_fu_54061_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1748_fu_30963_p3() {
    tmp_1748_fu_30963_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1749_fu_54069_p3() {
    tmp_1749_fu_54069_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(32, 32);
}

void krnl_sobel::thread_tmp_174_cast_fu_47483_p1() {
    tmp_174_cast_fu_47483_p1 = esl_zext<32,3>(tmp_158_fu_47477_p2.read());
}

void krnl_sobel::thread_tmp_174_fu_47722_p1() {
    tmp_174_fu_47722_p1 = esl_sext<64,32>(tmp_173_fu_47717_p2.read());
}

void krnl_sobel::thread_tmp_1750_fu_30971_p3() {
    tmp_1750_fu_30971_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1751_fu_54077_p3() {
    tmp_1751_fu_54077_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1752_fu_30979_p3() {
    tmp_1752_fu_30979_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1753_fu_54085_p3() {
    tmp_1753_fu_54085_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1754_fu_30987_p3() {
    tmp_1754_fu_30987_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1755_fu_54093_p3() {
    tmp_1755_fu_54093_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1756_fu_30995_p3() {
    tmp_1756_fu_30995_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1757_fu_54101_p3() {
    tmp_1757_fu_54101_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1758_fu_31003_p3() {
    tmp_1758_fu_31003_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1759_fu_54109_p3() {
    tmp_1759_fu_54109_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(27, 27);
}

void krnl_sobel::thread_tmp_175_fu_47731_p2() {
    tmp_175_fu_47731_p2 = (!x4_0_reg2mem639_0_i_i_cast_fu_47727_p1.read().is_01() || !tmp_62_reg_71292.read().is_01())? sc_lv<1>(): (sc_bigint<32>(x4_0_reg2mem639_0_i_i_cast_fu_47727_p1.read()) < sc_bigint<32>(tmp_62_reg_71292.read()));
}

void krnl_sobel::thread_tmp_1760_fu_31011_p3() {
    tmp_1760_fu_31011_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1761_fu_54117_p3() {
    tmp_1761_fu_54117_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1762_fu_31019_p3() {
    tmp_1762_fu_31019_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1763_fu_54125_p3() {
    tmp_1763_fu_54125_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1764_fu_31027_p3() {
    tmp_1764_fu_31027_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1765_fu_54133_p3() {
    tmp_1765_fu_54133_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1766_fu_31035_p3() {
    tmp_1766_fu_31035_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1767_fu_54141_p3() {
    tmp_1767_fu_54141_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1768_fu_31043_p3() {
    tmp_1768_fu_31043_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1769_fu_54149_p3() {
    tmp_1769_fu_54149_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(22, 22);
}

void krnl_sobel::thread_tmp_176_fu_43888_p3() {
    tmp_176_fu_43888_p3 = esl_concat<9,55>(xe_i_i_i_0_reg2mem_0_i_i_fu_43883_p2.read(), ap_const_lv55_0);
}

void krnl_sobel::thread_tmp_1770_fu_31051_p3() {
    tmp_1770_fu_31051_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1771_fu_54157_p3() {
    tmp_1771_fu_54157_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1772_fu_31059_p3() {
    tmp_1772_fu_31059_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1773_fu_54165_p3() {
    tmp_1773_fu_54165_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1774_fu_31067_p3() {
    tmp_1774_fu_31067_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1775_fu_54173_p3() {
    tmp_1775_fu_54173_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1776_fu_31075_p3() {
    tmp_1776_fu_31075_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1777_fu_54181_p3() {
    tmp_1777_fu_54181_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1778_fu_31083_p3() {
    tmp_1778_fu_31083_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1779_fu_54189_p3() {
    tmp_1779_fu_54189_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(17, 17);
}

void krnl_sobel::thread_tmp_177_fu_43906_p1() {
    tmp_177_fu_43906_p1 = esl_sext<64,57>(tmp_251_fu_43896_p4.read());
}

void krnl_sobel::thread_tmp_1780_fu_31091_p3() {
    tmp_1780_fu_31091_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1781_fu_54197_p3() {
    tmp_1781_fu_54197_p3 = p_143_reg2mem615_0_i_i_12_reg_15807.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1782_fu_31099_p3() {
    tmp_1782_fu_31099_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1783_fu_54241_p3() {
    tmp_1783_fu_54241_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1784_fu_31107_p3() {
    tmp_1784_fu_31107_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1785_fu_54249_p3() {
    tmp_1785_fu_54249_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1786_fu_31115_p3() {
    tmp_1786_fu_31115_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1787_fu_54257_p3() {
    tmp_1787_fu_54257_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1788_fu_31123_p3() {
    tmp_1788_fu_31123_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1789_fu_54265_p3() {
    tmp_1789_fu_54265_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(58, 58);
}

void krnl_sobel::thread_tmp_178_cast_fu_43972_p3() {
    tmp_178_cast_fu_43972_p3 = esl_concat<55,5>(tmp_4691_reg_79420.read(), ap_const_lv5_0);
}

void krnl_sobel::thread_tmp_1790_fu_31131_p3() {
    tmp_1790_fu_31131_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1791_fu_54273_p3() {
    tmp_1791_fu_54273_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1792_fu_31139_p3() {
    tmp_1792_fu_31139_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1793_fu_54281_p3() {
    tmp_1793_fu_54281_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1794_fu_31147_p3() {
    tmp_1794_fu_31147_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1795_fu_54289_p3() {
    tmp_1795_fu_54289_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1796_fu_31155_p3() {
    tmp_1796_fu_31155_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1797_fu_54297_p3() {
    tmp_1797_fu_54297_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1798_fu_31163_p3() {
    tmp_1798_fu_31163_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1799_fu_54305_p3() {
    tmp_1799_fu_54305_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(53, 53);
}

void krnl_sobel::thread_tmp_179_fu_47736_p2() {
    tmp_179_fu_47736_p2 = (!ap_const_lv31_7FFFFFFF.is_01() || !x4_0_reg2mem639_0_i_i_reg_12926.read().is_01())? sc_lv<31>(): (sc_bigint<31>(ap_const_lv31_7FFFFFFF) + sc_biguint<31>(x4_0_reg2mem639_0_i_i_reg_12926.read()));
}

void krnl_sobel::thread_tmp_17_fu_23704_p2() {
    tmp_17_fu_23704_p2 = (ap_pipeline_reg_pp1_iter1_krnl_sobel_rowbuf0_mult_reg_71054.read() | ap_const_lv32_2);
}

void krnl_sobel::thread_tmp_1800_fu_31171_p3() {
    tmp_1800_fu_31171_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1801_fu_54313_p3() {
    tmp_1801_fu_54313_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1802_fu_31179_p3() {
    tmp_1802_fu_31179_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1803_fu_54321_p3() {
    tmp_1803_fu_54321_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1804_fu_31187_p3() {
    tmp_1804_fu_31187_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1805_fu_54329_p3() {
    tmp_1805_fu_54329_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1806_fu_31195_p3() {
    tmp_1806_fu_31195_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1807_fu_54337_p3() {
    tmp_1807_fu_54337_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1808_fu_31203_p3() {
    tmp_1808_fu_31203_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1809_fu_54345_p3() {
    tmp_1809_fu_54345_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(48, 48);
}

void krnl_sobel::thread_tmp_180_fu_47759_p1() {
    tmp_180_fu_47759_p1 = esl_zext<64,31>(tmp_179_reg_80686.read());
}

void krnl_sobel::thread_tmp_1810_fu_31211_p3() {
    tmp_1810_fu_31211_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1811_fu_54353_p3() {
    tmp_1811_fu_54353_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1812_fu_31219_p3() {
    tmp_1812_fu_31219_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1813_fu_54361_p3() {
    tmp_1813_fu_54361_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1814_fu_31227_p3() {
    tmp_1814_fu_31227_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1815_fu_54369_p3() {
    tmp_1815_fu_54369_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1816_fu_31235_p3() {
    tmp_1816_fu_31235_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1817_fu_54377_p3() {
    tmp_1817_fu_54377_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1818_fu_31243_p3() {
    tmp_1818_fu_31243_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1819_fu_54385_p3() {
    tmp_1819_fu_54385_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(43, 43);
}

void krnl_sobel::thread_tmp_181_cast_fu_47517_p1() {
    tmp_181_cast_fu_47517_p1 = esl_zext<32,5>(tmp_159_fu_47510_p3.read());
}

void krnl_sobel::thread_tmp_181_fu_47922_p3() {
    tmp_181_fu_47922_p3 = esl_concat<8,1>(phi_load6_reg_12949.read(), ap_const_lv1_0);
}

void krnl_sobel::thread_tmp_1820_fu_31251_p3() {
    tmp_1820_fu_31251_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1821_fu_54393_p3() {
    tmp_1821_fu_54393_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1822_fu_31259_p3() {
    tmp_1822_fu_31259_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1823_fu_54401_p3() {
    tmp_1823_fu_54401_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1824_fu_31267_p3() {
    tmp_1824_fu_31267_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1825_fu_54409_p3() {
    tmp_1825_fu_54409_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1826_fu_31275_p3() {
    tmp_1826_fu_31275_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1827_fu_54417_p3() {
    tmp_1827_fu_54417_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1828_fu_31283_p3() {
    tmp_1828_fu_31283_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1829_fu_54425_p3() {
    tmp_1829_fu_54425_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(38, 38);
}

void krnl_sobel::thread_tmp_182_cast_fu_44024_p1() {
    tmp_182_cast_fu_44024_p1 = esl_zext<64,60>(tmp_182_fu_44017_p3.read());
}

void krnl_sobel::thread_tmp_182_fu_44017_p3() {
    tmp_182_fu_44017_p3 = esl_concat<5,55>(ap_const_lv5_0, tmp_4691_reg_79420.read());
}

void krnl_sobel::thread_tmp_1830_fu_31291_p3() {
    tmp_1830_fu_31291_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1831_fu_54433_p3() {
    tmp_1831_fu_54433_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1832_fu_31299_p3() {
    tmp_1832_fu_31299_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1833_fu_54441_p3() {
    tmp_1833_fu_54441_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1834_fu_31307_p3() {
    tmp_1834_fu_31307_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1835_fu_54449_p3() {
    tmp_1835_fu_54449_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1836_fu_31315_p3() {
    tmp_1836_fu_31315_p3 = p_164_reg2mem697_0_i_i_13_reg_5946.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1837_fu_54457_p3() {
    tmp_1837_fu_54457_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1838_fu_31360_p3() {
    tmp_1838_fu_31360_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1839_fu_54465_p3() {
    tmp_1839_fu_54465_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(33, 33);
}

void krnl_sobel::thread_tmp_183_fu_44028_p2() {
    tmp_183_fu_44028_p2 = (!Foy_i_i_i_0_reg2mem_0_i_i_reg_79415.read().is_01() || !tmp_182_cast_fu_44024_p1.read().is_01())? sc_lv<64>(): (sc_biguint<64>(Foy_i_i_i_0_reg2mem_0_i_i_reg_79415.read()) - sc_biguint<64>(tmp_182_cast_fu_44024_p1.read()));
}

void krnl_sobel::thread_tmp_1840_fu_31368_p3() {
    tmp_1840_fu_31368_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1841_fu_54473_p3() {
    tmp_1841_fu_54473_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1842_fu_31376_p3() {
    tmp_1842_fu_31376_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(59, 59);
}

void krnl_sobel::thread_tmp_1843_fu_54481_p3() {
    tmp_1843_fu_54481_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1844_fu_31384_p3() {
    tmp_1844_fu_31384_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1845_fu_54489_p3() {
    tmp_1845_fu_54489_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1846_fu_31392_p3() {
    tmp_1846_fu_31392_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1847_fu_54497_p3() {
    tmp_1847_fu_54497_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1848_fu_31400_p3() {
    tmp_1848_fu_31400_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1849_fu_54505_p3() {
    tmp_1849_fu_54505_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(28, 28);
}

void krnl_sobel::thread_tmp_184_cast1_fu_47580_p1() {
    tmp_184_cast1_fu_47580_p1 = esl_zext<31,1>(p_ph14_reg_12859.read());
}

void krnl_sobel::thread_tmp_184_cast_fu_47561_p1() {
    tmp_184_cast_fu_47561_p1 = esl_zext<63,1>(p_ph14_phi_fu_12864_p8.read());
}

void krnl_sobel::thread_tmp_184_fu_48207_p1() {
    tmp_184_fu_48207_p1 = esl_zext<32,16>(p_reg2mem315_0_i_i_2_cast_fu_48201_p1.read());
}

void krnl_sobel::thread_tmp_1850_fu_31408_p3() {
    tmp_1850_fu_31408_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1851_fu_54513_p3() {
    tmp_1851_fu_54513_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1852_fu_31416_p3() {
    tmp_1852_fu_31416_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1853_fu_54521_p3() {
    tmp_1853_fu_54521_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1854_fu_31424_p3() {
    tmp_1854_fu_31424_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1855_fu_54529_p3() {
    tmp_1855_fu_54529_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1856_fu_31432_p3() {
    tmp_1856_fu_31432_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1857_fu_54537_p3() {
    tmp_1857_fu_54537_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1858_fu_31440_p3() {
    tmp_1858_fu_31440_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1859_fu_54545_p3() {
    tmp_1859_fu_54545_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(23, 23);
}

void krnl_sobel::thread_tmp_1860_fu_31448_p3() {
    tmp_1860_fu_31448_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1861_fu_54553_p3() {
    tmp_1861_fu_54553_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(22, 22);
}

void krnl_sobel::thread_tmp_1862_fu_31456_p3() {
    tmp_1862_fu_31456_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(49, 49);
}

void krnl_sobel::thread_tmp_1863_fu_54561_p3() {
    tmp_1863_fu_54561_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(21, 21);
}

void krnl_sobel::thread_tmp_1864_fu_31464_p3() {
    tmp_1864_fu_31464_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1865_fu_54569_p3() {
    tmp_1865_fu_54569_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(20, 20);
}

void krnl_sobel::thread_tmp_1866_fu_31472_p3() {
    tmp_1866_fu_31472_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1867_fu_54577_p3() {
    tmp_1867_fu_54577_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(19, 19);
}

void krnl_sobel::thread_tmp_1868_fu_31480_p3() {
    tmp_1868_fu_31480_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1869_fu_54585_p3() {
    tmp_1869_fu_54585_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(18, 18);
}

void krnl_sobel::thread_tmp_1870_fu_31488_p3() {
    tmp_1870_fu_31488_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1871_fu_54593_p3() {
    tmp_1871_fu_54593_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(17, 17);
}

void krnl_sobel::thread_tmp_1872_fu_31496_p3() {
    tmp_1872_fu_31496_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(44, 44);
}

void krnl_sobel::thread_tmp_1873_fu_54601_p3() {
    tmp_1873_fu_54601_p3 = p_143_reg2mem615_0_i_i_13_reg_16016.read().range(16, 16);
}

void krnl_sobel::thread_tmp_1874_fu_31504_p3() {
    tmp_1874_fu_31504_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1875_fu_54646_p3() {
    tmp_1875_fu_54646_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(61, 61);
}

void krnl_sobel::thread_tmp_1876_fu_31512_p3() {
    tmp_1876_fu_31512_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(42, 42);
}

void krnl_sobel::thread_tmp_1877_fu_54654_p3() {
    tmp_1877_fu_54654_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(60, 60);
}

void krnl_sobel::thread_tmp_1878_fu_31520_p3() {
    tmp_1878_fu_31520_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(41, 41);
}

void krnl_sobel::thread_tmp_1879_fu_54662_p3() {
    tmp_1879_fu_54662_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(59, 59);
}

void krnl_sobel::thread_tmp_187_fu_48211_p1() {
    tmp_187_fu_48211_p1 = esl_zext<32,16>(p_reg2mem313_0_i_i_2_cast_fu_48204_p1.read());
}

void krnl_sobel::thread_tmp_1880_fu_31528_p3() {
    tmp_1880_fu_31528_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(40, 40);
}

void krnl_sobel::thread_tmp_1881_fu_54670_p3() {
    tmp_1881_fu_54670_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(58, 58);
}

void krnl_sobel::thread_tmp_1882_fu_31536_p3() {
    tmp_1882_fu_31536_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(39, 39);
}

void krnl_sobel::thread_tmp_1883_fu_54678_p3() {
    tmp_1883_fu_54678_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(57, 57);
}

void krnl_sobel::thread_tmp_1884_fu_31544_p3() {
    tmp_1884_fu_31544_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(38, 38);
}

void krnl_sobel::thread_tmp_1885_fu_54686_p3() {
    tmp_1885_fu_54686_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(56, 56);
}

void krnl_sobel::thread_tmp_1886_fu_31552_p3() {
    tmp_1886_fu_31552_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(37, 37);
}

void krnl_sobel::thread_tmp_1887_fu_54694_p3() {
    tmp_1887_fu_54694_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(55, 55);
}

void krnl_sobel::thread_tmp_1888_fu_31560_p3() {
    tmp_1888_fu_31560_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(36, 36);
}

void krnl_sobel::thread_tmp_1889_fu_54702_p3() {
    tmp_1889_fu_54702_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(54, 54);
}

void krnl_sobel::thread_tmp_1890_fu_31568_p3() {
    tmp_1890_fu_31568_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(35, 35);
}

void krnl_sobel::thread_tmp_1891_fu_54710_p3() {
    tmp_1891_fu_54710_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(53, 53);
}

void krnl_sobel::thread_tmp_1892_fu_31576_p3() {
    tmp_1892_fu_31576_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(34, 34);
}

void krnl_sobel::thread_tmp_1893_fu_54718_p3() {
    tmp_1893_fu_54718_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(52, 52);
}

void krnl_sobel::thread_tmp_1894_fu_31584_p3() {
    tmp_1894_fu_31584_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(33, 33);
}

void krnl_sobel::thread_tmp_1895_fu_54726_p3() {
    tmp_1895_fu_54726_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(51, 51);
}

void krnl_sobel::thread_tmp_1896_fu_31592_p3() {
    tmp_1896_fu_31592_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(32, 32);
}

void krnl_sobel::thread_tmp_1897_fu_54734_p3() {
    tmp_1897_fu_54734_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(50, 50);
}

void krnl_sobel::thread_tmp_1898_fu_31600_p3() {
    tmp_1898_fu_31600_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(31, 31);
}

void krnl_sobel::thread_tmp_1899_fu_54742_p3() {
    tmp_1899_fu_54742_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(49, 49);
}

void krnl_sobel::thread_tmp_18_fu_23709_p1() {
    tmp_18_fu_23709_p1 = esl_sext<64,32>(tmp_17_fu_23704_p2.read());
}

void krnl_sobel::thread_tmp_1900_fu_31608_p3() {
    tmp_1900_fu_31608_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(30, 30);
}

void krnl_sobel::thread_tmp_1901_fu_54750_p3() {
    tmp_1901_fu_54750_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(48, 48);
}

void krnl_sobel::thread_tmp_1902_fu_31616_p3() {
    tmp_1902_fu_31616_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(29, 29);
}

void krnl_sobel::thread_tmp_1903_fu_54758_p3() {
    tmp_1903_fu_54758_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(47, 47);
}

void krnl_sobel::thread_tmp_1904_fu_31624_p3() {
    tmp_1904_fu_31624_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(28, 28);
}

void krnl_sobel::thread_tmp_1905_fu_54766_p3() {
    tmp_1905_fu_54766_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(46, 46);
}

void krnl_sobel::thread_tmp_1906_fu_31632_p3() {
    tmp_1906_fu_31632_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(27, 27);
}

void krnl_sobel::thread_tmp_1907_fu_54774_p3() {
    tmp_1907_fu_54774_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(45, 45);
}

void krnl_sobel::thread_tmp_1908_fu_31640_p3() {
    tmp_1908_fu_31640_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(26, 26);
}

void krnl_sobel::thread_tmp_1909_fu_54782_p3() {
    tmp_1909_fu_54782_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(44, 44);
}

void krnl_sobel::thread_tmp_190_fu_47247_p1() {
    tmp_190_fu_47247_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_1910_fu_31648_p3() {
    tmp_1910_fu_31648_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(25, 25);
}

void krnl_sobel::thread_tmp_1911_fu_54790_p3() {
    tmp_1911_fu_54790_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(43, 43);
}

void krnl_sobel::thread_tmp_1912_fu_31656_p3() {
    tmp_1912_fu_31656_p3 = p_164_reg2mem697_0_i_i_14_reg_6155.read().range(24, 24);
}

void krnl_sobel::thread_tmp_1913_fu_54798_p3() {
    tmp_1913_fu_54798_p3 = p_143_reg2mem615_0_i_i_14_reg_16225.read().range(42, 42);
}

}

