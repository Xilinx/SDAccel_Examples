#include "krnl_sobel.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void krnl_sobel::thread_tmp_4296_fu_42135_p3() {
    tmp_4296_fu_42135_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4297_fu_65288_p3() {
    tmp_4297_fu_65288_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4298_fu_42143_p3() {
    tmp_4298_fu_42143_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4299_fu_65296_p3() {
    tmp_4299_fu_65296_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(45, 45);
}

void krnl_sobel::thread_tmp_42_fu_23766_p1() {
    tmp_42_fu_23766_p1 = esl_sext<62,30>(rd_cnt_burst_reg_70824.read());
}

void krnl_sobel::thread_tmp_4300_fu_42151_p3() {
    tmp_4300_fu_42151_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4301_fu_65304_p3() {
    tmp_4301_fu_65304_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4302_fu_42159_p3() {
    tmp_4302_fu_42159_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4303_fu_65312_p3() {
    tmp_4303_fu_65312_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4304_fu_42167_p3() {
    tmp_4304_fu_42167_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4305_fu_65320_p3() {
    tmp_4305_fu_65320_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4306_fu_42175_p3() {
    tmp_4306_fu_42175_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4307_fu_65328_p3() {
    tmp_4307_fu_65328_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4308_fu_42183_p3() {
    tmp_4308_fu_42183_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4309_fu_65336_p3() {
    tmp_4309_fu_65336_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(40, 40);
}

void krnl_sobel::thread_tmp_430_fu_47042_p2() {
    tmp_430_fu_47042_p2 = (tmp_428_fu_47036_p2.read() & tmp_429_reg_80353.read());
}

void krnl_sobel::thread_tmp_4310_fu_42191_p3() {
    tmp_4310_fu_42191_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4311_fu_65344_p3() {
    tmp_4311_fu_65344_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4312_fu_42199_p3() {
    tmp_4312_fu_42199_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4313_fu_65352_p3() {
    tmp_4313_fu_65352_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4314_fu_42207_p3() {
    tmp_4314_fu_42207_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4315_fu_65360_p3() {
    tmp_4315_fu_65360_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4316_fu_42215_p3() {
    tmp_4316_fu_42215_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4317_fu_65368_p3() {
    tmp_4317_fu_65368_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4318_fu_42223_p3() {
    tmp_4318_fu_42223_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4319_fu_65376_p3() {
    tmp_4319_fu_65376_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(35, 35);
}

void krnl_sobel::thread_tmp_431_fu_67245_p1() {
    tmp_431_fu_67245_p1 = esl_zext<64,63>(p_lshr1_reg_88559.read());
}

void krnl_sobel::thread_tmp_4320_fu_42231_p3() {
    tmp_4320_fu_42231_p3 = p_164_reg2mem697_0_i_i_40_reg_11589.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4321_fu_65384_p3() {
    tmp_4321_fu_65384_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4322_fu_42275_p3() {
    tmp_4322_fu_42275_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4323_fu_65392_p3() {
    tmp_4323_fu_65392_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4324_fu_42283_p3() {
    tmp_4324_fu_42283_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4325_fu_65400_p3() {
    tmp_4325_fu_65400_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4326_fu_42291_p3() {
    tmp_4326_fu_42291_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4327_fu_65408_p3() {
    tmp_4327_fu_65408_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4328_fu_42299_p3() {
    tmp_4328_fu_42299_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4329_fu_65416_p3() {
    tmp_4329_fu_65416_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(30, 30);
}

void krnl_sobel::thread_tmp_432_fu_67254_p1() {
    tmp_432_fu_67254_p1 = esl_zext<64,63>(p_lshr_f1_reg_88554.read());
}

void krnl_sobel::thread_tmp_4330_fu_42307_p3() {
    tmp_4330_fu_42307_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4331_fu_65424_p3() {
    tmp_4331_fu_65424_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4332_fu_42315_p3() {
    tmp_4332_fu_42315_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4333_fu_65432_p3() {
    tmp_4333_fu_65432_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4334_fu_42323_p3() {
    tmp_4334_fu_42323_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4335_fu_65440_p3() {
    tmp_4335_fu_65440_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4336_fu_42331_p3() {
    tmp_4336_fu_42331_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4337_fu_65448_p3() {
    tmp_4337_fu_65448_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4338_fu_42339_p3() {
    tmp_4338_fu_42339_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4339_fu_65456_p3() {
    tmp_4339_fu_65456_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(25, 25);
}

void krnl_sobel::thread_tmp_433_fu_25419_p3() {
    tmp_433_fu_25419_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4340_fu_42347_p3() {
    tmp_4340_fu_42347_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4341_fu_65464_p3() {
    tmp_4341_fu_65464_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4342_fu_42355_p3() {
    tmp_4342_fu_42355_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4343_fu_65472_p3() {
    tmp_4343_fu_65472_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4344_fu_42363_p3() {
    tmp_4344_fu_42363_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4345_fu_65480_p3() {
    tmp_4345_fu_65480_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4346_fu_42371_p3() {
    tmp_4346_fu_42371_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4347_fu_65488_p3() {
    tmp_4347_fu_65488_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4348_fu_42379_p3() {
    tmp_4348_fu_42379_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4349_fu_65496_p3() {
    tmp_4349_fu_65496_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(20, 20);
}

void krnl_sobel::thread_tmp_434_fu_48558_p3() {
    tmp_434_fu_48558_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4350_fu_42387_p3() {
    tmp_4350_fu_42387_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4351_fu_65504_p3() {
    tmp_4351_fu_65504_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4352_fu_42395_p3() {
    tmp_4352_fu_42395_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4353_fu_65512_p3() {
    tmp_4353_fu_65512_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4354_fu_42403_p3() {
    tmp_4354_fu_42403_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4355_fu_65520_p3() {
    tmp_4355_fu_65520_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4356_fu_42411_p3() {
    tmp_4356_fu_42411_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4357_fu_65528_p3() {
    tmp_4357_fu_65528_p3 = p_143_reg2mem615_0_i_i_40_reg_21659.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4358_fu_42419_p3() {
    tmp_4358_fu_42419_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4359_fu_65573_p3() {
    tmp_4359_fu_65573_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(61, 61);
}

void krnl_sobel::thread_tmp_435_fu_25427_p3() {
    tmp_435_fu_25427_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4360_fu_42427_p3() {
    tmp_4360_fu_42427_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4361_fu_65581_p3() {
    tmp_4361_fu_65581_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4362_fu_42435_p3() {
    tmp_4362_fu_42435_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4363_fu_65589_p3() {
    tmp_4363_fu_65589_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4364_fu_42443_p3() {
    tmp_4364_fu_42443_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4365_fu_65597_p3() {
    tmp_4365_fu_65597_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4366_fu_42451_p3() {
    tmp_4366_fu_42451_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4367_fu_65605_p3() {
    tmp_4367_fu_65605_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4368_fu_42459_p3() {
    tmp_4368_fu_42459_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4369_fu_65613_p3() {
    tmp_4369_fu_65613_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(56, 56);
}

void krnl_sobel::thread_tmp_436_fu_67389_p3() {
    tmp_436_fu_67389_p3 = (!tmp_4824_reg_88581.read()[0].is_01())? sc_lv<2>(): ((tmp_4824_reg_88581.read()[0].to_bool())? ap_const_lv2_2: ap_const_lv2_3);
}

void krnl_sobel::thread_tmp_4370_fu_42467_p3() {
    tmp_4370_fu_42467_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4371_fu_65621_p3() {
    tmp_4371_fu_65621_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4372_fu_42475_p3() {
    tmp_4372_fu_42475_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4373_fu_65629_p3() {
    tmp_4373_fu_65629_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4374_fu_42483_p3() {
    tmp_4374_fu_42483_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4375_fu_65637_p3() {
    tmp_4375_fu_65637_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4376_fu_42491_p3() {
    tmp_4376_fu_42491_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4377_fu_65645_p3() {
    tmp_4377_fu_65645_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4378_fu_42499_p3() {
    tmp_4378_fu_42499_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4379_fu_65653_p3() {
    tmp_4379_fu_65653_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(51, 51);
}

void krnl_sobel::thread_tmp_437_fu_67426_p4() {
    tmp_437_fu_67426_p4 = p_reg2mem231_0_i_i_1_fu_67381_p3.read().range(58, 3);
}

void krnl_sobel::thread_tmp_4380_fu_42507_p3() {
    tmp_4380_fu_42507_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4381_fu_65661_p3() {
    tmp_4381_fu_65661_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4382_fu_42515_p3() {
    tmp_4382_fu_42515_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4383_fu_65669_p3() {
    tmp_4383_fu_65669_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4384_fu_42523_p3() {
    tmp_4384_fu_42523_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4385_fu_65677_p3() {
    tmp_4385_fu_65677_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4386_fu_42531_p3() {
    tmp_4386_fu_42531_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4387_fu_65685_p3() {
    tmp_4387_fu_65685_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4388_fu_42539_p3() {
    tmp_4388_fu_42539_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4389_fu_65693_p3() {
    tmp_4389_fu_65693_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(46, 46);
}

void krnl_sobel::thread_tmp_438_fu_67487_p4() {
    tmp_438_fu_67487_p4 = y_i16_i_i_i20_1_reg2mem597_0_i_2_fu_67464_p3.read().range(61, 4);
}

void krnl_sobel::thread_tmp_4390_fu_42547_p3() {
    tmp_4390_fu_42547_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4391_fu_65701_p3() {
    tmp_4391_fu_65701_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4392_fu_42555_p3() {
    tmp_4392_fu_42555_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4393_fu_65709_p3() {
    tmp_4393_fu_65709_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4394_fu_42563_p3() {
    tmp_4394_fu_42563_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4395_fu_65717_p3() {
    tmp_4395_fu_65717_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4396_fu_42571_p3() {
    tmp_4396_fu_42571_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4397_fu_65725_p3() {
    tmp_4397_fu_65725_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4398_fu_42579_p3() {
    tmp_4398_fu_42579_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4399_fu_65733_p3() {
    tmp_4399_fu_65733_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(41, 41);
}

void krnl_sobel::thread_tmp_439_fu_67540_p4() {
    tmp_439_fu_67540_p4 = y_i16_i_i_i20_1_reg2mem597_0_i_3_fu_67517_p3.read().range(61, 5);
}

void krnl_sobel::thread_tmp_43_fu_23806_p2() {
    tmp_43_fu_23806_p2 = (prealign_wr_cnt_fu_23788_p2.read() & tmp_44_cast_fu_23798_p3.read());
}

void krnl_sobel::thread_tmp_4400_fu_42587_p3() {
    tmp_4400_fu_42587_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4401_fu_65741_p3() {
    tmp_4401_fu_65741_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4402_fu_42595_p3() {
    tmp_4402_fu_42595_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4403_fu_65749_p3() {
    tmp_4403_fu_65749_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4404_fu_42603_p3() {
    tmp_4404_fu_42603_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4405_fu_65757_p3() {
    tmp_4405_fu_65757_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4406_fu_42611_p3() {
    tmp_4406_fu_42611_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4407_fu_65765_p3() {
    tmp_4407_fu_65765_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4408_fu_42619_p3() {
    tmp_4408_fu_42619_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4409_fu_65773_p3() {
    tmp_4409_fu_65773_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4410_fu_42627_p3() {
    tmp_4410_fu_42627_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4411_fu_65781_p3() {
    tmp_4411_fu_65781_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4412_fu_42635_p3() {
    tmp_4412_fu_42635_p3 = p_164_reg2mem697_0_i_i_41_reg_11798.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4413_fu_65789_p3() {
    tmp_4413_fu_65789_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4414_fu_42680_p3() {
    tmp_4414_fu_42680_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4415_fu_65797_p3() {
    tmp_4415_fu_65797_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4416_fu_42688_p3() {
    tmp_4416_fu_42688_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4417_fu_65805_p3() {
    tmp_4417_fu_65805_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4418_fu_42696_p3() {
    tmp_4418_fu_42696_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4419_fu_65813_p3() {
    tmp_4419_fu_65813_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4420_fu_42704_p3() {
    tmp_4420_fu_42704_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4421_fu_65821_p3() {
    tmp_4421_fu_65821_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4422_fu_42712_p3() {
    tmp_4422_fu_42712_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4423_fu_65829_p3() {
    tmp_4423_fu_65829_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4424_fu_42720_p3() {
    tmp_4424_fu_42720_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4425_fu_65837_p3() {
    tmp_4425_fu_65837_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4426_fu_42728_p3() {
    tmp_4426_fu_42728_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4427_fu_65845_p3() {
    tmp_4427_fu_65845_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4428_fu_42736_p3() {
    tmp_4428_fu_42736_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4429_fu_65853_p3() {
    tmp_4429_fu_65853_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4430_fu_42744_p3() {
    tmp_4430_fu_42744_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4431_fu_65861_p3() {
    tmp_4431_fu_65861_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4432_fu_42752_p3() {
    tmp_4432_fu_42752_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4433_fu_65869_p3() {
    tmp_4433_fu_65869_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4434_fu_42760_p3() {
    tmp_4434_fu_42760_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4435_fu_65877_p3() {
    tmp_4435_fu_65877_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4436_fu_42768_p3() {
    tmp_4436_fu_42768_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4437_fu_65885_p3() {
    tmp_4437_fu_65885_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4438_fu_42776_p3() {
    tmp_4438_fu_42776_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4439_fu_65893_p3() {
    tmp_4439_fu_65893_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4440_fu_42784_p3() {
    tmp_4440_fu_42784_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4441_fu_65901_p3() {
    tmp_4441_fu_65901_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4442_fu_42792_p3() {
    tmp_4442_fu_42792_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4443_fu_65909_p3() {
    tmp_4443_fu_65909_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4444_fu_42800_p3() {
    tmp_4444_fu_42800_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4445_fu_65917_p3() {
    tmp_4445_fu_65917_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4446_fu_42808_p3() {
    tmp_4446_fu_42808_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4447_fu_65925_p3() {
    tmp_4447_fu_65925_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4448_fu_42816_p3() {
    tmp_4448_fu_42816_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4449_fu_65933_p3() {
    tmp_4449_fu_65933_p3 = p_143_reg2mem615_0_i_i_41_reg_21868.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4450_fu_42824_p3() {
    tmp_4450_fu_42824_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4451_fu_65977_p3() {
    tmp_4451_fu_65977_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4452_fu_42832_p3() {
    tmp_4452_fu_42832_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4453_fu_65985_p3() {
    tmp_4453_fu_65985_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4454_fu_42840_p3() {
    tmp_4454_fu_42840_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4455_fu_65993_p3() {
    tmp_4455_fu_65993_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4456_fu_42848_p3() {
    tmp_4456_fu_42848_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4457_fu_66001_p3() {
    tmp_4457_fu_66001_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4458_fu_42856_p3() {
    tmp_4458_fu_42856_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4459_fu_66009_p3() {
    tmp_4459_fu_66009_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4460_fu_42864_p3() {
    tmp_4460_fu_42864_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4461_fu_66017_p3() {
    tmp_4461_fu_66017_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4462_fu_42872_p3() {
    tmp_4462_fu_42872_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4463_fu_66025_p3() {
    tmp_4463_fu_66025_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4464_fu_42880_p3() {
    tmp_4464_fu_42880_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4465_fu_66033_p3() {
    tmp_4465_fu_66033_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4466_fu_42888_p3() {
    tmp_4466_fu_42888_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4467_fu_66041_p3() {
    tmp_4467_fu_66041_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4468_fu_42896_p3() {
    tmp_4468_fu_42896_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4469_fu_66049_p3() {
    tmp_4469_fu_66049_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4470_fu_42904_p3() {
    tmp_4470_fu_42904_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4471_fu_66057_p3() {
    tmp_4471_fu_66057_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4472_fu_42912_p3() {
    tmp_4472_fu_42912_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4473_fu_66065_p3() {
    tmp_4473_fu_66065_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4474_fu_42920_p3() {
    tmp_4474_fu_42920_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4475_fu_66073_p3() {
    tmp_4475_fu_66073_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4476_fu_42928_p3() {
    tmp_4476_fu_42928_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4477_fu_66081_p3() {
    tmp_4477_fu_66081_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4478_fu_42936_p3() {
    tmp_4478_fu_42936_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4479_fu_66089_p3() {
    tmp_4479_fu_66089_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4480_fu_42944_p3() {
    tmp_4480_fu_42944_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4481_fu_66097_p3() {
    tmp_4481_fu_66097_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4482_fu_42952_p3() {
    tmp_4482_fu_42952_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4483_fu_66105_p3() {
    tmp_4483_fu_66105_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4484_fu_42960_p3() {
    tmp_4484_fu_42960_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4485_fu_66113_p3() {
    tmp_4485_fu_66113_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4486_fu_42968_p3() {
    tmp_4486_fu_42968_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4487_fu_66121_p3() {
    tmp_4487_fu_66121_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4488_fu_42976_p3() {
    tmp_4488_fu_42976_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4489_fu_66129_p3() {
    tmp_4489_fu_66129_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4490_fu_42984_p3() {
    tmp_4490_fu_42984_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4491_fu_66137_p3() {
    tmp_4491_fu_66137_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4492_fu_42992_p3() {
    tmp_4492_fu_42992_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4493_fu_66145_p3() {
    tmp_4493_fu_66145_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4494_fu_43000_p3() {
    tmp_4494_fu_43000_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4495_fu_66153_p3() {
    tmp_4495_fu_66153_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4496_fu_43008_p3() {
    tmp_4496_fu_43008_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4497_fu_66161_p3() {
    tmp_4497_fu_66161_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4498_fu_43016_p3() {
    tmp_4498_fu_43016_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4499_fu_66169_p3() {
    tmp_4499_fu_66169_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(37, 37);
}

void krnl_sobel::thread_tmp_44_cast_fu_23798_p3() {
    tmp_44_cast_fu_23798_p3 = (!mod_ne_zero1_fu_23793_p2.read()[0].is_01())? sc_lv<3>(): ((mod_ne_zero1_fu_23793_p2.read()[0].to_bool())? ap_const_lv3_7: ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_44_fu_23839_p3() {
    tmp_44_fu_23839_p3 = esl_concat<2,3>(tmp_5_reg_70799.read(), ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_4500_fu_43024_p3() {
    tmp_4500_fu_43024_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4501_fu_66177_p3() {
    tmp_4501_fu_66177_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4502_fu_43032_p3() {
    tmp_4502_fu_43032_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4503_fu_66185_p3() {
    tmp_4503_fu_66185_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4504_fu_43040_p3() {
    tmp_4504_fu_43040_p3 = p_164_reg2mem697_0_i_i_42_reg_12007.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4505_fu_66193_p3() {
    tmp_4505_fu_66193_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4506_fu_43085_p3() {
    tmp_4506_fu_43085_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4507_fu_66201_p3() {
    tmp_4507_fu_66201_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4508_fu_43093_p3() {
    tmp_4508_fu_43093_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4509_fu_66209_p3() {
    tmp_4509_fu_66209_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4510_fu_43101_p3() {
    tmp_4510_fu_43101_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4511_fu_66217_p3() {
    tmp_4511_fu_66217_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4512_fu_43109_p3() {
    tmp_4512_fu_43109_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4513_fu_66225_p3() {
    tmp_4513_fu_66225_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4514_fu_43117_p3() {
    tmp_4514_fu_43117_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4515_fu_66233_p3() {
    tmp_4515_fu_66233_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4516_fu_43125_p3() {
    tmp_4516_fu_43125_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4517_fu_66241_p3() {
    tmp_4517_fu_66241_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4518_fu_43133_p3() {
    tmp_4518_fu_43133_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4519_fu_66249_p3() {
    tmp_4519_fu_66249_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4520_fu_43141_p3() {
    tmp_4520_fu_43141_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4521_fu_66257_p3() {
    tmp_4521_fu_66257_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4522_fu_43149_p3() {
    tmp_4522_fu_43149_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4523_fu_66265_p3() {
    tmp_4523_fu_66265_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4524_fu_43157_p3() {
    tmp_4524_fu_43157_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4525_fu_66273_p3() {
    tmp_4525_fu_66273_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4526_fu_43165_p3() {
    tmp_4526_fu_43165_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4527_fu_66281_p3() {
    tmp_4527_fu_66281_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4528_fu_43173_p3() {
    tmp_4528_fu_43173_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4529_fu_66289_p3() {
    tmp_4529_fu_66289_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4530_fu_43181_p3() {
    tmp_4530_fu_43181_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4531_fu_66297_p3() {
    tmp_4531_fu_66297_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4532_fu_43189_p3() {
    tmp_4532_fu_43189_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4533_fu_66305_p3() {
    tmp_4533_fu_66305_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4534_fu_43197_p3() {
    tmp_4534_fu_43197_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4535_fu_66313_p3() {
    tmp_4535_fu_66313_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4536_fu_43205_p3() {
    tmp_4536_fu_43205_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4537_fu_66321_p3() {
    tmp_4537_fu_66321_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4538_fu_43213_p3() {
    tmp_4538_fu_43213_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4539_fu_66329_p3() {
    tmp_4539_fu_66329_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4540_fu_43221_p3() {
    tmp_4540_fu_43221_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4541_fu_66337_p3() {
    tmp_4541_fu_66337_p3 = p_143_reg2mem615_0_i_i_42_reg_22077.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4542_fu_43229_p3() {
    tmp_4542_fu_43229_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4543_fu_66382_p3() {
    tmp_4543_fu_66382_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4544_fu_43237_p3() {
    tmp_4544_fu_43237_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4545_fu_66390_p3() {
    tmp_4545_fu_66390_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4546_fu_43245_p3() {
    tmp_4546_fu_43245_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4547_fu_66398_p3() {
    tmp_4547_fu_66398_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4548_fu_43253_p3() {
    tmp_4548_fu_43253_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4549_fu_66406_p3() {
    tmp_4549_fu_66406_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4550_fu_43261_p3() {
    tmp_4550_fu_43261_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4551_fu_66414_p3() {
    tmp_4551_fu_66414_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4552_fu_43269_p3() {
    tmp_4552_fu_43269_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4553_fu_66422_p3() {
    tmp_4553_fu_66422_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4554_fu_43277_p3() {
    tmp_4554_fu_43277_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4555_fu_66430_p3() {
    tmp_4555_fu_66430_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4556_fu_43285_p3() {
    tmp_4556_fu_43285_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4557_fu_66438_p3() {
    tmp_4557_fu_66438_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4558_fu_43293_p3() {
    tmp_4558_fu_43293_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4559_fu_66446_p3() {
    tmp_4559_fu_66446_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4560_fu_43301_p3() {
    tmp_4560_fu_43301_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4561_fu_66454_p3() {
    tmp_4561_fu_66454_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4562_fu_43309_p3() {
    tmp_4562_fu_43309_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4563_fu_66462_p3() {
    tmp_4563_fu_66462_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4564_fu_43317_p3() {
    tmp_4564_fu_43317_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4565_fu_66470_p3() {
    tmp_4565_fu_66470_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4566_fu_43325_p3() {
    tmp_4566_fu_43325_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4567_fu_66478_p3() {
    tmp_4567_fu_66478_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4568_fu_43333_p3() {
    tmp_4568_fu_43333_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4569_fu_66486_p3() {
    tmp_4569_fu_66486_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4570_fu_43341_p3() {
    tmp_4570_fu_43341_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4571_fu_66494_p3() {
    tmp_4571_fu_66494_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4572_fu_43349_p3() {
    tmp_4572_fu_43349_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4573_fu_66502_p3() {
    tmp_4573_fu_66502_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4574_fu_43357_p3() {
    tmp_4574_fu_43357_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4575_fu_66510_p3() {
    tmp_4575_fu_66510_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4576_fu_43365_p3() {
    tmp_4576_fu_43365_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4577_fu_66518_p3() {
    tmp_4577_fu_66518_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4578_fu_43373_p3() {
    tmp_4578_fu_43373_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4579_fu_66526_p3() {
    tmp_4579_fu_66526_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4580_fu_43381_p3() {
    tmp_4580_fu_43381_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4581_fu_66534_p3() {
    tmp_4581_fu_66534_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4582_fu_43389_p3() {
    tmp_4582_fu_43389_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4583_fu_66542_p3() {
    tmp_4583_fu_66542_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4584_fu_43397_p3() {
    tmp_4584_fu_43397_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4585_fu_66550_p3() {
    tmp_4585_fu_66550_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4586_fu_43405_p3() {
    tmp_4586_fu_43405_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4587_fu_66558_p3() {
    tmp_4587_fu_66558_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4588_fu_43413_p3() {
    tmp_4588_fu_43413_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4589_fu_66566_p3() {
    tmp_4589_fu_66566_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4590_fu_43421_p3() {
    tmp_4590_fu_43421_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4591_fu_66574_p3() {
    tmp_4591_fu_66574_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4592_fu_43429_p3() {
    tmp_4592_fu_43429_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4593_fu_66582_p3() {
    tmp_4593_fu_66582_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4594_fu_43437_p3() {
    tmp_4594_fu_43437_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4595_fu_66590_p3() {
    tmp_4595_fu_66590_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4596_fu_43445_p3() {
    tmp_4596_fu_43445_p3 = p_164_reg2mem697_0_i_i_43_reg_12216.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4597_fu_66598_p3() {
    tmp_4597_fu_66598_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4598_fu_43490_p3() {
    tmp_4598_fu_43490_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4599_fu_66606_p3() {
    tmp_4599_fu_66606_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(33, 33);
}

void krnl_sobel::thread_tmp_45_cast_fu_23812_p1() {
    tmp_45_cast_fu_23812_p1 = esl_zext<32,3>(tmp_43_fu_23806_p2.read());
}

void krnl_sobel::thread_tmp_45_fu_23912_p3() {
    tmp_45_fu_23912_p3 = esl_concat<30,2>(rd_cnt_burst1_reg_71118.read(), ap_const_lv2_0);
}

void krnl_sobel::thread_tmp_4600_fu_43498_p3() {
    tmp_4600_fu_43498_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4601_fu_66614_p3() {
    tmp_4601_fu_66614_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4602_fu_43506_p3() {
    tmp_4602_fu_43506_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4603_fu_66622_p3() {
    tmp_4603_fu_66622_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4604_fu_43514_p3() {
    tmp_4604_fu_43514_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4605_fu_66630_p3() {
    tmp_4605_fu_66630_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4606_fu_43522_p3() {
    tmp_4606_fu_43522_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4607_fu_66638_p3() {
    tmp_4607_fu_66638_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4608_fu_43530_p3() {
    tmp_4608_fu_43530_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4609_fu_66646_p3() {
    tmp_4609_fu_66646_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4610_fu_43538_p3() {
    tmp_4610_fu_43538_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4611_fu_66654_p3() {
    tmp_4611_fu_66654_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4612_fu_43546_p3() {
    tmp_4612_fu_43546_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4613_fu_66662_p3() {
    tmp_4613_fu_66662_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4614_fu_43554_p3() {
    tmp_4614_fu_43554_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4615_fu_66670_p3() {
    tmp_4615_fu_66670_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4616_fu_43562_p3() {
    tmp_4616_fu_43562_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4617_fu_66678_p3() {
    tmp_4617_fu_66678_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4618_fu_43570_p3() {
    tmp_4618_fu_43570_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4619_fu_66686_p3() {
    tmp_4619_fu_66686_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4620_fu_43578_p3() {
    tmp_4620_fu_43578_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4621_fu_66694_p3() {
    tmp_4621_fu_66694_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4622_fu_43586_p3() {
    tmp_4622_fu_43586_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4623_fu_66702_p3() {
    tmp_4623_fu_66702_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4624_fu_43594_p3() {
    tmp_4624_fu_43594_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4625_fu_66710_p3() {
    tmp_4625_fu_66710_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4626_fu_43602_p3() {
    tmp_4626_fu_43602_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4627_fu_66718_p3() {
    tmp_4627_fu_66718_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4628_fu_43610_p3() {
    tmp_4628_fu_43610_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4629_fu_66726_p3() {
    tmp_4629_fu_66726_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4630_fu_43618_p3() {
    tmp_4630_fu_43618_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4631_fu_66734_p3() {
    tmp_4631_fu_66734_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4632_fu_43626_p3() {
    tmp_4632_fu_43626_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4633_fu_66742_p3() {
    tmp_4633_fu_66742_p3 = p_143_reg2mem615_0_i_i_43_reg_22286.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4634_fu_43634_p3() {
    tmp_4634_fu_43634_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4635_fu_66786_p3() {
    tmp_4635_fu_66786_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(61, 61);
}

void krnl_sobel::thread_tmp_4636_fu_43642_p3() {
    tmp_4636_fu_43642_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4637_fu_66794_p3() {
    tmp_4637_fu_66794_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4638_fu_43650_p3() {
    tmp_4638_fu_43650_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4639_fu_66802_p3() {
    tmp_4639_fu_66802_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4640_fu_43658_p3() {
    tmp_4640_fu_43658_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4641_fu_66810_p3() {
    tmp_4641_fu_66810_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4642_fu_43666_p3() {
    tmp_4642_fu_43666_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4643_fu_66818_p3() {
    tmp_4643_fu_66818_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(57, 57);
}

void krnl_sobel::thread_tmp_4644_fu_43674_p3() {
    tmp_4644_fu_43674_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4645_fu_66826_p3() {
    tmp_4645_fu_66826_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(56, 56);
}

void krnl_sobel::thread_tmp_4646_fu_43682_p3() {
    tmp_4646_fu_43682_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4647_fu_66834_p3() {
    tmp_4647_fu_66834_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(55, 55);
}

void krnl_sobel::thread_tmp_4648_fu_43690_p3() {
    tmp_4648_fu_43690_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4649_fu_66842_p3() {
    tmp_4649_fu_66842_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(54, 54);
}

void krnl_sobel::thread_tmp_4650_fu_43698_p3() {
    tmp_4650_fu_43698_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4651_fu_66850_p3() {
    tmp_4651_fu_66850_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(53, 53);
}

void krnl_sobel::thread_tmp_4652_fu_43706_p3() {
    tmp_4652_fu_43706_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4653_fu_66858_p3() {
    tmp_4653_fu_66858_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(52, 52);
}

void krnl_sobel::thread_tmp_4654_fu_43714_p3() {
    tmp_4654_fu_43714_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4655_fu_66866_p3() {
    tmp_4655_fu_66866_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(51, 51);
}

void krnl_sobel::thread_tmp_4656_fu_43722_p3() {
    tmp_4656_fu_43722_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4657_fu_66874_p3() {
    tmp_4657_fu_66874_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(50, 50);
}

void krnl_sobel::thread_tmp_4658_fu_43730_p3() {
    tmp_4658_fu_43730_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4659_fu_66882_p3() {
    tmp_4659_fu_66882_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(49, 49);
}

void krnl_sobel::thread_tmp_4660_fu_43738_p3() {
    tmp_4660_fu_43738_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4661_fu_66890_p3() {
    tmp_4661_fu_66890_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(48, 48);
}

void krnl_sobel::thread_tmp_4662_fu_43746_p3() {
    tmp_4662_fu_43746_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4663_fu_66898_p3() {
    tmp_4663_fu_66898_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(47, 47);
}

void krnl_sobel::thread_tmp_4664_fu_43754_p3() {
    tmp_4664_fu_43754_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4665_fu_66906_p3() {
    tmp_4665_fu_66906_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(46, 46);
}

void krnl_sobel::thread_tmp_4666_fu_43762_p3() {
    tmp_4666_fu_43762_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4667_fu_66914_p3() {
    tmp_4667_fu_66914_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(45, 45);
}

void krnl_sobel::thread_tmp_4668_fu_43770_p3() {
    tmp_4668_fu_43770_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4669_fu_66922_p3() {
    tmp_4669_fu_66922_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(44, 44);
}

void krnl_sobel::thread_tmp_4670_fu_43778_p3() {
    tmp_4670_fu_43778_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4671_fu_66930_p3() {
    tmp_4671_fu_66930_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(43, 43);
}

void krnl_sobel::thread_tmp_4672_fu_43786_p3() {
    tmp_4672_fu_43786_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4673_fu_66938_p3() {
    tmp_4673_fu_66938_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(42, 42);
}

void krnl_sobel::thread_tmp_4674_fu_43794_p3() {
    tmp_4674_fu_43794_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4675_fu_66946_p3() {
    tmp_4675_fu_66946_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4676_fu_43802_p3() {
    tmp_4676_fu_43802_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4677_fu_66954_p3() {
    tmp_4677_fu_66954_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4678_fu_43810_p3() {
    tmp_4678_fu_43810_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4679_fu_66962_p3() {
    tmp_4679_fu_66962_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4680_fu_43818_p3() {
    tmp_4680_fu_43818_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4681_fu_66970_p3() {
    tmp_4681_fu_66970_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(38, 38);
}

void krnl_sobel::thread_tmp_4682_fu_43826_p3() {
    tmp_4682_fu_43826_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4683_fu_66978_p3() {
    tmp_4683_fu_66978_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(37, 37);
}

void krnl_sobel::thread_tmp_4684_fu_43834_p3() {
    tmp_4684_fu_43834_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4685_fu_66986_p3() {
    tmp_4685_fu_66986_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(36, 36);
}

void krnl_sobel::thread_tmp_4686_fu_43842_p3() {
    tmp_4686_fu_43842_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4687_fu_66994_p3() {
    tmp_4687_fu_66994_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(35, 35);
}

void krnl_sobel::thread_tmp_4688_fu_43850_p3() {
    tmp_4688_fu_43850_p3 = p_164_reg2mem697_0_i_i_44_reg_12425.read().range(16, 16);
}

void krnl_sobel::thread_tmp_4689_fu_67002_p3() {
    tmp_4689_fu_67002_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(34, 34);
}

void krnl_sobel::thread_tmp_4691_fu_43968_p1() {
    tmp_4691_fu_43968_p1 = Foy_i_i_i_0_reg2mem_0_i_i_fu_43961_p3.read().range(55-1, 0);
}

void krnl_sobel::thread_tmp_4692_fu_43989_p1() {
    tmp_4692_fu_43989_p1 = D_i_i_i_i_0_reg2mem_0_i_i_fu_43983_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4693_fu_43993_p3() {
    tmp_4693_fu_43993_p3 = D_i_i_i_i_0_reg2mem_0_i_i_fu_43983_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4695_fu_44052_p1() {
    tmp_4695_fu_44052_p1 = D_i_i_i_i_0_reg2mem_0_i_i_1_fu_44046_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4696_fu_44056_p3() {
    tmp_4696_fu_44056_p3 = D_i_i_i_i_0_reg2mem_0_i_i_1_fu_44046_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4697_fu_44078_p2() {
    tmp_4697_fu_44078_p2 = (tmp_4696_reg_79449.read() | tmp_4694_reg_79426.read());
}

void krnl_sobel::thread_tmp_4698_fu_44118_p1() {
    tmp_4698_fu_44118_p1 = D_i_i_i_i_0_reg2mem_0_i_i_2_fu_44112_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4699_fu_44122_p3() {
    tmp_4699_fu_44122_p3 = D_i_i_i_i_0_reg2mem_0_i_i_2_fu_44112_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_46_cast_fu_23846_p1() {
    tmp_46_cast_fu_23846_p1 = esl_zext<32,5>(tmp_44_fu_23839_p3.read());
}

void krnl_sobel::thread_tmp_46_fu_23919_p2() {
    tmp_46_fu_23919_p2 = (!p_ph6_reg_2718.read().is_01() || !tmp_45_fu_23912_p3.read().is_01())? sc_lv<32>(): (sc_biguint<32>(p_ph6_reg_2718.read()) - sc_biguint<32>(tmp_45_fu_23912_p3.read()));
}

void krnl_sobel::thread_tmp_4700_fu_44179_p1() {
    tmp_4700_fu_44179_p1 = D_i_i_i_i_0_reg2mem_0_i_i_3_fu_44173_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4701_fu_44183_p3() {
    tmp_4701_fu_44183_p3 = D_i_i_i_i_0_reg2mem_0_i_i_3_fu_44173_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4702_fu_44232_p1() {
    tmp_4702_fu_44232_p1 = D_i_i_i_i_0_reg2mem_0_i_i_4_fu_44226_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4703_fu_44236_p3() {
    tmp_4703_fu_44236_p3 = D_i_i_i_i_0_reg2mem_0_i_i_4_fu_44226_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4704_fu_44298_p1() {
    tmp_4704_fu_44298_p1 = D_i_i_i_i_0_reg2mem_0_i_i_5_fu_44292_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4705_fu_44302_p3() {
    tmp_4705_fu_44302_p3 = D_i_i_i_i_0_reg2mem_0_i_i_5_fu_44292_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4706_fu_44351_p1() {
    tmp_4706_fu_44351_p1 = D_i_i_i_i_0_reg2mem_0_i_i_6_fu_44345_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4707_fu_44355_p3() {
    tmp_4707_fu_44355_p3 = D_i_i_i_i_0_reg2mem_0_i_i_6_fu_44345_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4708_fu_44404_p1() {
    tmp_4708_fu_44404_p1 = D_i_i_i_i_0_reg2mem_0_i_i_7_fu_44398_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4709_fu_44408_p3() {
    tmp_4709_fu_44408_p3 = D_i_i_i_i_0_reg2mem_0_i_i_7_fu_44398_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4710_fu_44457_p1() {
    tmp_4710_fu_44457_p1 = D_i_i_i_i_0_reg2mem_0_i_i_8_fu_44451_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4711_fu_44461_p3() {
    tmp_4711_fu_44461_p3 = D_i_i_i_i_0_reg2mem_0_i_i_8_fu_44451_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4712_fu_44510_p1() {
    tmp_4712_fu_44510_p1 = D_i_i_i_i_0_reg2mem_0_i_i_9_fu_44504_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4713_fu_44514_p3() {
    tmp_4713_fu_44514_p3 = D_i_i_i_i_0_reg2mem_0_i_i_9_fu_44504_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4714_fu_44563_p1() {
    tmp_4714_fu_44563_p1 = D_i_i_i_i_0_reg2mem_0_i_i_s_fu_44557_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4715_fu_44567_p3() {
    tmp_4715_fu_44567_p3 = D_i_i_i_i_0_reg2mem_0_i_i_s_fu_44557_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4716_fu_44616_p1() {
    tmp_4716_fu_44616_p1 = D_i_i_i_i_0_reg2mem_0_i_i_10_fu_44610_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4717_fu_44620_p3() {
    tmp_4717_fu_44620_p3 = D_i_i_i_i_0_reg2mem_0_i_i_10_fu_44610_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4718_fu_44669_p1() {
    tmp_4718_fu_44669_p1 = D_i_i_i_i_0_reg2mem_0_i_i_11_fu_44663_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4719_fu_44673_p3() {
    tmp_4719_fu_44673_p3 = D_i_i_i_i_0_reg2mem_0_i_i_11_fu_44663_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4720_fu_44722_p1() {
    tmp_4720_fu_44722_p1 = D_i_i_i_i_0_reg2mem_0_i_i_12_fu_44716_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4721_fu_44726_p3() {
    tmp_4721_fu_44726_p3 = D_i_i_i_i_0_reg2mem_0_i_i_12_fu_44716_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4722_fu_44775_p1() {
    tmp_4722_fu_44775_p1 = D_i_i_i_i_0_reg2mem_0_i_i_13_fu_44769_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4723_fu_44779_p3() {
    tmp_4723_fu_44779_p3 = D_i_i_i_i_0_reg2mem_0_i_i_13_fu_44769_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4724_fu_44828_p1() {
    tmp_4724_fu_44828_p1 = D_i_i_i_i_0_reg2mem_0_i_i_14_fu_44822_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4725_fu_44832_p3() {
    tmp_4725_fu_44832_p3 = D_i_i_i_i_0_reg2mem_0_i_i_14_fu_44822_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4726_fu_44881_p1() {
    tmp_4726_fu_44881_p1 = D_i_i_i_i_0_reg2mem_0_i_i_15_fu_44875_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4727_fu_44885_p3() {
    tmp_4727_fu_44885_p3 = D_i_i_i_i_0_reg2mem_0_i_i_15_fu_44875_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4728_fu_44934_p1() {
    tmp_4728_fu_44934_p1 = D_i_i_i_i_0_reg2mem_0_i_i_16_fu_44928_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4729_fu_44938_p3() {
    tmp_4729_fu_44938_p3 = D_i_i_i_i_0_reg2mem_0_i_i_16_fu_44928_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4730_fu_44987_p1() {
    tmp_4730_fu_44987_p1 = D_i_i_i_i_0_reg2mem_0_i_i_17_fu_44981_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4731_fu_44991_p3() {
    tmp_4731_fu_44991_p3 = D_i_i_i_i_0_reg2mem_0_i_i_17_fu_44981_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4732_fu_45040_p1() {
    tmp_4732_fu_45040_p1 = D_i_i_i_i_0_reg2mem_0_i_i_18_fu_45034_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4733_fu_45044_p3() {
    tmp_4733_fu_45044_p3 = D_i_i_i_i_0_reg2mem_0_i_i_18_fu_45034_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4734_fu_45093_p1() {
    tmp_4734_fu_45093_p1 = D_i_i_i_i_0_reg2mem_0_i_i_19_fu_45087_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4735_fu_45097_p3() {
    tmp_4735_fu_45097_p3 = D_i_i_i_i_0_reg2mem_0_i_i_19_fu_45087_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4736_fu_45146_p1() {
    tmp_4736_fu_45146_p1 = D_i_i_i_i_0_reg2mem_0_i_i_20_fu_45140_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4737_fu_45150_p3() {
    tmp_4737_fu_45150_p3 = D_i_i_i_i_0_reg2mem_0_i_i_20_fu_45140_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4738_fu_45199_p1() {
    tmp_4738_fu_45199_p1 = D_i_i_i_i_0_reg2mem_0_i_i_21_fu_45193_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4739_fu_45203_p3() {
    tmp_4739_fu_45203_p3 = D_i_i_i_i_0_reg2mem_0_i_i_21_fu_45193_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4740_fu_45252_p1() {
    tmp_4740_fu_45252_p1 = D_i_i_i_i_0_reg2mem_0_i_i_22_fu_45246_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4741_fu_45256_p3() {
    tmp_4741_fu_45256_p3 = D_i_i_i_i_0_reg2mem_0_i_i_22_fu_45246_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4742_fu_45305_p1() {
    tmp_4742_fu_45305_p1 = D_i_i_i_i_0_reg2mem_0_i_i_23_fu_45299_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4743_fu_45309_p3() {
    tmp_4743_fu_45309_p3 = D_i_i_i_i_0_reg2mem_0_i_i_23_fu_45299_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4744_fu_45358_p1() {
    tmp_4744_fu_45358_p1 = D_i_i_i_i_0_reg2mem_0_i_i_24_fu_45352_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4745_fu_45362_p3() {
    tmp_4745_fu_45362_p3 = D_i_i_i_i_0_reg2mem_0_i_i_24_fu_45352_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4746_fu_45411_p1() {
    tmp_4746_fu_45411_p1 = D_i_i_i_i_0_reg2mem_0_i_i_25_fu_45405_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4747_fu_45415_p3() {
    tmp_4747_fu_45415_p3 = D_i_i_i_i_0_reg2mem_0_i_i_25_fu_45405_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4748_fu_45464_p1() {
    tmp_4748_fu_45464_p1 = D_i_i_i_i_0_reg2mem_0_i_i_26_fu_45458_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4749_fu_45468_p3() {
    tmp_4749_fu_45468_p3 = D_i_i_i_i_0_reg2mem_0_i_i_26_fu_45458_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4750_fu_45517_p1() {
    tmp_4750_fu_45517_p1 = D_i_i_i_i_0_reg2mem_0_i_i_27_fu_45511_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4751_fu_45521_p3() {
    tmp_4751_fu_45521_p3 = D_i_i_i_i_0_reg2mem_0_i_i_27_fu_45511_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4752_fu_45570_p1() {
    tmp_4752_fu_45570_p1 = D_i_i_i_i_0_reg2mem_0_i_i_28_fu_45564_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4753_fu_45574_p3() {
    tmp_4753_fu_45574_p3 = D_i_i_i_i_0_reg2mem_0_i_i_28_fu_45564_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4754_fu_45623_p1() {
    tmp_4754_fu_45623_p1 = D_i_i_i_i_0_reg2mem_0_i_i_29_fu_45617_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4755_fu_45627_p3() {
    tmp_4755_fu_45627_p3 = D_i_i_i_i_0_reg2mem_0_i_i_29_fu_45617_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4756_fu_45676_p1() {
    tmp_4756_fu_45676_p1 = D_i_i_i_i_0_reg2mem_0_i_i_30_fu_45670_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4757_fu_45680_p3() {
    tmp_4757_fu_45680_p3 = D_i_i_i_i_0_reg2mem_0_i_i_30_fu_45670_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4758_fu_45729_p1() {
    tmp_4758_fu_45729_p1 = D_i_i_i_i_0_reg2mem_0_i_i_31_fu_45723_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4759_fu_45733_p3() {
    tmp_4759_fu_45733_p3 = D_i_i_i_i_0_reg2mem_0_i_i_31_fu_45723_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4760_fu_45782_p1() {
    tmp_4760_fu_45782_p1 = D_i_i_i_i_0_reg2mem_0_i_i_32_fu_45776_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4761_fu_45786_p3() {
    tmp_4761_fu_45786_p3 = D_i_i_i_i_0_reg2mem_0_i_i_32_fu_45776_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4762_fu_45835_p1() {
    tmp_4762_fu_45835_p1 = D_i_i_i_i_0_reg2mem_0_i_i_33_fu_45829_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4763_fu_45839_p3() {
    tmp_4763_fu_45839_p3 = D_i_i_i_i_0_reg2mem_0_i_i_33_fu_45829_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4764_fu_45888_p1() {
    tmp_4764_fu_45888_p1 = D_i_i_i_i_0_reg2mem_0_i_i_34_fu_45882_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4765_fu_45892_p3() {
    tmp_4765_fu_45892_p3 = D_i_i_i_i_0_reg2mem_0_i_i_34_fu_45882_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4766_fu_45941_p1() {
    tmp_4766_fu_45941_p1 = D_i_i_i_i_0_reg2mem_0_i_i_35_fu_45935_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4767_fu_45945_p3() {
    tmp_4767_fu_45945_p3 = D_i_i_i_i_0_reg2mem_0_i_i_35_fu_45935_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4768_fu_45994_p1() {
    tmp_4768_fu_45994_p1 = D_i_i_i_i_0_reg2mem_0_i_i_36_fu_45988_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4769_fu_45998_p3() {
    tmp_4769_fu_45998_p3 = D_i_i_i_i_0_reg2mem_0_i_i_36_fu_45988_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4770_fu_46047_p1() {
    tmp_4770_fu_46047_p1 = D_i_i_i_i_0_reg2mem_0_i_i_37_fu_46041_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4771_fu_46051_p3() {
    tmp_4771_fu_46051_p3 = D_i_i_i_i_0_reg2mem_0_i_i_37_fu_46041_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4772_fu_46100_p1() {
    tmp_4772_fu_46100_p1 = D_i_i_i_i_0_reg2mem_0_i_i_38_fu_46094_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4773_fu_46104_p3() {
    tmp_4773_fu_46104_p3 = D_i_i_i_i_0_reg2mem_0_i_i_38_fu_46094_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4774_fu_46153_p1() {
    tmp_4774_fu_46153_p1 = D_i_i_i_i_0_reg2mem_0_i_i_39_fu_46147_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4775_fu_46157_p3() {
    tmp_4775_fu_46157_p3 = D_i_i_i_i_0_reg2mem_0_i_i_39_fu_46147_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4776_fu_46206_p1() {
    tmp_4776_fu_46206_p1 = D_i_i_i_i_0_reg2mem_0_i_i_40_fu_46200_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4777_fu_46210_p3() {
    tmp_4777_fu_46210_p3 = D_i_i_i_i_0_reg2mem_0_i_i_40_fu_46200_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4778_fu_46259_p1() {
    tmp_4778_fu_46259_p1 = D_i_i_i_i_0_reg2mem_0_i_i_41_fu_46253_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4779_fu_46263_p3() {
    tmp_4779_fu_46263_p3 = D_i_i_i_i_0_reg2mem_0_i_i_41_fu_46253_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4780_fu_46312_p1() {
    tmp_4780_fu_46312_p1 = D_i_i_i_i_0_reg2mem_0_i_i_42_fu_46306_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4781_fu_46316_p3() {
    tmp_4781_fu_46316_p3 = D_i_i_i_i_0_reg2mem_0_i_i_42_fu_46306_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4782_fu_46398_p1() {
    tmp_4782_fu_46398_p1 = D_i_i_i_i_0_reg2mem_0_i_i_43_reg_80183.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4783_fu_46365_p3() {
    tmp_4783_fu_46365_p3 = D_i_i_i_i_0_reg2mem_0_i_i_43_fu_46359_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4784_fu_46417_p3() {
    tmp_4784_fu_46417_p3 = D_i_i_i_i_0_reg2mem_0_i_i_44_fu_46411_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4785_fu_67010_p3() {
    tmp_4785_fu_67010_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(33, 33);
}

void krnl_sobel::thread_tmp_4786_fu_46440_p4() {
    tmp_4786_fu_46440_p4 = ux_i_i_i_i_i_i_1_reg_12643.read().range(61, 24);
}

void krnl_sobel::thread_tmp_4787_fu_67018_p3() {
    tmp_4787_fu_67018_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(32, 32);
}

void krnl_sobel::thread_tmp_4788_fu_46468_p1() {
    tmp_4788_fu_46468_p1 = fract_i_i_i_i_0_reg2mem673_0_i_reg_12665.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4789_fu_46496_p1() {
    tmp_4789_fu_46496_p1 = ux_i_i_i_i_i_i_1_reg_12643.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4790_fu_46524_p1() {
    tmp_4790_fu_46524_p1 = ux_i_i_i_i_i_i_1_reg_12643.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4791_fu_46528_p1() {
    tmp_4791_fu_46528_p1 = fract_i_i_i_i_0_reg2mem673_0_i_reg_12665.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4792_fu_46568_p4() {
    tmp_4792_fu_46568_p4 = tmp_217_fu_46562_p2.read().range(62, 24);
}

void krnl_sobel::thread_tmp_4793_fu_67026_p3() {
    tmp_4793_fu_67026_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(31, 31);
}

void krnl_sobel::thread_tmp_4794_fu_46672_p3() {
    tmp_4794_fu_46672_p3 = ux_i_i_i_i_i_i_2_reg_12688.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4795_fu_67034_p3() {
    tmp_4795_fu_67034_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(30, 30);
}

void krnl_sobel::thread_tmp_4796_fu_46704_p1() {
    tmp_4796_fu_46704_p1 = e_i10_i_i_i_3_reg2mem665_0_i_i_reg_12697.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_4797_fu_46708_p1() {
    tmp_4797_fu_46708_p1 = ux_i_i_i_i_i_i_2_reg_12688.read().range(23-1, 0);
}

void krnl_sobel::thread_tmp_4798_fu_46712_p1() {
    tmp_4798_fu_46712_p1 = e_i10_i_i_i_3_reg2mem665_0_i_i_reg_12697.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_47_cast1_fu_23908_p1() {
    tmp_47_cast1_fu_23908_p1 = esl_zext<31,1>(p_ph5_reg_2676.read());
}

void krnl_sobel::thread_tmp_47_cast_fu_23889_p1() {
    tmp_47_cast_fu_23889_p1 = esl_zext<63,1>(p_ph5_phi_fu_2681_p8.read());
}

void krnl_sobel::thread_tmp_47_fu_23686_p1() {
    tmp_47_fu_23686_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_4801_fu_46898_p4() {
    tmp_4801_fu_46898_p4 = esl_bitset<32,32,32,1>(tmp_305_fu_46894_p1.read(), ap_const_lv32_1F, tmp_4800_reg_80328.read());
}

void krnl_sobel::thread_tmp_4802_fu_46698_p2() {
    tmp_4802_fu_46698_p2 = (!ap_const_lv64_1.is_01())? sc_lv<64>(): ux_i_i_i_i_i_i_2_reg_12688.read() << (unsigned short)ap_const_lv64_1.to_uint();
}

void krnl_sobel::thread_tmp_4803_fu_67042_p3() {
    tmp_4803_fu_67042_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(29, 29);
}

void krnl_sobel::thread_tmp_4804_fu_46925_p1() {
    tmp_4804_fu_46925_p1 = p_0107_reg2mem651_0_i_i_to_int_fu_46911_p1.read().range(23-1, 0);
}

void krnl_sobel::thread_tmp_4805_fu_46955_p1() {
    tmp_4805_fu_46955_p1 = maxg_1_reg2mem723_0_i_i_to_int_fu_46941_p1.read().range(23-1, 0);
}

void krnl_sobel::thread_tmp_4806_fu_47014_p1() {
    tmp_4806_fu_47014_p1 = ming_1_reg2mem725_0_i_i_to_int_fu_47000_p1.read().range(23-1, 0);
}

void krnl_sobel::thread_tmp_4807_fu_67050_p3() {
    tmp_4807_fu_67050_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(28, 28);
}

void krnl_sobel::thread_tmp_4808_fu_67058_p3() {
    tmp_4808_fu_67058_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(27, 27);
}

void krnl_sobel::thread_tmp_4809_fu_67066_p3() {
    tmp_4809_fu_67066_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(26, 26);
}

void krnl_sobel::thread_tmp_4810_fu_67074_p3() {
    tmp_4810_fu_67074_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(25, 25);
}

void krnl_sobel::thread_tmp_4811_fu_67082_p3() {
    tmp_4811_fu_67082_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(24, 24);
}

void krnl_sobel::thread_tmp_4812_fu_67090_p3() {
    tmp_4812_fu_67090_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4813_fu_67098_p3() {
    tmp_4813_fu_67098_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(22, 22);
}

void krnl_sobel::thread_tmp_4814_fu_67106_p3() {
    tmp_4814_fu_67106_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(21, 21);
}

void krnl_sobel::thread_tmp_4815_fu_67114_p3() {
    tmp_4815_fu_67114_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(20, 20);
}

void krnl_sobel::thread_tmp_4816_fu_67122_p3() {
    tmp_4816_fu_67122_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(19, 19);
}

void krnl_sobel::thread_tmp_4817_fu_67130_p3() {
    tmp_4817_fu_67130_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(18, 18);
}

void krnl_sobel::thread_tmp_4818_fu_67138_p3() {
    tmp_4818_fu_67138_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(17, 17);
}

void krnl_sobel::thread_tmp_4819_fu_67146_p3() {
    tmp_4819_fu_67146_p3 = p_143_reg2mem615_0_i_i_44_reg_22495.read().range(16, 16);
}

void krnl_sobel::thread_tmp_481_fu_48566_p3() {
    tmp_481_fu_48566_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4821_fu_67264_p1() {
    tmp_4821_fu_67264_p1 = Foy_i_i_i74_0_reg2mem_0_i_i_fu_67257_p3.read().range(55-1, 0);
}

void krnl_sobel::thread_tmp_4822_fu_67285_p1() {
    tmp_4822_fu_67285_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_fu_67279_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4823_fu_67289_p3() {
    tmp_4823_fu_67289_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_fu_67279_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4825_fu_67348_p1() {
    tmp_4825_fu_67348_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_1_fu_67342_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4826_fu_67352_p3() {
    tmp_4826_fu_67352_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_1_fu_67342_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4827_fu_67377_p2() {
    tmp_4827_fu_67377_p2 = (tmp_4826_reg_88598.read() | tmp_4824_reg_88581.read());
}

void krnl_sobel::thread_tmp_4828_fu_67414_p1() {
    tmp_4828_fu_67414_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_2_fu_67408_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4829_fu_67418_p3() {
    tmp_4829_fu_67418_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_2_fu_67408_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4830_fu_67475_p1() {
    tmp_4830_fu_67475_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_3_fu_67469_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4831_fu_67479_p3() {
    tmp_4831_fu_67479_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_3_fu_67469_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4832_fu_67528_p1() {
    tmp_4832_fu_67528_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_4_fu_67522_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4833_fu_67532_p3() {
    tmp_4833_fu_67532_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_4_fu_67522_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4834_fu_67594_p1() {
    tmp_4834_fu_67594_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_5_fu_67588_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4835_fu_67598_p3() {
    tmp_4835_fu_67598_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_5_fu_67588_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4836_fu_67647_p1() {
    tmp_4836_fu_67647_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_6_fu_67641_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4837_fu_67651_p3() {
    tmp_4837_fu_67651_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_6_fu_67641_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4838_fu_67700_p1() {
    tmp_4838_fu_67700_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_7_fu_67694_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4839_fu_67704_p3() {
    tmp_4839_fu_67704_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_7_fu_67694_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_483_fu_25435_p3() {
    tmp_483_fu_25435_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(41, 41);
}

void krnl_sobel::thread_tmp_4840_fu_67753_p1() {
    tmp_4840_fu_67753_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_8_fu_67747_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4841_fu_67757_p3() {
    tmp_4841_fu_67757_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_8_fu_67747_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4842_fu_67806_p1() {
    tmp_4842_fu_67806_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_9_fu_67800_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4843_fu_67810_p3() {
    tmp_4843_fu_67810_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_9_fu_67800_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4844_fu_67859_p1() {
    tmp_4844_fu_67859_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_s_fu_67853_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4845_fu_67863_p3() {
    tmp_4845_fu_67863_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_s_fu_67853_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4846_fu_67912_p1() {
    tmp_4846_fu_67912_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_10_fu_67906_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4847_fu_67916_p3() {
    tmp_4847_fu_67916_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_10_fu_67906_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4848_fu_67965_p1() {
    tmp_4848_fu_67965_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_11_fu_67959_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4849_fu_67969_p3() {
    tmp_4849_fu_67969_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_11_fu_67959_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_484_fu_69768_p2() {
    tmp_484_fu_69768_p2 = (tmp_4916_fu_69764_p1.read() | rnd_i_i_i_i29_0_reg2mem589_0_i_reg_22746.read());
}

void krnl_sobel::thread_tmp_4850_fu_68018_p1() {
    tmp_4850_fu_68018_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_12_fu_68012_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4851_fu_68022_p3() {
    tmp_4851_fu_68022_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_12_fu_68012_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4852_fu_68071_p1() {
    tmp_4852_fu_68071_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_13_fu_68065_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4853_fu_68075_p3() {
    tmp_4853_fu_68075_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_13_fu_68065_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4854_fu_68124_p1() {
    tmp_4854_fu_68124_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_14_fu_68118_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4855_fu_68128_p3() {
    tmp_4855_fu_68128_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_14_fu_68118_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4856_fu_68177_p1() {
    tmp_4856_fu_68177_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_15_fu_68171_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4857_fu_68181_p3() {
    tmp_4857_fu_68181_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_15_fu_68171_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4858_fu_68230_p1() {
    tmp_4858_fu_68230_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_16_fu_68224_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4859_fu_68234_p3() {
    tmp_4859_fu_68234_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_16_fu_68224_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_485_fu_69774_p4() {
    tmp_485_fu_69774_p4 = fract_i_i_i_i28_0_reg2mem591_reg_22735.read().range(31, 1);
}

void krnl_sobel::thread_tmp_4860_fu_68283_p1() {
    tmp_4860_fu_68283_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_17_fu_68277_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4861_fu_68287_p3() {
    tmp_4861_fu_68287_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_17_fu_68277_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4862_fu_68336_p1() {
    tmp_4862_fu_68336_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_18_fu_68330_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4863_fu_68340_p3() {
    tmp_4863_fu_68340_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_18_fu_68330_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4864_fu_68389_p1() {
    tmp_4864_fu_68389_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_19_fu_68383_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4865_fu_68393_p3() {
    tmp_4865_fu_68393_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_19_fu_68383_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4866_fu_68442_p1() {
    tmp_4866_fu_68442_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_20_fu_68436_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4867_fu_68446_p3() {
    tmp_4867_fu_68446_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_20_fu_68436_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4868_fu_68495_p1() {
    tmp_4868_fu_68495_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_21_fu_68489_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4869_fu_68499_p3() {
    tmp_4869_fu_68499_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_21_fu_68489_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_486_fu_69812_p1() {
    tmp_486_fu_69812_p1 = esl_zext<62,61>(tmp_331_fu_69802_p4.read());
}

void krnl_sobel::thread_tmp_4870_fu_68548_p1() {
    tmp_4870_fu_68548_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_22_fu_68542_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4871_fu_68552_p3() {
    tmp_4871_fu_68552_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_22_fu_68542_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4872_fu_68601_p1() {
    tmp_4872_fu_68601_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_23_fu_68595_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4873_fu_68605_p3() {
    tmp_4873_fu_68605_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_23_fu_68595_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4874_fu_68654_p1() {
    tmp_4874_fu_68654_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_24_fu_68648_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4875_fu_68658_p3() {
    tmp_4875_fu_68658_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_24_fu_68648_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4876_fu_68707_p1() {
    tmp_4876_fu_68707_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_25_fu_68701_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4877_fu_68711_p3() {
    tmp_4877_fu_68711_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_25_fu_68701_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4878_fu_68760_p1() {
    tmp_4878_fu_68760_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_26_fu_68754_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4879_fu_68764_p3() {
    tmp_4879_fu_68764_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_26_fu_68754_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_487_fu_48574_p3() {
    tmp_487_fu_48574_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(59, 59);
}

void krnl_sobel::thread_tmp_4880_fu_68813_p1() {
    tmp_4880_fu_68813_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_27_fu_68807_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4881_fu_68817_p3() {
    tmp_4881_fu_68817_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_27_fu_68807_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4882_fu_68866_p1() {
    tmp_4882_fu_68866_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_28_fu_68860_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4883_fu_68870_p3() {
    tmp_4883_fu_68870_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_28_fu_68860_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4884_fu_68919_p1() {
    tmp_4884_fu_68919_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_29_fu_68913_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4885_fu_68923_p3() {
    tmp_4885_fu_68923_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_29_fu_68913_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4886_fu_68972_p1() {
    tmp_4886_fu_68972_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_30_fu_68966_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4887_fu_68976_p3() {
    tmp_4887_fu_68976_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_30_fu_68966_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4888_fu_69025_p1() {
    tmp_4888_fu_69025_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_31_fu_69019_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4889_fu_69029_p3() {
    tmp_4889_fu_69029_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_31_fu_69019_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_488_fu_69828_p2() {
    tmp_488_fu_69828_p2 = (tmp_4919_fu_69824_p1.read() | tmp_4918_fu_69820_p1.read());
}

void krnl_sobel::thread_tmp_4890_fu_69078_p1() {
    tmp_4890_fu_69078_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_32_fu_69072_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4891_fu_69082_p3() {
    tmp_4891_fu_69082_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_32_fu_69072_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4892_fu_69131_p1() {
    tmp_4892_fu_69131_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_33_fu_69125_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4893_fu_69135_p3() {
    tmp_4893_fu_69135_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_33_fu_69125_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4894_fu_69184_p1() {
    tmp_4894_fu_69184_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_34_fu_69178_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4895_fu_69188_p3() {
    tmp_4895_fu_69188_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_34_fu_69178_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4896_fu_69237_p1() {
    tmp_4896_fu_69237_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_35_fu_69231_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4897_fu_69241_p3() {
    tmp_4897_fu_69241_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_35_fu_69231_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4898_fu_69290_p1() {
    tmp_4898_fu_69290_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_36_fu_69284_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4899_fu_69294_p3() {
    tmp_4899_fu_69294_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_36_fu_69284_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_489_fu_69834_p4() {
    tmp_489_fu_69834_p4 = fract_i_i_i_i28_0_reg2mem591_reg_22735.read().range(31, 1);
}

void krnl_sobel::thread_tmp_48_fu_23948_p1() {
    tmp_48_fu_23948_p1 = esl_sext<64,32>(krnl_sobel_rowbuf1_addr_reg_71204.read());
}

void krnl_sobel::thread_tmp_4900_fu_69343_p1() {
    tmp_4900_fu_69343_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_37_fu_69337_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4901_fu_69347_p3() {
    tmp_4901_fu_69347_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_37_fu_69337_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4902_fu_69396_p1() {
    tmp_4902_fu_69396_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_38_fu_69390_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4903_fu_69400_p3() {
    tmp_4903_fu_69400_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_38_fu_69390_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4904_fu_69449_p1() {
    tmp_4904_fu_69449_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_39_fu_69443_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4905_fu_69453_p3() {
    tmp_4905_fu_69453_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_39_fu_69443_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4906_fu_69502_p1() {
    tmp_4906_fu_69502_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_40_fu_69496_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4907_fu_69506_p3() {
    tmp_4907_fu_69506_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_40_fu_69496_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4908_fu_69555_p1() {
    tmp_4908_fu_69555_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_41_fu_69549_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4909_fu_69559_p3() {
    tmp_4909_fu_69559_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_41_fu_69549_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_490_fu_25443_p3() {
    tmp_490_fu_25443_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(40, 40);
}

void krnl_sobel::thread_tmp_4910_fu_69608_p1() {
    tmp_4910_fu_69608_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_42_fu_69602_p2.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4911_fu_69612_p3() {
    tmp_4911_fu_69612_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_42_fu_69602_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4912_fu_69694_p1() {
    tmp_4912_fu_69694_p1 = D_i_i_i_i22_0_reg2mem_0_i_i_43_reg_89332.read().range(60-1, 0);
}

void krnl_sobel::thread_tmp_4913_fu_69661_p3() {
    tmp_4913_fu_69661_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_43_fu_69655_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4914_fu_69713_p3() {
    tmp_4914_fu_69713_p3 = D_i_i_i_i22_0_reg2mem_0_i_i_44_fu_69707_p2.read().range(60, 60);
}

void krnl_sobel::thread_tmp_4915_fu_69736_p4() {
    tmp_4915_fu_69736_p4 = ux_i_i_i_i24_i_i_1_reg_22713.read().range(61, 24);
}

void krnl_sobel::thread_tmp_4916_fu_69764_p1() {
    tmp_4916_fu_69764_p1 = fract_i_i_i_i28_0_reg2mem591_reg_22735.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4917_fu_69792_p1() {
    tmp_4917_fu_69792_p1 = ux_i_i_i_i24_i_i_1_reg_22713.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4918_fu_69820_p1() {
    tmp_4918_fu_69820_p1 = ux_i_i_i_i24_i_i_1_reg_22713.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_4919_fu_69824_p1() {
    tmp_4919_fu_69824_p1 = fract_i_i_i_i28_0_reg2mem591_reg_22735.read().range(1-1, 0);
}

void krnl_sobel::thread_tmp_491_fu_48582_p3() {
    tmp_491_fu_48582_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(58, 58);
}

void krnl_sobel::thread_tmp_4920_fu_69864_p4() {
    tmp_4920_fu_69864_p4 = tmp_340_fu_69858_p2.read().range(62, 24);
}

void krnl_sobel::thread_tmp_4921_fu_69968_p3() {
    tmp_4921_fu_69968_p3 = ux_i_i_i_i24_i_i_2_reg_22758.read().range(23, 23);
}

void krnl_sobel::thread_tmp_4922_fu_70000_p1() {
    tmp_4922_fu_70000_p1 = e_i10_i_i_i26_3_reg2mem583_0_i_2_reg_22767.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_4923_fu_70004_p1() {
    tmp_4923_fu_70004_p1 = ux_i_i_i_i24_i_i_2_reg_22758.read().range(23-1, 0);
}

void krnl_sobel::thread_tmp_4924_fu_70008_p1() {
    tmp_4924_fu_70008_p1 = e_i10_i_i_i26_3_reg2mem583_0_i_2_reg_22767.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_4927_fu_70194_p4() {
    tmp_4927_fu_70194_p4 = esl_bitset<32,32,32,1>(tmp_359_fu_70190_p1.read(), ap_const_lv32_1F, tmp_4926_reg_89477.read());
}

void krnl_sobel::thread_tmp_4928_fu_69994_p2() {
    tmp_4928_fu_69994_p2 = (!ap_const_lv64_1.is_01())? sc_lv<64>(): ux_i_i_i_i24_i_i_2_reg_22758.read() << (unsigned short)ap_const_lv64_1.to_uint();
}

void krnl_sobel::thread_tmp_492_fu_25451_p3() {
    tmp_492_fu_25451_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(39, 39);
}

void krnl_sobel::thread_tmp_4931_fu_70293_p3() {
    tmp_4931_fu_70293_p3 = r_V_fu_70281_p2.read().range(23, 23);
}

void krnl_sobel::thread_tmp_493_fu_70116_p2() {
    tmp_493_fu_70116_p2 = (notrhs5_reg_89446.read() | notlhs5_fu_70111_p2.read());
}

void krnl_sobel::thread_tmp_495_fu_70121_p2() {
    tmp_495_fu_70121_p2 = (tmp_493_fu_70116_p2.read() & tmp_494_reg_89451.read());
}

void krnl_sobel::thread_tmp_496_fu_48590_p3() {
    tmp_496_fu_48590_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(57, 57);
}

void krnl_sobel::thread_tmp_497_fu_70089_p4() {
    tmp_497_fu_70089_p4 = tmp_317_reg_88587.read().range(62, 55);
}

void krnl_sobel::thread_tmp_498_fu_70098_p2() {
    tmp_498_fu_70098_p2 = (!tmp_497_fu_70089_p4.read().is_01() || !tmp_4924_fu_70008_p1.read().is_01())? sc_lv<8>(): (sc_biguint<8>(tmp_497_fu_70089_p4.read()) + sc_biguint<8>(tmp_4924_fu_70008_p1.read()));
}

void krnl_sobel::thread_tmp_499_fu_25459_p3() {
    tmp_499_fu_25459_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(38, 38);
}

void krnl_sobel::thread_tmp_49_fu_23952_p2() {
    tmp_49_fu_23952_p2 = (!ap_const_lv32_1.is_01() || !krnl_sobel_rowbuf1_addr_reg_71204.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_1) + sc_biguint<32>(krnl_sobel_rowbuf1_addr_reg_71204.read()));
}

void krnl_sobel::thread_tmp_4_fu_23317_p4() {
    tmp_4_fu_23317_p4 = indvars_iv1_reg_2596.read().range(31, 2);
}

void krnl_sobel::thread_tmp_500_fu_70153_p3() {
    tmp_500_fu_70153_p3 = (!tmp_355_reg_89461.read()[0].is_01())? sc_lv<8>(): ((tmp_355_reg_89461.read()[0].to_bool())? ap_const_lv8_0: ap_const_lv8_FF);
}

void krnl_sobel::thread_tmp_501_fu_70141_p2() {
    tmp_501_fu_70141_p2 = (tmp_355_reg_89461.read() | icmp5_fu_70136_p2.read());
}

void krnl_sobel::thread_tmp_502_fu_70160_p3() {
    tmp_502_fu_70160_p3 = (!tmp_501_fu_70141_p2.read()[0].is_01())? sc_lv<8>(): ((tmp_501_fu_70141_p2.read()[0].to_bool())? tmp_500_fu_70153_p3.read(): tmp_498_reg_89472.read());
}

void krnl_sobel::thread_tmp_503_fu_70301_p1() {
    tmp_503_fu_70301_p1 = esl_zext<8,1>(tmp_4931_fu_70293_p3.read());
}

void krnl_sobel::thread_tmp_504_fu_70305_p4() {
    tmp_504_fu_70305_p4 = r_V_1_fu_70287_p2.read().range(30, 23);
}

void krnl_sobel::thread_tmp_505_fu_48598_p3() {
    tmp_505_fu_48598_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(56, 56);
}

void krnl_sobel::thread_tmp_506_fu_25467_p3() {
    tmp_506_fu_25467_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(37, 37);
}

void krnl_sobel::thread_tmp_507_fu_48606_p3() {
    tmp_507_fu_48606_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(55, 55);
}

void krnl_sobel::thread_tmp_508_fu_25475_p3() {
    tmp_508_fu_25475_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(36, 36);
}

void krnl_sobel::thread_tmp_509_fu_48614_p3() {
    tmp_509_fu_48614_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(54, 54);
}

void krnl_sobel::thread_tmp_50_fu_23957_p1() {
    tmp_50_fu_23957_p1 = esl_sext<64,32>(tmp_49_fu_23952_p2.read());
}

void krnl_sobel::thread_tmp_510_fu_25483_p3() {
    tmp_510_fu_25483_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(35, 35);
}

void krnl_sobel::thread_tmp_511_fu_48622_p3() {
    tmp_511_fu_48622_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(53, 53);
}

void krnl_sobel::thread_tmp_512_fu_25491_p3() {
    tmp_512_fu_25491_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(34, 34);
}

void krnl_sobel::thread_tmp_513_fu_48630_p3() {
    tmp_513_fu_48630_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(52, 52);
}

void krnl_sobel::thread_tmp_514_fu_25499_p3() {
    tmp_514_fu_25499_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(33, 33);
}

void krnl_sobel::thread_tmp_515_fu_48638_p3() {
    tmp_515_fu_48638_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(51, 51);
}

void krnl_sobel::thread_tmp_516_fu_25507_p3() {
    tmp_516_fu_25507_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(32, 32);
}

void krnl_sobel::thread_tmp_517_fu_48646_p3() {
    tmp_517_fu_48646_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(50, 50);
}

void krnl_sobel::thread_tmp_518_fu_25515_p3() {
    tmp_518_fu_25515_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(31, 31);
}

void krnl_sobel::thread_tmp_519_fu_48654_p3() {
    tmp_519_fu_48654_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(49, 49);
}

void krnl_sobel::thread_tmp_51_fu_23962_p2() {
    tmp_51_fu_23962_p2 = (!ap_const_lv32_2.is_01() || !ap_pipeline_reg_pp2_iter1_krnl_sobel_rowbuf1_addr_reg_71204.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_2) + sc_biguint<32>(ap_pipeline_reg_pp2_iter1_krnl_sobel_rowbuf1_addr_reg_71204.read()));
}

void krnl_sobel::thread_tmp_520_fu_25523_p3() {
    tmp_520_fu_25523_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(30, 30);
}

void krnl_sobel::thread_tmp_521_fu_48662_p3() {
    tmp_521_fu_48662_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(48, 48);
}

void krnl_sobel::thread_tmp_522_cast_fu_24559_p1() {
    tmp_522_cast_fu_24559_p1 = esl_zext<9,8>(phi_load_reg_2869.read());
}

void krnl_sobel::thread_tmp_522_fu_25531_p3() {
    tmp_522_fu_25531_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(29, 29);
}

void krnl_sobel::thread_tmp_523_fu_48670_p3() {
    tmp_523_fu_48670_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(47, 47);
}

void krnl_sobel::thread_tmp_524_cast_fu_24630_p1() {
    tmp_524_cast_fu_24630_p1 = esl_zext<9,8>(rowbuf2_q0.read());
}

void krnl_sobel::thread_tmp_524_fu_25539_p3() {
    tmp_524_fu_25539_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(28, 28);
}

void krnl_sobel::thread_tmp_525_fu_48678_p3() {
    tmp_525_fu_48678_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(46, 46);
}

void krnl_sobel::thread_tmp_526_cast_fu_25257_p1() {
    tmp_526_cast_fu_25257_p1 = esl_zext<62,6>(p_067_reg2mem699_0_i_i_reg_2920.read());
}

void krnl_sobel::thread_tmp_526_fu_25547_p3() {
    tmp_526_fu_25547_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(27, 27);
}

void krnl_sobel::thread_tmp_527_cast_fu_25266_p1() {
    tmp_527_cast_fu_25266_p1 = esl_zext<63,62>(tmp_245_fu_25261_p2.read());
}

void krnl_sobel::thread_tmp_527_fu_48686_p3() {
    tmp_527_fu_48686_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(45, 45);
}

void krnl_sobel::thread_tmp_528_fu_25555_p3() {
    tmp_528_fu_25555_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(26, 26);
}

void krnl_sobel::thread_tmp_529_fu_48694_p3() {
    tmp_529_fu_48694_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(44, 44);
}

void krnl_sobel::thread_tmp_52_fu_23967_p1() {
    tmp_52_fu_23967_p1 = esl_sext<64,32>(tmp_51_fu_23962_p2.read());
}

void krnl_sobel::thread_tmp_530_fu_25563_p3() {
    tmp_530_fu_25563_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(25, 25);
}

void krnl_sobel::thread_tmp_531_fu_48702_p3() {
    tmp_531_fu_48702_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(43, 43);
}

void krnl_sobel::thread_tmp_532_fu_25571_p3() {
    tmp_532_fu_25571_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(24, 24);
}

void krnl_sobel::thread_tmp_533_fu_48710_p3() {
    tmp_533_fu_48710_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(42, 42);
}

void krnl_sobel::thread_tmp_534_fu_25579_p3() {
    tmp_534_fu_25579_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(23, 23);
}

void krnl_sobel::thread_tmp_535_fu_48718_p3() {
    tmp_535_fu_48718_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(41, 41);
}

void krnl_sobel::thread_tmp_536_fu_25587_p3() {
    tmp_536_fu_25587_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(22, 22);
}

void krnl_sobel::thread_tmp_537_fu_48726_p3() {
    tmp_537_fu_48726_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(40, 40);
}

void krnl_sobel::thread_tmp_538_fu_25595_p3() {
    tmp_538_fu_25595_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(21, 21);
}

void krnl_sobel::thread_tmp_539_fu_48734_p3() {
    tmp_539_fu_48734_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(39, 39);
}

void krnl_sobel::thread_tmp_53_fu_23972_p2() {
    tmp_53_fu_23972_p2 = (!ap_const_lv32_3.is_01() || !ap_pipeline_reg_pp2_iter1_krnl_sobel_rowbuf1_addr_reg_71204.read().is_01())? sc_lv<32>(): (sc_biguint<32>(ap_const_lv32_3) + sc_biguint<32>(ap_pipeline_reg_pp2_iter1_krnl_sobel_rowbuf1_addr_reg_71204.read()));
}

void krnl_sobel::thread_tmp_540_fu_25603_p3() {
    tmp_540_fu_25603_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(20, 20);
}

void krnl_sobel::thread_tmp_541_fu_48742_p3() {
    tmp_541_fu_48742_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(38, 38);
}

void krnl_sobel::thread_tmp_542_fu_25611_p3() {
    tmp_542_fu_25611_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(19, 19);
}

void krnl_sobel::thread_tmp_543_fu_48750_p3() {
    tmp_543_fu_48750_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(37, 37);
}

void krnl_sobel::thread_tmp_544_fu_25619_p3() {
    tmp_544_fu_25619_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(18, 18);
}

void krnl_sobel::thread_tmp_545_fu_48758_p3() {
    tmp_545_fu_48758_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(36, 36);
}

void krnl_sobel::thread_tmp_546_fu_25627_p3() {
    tmp_546_fu_25627_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(17, 17);
}

void krnl_sobel::thread_tmp_547_fu_48766_p3() {
    tmp_547_fu_48766_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(35, 35);
}

void krnl_sobel::thread_tmp_548_fu_25635_p3() {
    tmp_548_fu_25635_p3 = p_164_reg2mem697_0_i_i_reg_3019.read().range(16, 16);
}

void krnl_sobel::thread_tmp_549_fu_48774_p3() {
    tmp_549_fu_48774_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(34, 34);
}

void krnl_sobel::thread_tmp_54_fu_23977_p1() {
    tmp_54_fu_23977_p1 = esl_sext<64,32>(tmp_53_fu_23972_p2.read());
}

void krnl_sobel::thread_tmp_550_fu_25684_p3() {
    tmp_550_fu_25684_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(61, 61);
}

void krnl_sobel::thread_tmp_551_fu_48782_p3() {
    tmp_551_fu_48782_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(33, 33);
}

void krnl_sobel::thread_tmp_552_fu_25692_p3() {
    tmp_552_fu_25692_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(60, 60);
}

void krnl_sobel::thread_tmp_553_fu_48790_p3() {
    tmp_553_fu_48790_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(32, 32);
}

void krnl_sobel::thread_tmp_554_fu_25700_p3() {
    tmp_554_fu_25700_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(59, 59);
}

void krnl_sobel::thread_tmp_555_fu_48798_p3() {
    tmp_555_fu_48798_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(31, 31);
}

void krnl_sobel::thread_tmp_556_fu_25708_p3() {
    tmp_556_fu_25708_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(58, 58);
}

void krnl_sobel::thread_tmp_557_fu_48806_p3() {
    tmp_557_fu_48806_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(30, 30);
}

void krnl_sobel::thread_tmp_558_fu_25716_p3() {
    tmp_558_fu_25716_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(57, 57);
}

void krnl_sobel::thread_tmp_559_fu_48814_p3() {
    tmp_559_fu_48814_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(29, 29);
}

void krnl_sobel::thread_tmp_55_fu_24013_p1() {
    tmp_55_fu_24013_p1 = esl_sext<64,32>(done_cnt2_reg_71232.read());
}

void krnl_sobel::thread_tmp_560_fu_25724_p3() {
    tmp_560_fu_25724_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(56, 56);
}

void krnl_sobel::thread_tmp_561_fu_48822_p3() {
    tmp_561_fu_48822_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(28, 28);
}

void krnl_sobel::thread_tmp_562_fu_25732_p3() {
    tmp_562_fu_25732_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(55, 55);
}

void krnl_sobel::thread_tmp_563_fu_48830_p3() {
    tmp_563_fu_48830_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(27, 27);
}

void krnl_sobel::thread_tmp_564_fu_25740_p3() {
    tmp_564_fu_25740_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(54, 54);
}

void krnl_sobel::thread_tmp_565_fu_48838_p3() {
    tmp_565_fu_48838_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(26, 26);
}

void krnl_sobel::thread_tmp_566_fu_25748_p3() {
    tmp_566_fu_25748_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(53, 53);
}

void krnl_sobel::thread_tmp_567_fu_48846_p3() {
    tmp_567_fu_48846_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(25, 25);
}

void krnl_sobel::thread_tmp_568_fu_25756_p3() {
    tmp_568_fu_25756_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(52, 52);
}

void krnl_sobel::thread_tmp_569_fu_48854_p3() {
    tmp_569_fu_48854_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(24, 24);
}

void krnl_sobel::thread_tmp_56_fu_24022_p2() {
    tmp_56_fu_24022_p2 = (!done_cnt2_reg_71232.read().is_01() || !ap_const_lv32_1.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt2_reg_71232.read()) + sc_biguint<32>(ap_const_lv32_1));
}

void krnl_sobel::thread_tmp_570_fu_25764_p3() {
    tmp_570_fu_25764_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(51, 51);
}

void krnl_sobel::thread_tmp_571_fu_48862_p3() {
    tmp_571_fu_48862_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(23, 23);
}

void krnl_sobel::thread_tmp_572_fu_25772_p3() {
    tmp_572_fu_25772_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(50, 50);
}

void krnl_sobel::thread_tmp_573_fu_48870_p3() {
    tmp_573_fu_48870_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(22, 22);
}

void krnl_sobel::thread_tmp_574_fu_25780_p3() {
    tmp_574_fu_25780_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(49, 49);
}

void krnl_sobel::thread_tmp_575_fu_48878_p3() {
    tmp_575_fu_48878_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(21, 21);
}

void krnl_sobel::thread_tmp_576_fu_25788_p3() {
    tmp_576_fu_25788_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(48, 48);
}

void krnl_sobel::thread_tmp_577_fu_48886_p3() {
    tmp_577_fu_48886_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(20, 20);
}

void krnl_sobel::thread_tmp_578_fu_25796_p3() {
    tmp_578_fu_25796_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(47, 47);
}

void krnl_sobel::thread_tmp_579_fu_48894_p3() {
    tmp_579_fu_48894_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(19, 19);
}

void krnl_sobel::thread_tmp_57_fu_24027_p1() {
    tmp_57_fu_24027_p1 = esl_sext<64,32>(tmp_56_fu_24022_p2.read());
}

void krnl_sobel::thread_tmp_580_fu_25804_p3() {
    tmp_580_fu_25804_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(46, 46);
}

void krnl_sobel::thread_tmp_581_fu_48902_p3() {
    tmp_581_fu_48902_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(18, 18);
}

void krnl_sobel::thread_tmp_582_fu_25812_p3() {
    tmp_582_fu_25812_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(45, 45);
}

void krnl_sobel::thread_tmp_583_fu_48910_p3() {
    tmp_583_fu_48910_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(17, 17);
}

void krnl_sobel::thread_tmp_584_fu_25820_p3() {
    tmp_584_fu_25820_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(44, 44);
}

void krnl_sobel::thread_tmp_585_fu_48918_p3() {
    tmp_585_fu_48918_p3 = p_143_reg2mem615_0_i_i_reg_13089.read().range(16, 16);
}

void krnl_sobel::thread_tmp_586_fu_25828_p3() {
    tmp_586_fu_25828_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(43, 43);
}

void krnl_sobel::thread_tmp_587_fu_48967_p3() {
    tmp_587_fu_48967_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(61, 61);
}

void krnl_sobel::thread_tmp_588_fu_25836_p3() {
    tmp_588_fu_25836_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(42, 42);
}

void krnl_sobel::thread_tmp_589_fu_48975_p3() {
    tmp_589_fu_48975_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(60, 60);
}

void krnl_sobel::thread_tmp_58_fu_24037_p2() {
    tmp_58_fu_24037_p2 = (!done_cnt2_reg_71232.read().is_01() || !ap_const_lv32_2.is_01())? sc_lv<32>(): (sc_biguint<32>(done_cnt2_reg_71232.read()) + sc_biguint<32>(ap_const_lv32_2));
}

void krnl_sobel::thread_tmp_590_fu_25844_p3() {
    tmp_590_fu_25844_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(41, 41);
}

void krnl_sobel::thread_tmp_591_fu_48983_p3() {
    tmp_591_fu_48983_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(59, 59);
}

void krnl_sobel::thread_tmp_592_fu_25852_p3() {
    tmp_592_fu_25852_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(40, 40);
}

void krnl_sobel::thread_tmp_593_fu_48991_p3() {
    tmp_593_fu_48991_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(58, 58);
}

void krnl_sobel::thread_tmp_594_fu_25860_p3() {
    tmp_594_fu_25860_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(39, 39);
}

void krnl_sobel::thread_tmp_595_fu_48999_p3() {
    tmp_595_fu_48999_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(57, 57);
}

void krnl_sobel::thread_tmp_596_fu_25868_p3() {
    tmp_596_fu_25868_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(38, 38);
}

void krnl_sobel::thread_tmp_597_fu_49007_p3() {
    tmp_597_fu_49007_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(56, 56);
}

void krnl_sobel::thread_tmp_598_fu_25876_p3() {
    tmp_598_fu_25876_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(37, 37);
}

void krnl_sobel::thread_tmp_599_fu_49015_p3() {
    tmp_599_fu_49015_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(55, 55);
}

void krnl_sobel::thread_tmp_59_fu_24042_p1() {
    tmp_59_fu_24042_p1 = esl_sext<64,32>(tmp_58_fu_24037_p2.read());
}

void krnl_sobel::thread_tmp_5_cast_fu_23331_p1() {
    tmp_5_cast_fu_23331_p1 = esl_zext<63,62>(tmp_s_fu_23327_p1.read());
}

void krnl_sobel::thread_tmp_5_fu_23255_p1() {
    tmp_5_fu_23255_p1 = grp_fu_23251_p2.read().range(2-1, 0);
}

void krnl_sobel::thread_tmp_600_fu_25884_p3() {
    tmp_600_fu_25884_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(36, 36);
}

void krnl_sobel::thread_tmp_601_fu_49023_p3() {
    tmp_601_fu_49023_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(54, 54);
}

void krnl_sobel::thread_tmp_602_fu_25892_p3() {
    tmp_602_fu_25892_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(35, 35);
}

void krnl_sobel::thread_tmp_603_fu_49031_p3() {
    tmp_603_fu_49031_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(53, 53);
}

void krnl_sobel::thread_tmp_604_fu_25900_p3() {
    tmp_604_fu_25900_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(34, 34);
}

void krnl_sobel::thread_tmp_605_fu_49039_p3() {
    tmp_605_fu_49039_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(52, 52);
}

void krnl_sobel::thread_tmp_606_fu_25908_p3() {
    tmp_606_fu_25908_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(33, 33);
}

void krnl_sobel::thread_tmp_607_fu_49047_p3() {
    tmp_607_fu_49047_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(51, 51);
}

void krnl_sobel::thread_tmp_608_fu_25916_p3() {
    tmp_608_fu_25916_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(32, 32);
}

void krnl_sobel::thread_tmp_609_fu_49055_p3() {
    tmp_609_fu_49055_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(50, 50);
}

void krnl_sobel::thread_tmp_60_fu_23747_p1() {
    tmp_60_fu_23747_p1 = gmem_RDATA.read().range(8-1, 0);
}

void krnl_sobel::thread_tmp_610_fu_25924_p3() {
    tmp_610_fu_25924_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(31, 31);
}

void krnl_sobel::thread_tmp_611_fu_49063_p3() {
    tmp_611_fu_49063_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(49, 49);
}

void krnl_sobel::thread_tmp_612_fu_25932_p3() {
    tmp_612_fu_25932_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(30, 30);
}

void krnl_sobel::thread_tmp_613_fu_49071_p3() {
    tmp_613_fu_49071_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(48, 48);
}

void krnl_sobel::thread_tmp_614_fu_25940_p3() {
    tmp_614_fu_25940_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(29, 29);
}

void krnl_sobel::thread_tmp_615_fu_49079_p3() {
    tmp_615_fu_49079_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(47, 47);
}

void krnl_sobel::thread_tmp_616_fu_25948_p3() {
    tmp_616_fu_25948_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(28, 28);
}

void krnl_sobel::thread_tmp_617_fu_49087_p3() {
    tmp_617_fu_49087_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(46, 46);
}

void krnl_sobel::thread_tmp_618_fu_25956_p3() {
    tmp_618_fu_25956_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(27, 27);
}

void krnl_sobel::thread_tmp_619_fu_49095_p3() {
    tmp_619_fu_49095_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(45, 45);
}

void krnl_sobel::thread_tmp_61_fu_24052_p2() {
    tmp_61_fu_24052_p2 = (!ap_const_lv32_FFFFFFFF.is_01() || !arg_height_reg_70737.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFF) + sc_biguint<32>(arg_height_reg_70737.read()));
}

void krnl_sobel::thread_tmp_620_fu_25964_p3() {
    tmp_620_fu_25964_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(26, 26);
}

void krnl_sobel::thread_tmp_621_fu_49103_p3() {
    tmp_621_fu_49103_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(44, 44);
}

void krnl_sobel::thread_tmp_622_fu_25972_p3() {
    tmp_622_fu_25972_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(25, 25);
}

void krnl_sobel::thread_tmp_623_fu_49111_p3() {
    tmp_623_fu_49111_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(43, 43);
}

void krnl_sobel::thread_tmp_624_fu_25980_p3() {
    tmp_624_fu_25980_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(24, 24);
}

void krnl_sobel::thread_tmp_625_fu_49119_p3() {
    tmp_625_fu_49119_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(42, 42);
}

void krnl_sobel::thread_tmp_626_fu_25988_p3() {
    tmp_626_fu_25988_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(23, 23);
}

void krnl_sobel::thread_tmp_627_fu_49127_p3() {
    tmp_627_fu_49127_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(41, 41);
}

void krnl_sobel::thread_tmp_628_fu_25996_p3() {
    tmp_628_fu_25996_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(22, 22);
}

void krnl_sobel::thread_tmp_629_fu_49135_p3() {
    tmp_629_fu_49135_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(40, 40);
}

void krnl_sobel::thread_tmp_62_fu_24067_p2() {
    tmp_62_fu_24067_p2 = (!ap_const_lv32_FFFFFFFF.is_01() || !arg_width_reg_70731.read().is_01())? sc_lv<32>(): (sc_bigint<32>(ap_const_lv32_FFFFFFFF) + sc_bigint<32>(arg_width_reg_70731.read()));
}

void krnl_sobel::thread_tmp_630_fu_26004_p3() {
    tmp_630_fu_26004_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(21, 21);
}

void krnl_sobel::thread_tmp_631_fu_49143_p3() {
    tmp_631_fu_49143_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(39, 39);
}

void krnl_sobel::thread_tmp_632_fu_26012_p3() {
    tmp_632_fu_26012_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(20, 20);
}

void krnl_sobel::thread_tmp_633_fu_49151_p3() {
    tmp_633_fu_49151_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(38, 38);
}

void krnl_sobel::thread_tmp_634_fu_26020_p3() {
    tmp_634_fu_26020_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(19, 19);
}

void krnl_sobel::thread_tmp_635_fu_49159_p3() {
    tmp_635_fu_49159_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(37, 37);
}

void krnl_sobel::thread_tmp_636_fu_26028_p3() {
    tmp_636_fu_26028_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(18, 18);
}

void krnl_sobel::thread_tmp_637_fu_49167_p3() {
    tmp_637_fu_49167_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(36, 36);
}

void krnl_sobel::thread_tmp_638_fu_26036_p3() {
    tmp_638_fu_26036_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(17, 17);
}

void krnl_sobel::thread_tmp_639_fu_49175_p3() {
    tmp_639_fu_49175_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(35, 35);
}

void krnl_sobel::thread_tmp_63_fu_23600_p1() {
    tmp_63_fu_23600_p1 = tmp_12_reg_70931.read().range(4-1, 0);
}

void krnl_sobel::thread_tmp_640_fu_26044_p3() {
    tmp_640_fu_26044_p3 = p_164_reg2mem697_0_i_i_1_reg_3229.read().range(16, 16);
}

void krnl_sobel::thread_tmp_641_fu_49183_p3() {
    tmp_641_fu_49183_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(34, 34);
}

void krnl_sobel::thread_tmp_642_fu_26097_p3() {
    tmp_642_fu_26097_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(61, 61);
}

void krnl_sobel::thread_tmp_643_fu_49191_p3() {
    tmp_643_fu_49191_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(33, 33);
}

void krnl_sobel::thread_tmp_644_fu_26105_p3() {
    tmp_644_fu_26105_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(60, 60);
}

void krnl_sobel::thread_tmp_645_fu_49199_p3() {
    tmp_645_fu_49199_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(32, 32);
}

void krnl_sobel::thread_tmp_646_fu_26113_p3() {
    tmp_646_fu_26113_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(59, 59);
}

void krnl_sobel::thread_tmp_647_fu_49207_p3() {
    tmp_647_fu_49207_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(31, 31);
}

void krnl_sobel::thread_tmp_648_fu_26121_p3() {
    tmp_648_fu_26121_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(58, 58);
}

void krnl_sobel::thread_tmp_649_fu_49215_p3() {
    tmp_649_fu_49215_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(30, 30);
}

void krnl_sobel::thread_tmp_64_fu_24151_p4() {
    tmp_64_fu_24151_p4 = indvars_iv2_reg_2743.read().range(31, 2);
}

void krnl_sobel::thread_tmp_650_fu_26129_p3() {
    tmp_650_fu_26129_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(57, 57);
}

void krnl_sobel::thread_tmp_651_fu_49223_p3() {
    tmp_651_fu_49223_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(29, 29);
}

void krnl_sobel::thread_tmp_652_fu_26137_p3() {
    tmp_652_fu_26137_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(56, 56);
}

void krnl_sobel::thread_tmp_653_fu_49231_p3() {
    tmp_653_fu_49231_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(28, 28);
}

void krnl_sobel::thread_tmp_654_fu_26145_p3() {
    tmp_654_fu_26145_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(55, 55);
}

void krnl_sobel::thread_tmp_655_fu_49239_p3() {
    tmp_655_fu_49239_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(27, 27);
}

void krnl_sobel::thread_tmp_656_fu_26153_p3() {
    tmp_656_fu_26153_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(54, 54);
}

void krnl_sobel::thread_tmp_657_fu_49247_p3() {
    tmp_657_fu_49247_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(26, 26);
}

void krnl_sobel::thread_tmp_658_fu_26161_p3() {
    tmp_658_fu_26161_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(53, 53);
}

void krnl_sobel::thread_tmp_659_fu_49255_p3() {
    tmp_659_fu_49255_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(25, 25);
}

void krnl_sobel::thread_tmp_65_fu_24161_p1() {
    tmp_65_fu_24161_p1 = esl_sext<62,30>(tmp_64_fu_24151_p4.read());
}

void krnl_sobel::thread_tmp_660_fu_26169_p3() {
    tmp_660_fu_26169_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(52, 52);
}

void krnl_sobel::thread_tmp_661_fu_49263_p3() {
    tmp_661_fu_49263_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(24, 24);
}

void krnl_sobel::thread_tmp_662_fu_26177_p3() {
    tmp_662_fu_26177_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(51, 51);
}

void krnl_sobel::thread_tmp_663_fu_49271_p3() {
    tmp_663_fu_49271_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(23, 23);
}

void krnl_sobel::thread_tmp_664_fu_26185_p3() {
    tmp_664_fu_26185_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(50, 50);
}

void krnl_sobel::thread_tmp_665_fu_49279_p3() {
    tmp_665_fu_49279_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(22, 22);
}

void krnl_sobel::thread_tmp_666_fu_26193_p3() {
    tmp_666_fu_26193_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(49, 49);
}

void krnl_sobel::thread_tmp_667_fu_49287_p3() {
    tmp_667_fu_49287_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(21, 21);
}

void krnl_sobel::thread_tmp_668_fu_26201_p3() {
    tmp_668_fu_26201_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(48, 48);
}

void krnl_sobel::thread_tmp_669_fu_49295_p3() {
    tmp_669_fu_49295_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(20, 20);
}

void krnl_sobel::thread_tmp_66_fu_24094_p2() {
    tmp_66_fu_24094_p2 = (!y1_0_reg2mem727_0_i_i_cast_fu_24090_p1.read().is_01() || !tmp_61_reg_71272.read().is_01())? sc_lv<1>(): (sc_bigint<32>(y1_0_reg2mem727_0_i_i_cast_fu_24090_p1.read()) < sc_bigint<32>(tmp_61_reg_71272.read()));
}

void krnl_sobel::thread_tmp_670_fu_26209_p3() {
    tmp_670_fu_26209_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(47, 47);
}

void krnl_sobel::thread_tmp_671_fu_49303_p3() {
    tmp_671_fu_49303_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(19, 19);
}

void krnl_sobel::thread_tmp_672_fu_26217_p3() {
    tmp_672_fu_26217_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(46, 46);
}

void krnl_sobel::thread_tmp_673_fu_49311_p3() {
    tmp_673_fu_49311_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(18, 18);
}

void krnl_sobel::thread_tmp_674_fu_26225_p3() {
    tmp_674_fu_26225_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(45, 45);
}

void krnl_sobel::thread_tmp_675_fu_49319_p3() {
    tmp_675_fu_49319_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(17, 17);
}

void krnl_sobel::thread_tmp_676_fu_26233_p3() {
    tmp_676_fu_26233_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(44, 44);
}

void krnl_sobel::thread_tmp_677_fu_49327_p3() {
    tmp_677_fu_49327_p3 = p_143_reg2mem615_0_i_i_1_reg_13299.read().range(16, 16);
}

void krnl_sobel::thread_tmp_678_fu_26241_p3() {
    tmp_678_fu_26241_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(43, 43);
}

void krnl_sobel::thread_tmp_679_fu_49380_p3() {
    tmp_679_fu_49380_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(61, 61);
}

void krnl_sobel::thread_tmp_67_fu_24099_p2() {
    tmp_67_fu_24099_p2 = (!ap_const_lv31_1.is_01() || !y1_0_reg2mem727_0_i_i_reg_2779.read().is_01())? sc_lv<31>(): (sc_biguint<31>(ap_const_lv31_1) + sc_biguint<31>(y1_0_reg2mem727_0_i_i_reg_2779.read()));
}

void krnl_sobel::thread_tmp_680_fu_26249_p3() {
    tmp_680_fu_26249_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(42, 42);
}

void krnl_sobel::thread_tmp_681_fu_49388_p3() {
    tmp_681_fu_49388_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(60, 60);
}

void krnl_sobel::thread_tmp_682_fu_26257_p3() {
    tmp_682_fu_26257_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(41, 41);
}

void krnl_sobel::thread_tmp_683_fu_49396_p3() {
    tmp_683_fu_49396_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(59, 59);
}

void krnl_sobel::thread_tmp_684_fu_26265_p3() {
    tmp_684_fu_26265_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(40, 40);
}

void krnl_sobel::thread_tmp_685_fu_49404_p3() {
    tmp_685_fu_49404_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(58, 58);
}

void krnl_sobel::thread_tmp_686_fu_26273_p3() {
    tmp_686_fu_26273_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(39, 39);
}

void krnl_sobel::thread_tmp_687_fu_49412_p3() {
    tmp_687_fu_49412_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(57, 57);
}

void krnl_sobel::thread_tmp_688_fu_26281_p3() {
    tmp_688_fu_26281_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(38, 38);
}

void krnl_sobel::thread_tmp_689_fu_49420_p3() {
    tmp_689_fu_49420_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(56, 56);
}

void krnl_sobel::thread_tmp_690_fu_26289_p3() {
    tmp_690_fu_26289_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(37, 37);
}

void krnl_sobel::thread_tmp_691_fu_49428_p3() {
    tmp_691_fu_49428_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(55, 55);
}

void krnl_sobel::thread_tmp_692_fu_26297_p3() {
    tmp_692_fu_26297_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(36, 36);
}

void krnl_sobel::thread_tmp_693_fu_49436_p3() {
    tmp_693_fu_49436_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(54, 54);
}

void krnl_sobel::thread_tmp_694_fu_26305_p3() {
    tmp_694_fu_26305_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(35, 35);
}

void krnl_sobel::thread_tmp_695_fu_49444_p3() {
    tmp_695_fu_49444_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(53, 53);
}

void krnl_sobel::thread_tmp_696_fu_26313_p3() {
    tmp_696_fu_26313_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(34, 34);
}

void krnl_sobel::thread_tmp_697_fu_49452_p3() {
    tmp_697_fu_49452_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(52, 52);
}

void krnl_sobel::thread_tmp_698_fu_26321_p3() {
    tmp_698_fu_26321_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(33, 33);
}

void krnl_sobel::thread_tmp_699_fu_49460_p3() {
    tmp_699_fu_49460_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(51, 51);
}

void krnl_sobel::thread_tmp_69_cast_fu_24165_p1() {
    tmp_69_cast_fu_24165_p1 = esl_zext<63,62>(tmp_65_fu_24161_p1.read());
}

void krnl_sobel::thread_tmp_69_fu_23831_p1() {
    tmp_69_fu_23831_p1 = esl_zext<32,30>(rd_cnt_burst1_fu_23821_p4.read());
}

void krnl_sobel::thread_tmp_6_fu_23263_p2() {
    tmp_6_fu_23263_p2 = (!y_0_reg2mem737_0_i_i_cast_fu_23259_p1.read().is_01() || !arg_height_reg_70737.read().is_01())? sc_lv<1>(): (sc_bigint<32>(y_0_reg2mem737_0_i_i_cast_fu_23259_p1.read()) < sc_bigint<32>(arg_height_reg_70737.read()));
}

void krnl_sobel::thread_tmp_700_fu_26329_p3() {
    tmp_700_fu_26329_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(32, 32);
}

void krnl_sobel::thread_tmp_701_fu_49468_p3() {
    tmp_701_fu_49468_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(50, 50);
}

void krnl_sobel::thread_tmp_702_fu_26337_p3() {
    tmp_702_fu_26337_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(31, 31);
}

void krnl_sobel::thread_tmp_703_fu_49476_p3() {
    tmp_703_fu_49476_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(49, 49);
}

void krnl_sobel::thread_tmp_704_fu_26345_p3() {
    tmp_704_fu_26345_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(30, 30);
}

void krnl_sobel::thread_tmp_705_fu_49484_p3() {
    tmp_705_fu_49484_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(48, 48);
}

void krnl_sobel::thread_tmp_706_fu_26353_p3() {
    tmp_706_fu_26353_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(29, 29);
}

void krnl_sobel::thread_tmp_707_fu_49492_p3() {
    tmp_707_fu_49492_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(47, 47);
}

void krnl_sobel::thread_tmp_708_fu_26361_p3() {
    tmp_708_fu_26361_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(28, 28);
}

void krnl_sobel::thread_tmp_709_fu_49500_p3() {
    tmp_709_fu_49500_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(46, 46);
}

void krnl_sobel::thread_tmp_70_fu_24118_p4() {
    tmp_70_fu_24118_p4 = grp_fu_24109_p2.read().range(31, 2);
}

void krnl_sobel::thread_tmp_710_fu_26369_p3() {
    tmp_710_fu_26369_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(27, 27);
}

void krnl_sobel::thread_tmp_711_fu_49508_p3() {
    tmp_711_fu_49508_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(45, 45);
}

void krnl_sobel::thread_tmp_712_fu_26377_p3() {
    tmp_712_fu_26377_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(26, 26);
}

void krnl_sobel::thread_tmp_713_fu_49516_p3() {
    tmp_713_fu_49516_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(44, 44);
}

void krnl_sobel::thread_tmp_714_fu_26385_p3() {
    tmp_714_fu_26385_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(25, 25);
}

void krnl_sobel::thread_tmp_715_fu_49524_p3() {
    tmp_715_fu_49524_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(43, 43);
}

void krnl_sobel::thread_tmp_716_fu_26393_p3() {
    tmp_716_fu_26393_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(24, 24);
}

void krnl_sobel::thread_tmp_717_fu_49532_p3() {
    tmp_717_fu_49532_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(42, 42);
}

void krnl_sobel::thread_tmp_718_fu_26401_p3() {
    tmp_718_fu_26401_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(23, 23);
}

void krnl_sobel::thread_tmp_719_fu_49540_p3() {
    tmp_719_fu_49540_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(41, 41);
}

void krnl_sobel::thread_tmp_71_fu_24128_p1() {
    tmp_71_fu_24128_p1 = esl_sext<62,30>(tmp_70_fu_24118_p4.read());
}

void krnl_sobel::thread_tmp_720_fu_26409_p3() {
    tmp_720_fu_26409_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(22, 22);
}

void krnl_sobel::thread_tmp_721_fu_49548_p3() {
    tmp_721_fu_49548_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(40, 40);
}

void krnl_sobel::thread_tmp_722_fu_26417_p3() {
    tmp_722_fu_26417_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(21, 21);
}

void krnl_sobel::thread_tmp_723_fu_49556_p3() {
    tmp_723_fu_49556_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(39, 39);
}

void krnl_sobel::thread_tmp_724_fu_26425_p3() {
    tmp_724_fu_26425_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(20, 20);
}

void krnl_sobel::thread_tmp_725_fu_49564_p3() {
    tmp_725_fu_49564_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(38, 38);
}

void krnl_sobel::thread_tmp_726_fu_26433_p3() {
    tmp_726_fu_26433_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(19, 19);
}

void krnl_sobel::thread_tmp_727_fu_49572_p3() {
    tmp_727_fu_49572_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(37, 37);
}

void krnl_sobel::thread_tmp_728_fu_26441_p3() {
    tmp_728_fu_26441_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(18, 18);
}

void krnl_sobel::thread_tmp_729_fu_49580_p3() {
    tmp_729_fu_49580_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(36, 36);
}

void krnl_sobel::thread_tmp_72_fu_24192_p2() {
    tmp_72_fu_24192_p2 = (prealign_wr_cnt1_reg_71336.read() & tmp_73_cast_fu_24184_p3.read());
}

void krnl_sobel::thread_tmp_730_fu_26449_p3() {
    tmp_730_fu_26449_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(17, 17);
}

void krnl_sobel::thread_tmp_731_fu_49588_p3() {
    tmp_731_fu_49588_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(35, 35);
}

void krnl_sobel::thread_tmp_732_fu_26457_p3() {
    tmp_732_fu_26457_p3 = p_164_reg2mem697_0_i_i_2_reg_3439.read().range(16, 16);
}

void krnl_sobel::thread_tmp_733_fu_49596_p3() {
    tmp_733_fu_49596_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(34, 34);
}

void krnl_sobel::thread_tmp_734_fu_26509_p3() {
    tmp_734_fu_26509_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(61, 61);
}

void krnl_sobel::thread_tmp_735_fu_49604_p3() {
    tmp_735_fu_49604_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(33, 33);
}

void krnl_sobel::thread_tmp_736_fu_26517_p3() {
    tmp_736_fu_26517_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(60, 60);
}

void krnl_sobel::thread_tmp_737_fu_49612_p3() {
    tmp_737_fu_49612_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(32, 32);
}

void krnl_sobel::thread_tmp_738_fu_26525_p3() {
    tmp_738_fu_26525_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(59, 59);
}

void krnl_sobel::thread_tmp_739_fu_49620_p3() {
    tmp_739_fu_49620_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(31, 31);
}

void krnl_sobel::thread_tmp_73_cast_fu_24184_p3() {
    tmp_73_cast_fu_24184_p3 = (!mod_ne_zero2_fu_24179_p2.read()[0].is_01())? sc_lv<3>(): ((mod_ne_zero2_fu_24179_p2.read()[0].to_bool())? ap_const_lv3_7: ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_73_fu_24224_p3() {
    tmp_73_fu_24224_p3 = esl_concat<2,3>(tmp_130_reg_71324.read(), ap_const_lv3_0);
}

void krnl_sobel::thread_tmp_740_fu_26533_p3() {
    tmp_740_fu_26533_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(58, 58);
}

void krnl_sobel::thread_tmp_741_fu_49628_p3() {
    tmp_741_fu_49628_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(30, 30);
}

void krnl_sobel::thread_tmp_742_fu_26541_p3() {
    tmp_742_fu_26541_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(57, 57);
}

void krnl_sobel::thread_tmp_743_fu_49636_p3() {
    tmp_743_fu_49636_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(29, 29);
}

void krnl_sobel::thread_tmp_744_fu_26549_p3() {
    tmp_744_fu_26549_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(56, 56);
}

void krnl_sobel::thread_tmp_745_fu_49644_p3() {
    tmp_745_fu_49644_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(28, 28);
}

void krnl_sobel::thread_tmp_746_fu_26557_p3() {
    tmp_746_fu_26557_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(55, 55);
}

void krnl_sobel::thread_tmp_747_fu_49652_p3() {
    tmp_747_fu_49652_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(27, 27);
}

void krnl_sobel::thread_tmp_748_fu_26565_p3() {
    tmp_748_fu_26565_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(54, 54);
}

void krnl_sobel::thread_tmp_749_fu_49660_p3() {
    tmp_749_fu_49660_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(26, 26);
}

void krnl_sobel::thread_tmp_74_cast_fu_24197_p1() {
    tmp_74_cast_fu_24197_p1 = esl_zext<32,3>(tmp_72_fu_24192_p2.read());
}

void krnl_sobel::thread_tmp_74_fu_47088_p1() {
    tmp_74_fu_47088_p1 = esl_sext<64,32>(krnl_sobel_rowbuf0_mult1_reg_80367.read());
}

void krnl_sobel::thread_tmp_750_fu_26573_p3() {
    tmp_750_fu_26573_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(53, 53);
}

void krnl_sobel::thread_tmp_751_fu_49668_p3() {
    tmp_751_fu_49668_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(25, 25);
}

void krnl_sobel::thread_tmp_752_fu_26581_p3() {
    tmp_752_fu_26581_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(52, 52);
}

void krnl_sobel::thread_tmp_753_fu_49676_p3() {
    tmp_753_fu_49676_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(24, 24);
}

void krnl_sobel::thread_tmp_754_fu_26589_p3() {
    tmp_754_fu_26589_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(51, 51);
}

void krnl_sobel::thread_tmp_755_fu_49684_p3() {
    tmp_755_fu_49684_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(23, 23);
}

void krnl_sobel::thread_tmp_756_fu_26597_p3() {
    tmp_756_fu_26597_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(50, 50);
}

void krnl_sobel::thread_tmp_757_fu_49692_p3() {
    tmp_757_fu_49692_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(22, 22);
}

void krnl_sobel::thread_tmp_758_fu_26605_p3() {
    tmp_758_fu_26605_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(49, 49);
}

void krnl_sobel::thread_tmp_759_fu_49700_p3() {
    tmp_759_fu_49700_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(21, 21);
}

void krnl_sobel::thread_tmp_75_cast_fu_24231_p1() {
    tmp_75_cast_fu_24231_p1 = esl_zext<32,5>(tmp_73_fu_24224_p3.read());
}

void krnl_sobel::thread_tmp_75_fu_47092_p2() {
    tmp_75_fu_47092_p2 = (krnl_sobel_rowbuf0_mult1_reg_80367.read() | ap_const_lv32_1);
}

void krnl_sobel::thread_tmp_760_fu_26613_p3() {
    tmp_760_fu_26613_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(48, 48);
}

void krnl_sobel::thread_tmp_761_fu_49708_p3() {
    tmp_761_fu_49708_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(20, 20);
}

void krnl_sobel::thread_tmp_762_fu_26621_p3() {
    tmp_762_fu_26621_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(47, 47);
}

void krnl_sobel::thread_tmp_763_fu_49716_p3() {
    tmp_763_fu_49716_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(19, 19);
}

void krnl_sobel::thread_tmp_764_fu_26629_p3() {
    tmp_764_fu_26629_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(46, 46);
}

void krnl_sobel::thread_tmp_765_fu_49724_p3() {
    tmp_765_fu_49724_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(18, 18);
}

void krnl_sobel::thread_tmp_766_fu_26637_p3() {
    tmp_766_fu_26637_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(45, 45);
}

void krnl_sobel::thread_tmp_767_fu_49732_p3() {
    tmp_767_fu_49732_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(17, 17);
}

void krnl_sobel::thread_tmp_768_fu_26645_p3() {
    tmp_768_fu_26645_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(44, 44);
}

void krnl_sobel::thread_tmp_769_fu_49740_p3() {
    tmp_769_fu_49740_p3 = p_143_reg2mem615_0_i_i_2_reg_13509.read().range(16, 16);
}

void krnl_sobel::thread_tmp_76_fu_47097_p1() {
    tmp_76_fu_47097_p1 = esl_sext<64,32>(tmp_75_fu_47092_p2.read());
}

void krnl_sobel::thread_tmp_770_fu_26653_p3() {
    tmp_770_fu_26653_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(43, 43);
}

void krnl_sobel::thread_tmp_771_fu_49792_p3() {
    tmp_771_fu_49792_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(61, 61);
}

void krnl_sobel::thread_tmp_772_fu_26661_p3() {
    tmp_772_fu_26661_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(42, 42);
}

void krnl_sobel::thread_tmp_773_fu_49800_p3() {
    tmp_773_fu_49800_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(60, 60);
}

void krnl_sobel::thread_tmp_774_fu_26669_p3() {
    tmp_774_fu_26669_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(41, 41);
}

void krnl_sobel::thread_tmp_775_fu_49808_p3() {
    tmp_775_fu_49808_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(59, 59);
}

void krnl_sobel::thread_tmp_776_fu_26677_p3() {
    tmp_776_fu_26677_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(40, 40);
}

void krnl_sobel::thread_tmp_777_fu_49816_p3() {
    tmp_777_fu_49816_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(58, 58);
}

void krnl_sobel::thread_tmp_778_fu_26685_p3() {
    tmp_778_fu_26685_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(39, 39);
}

void krnl_sobel::thread_tmp_779_fu_49824_p3() {
    tmp_779_fu_49824_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(57, 57);
}

void krnl_sobel::thread_tmp_77_fu_47102_p2() {
    tmp_77_fu_47102_p2 = (ap_pipeline_reg_pp4_iter1_krnl_sobel_rowbuf0_mult1_reg_80367.read() | ap_const_lv32_2);
}

void krnl_sobel::thread_tmp_780_fu_26693_p3() {
    tmp_780_fu_26693_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(38, 38);
}

void krnl_sobel::thread_tmp_781_fu_49832_p3() {
    tmp_781_fu_49832_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(56, 56);
}

void krnl_sobel::thread_tmp_782_fu_26701_p3() {
    tmp_782_fu_26701_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(37, 37);
}

void krnl_sobel::thread_tmp_783_fu_49840_p3() {
    tmp_783_fu_49840_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(55, 55);
}

void krnl_sobel::thread_tmp_784_fu_26709_p3() {
    tmp_784_fu_26709_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(36, 36);
}

void krnl_sobel::thread_tmp_785_fu_49848_p3() {
    tmp_785_fu_49848_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(54, 54);
}

void krnl_sobel::thread_tmp_786_fu_26717_p3() {
    tmp_786_fu_26717_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(35, 35);
}

void krnl_sobel::thread_tmp_787_fu_49856_p3() {
    tmp_787_fu_49856_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(53, 53);
}

void krnl_sobel::thread_tmp_788_fu_26725_p3() {
    tmp_788_fu_26725_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(34, 34);
}

void krnl_sobel::thread_tmp_789_fu_49864_p3() {
    tmp_789_fu_49864_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(52, 52);
}

void krnl_sobel::thread_tmp_78_fu_47107_p1() {
    tmp_78_fu_47107_p1 = esl_sext<64,32>(tmp_77_fu_47102_p2.read());
}

void krnl_sobel::thread_tmp_790_fu_26733_p3() {
    tmp_790_fu_26733_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(33, 33);
}

void krnl_sobel::thread_tmp_791_fu_49872_p3() {
    tmp_791_fu_49872_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(51, 51);
}

void krnl_sobel::thread_tmp_792_fu_26741_p3() {
    tmp_792_fu_26741_p3 = p_164_reg2mem697_0_i_i_3_reg_3648.read().range(32, 32);
}

void krnl_sobel::thread_tmp_793_fu_49880_p3() {
    tmp_793_fu_49880_p3 = p_143_reg2mem615_0_i_i_3_reg_13718.read().range(50, 50);
}

}

