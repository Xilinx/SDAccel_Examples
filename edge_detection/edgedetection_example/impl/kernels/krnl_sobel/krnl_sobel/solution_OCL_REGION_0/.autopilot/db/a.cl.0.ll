; ModuleID = '/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/solution_OCL_REGION_0/.autopilot/db/a.cl.0.bc'
target datalayout = "e-p:64:64:64-i1:8:8-i8:8:8-i16:16:16-i32:32:32-i64:64:64-f32:32:32-f64:64:64-v16:16:16-v24:32:32-v32:32:32-v48:64:64-v64:64:64-v96:128:128-v128:128:128-v192:256:256-v256:256:256-v512:512:512-v1024:1024:1024"
target triple = "spir64-unknown-linux-gnu"

%struct.__spir_rt_info_tT.2 = type { i32, [3 x i32], [3 x i32], [3 x i32], [3 x i32], [3 x i32], [3 x i32], [3 x i32], i8*, i1, i8*, i8*, i64 }
%class.sw_em_force_ftz = type { i32 }
%struct.krnl_sobel_args_t = type { i64, i32, i32, i32, i64 }
%union.anon.0 = type { float }
%union.anon = type { float }
%union.anon.1 = type { i64 }
%union.anon.13 = type { float }
%struct.__spir_rt_info_tT = type { i32, [3 x i32], [3 x i32], [3 x i32], [3 x i32], [3 x i32], [3 x i32], [3 x i32], i8*, i8, i8*, i8*, i64 }

@krnl_sobel.rowbuf0 = internal addrspace(3) global [4096 x i8] zeroinitializer, align 1 ; [#uses=2 type=[4096 x i8] addrspace(3)*]
@krnl_sobel.rowbuf1 = internal addrspace(3) global [4096 x i8] zeroinitializer, align 1 ; [#uses=2 type=[4096 x i8] addrspace(3)*]
@krnl_sobel.rowbuf2 = internal addrspace(3) global [4096 x i8] zeroinitializer, align 1 ; [#uses=6 type=[4096 x i8] addrspace(3)*]
@krnl_sobel.resbuf = internal addrspace(3) global [4096 x i8] zeroinitializer, align 1 ; [#uses=3 type=[4096 x i8] addrspace(3)*]
@_ZZL10hls_cordicE6angles = internal global [64 x i64] zeroinitializer, align 8 ; [#uses=0 type=[64 x i64]*]
@_ZZL22hls_payne_hanek_hyperbfPiE4iln2 = internal constant [4 x i16] [i16 -3909, i16 23575, i16 15145, i16 -18262], align 2 ; [#uses=0 type=[4 x i16]*]
@_ZZL22hls_payne_hanek_hyperbfPiE3ln2 = internal constant [4 x i16] [i16 -17195, i16 -5913, i16 3067, i16 22713], align 2 ; [#uses=0 type=[4 x i16]*]
@_ZZL20hls_payne_hanek_trigfPiE4ipi2 = internal constant [15 x i16] [i16 -4258, i16 -20011, i16 -216, i16 -14304, i16 -25055, i16 19148, i16 28081, i16 28384, i16 -1382, i16 -21528, i16 -493, i16 2708, i16 10018, i16 -15945, i16 20860], align 2 ; [#uses=0 type=[15 x i16]*]
@_ZZL20hls_payne_hanek_trigfPiE3pi2 = internal constant [15 x i16] [i16 3068, i16 -21526, i16 -4573, i16 20057, i16 24478, i16 -29278, i16 31443, i16 24801, i16 -9846, i16 16987, i16 -22400, i16 -16698, i16 8552, i16 -9566, i16 -14065], align 2 ; [#uses=0 type=[15 x i16]*]
@_ZZL13hls_exp2_fracE3pos = internal global [47 x i64] zeroinitializer, align 8 ; [#uses=49 type=[47 x i64]*]
@_ZZL13hls_log2_fracE3pos = internal global [47 x i64] zeroinitializer, align 8 ; [#uses=49 type=[47 x i64]*]
@_ZZL9__log2_epPdS_dE12__loglTable1 = private unnamed_addr constant [64 x [3 x double]] [[3 x double] [double 0x3FF5390948F40FEA, double 0xBFDA152F142A0000, double 0x3D7F93E27B43BD2C], [3 x double] [double 0x3FF5015015015015, double 0xBFD9218009250000, double 0x3D6162432A1B8DF7], [3 x double] [double 0x3FF4CAB88725AF6E, double 0xBFD8304D90C18000, double 0x3D780BB749056FE7], [3 x double] [double 0x3FF49539E3B2D066, double 0xBFD7418ACEBC0000, double 0x3D4CEAC7F0607711], [3 x double] [double 0x3FF460CBC7F5CF9A, double 0xBFD6552B49988000, double 0x3D5D8913D0E89FA0], [3 x double] [double 0x3FF42D6625D51F86, double 0xBFD56B22E6B58000, double 0x3D3C7EAF515033A1], [3 x double] [double 0x3FF3FB013FB013FB, double 0xBFD48365E6960000, double 0x3D6434ADCDE7EDC7], [3 x double] [double 0x3FF3C995A47BABE7, double 0xBFD39DE8E1560000, double 0x3D78246F8E527754], [3 x double] [double 0x3FF3991C2C187F63, double 0xBFD2BAA0C34C0000, double 0x3D5E1513C28E180D], [3 x double] [double 0x3FF3698DF3DE0747, double 0xBFD1D982C9D58000, double 0x3D763EA3FED4B8A2], [3 x double] [double 0x3FF33AE45B57BCB1, double 0xBFD0FA8480450000, double 0x3D732CCBACF1779B], [3 x double] [double 0x3FF30D190130D190, double 0xBFD01D9BBCFA8000, double 0x3D5E2BFEB2B884AA], [3 x double] [double 0x3FF2E025C04B8097, double 0xBFCE857D3D370000, double 0x3D7D9309B4D2EA85], [3 x double] [double 0x3FF2B404AD012B40, double 0xBFCCD3C712D40000, double 0x3D7DDF360962D7AB], [3 x double] [double 0x3FF288B01288B012, double 0xBFCB2602497E0000, double 0x3D7597F8A121640F], [3 x double] [double 0x3FF25E22708092F1, double 0xBFC97C1CB13D0000, double 0x3D702807D15580DC], [3 x double] [double 0x3FF23456789ABCDF, double 0xBFC7D60496D00000, double 0x3D612CE913D7A827], [3 x double] [double 0x3FF20B470C67C0D8, double 0xBFC633A8BF440000, double 0x3D70648BCA9C96BD], [3 x double] [double 0x3FF1E2EF3B3FB874, double 0xBFC494F863B90000, double 0x3D5066FCEB89B0EB], [3 x double] [double 0x3FF1BB4A4046ED29, double 0xBFC2F9E32D5C0000, double 0x3D117B8B6C4F846B], [3 x double] [double 0x3FF19453808CA29C, double 0xBFC1625931870000, double 0x3D52C83506452154], [3 x double] [double 0x3FF16E0689427378, double 0xBFBF9C95DC1E0000, double 0x3D6DD5D2183150F3], [3 x double] [double 0x3FF1485F0E0ACD3B, double 0xBFBC7B528B720000, double 0x3D70E43C4F4E619D], [3 x double] [double 0x3FF12358E75D3033, double 0xBFB960CAF9AC0000, double 0x3D520FBFD5902A1E], [3 x double] [double 0x3FF0FEF010FEF010, double 0xBFB64CE26C080000, double 0x3D78EBEEFB4AC467], [3 x double] [double 0x3FF0DB20A88F4695, double 0xBFB33F7CDE160000, double 0x3D730B3312DA7A7D], [3 x double] [double 0x3FF0B7E6EC259DC7, double 0xBFB0387EFBCC0000, double 0x3D7796F1632949C3], [3 x double] [double 0x3FF0953F39010953, double 0xBFAA6F9C37800000, double 0x3D71687E151172CC], [3 x double] [double 0x3FF073260A47F7C6, double 0xBFA47AA073580000, double 0x3D51F87E4A9CC778], [3 x double] [double 0x3FF05197F7D73404, double 0xBF9D23AFC4980000, double 0x3D7B183A6B628487], [3 x double] [double 0x3FF03091B51F5E1A, double 0xBF916A21E2100000, double 0x3D77D75C58973CE5], [3 x double] [double 1.000000e+00, double 0.000000e+00, double 0.000000e+00], [3 x double] [double 1.000000e+00, double 0.000000e+00, double 0.000000e+00], [3 x double] [double 0x3FEF44659E4A4271, double 0x3FA11CD1D5100000, double 0x3D79A0D857E2F4B2], [3 x double] [double 0x3FEECC07B301ECC0, double 0x3FAC4DFAB9080000, double 0x3D755B53FCE557FD], [3 x double] [double 0x3FEE573AC901E573, double 0x3FB3AA2FDD260000, double 0x3D7F1CB0C9532089], [3 x double] [double 0x3FEDE5D6E3F8868A, double 0x3FB918A16E460000, double 0x3D49AF0DCD65A6E1], [3 x double] [double 0x3FED77B654B82C33, double 0x3FBE72EC117E0000, double 0x3D7A5B93C4EBE124], [3 x double] [double 0x3FED0CB58F6EC074, double 0x3FC1DCD197550000, double 0x3D55BE50E71DDC6C], [3 x double] [double 0x3FECA4B3055EE191, double 0x3FC476A9F9830000, double 0x3D7EE9A798719E7F], [3 x double] [double 0x3FEC3F8F01C3F8F0, double 0x3FC70742D4EF0000, double 0x3D13FF1352C1219C], [3 x double] [double 0x3FEBDD2B899406F7, double 0x3FC98EDD077E0000, double 0x3D6C383CD11362F4], [3 x double] [double 0x3FEB7D6C3DDA338B, double 0x3FCC0DB6CDD90000, double 0x3D637BD85B1A824E], [3 x double] [double 0x3FEB2036406C80D9, double 0x3FCE840BE74E0000, double 0x3D6A9334D525E1EC], [3 x double] [double 0x3FEAC5701AC5701A, double 0x3FD0790ADBB00000, double 0x3D68060BFB6A4910], [3 x double] [double 0x3FEA6D01A6D01A6D, double 0x3FD1AC05B2918000, double 0x3D7C1C161471580A], [3 x double] [double 0x3FEA16D3F97A4B01, double 0x3FD2DB10FC4D8000, double 0x3D5AB1AA62214581], [3 x double] [double 0x3FE9C2D14EE4A101, double 0x3FD406463B1B0000, double 0x3D312E95DBDA6611], [3 x double] [double 0x3FE970E4F80CB872, double 0x3FD52DBDFC4C8000, double 0x3D56B53FEE511AF0], [3 x double] [double 0x3FE920FB49D0E228, double 0x3FD6518FE4670000, double 0x3D7EEA7D7D7D1764], [3 x double] [double 0x3FE8D3018D3018D3, double 0x3FD771D2BA7E8000, double 0x3D7ECEFA8D4FAB97], [3 x double] [double 0x3FE886E5F0ABB049, double 0x3FD88E9C72E08000, double 0x3D6913EA3D33FD14], [3 x double] [double 0x3FE83C977AB2BEDD, double 0x3FD9A802391E0000, double 0x3D6197E845877C94], [3 x double] [double 0x3FE7F405FD017F40, double 0x3FDABE18797F0000, double 0x3D5F4A52F8E8A810], [3 x double] [double 0x3FE7AD2208E0ECC3, double 0x3FDBD0F2E9E78000, double 0x3D5031F4336644CC], [3 x double] [double 0x3FE767DCE434A9B1, double 0x3FDCE0A4923A0000, double 0x3D761F33C897020C], [3 x double] [double 0x3FE724287F46DEBC, double 0x3FDDED3FD4420000, double 0x3D6B2632E8306320], [3 x double] [double 0x3FE6E1F76B4337C6, double 0x3FDEF6D673288000, double 0x3D7888EC245A0BF0], [3 x double] [double 0x3FE6A13CD1537290, double 0x3FDFFD799A838000, double 0x3D7FE6F3B2F5FC8E], [3 x double] [double 0x3FE661EC6A5122F9, double 0x3FE0809CF27F4000, double 0x3D781EAA9EF284DD], [3 x double] [double 0x3FE623FA7701623F, double 0x3FE10113B153C000, double 0x3D51D7B07D6B1143], [3 x double] [double 0x3FE5E75BB8D015E7, double 0x3FE18028CF728000, double 0x3D676B100B1F6C60], [3 x double] [double 0x3FE5AC056B015AC0, double 0x3FE1FDE3D30E8000, double 0x3D226FAEB9870945], [3 x double] [double 0x3FE571ED3C506B39, double 0x3FE27A4C0585C000, double 0x3D57F2C5344D762B]], align 8 ; [#uses=0 type=[64 x [3 x double]]*]
@_ZZL9__log2_epPdS_dE12__loglTable2 = private unnamed_addr constant [64 x [3 x double]] [[3 x double] [double 0x3FF01FBE7F0A1BE6, double 0xBF86CF6DDD26112A, double 0x3C30725E5755E314], [3 x double] [double 0x3FF01EBA93A97B12, double 0xBF86155B1D99F603, double 0x3C34BCEA073117F4], [3 x double] [double 0x3FF01DB6C9029CD1, double 0xBF855B54153137FF, double 0x3C221E8FACCAD0EC], [3 x double] [double 0x3FF01CB31F0F534C, double 0xBF84A158C27245BD, double 0x3C31A5B7BFBF35D3], [3 x double] [double 0x3FF01BAF95C9723C, double 0xBF83E76923E3D678, double 0x3C1EEE400EB5FE34], [3 x double] [double 0x3FF01AAC2D2ACEE6, double 0xBF832D85380CE776, double 0x3C2CBF7A513937BD], [3 x double] [double 0x3FF019A8E52D401E, double 0xBF8273ACFD74BE72, double 0x3C35C64599EFA5E6], [3 x double] [double 0x3FF018A5BDCA9E42, double 0xBF81B9E072A2E650, double 0x3C3364180E0A5D37], [3 x double] [double 0x3FF017A2B6FCC33E, double 0xBF81001F961F3243, double 0x3C363D795746F216], [3 x double] [double 0x3FF0169FD0BD8A8A, double 0xBF80466A6671BCA4, double 0x3C34C99FF1907435], [3 x double] [double 0x3FF0159D0B06D129, double 0xBF7F1981C445CD05, double 0x3C14BFFF6366B723], [3 x double] [double 0x3FF0149A65D275A6, double 0xBF7DA6460F76AB8C, double 0x3C29C5404F47589C], [3 x double] [double 0x3FF01397E11A581B, double 0xBF7C3321AB87F4EF, double 0x3C2C0DA537429CEA], [3 x double] [double 0x3FF012957CD85A28, double 0xBF7AC014958C112C, double 0x3BF000C2A1B595E3], [3 x double] [double 0x3FF0119339065EF7, double 0xBF794D1ECA95F67A, double 0x3C2D8D20B0564D50], [3 x double] [double 0x3FF01091159E4B3D, double 0xBF77DA4047B92B3E, double 0x3BD6194A5D68CF20], [3 x double] [double 0x3FF00F8F129A0535, double 0xBF7667790A09BF77, double 0x3C2CA230E0BEA645], [3 x double] [double 0x3FF00E8D2FF374A1, double 0xBF74F4C90E9C4EAD, double 0x3C21DE3E7F350C10], [3 x double] [double 0x3FF00D8B6DA482CE, double 0xBF73823052860649, double 0x3BF5789B4C5891B8], [3 x double] [double 0x3FF00C89CBA71A8C, double 0xBF720FAED2DC9A9E, double 0x3C19E7C40F9839FD], [3 x double] [double 0x3FF00B8849F52834, double 0xBF709D448CB65014, double 0x3C1387E3E9B6D020], [3 x double] [double 0x3FF00A86E88899A4, double 0xBF6E55E2FA53EBF1, double 0x3C1CDAA71FDDFDDF], [3 x double] [double 0x3FF00985A75B5E3F, double 0xBF6B716B429DCE0F, double 0x3C02F2AF081367BF], [3 x double] [double 0x3FF00884866766EE, double 0xBF688D21EC7A16D7, double 0x3C1FB95C228D6F16], [3 x double] [double 0x3FF0078385A6A61D, double 0xBF65A906F219A9E8, double 0x3BF18AFF10A89F29], [3 x double] [double 0x3FF00682A5130FBE, double 0xBF62C51A4DAE87F1, double 0x3C0BCC7E33DDDE30], [3 x double] [double 0x3FF00581E4A69944, double 0xBF5FC2B7F2D782B1, double 0x3BFFE3EF3300A9FA], [3 x double] [double 0x3FF00481445B39A8, double 0xBF59FB97DF0B0B83, double 0x3BE0D9A601F2F324], [3 x double] [double 0x3FF00380C42AE963, double 0xBF5434D4546227AE, double 0x3C00B9B6A5868F33], [3 x double] [double 0x3FF00280640FA271, double 0xBF4CDCDA8E930C19, double 0x3BF3D424AB39F789], [3 x double] [double 0x3FF0018024036051, double 0xBF4150C558601261, double 0x3BF285BB90327A0F], [3 x double] [double 1.000000e+00, double 0.000000e+00, double 0.000000e+00], [3 x double] [double 1.000000e+00, double 0.000000e+00, double 0.000000e+00], [3 x double] [double 0x3FEFFA011FCA0A1E, double 0x3F514E5640C4197B, double 0x3C095728136AE401], [3 x double] [double 0x3FEFF6031F064E07, double 0x3F5CD61806BF532D, double 0x3C0568A4F35D8538], [3 x double] [double 0x3FEFF2061D532B9C, double 0x3F642E34AF550EDA, double 0x3C18F69CEE55FEC0], [3 x double] [double 0x3FEFEE0A1A513253, double 0x3F69F0A5523902EA, double 0x3C0DAEC734B11615], [3 x double] [double 0x3FEFEA0F15A12139, double 0x3F6FB25E19F11B26, double 0x3C18BAFCA62941DA], [3 x double] [double 0x3FEFE6150EE3E6D4, double 0x3F72B9AF9A28E282, double 0x3C20FD3674E1DC5B], [3 x double] [double 0x3FEFE21C05BAA109, double 0x3F7599D4678F24B9, double 0x3C2DAFCE1F09937B], [3 x double] [double 0x3FEFDE23F9C69CF9, double 0x3F78799D8C046EB0, double 0x3BEFFA0CE0BDD217], [3 x double] [double 0x3FEFDA2CEAA956E8, double 0x3F7B590B1E5951EE, double 0x3C1645A769232446], [3 x double] [double 0x3FEFD636D8047A1F, double 0x3F7E381D3555DBCF, double 0x3C2882320D368331], [3 x double] [double 0x3FEFD241C179E0CC, double 0x3F808B69F3DCCDE0, double 0x3C201AD5065ABA9E], [3 x double] [double 0x3FEFCE4DA6AB93E8, double 0x3F81FA97A61DD298, double 0x3C384CD1F931AE34], [3 x double] [double 0x3FEFCA5A873BCB19, double 0x3F836997BCC54A3F, double 0x3C31485E97EAEE03], [3 x double] [double 0x3FEFC66862CCEC93, double 0x3F84D86A43264A4F, double 0x3C2C75E63370988B], [3 x double] [double 0x3FEFC27739018CFE, double 0x3F86470F448FB09D, double 0x3BED7361EEAED0A1], [3 x double] [double 0x3FEFBE87097C6F5A, double 0x3F87B586CC4C2523, double 0x3C2B3DF952CC473C], [3 x double] [double 0x3FEFBA97D3E084DD, double 0x3F8923D0E5A21E06, double 0x3C1CF56C7B64AE5D], [3 x double] [double 0x3FEFB6A997D0ECDC, double 0x3F8A91ED9BD3DF9A, double 0x3C2B957BDCD89E43], [3 x double] [double 0x3FEFB2BC54F0F4AB, double 0x3F8BFFDCFA1F7FBB, double 0x3C1EA8CAD9A21771], [3 x double] [double 0x3FEFAED00AE41783, double 0x3F8D6D9F0BBEE6F6, double 0x3C35762A9AF89C82], [3 x double] [double 0x3FEFAAE4B94DFE64, double 0x3F8EDB33DBE7D335, double 0x3C121E24FC245697], [3 x double] [double 0x3FEFA6FA5FD27FF8, double 0x3F90244DBAE5ED05, double 0x3C312EF51B967102], [3 x double] [double 0x3FEFA310FE15A078, double 0x3F90DAEAF24C3529, double 0x3C410D3CFCA60B45], [3 x double] [double 0x3FEF9F2893BB9192, double 0x3F91917199BB66BC, double 0x3C36CF6034C32E19], [3 x double] [double 0x3FEF9B412068B247, double 0x3F9247E1B6C615D5, double 0x3C242F0FFFA229F7], [3 x double] [double 0x3FEF975AA3C18ED6, double 0x3F92FE3B4EFCC5AD, double 0x3C370106136A8919], [3 x double] [double 0x3FEF93751D6AE09B, double 0x3F93B47E67EDEA93, double 0x3C438DD5A4F6959A], [3 x double] [double 0x3FEF8F908D098DF6, double 0x3F946AAB0725EA6C, double 0x3C3821FC1E799E01], [3 x double] [double 0x3FEF8BACF242AA2C, double 0x3F9520C1322F1E4E, double 0x3C3129DCDA3AD563], [3 x double] [double 0x3FEF87CA4CBB7550, double 0x3F95D6C0EE91D2AB, double 0x3C1C5B190C04606E], [3 x double] [double 0x3FEF83E89C195C25, double 0x3F968CAA41D448C3, double 0x3C44723441195AC9]], align 8 ; [#uses=0 type=[64 x [3 x double]]*]
@_ZZL9__log2_epPdS_dE12__loglTable3 = private unnamed_addr constant [8 x [3 x double]] [[3 x double] [double 0x3FF000E00C40AB89, double 0xBF34332BE0032168, double 0x3BEA1003588D217A], [3 x double] [double 0x3FF000A006403E82, double 0xBF2CDB2987366FCC, double 0x3BC5C86001294BBC], [3 x double] [double 0x3FF0006002400D80, double 0xBF2150297C90FA6F, double 0x3BD01FB4865FAE32], [3 x double] [double 1.000000e+00, double 0.000000e+00, double 0.000000e+00], [3 x double] [double 1.000000e+00, double 0.000000e+00, double 0.000000e+00], [3 x double] [double 0x3FEFFE8011FF280A, double 0x3F314F8DAF5E3D3B, double 0x3BB3C933B4B6B914], [3 x double] [double 0x3FEFFD8031FC184E, double 0x3F3CD978C38042BB, double 0x3BE10F8E642E66FD], [3 x double] [double 0x3FEFFC8061F5492B, double 0x3F443183C878274E, double 0x3BE5885DD1EB6582]], align 8 ; [#uses=0 type=[8 x [3 x double]]*]
@_ZZL7hls_fmaE4kMSB = internal constant i32 -2147483648, align 4 ; [#uses=0 type=i32*]
@_ZZL19hls_payne_hanek_expfPiE4loge = internal constant [4 x i16] [i16 -1955, i16 -20981, i16 7572, i16 23637], align 2 ; [#uses=0 type=[4 x i16]*]
@_ZZL21hls_payne_hanek_exp10fPiE4loge = internal constant [4 x i16] [i16 -29954, i16 -13029, i16 30795, i16 -11110], align 2 ; [#uses=0 type=[4 x i16]*]
@hls_region = private constant [13 x i8] c"xcl_region_0\00", align 1 ; [#uses=1 type=[13 x i8]*]
@hls_region7 = private constant [13 x i8] c"xcl_region_1\00", align 1 ; [#uses=1 type=[13 x i8]*]
@.str = private unnamed_addr constant [6 x i8] c"m_axi\00", align 1 ; [#uses=1 type=[6 x i8]*]
@.str1 = private unnamed_addr constant [1 x i8] zeroinitializer, align 1 ; [#uses=1 type=[1 x i8]*]
@.str2 = private unnamed_addr constant [10 x i8] c"s_axilite\00", align 1 ; [#uses=1 type=[10 x i8]*]
@.str3 = private unnamed_addr constant [8 x i8] c"control\00", align 1 ; [#uses=1 type=[8 x i8]*]
@rt_info = internal global %struct.__spir_rt_info_tT.2 zeroinitializer, align 8 ; [#uses=35 type=%struct.__spir_rt_info_tT.2*]
@.str4 = private unnamed_addr constant [12 x i8] c"member_name\00", align 1 ; [#uses=1 type=[12 x i8]*]
@.str5 = private unnamed_addr constant [10 x i8] c"in_pixels\00", align 1 ; [#uses=1 type=[10 x i8]*]
@.str6 = private unnamed_addr constant [10 x i8] c"nchannels\00", align 1 ; [#uses=1 type=[10 x i8]*]
@.str7 = private unnamed_addr constant [6 x i8] c"width\00", align 1 ; [#uses=1 type=[6 x i8]*]
@.str8 = private unnamed_addr constant [7 x i8] c"height\00", align 1 ; [#uses=1 type=[7 x i8]*]
@.str9 = private unnamed_addr constant [11 x i8] c"out_pixels\00", align 1 ; [#uses=1 type=[11 x i8]*]

; [#uses=2]
declare void @llvm.dbg.declare(metadata, metadata) nounwind readnone

; [#uses=2]
declare void @llvm.memset.p0i8.i64(i8* nocapture, i8, i64, i32, i1) nounwind

; [#uses=8]
declare spir_func void @_ssdm_xcl_PointerMap(...)

; [#uses=8]
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture, i8* nocapture, i64, i32, i1) nounwind

; [#uses=2]
define linkonce_odr spir_func void @_ZN15sw_em_force_ftzC1Ev(%class.sw_em_force_ftz* %this) unnamed_addr align 2 {
  call spir_func void @_ZN15sw_em_force_ftzC2Ev(%class.sw_em_force_ftz* %this)
  ret void
}

; [#uses=2]
define linkonce_odr spir_func void @_ZN15sw_em_force_ftzD1Ev(%class.sw_em_force_ftz* %this) unnamed_addr align 2 {
  call spir_func void @_ZN15sw_em_force_ftzD2Ev(%class.sw_em_force_ftz* %this)
  ret void
}

; [#uses=1]
define linkonce_odr spir_func void @_ZN15sw_em_force_ftzD2Ev(%class.sw_em_force_ftz* %this) unnamed_addr nounwind align 2 {
  ret void
}

; [#uses=1]
define linkonce_odr spir_func void @_ZN15sw_em_force_ftzC2Ev(%class.sw_em_force_ftz* %this) unnamed_addr nounwind align 2 {
  %1 = getelementptr inbounds %class.sw_em_force_ftz* %this, i64 0, i32 0 ; [#uses=1 type=i32*]
  store i32 0, i32* %1, align 4
  ret void
}

; [#uses=2]
declare void @_ssdm_RegionBegin(...)

; [#uses=2]
declare void @_ssdm_RegionEnd(...)

; [#uses=2]
declare void @_ssdm_op_SpecPipeline(...)

; [#uses=3]
declare spir_func void @_ssdm_op_SpecInterface(...) nounwind

; [#uses=1]
declare spir_func void @_ssdm_InlineRegion(...) nounwind

; [#uses=5]
declare spir_func void @_ssdm_op_SpecExt(...) nounwind

; [#uses=0]
define spir_func void @krnl_sobel(i32 addrspace(1)* %gmem, %struct.krnl_sobel_args_t* %args) {
  %x.i19.i.i.i8.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i.i12.i.i.i14.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i8.i.i.i23.i.i = alloca %union.anon, align 4 ; [#uses=4 type=%union.anon*]
  %ux.i.i.i.i24.i.i = alloca %union.anon.1, align 8 ; [#uses=14 type=%union.anon.1*]
  %x.i.i.i.i.i.i.i31.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i1.i.i.i.i.i35.i.i = alloca %union.anon, align 4 ; [#uses=4 type=%union.anon*]
  %x.i.i2.i.i.i.i36.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i1.i.i.i.i41.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i5.i.i.i42.i.i = alloca %union.anon, align 4 ; [#uses=4 type=%union.anon*]
  %x.i.i.i.i.i.i43.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i.i.i55.i.i = alloca %union.anon.13, align 4 ; [#uses=6 type=%union.anon.13*]
  %y.i.i.i.i56.i.i = alloca %union.anon.13, align 4 ; [#uses=4 type=%union.anon.13*]
  %x.i.i1.i.i.i57.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i.i.i.i61.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %fftz.i.i.i65.i.i = alloca %class.sw_em_force_ftz, align 4 ; [#uses=4 type=%class.sw_em_force_ftz*]
  %x.i19.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i.i12.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i8.i.i.i.i.i = alloca %union.anon, align 4 ; [#uses=4 type=%union.anon*]
  %ux.i.i.i.i.i.i = alloca %union.anon.1, align 8 ; [#uses=14 type=%union.anon.1*]
  %x.i.i.i.i.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i1.i.i.i.i.i.i.i = alloca %union.anon, align 4 ; [#uses=4 type=%union.anon*]
  %x.i.i2.i.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i1.i.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i5.i.i.i.i.i = alloca %union.anon, align 4 ; [#uses=4 type=%union.anon*]
  %x.i.i.i.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i.i.i.i.i = alloca %union.anon.13, align 4 ; [#uses=6 type=%union.anon.13*]
  %y.i.i.i.i.i.i = alloca %union.anon.13, align 4 ; [#uses=4 type=%union.anon.13*]
  %x.i.i1.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %x.i.i.i.i.i.i.i = alloca %union.anon.0, align 4 ; [#uses=4 type=%union.anon.0*]
  %fftz.i.i.i.i.i = alloca %class.sw_em_force_ftz, align 4 ; [#uses=4 type=%class.sw_em_force_ftz*]
  %GX.i.i = alloca [3 x [3 x i32]], align 4       ; [#uses=15 type=[3 x [3 x i32]]*]
  %GY.i.i = alloca [3 x [3 x i32]], align 4       ; [#uses=15 type=[3 x [3 x i32]]*]
  %.cast.i = alloca %struct.__spir_rt_info_tT     ; [#uses=15 type=%struct.__spir_rt_info_tT*]
  call void @llvm.dbg.value(metadata !{i32 addrspace(1)* %gmem}, i64 0, metadata !101), !dbg !102 ; [debug line = 56:84] [debug variable = gmem]
  call void @llvm.dbg.value(metadata !{%struct.krnl_sobel_args_t* %args}, i64 0, metadata !103), !dbg !104 ; [debug line = 56:109] [debug variable = args]
  call void @llvm.dbg.value(metadata !{%struct.krnl_sobel_args_t* %args}, i64 0, metadata !105), !dbg !106 ; [debug line = 29:44@61:1] [debug variable = args]
  %1 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 0, !dbg !109 ; [#uses=1 type=i64*] [debug line = 30:5@61:1]
  call spir_func void (...)* @_ssdm_op_SpecExt(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([10 x i8]* @.str5, i32 0, i32 0), i64* %1) nounwind, !dbg !109 ; [debug line = 30:5@61:1]
  %2 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 1, !dbg !111 ; [#uses=1 type=i32*] [debug line = 31:5@61:1]
  call spir_func void (...)* @_ssdm_op_SpecExt(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([10 x i8]* @.str6, i32 0, i32 0), i32* %2) nounwind, !dbg !111 ; [debug line = 31:5@61:1]
  %3 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 2, !dbg !112 ; [#uses=1 type=i32*] [debug line = 32:5@61:1]
  call spir_func void (...)* @_ssdm_op_SpecExt(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([6 x i8]* @.str7, i32 0, i32 0), i32* %3) nounwind, !dbg !112 ; [debug line = 32:5@61:1]
  %4 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 3, !dbg !113 ; [#uses=1 type=i32*] [debug line = 33:5@61:1]
  call spir_func void (...)* @_ssdm_op_SpecExt(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([7 x i8]* @.str8, i32 0, i32 0), i32* %4) nounwind, !dbg !113 ; [debug line = 33:5@61:1]
  %5 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 4, !dbg !114 ; [#uses=1 type=i64*] [debug line = 34:5@61:1]
  call spir_func void (...)* @_ssdm_op_SpecExt(i8* getelementptr inbounds ([12 x i8]* @.str4, i32 0, i32 0), i8* getelementptr inbounds ([11 x i8]* @.str9, i32 0, i32 0), i64* %5) nounwind, !dbg !114 ; [debug line = 34:5@61:1]
  call spir_func void (...)* @_ssdm_op_SpecInterface(i32 addrspace(1)* %gmem, i8* getelementptr inbounds ([6 x i8]* @.str, i32 0, i32 0), i32 0, i32 0, i32 128, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 16, i32 16, i32 16, i32 16, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !115 ; [debug line = 62:1]
  call spir_func void (...)* @_ssdm_op_SpecInterface(i32 0, i8* getelementptr inbounds ([10 x i8]* @.str2, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([8 x i8]* @.str3, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !116 ; [debug line = 63:1]
  call spir_func void (...)* @_ssdm_op_SpecInterface(%struct.krnl_sobel_args_t* %args, i8* getelementptr inbounds ([10 x i8]* @.str2, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([8 x i8]* @.str3, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0), i32 0, i32 0, i32 0, i32 0, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !117 ; [debug line = 64:1]
  call spir_func void (...)* @_ssdm_InlineRegion(i32 1, i8* getelementptr inbounds ([1 x i8]* @.str1, i32 0, i32 0)) nounwind, !dbg !118 ; [debug line = 46:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 0), align 4, !dbg !120 ; [debug line = 54:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 1, i64 0), align 4, !dbg !121 ; [debug line = 63:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 1, i64 1), align 4, !dbg !122 ; [debug line = 64:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 1, i64 2), align 4, !dbg !123 ; [debug line = 65:3]
  store i32 1, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3, i64 0), align 4, !dbg !124 ; [debug line = 70:3]
  store i32 1, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3, i64 1), align 4, !dbg !125 ; [debug line = 79:3]
  store i32 1, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3, i64 2), align 4, !dbg !126 ; [debug line = 88:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 4, i64 0), align 4, !dbg !127 ; [debug line = 103:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 4, i64 1), align 4, !dbg !128 ; [debug line = 104:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 4, i64 2), align 4, !dbg !129 ; [debug line = 105:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 5, i64 0), align 4, !dbg !130 ; [debug line = 114:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 5, i64 1), align 4, !dbg !131 ; [debug line = 115:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 5, i64 2), align 4, !dbg !132 ; [debug line = 116:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6, i64 0), align 4, !dbg !133 ; [debug line = 125:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6, i64 1), align 4, !dbg !134 ; [debug line = 126:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6, i64 2), align 4, !dbg !135 ; [debug line = 127:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7, i64 0), align 4, !dbg !136 ; [debug line = 136:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7, i64 1), align 4, !dbg !137 ; [debug line = 137:3]
  store i32 0, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7, i64 2), align 4, !dbg !138 ; [debug line = 138:3]
  %6 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6, i64 0), align 4, !dbg !139 ; [#uses=1 type=i32] [debug line = 147:3]
  %7 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3, i64 0), align 4, !dbg !139 ; [#uses=1 type=i32] [debug line = 147:3]
  %8 = mul i32 %6, %7, !dbg !139                  ; [#uses=1 type=i32] [debug line = 147:3]
  %9 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7, i64 0), align 4, !dbg !139 ; [#uses=1 type=i32] [debug line = 147:3]
  %10 = add i32 %8, %9, !dbg !139                 ; [#uses=1 type=i32] [debug line = 147:3]
  store i32 %10, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 2, i64 0), align 4, !dbg !139 ; [debug line = 147:3]
  %11 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6, i64 1), align 4, !dbg !140 ; [#uses=1 type=i32] [debug line = 148:3]
  %12 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3, i64 1), align 4, !dbg !140 ; [#uses=1 type=i32] [debug line = 148:3]
  %13 = mul i32 %11, %12, !dbg !140               ; [#uses=1 type=i32] [debug line = 148:3]
  %14 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7, i64 1), align 4, !dbg !140 ; [#uses=1 type=i32] [debug line = 148:3]
  %15 = add i32 %13, %14, !dbg !140               ; [#uses=1 type=i32] [debug line = 148:3]
  store i32 %15, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 2, i64 1), align 4, !dbg !140 ; [debug line = 148:3]
  %16 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6, i64 2), align 4, !dbg !141 ; [#uses=1 type=i32] [debug line = 149:3]
  %17 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3, i64 2), align 4, !dbg !141 ; [#uses=1 type=i32] [debug line = 149:3]
  %18 = mul i32 %16, %17, !dbg !141               ; [#uses=1 type=i32] [debug line = 149:3]
  %19 = load i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7, i64 2), align 4, !dbg !141 ; [#uses=1 type=i32] [debug line = 149:3]
  %20 = add i32 %18, %19, !dbg !141               ; [#uses=1 type=i32] [debug line = 149:3]
  store i32 %20, i32* getelementptr inbounds (%struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 2, i64 2), align 4, !dbg !141 ; [debug line = 149:3]
  %21 = bitcast %struct.__spir_rt_info_tT* %.cast.i to i8* ; [#uses=0 type=i8*]
  call void @llvm.dbg.value(metadata !{i32 addrspace(1)* %gmem}, i64 0, metadata !142), !dbg !143 ; [debug line = 44:90] [debug variable = gmem]
  call void @llvm.dbg.value(metadata !144, i64 0, metadata !145), !dbg !146 ; [debug line = 44:114] [debug variable = rt_info]
  call void @llvm.dbg.value(metadata !{%struct.krnl_sobel_args_t* %args}, i64 0, metadata !147), !dbg !148 ; [debug line = 44:142] [debug variable = args]
  %22 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 0, !dbg !149 ; [#uses=1 type=i64*] [debug line = 46:126]
  %23 = load i64* %22, align 8, !dbg !149         ; [#uses=1 type=i64] [debug line = 46:126]
  %24 = lshr i64 %23, 2, !dbg !149                ; [#uses=1 type=i64] [debug line = 46:126]
  %arg_in_pixels.i.0 = getelementptr inbounds i32 addrspace(1)* %gmem, i64 %24, !dbg !149 ; [#uses=14 type=i32 addrspace(1)*] [debug line = 46:126]
  call void @llvm.dbg.value(metadata !{i32 addrspace(1)* %arg_in_pixels.i.0}, i64 0, metadata !151), !dbg !149 ; [debug line = 46:126] [debug variable = arg_in_pixels]
  %25 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 1, !dbg !152 ; [#uses=1 type=i32*] [debug line = 47:47]
  %arg_nchannels.i.0 = load i32* %25, align 4, !dbg !152 ; [#uses=1 type=i32] [debug line = 47:47]
  call void @llvm.dbg.value(metadata !{i32 %arg_nchannels.i.0}, i64 0, metadata !153), !dbg !152 ; [debug line = 47:47] [debug variable = arg_nchannels]
  %26 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 2, !dbg !154 ; [#uses=1 type=i32*] [debug line = 48:39]
  %arg_width.i.0 = load i32* %26, align 4, !dbg !154 ; [#uses=3 type=i32] [debug line = 48:39]
  call void @llvm.dbg.value(metadata !{i32 %arg_width.i.0}, i64 0, metadata !155), !dbg !154 ; [debug line = 48:39] [debug variable = arg_width]
  %27 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 3, !dbg !156 ; [#uses=1 type=i32*] [debug line = 49:41]
  %arg_height.i.0 = load i32* %27, align 4, !dbg !156 ; [#uses=3 type=i32] [debug line = 49:41]
  call void @llvm.dbg.value(metadata !{i32 %arg_height.i.0}, i64 0, metadata !157), !dbg !156 ; [debug line = 49:41] [debug variable = arg_height]
  %28 = getelementptr inbounds %struct.krnl_sobel_args_t* %args, i32 0, i32 4, !dbg !158 ; [#uses=1 type=i64*] [debug line = 50:128]
  %29 = load i64* %28, align 8, !dbg !158         ; [#uses=1 type=i64] [debug line = 50:128]
  %30 = lshr i64 %29, 2, !dbg !158                ; [#uses=1 type=i64] [debug line = 50:128]
  %arg_out_pixels.i.0 = getelementptr inbounds i32 addrspace(1)* %gmem, i64 %30, !dbg !158 ; [#uses=4 type=i32 addrspace(1)*] [debug line = 50:128]
  call void @llvm.dbg.value(metadata !{i32 addrspace(1)* %arg_out_pixels.i.0}, i64 0, metadata !159), !dbg !158 ; [debug line = 50:128] [debug variable = arg_out_pixels]
  %31 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 0 ; [#uses=1 type=i32*]
  %32 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 0 ; [#uses=1 type=i32*]
  %33 = load i32* %31                             ; [#uses=1 type=i32]
  %34 = bitcast i32 %33 to i32                    ; [#uses=1 type=i32]
  store volatile i32 %34, i32* %32
  %35 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 1 ; [#uses=3 type=[3 x i32]*]
  %36 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 1 ; [#uses=3 type=[3 x i32]*]
  %37 = getelementptr [3 x i32]* %35, i32 0, i32 0 ; [#uses=1 type=i32*]
  %38 = getelementptr [3 x i32]* %36, i32 0, i32 0 ; [#uses=1 type=i32*]
  %39 = load i32* %37                             ; [#uses=1 type=i32]
  store volatile i32 %39, i32* %38
  %40 = getelementptr [3 x i32]* %35, i32 0, i32 1 ; [#uses=1 type=i32*]
  %41 = getelementptr [3 x i32]* %36, i32 0, i32 1 ; [#uses=1 type=i32*]
  %42 = load i32* %40                             ; [#uses=1 type=i32]
  store volatile i32 %42, i32* %41
  %43 = getelementptr [3 x i32]* %35, i32 0, i32 2 ; [#uses=1 type=i32*]
  %44 = getelementptr [3 x i32]* %36, i32 0, i32 2 ; [#uses=1 type=i32*]
  %45 = load i32* %43                             ; [#uses=1 type=i32]
  store volatile i32 %45, i32* %44
  %46 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 2 ; [#uses=3 type=[3 x i32]*]
  %47 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 2 ; [#uses=3 type=[3 x i32]*]
  %48 = getelementptr [3 x i32]* %46, i32 0, i32 0 ; [#uses=1 type=i32*]
  %49 = getelementptr [3 x i32]* %47, i32 0, i32 0 ; [#uses=1 type=i32*]
  %50 = load i32* %48                             ; [#uses=1 type=i32]
  store volatile i32 %50, i32* %49
  %51 = getelementptr [3 x i32]* %46, i32 0, i32 1 ; [#uses=1 type=i32*]
  %52 = getelementptr [3 x i32]* %47, i32 0, i32 1 ; [#uses=1 type=i32*]
  %53 = load i32* %51                             ; [#uses=1 type=i32]
  store volatile i32 %53, i32* %52
  %54 = getelementptr [3 x i32]* %46, i32 0, i32 2 ; [#uses=1 type=i32*]
  %55 = getelementptr [3 x i32]* %47, i32 0, i32 2 ; [#uses=1 type=i32*]
  %56 = load i32* %54                             ; [#uses=1 type=i32]
  store volatile i32 %56, i32* %55
  %57 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 3 ; [#uses=3 type=[3 x i32]*]
  %58 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 3 ; [#uses=3 type=[3 x i32]*]
  %59 = getelementptr [3 x i32]* %57, i32 0, i32 0 ; [#uses=1 type=i32*]
  %60 = getelementptr [3 x i32]* %58, i32 0, i32 0 ; [#uses=1 type=i32*]
  %61 = load i32* %59                             ; [#uses=1 type=i32]
  store volatile i32 %61, i32* %60
  %62 = getelementptr [3 x i32]* %57, i32 0, i32 1 ; [#uses=1 type=i32*]
  %63 = getelementptr [3 x i32]* %58, i32 0, i32 1 ; [#uses=1 type=i32*]
  %64 = load i32* %62                             ; [#uses=1 type=i32]
  store volatile i32 %64, i32* %63
  %65 = getelementptr [3 x i32]* %57, i32 0, i32 2 ; [#uses=1 type=i32*]
  %66 = getelementptr [3 x i32]* %58, i32 0, i32 2 ; [#uses=1 type=i32*]
  %67 = load i32* %65                             ; [#uses=1 type=i32]
  store volatile i32 %67, i32* %66
  %68 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 4 ; [#uses=3 type=[3 x i32]*]
  %69 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 4 ; [#uses=3 type=[3 x i32]*]
  %70 = getelementptr [3 x i32]* %68, i32 0, i32 0 ; [#uses=1 type=i32*]
  %71 = getelementptr [3 x i32]* %69, i32 0, i32 0 ; [#uses=1 type=i32*]
  %72 = load i32* %70                             ; [#uses=1 type=i32]
  store volatile i32 %72, i32* %71
  %73 = getelementptr [3 x i32]* %68, i32 0, i32 1 ; [#uses=1 type=i32*]
  %74 = getelementptr [3 x i32]* %69, i32 0, i32 1 ; [#uses=1 type=i32*]
  %75 = load i32* %73                             ; [#uses=1 type=i32]
  store volatile i32 %75, i32* %74
  %76 = getelementptr [3 x i32]* %68, i32 0, i32 2 ; [#uses=1 type=i32*]
  %77 = getelementptr [3 x i32]* %69, i32 0, i32 2 ; [#uses=1 type=i32*]
  %78 = load i32* %76                             ; [#uses=1 type=i32]
  store volatile i32 %78, i32* %77
  %79 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 5 ; [#uses=3 type=[3 x i32]*]
  %80 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 5 ; [#uses=3 type=[3 x i32]*]
  %81 = getelementptr [3 x i32]* %79, i32 0, i32 0 ; [#uses=1 type=i32*]
  %82 = getelementptr [3 x i32]* %80, i32 0, i32 0 ; [#uses=1 type=i32*]
  %83 = load i32* %81                             ; [#uses=1 type=i32]
  store volatile i32 %83, i32* %82
  %84 = getelementptr [3 x i32]* %79, i32 0, i32 1 ; [#uses=1 type=i32*]
  %85 = getelementptr [3 x i32]* %80, i32 0, i32 1 ; [#uses=1 type=i32*]
  %86 = load i32* %84                             ; [#uses=1 type=i32]
  store volatile i32 %86, i32* %85
  %87 = getelementptr [3 x i32]* %79, i32 0, i32 2 ; [#uses=1 type=i32*]
  %88 = getelementptr [3 x i32]* %80, i32 0, i32 2 ; [#uses=1 type=i32*]
  %89 = load i32* %87                             ; [#uses=1 type=i32]
  store volatile i32 %89, i32* %88
  %90 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 6 ; [#uses=3 type=[3 x i32]*]
  %91 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 6 ; [#uses=3 type=[3 x i32]*]
  %92 = getelementptr [3 x i32]* %90, i32 0, i32 0 ; [#uses=1 type=i32*]
  %93 = getelementptr [3 x i32]* %91, i32 0, i32 0 ; [#uses=1 type=i32*]
  %94 = load i32* %92                             ; [#uses=1 type=i32]
  store volatile i32 %94, i32* %93
  %95 = getelementptr [3 x i32]* %90, i32 0, i32 1 ; [#uses=1 type=i32*]
  %96 = getelementptr [3 x i32]* %91, i32 0, i32 1 ; [#uses=1 type=i32*]
  %97 = load i32* %95                             ; [#uses=1 type=i32]
  store volatile i32 %97, i32* %96
  %98 = getelementptr [3 x i32]* %90, i32 0, i32 2 ; [#uses=1 type=i32*]
  %99 = getelementptr [3 x i32]* %91, i32 0, i32 2 ; [#uses=1 type=i32*]
  %100 = load i32* %98                            ; [#uses=1 type=i32]
  store volatile i32 %100, i32* %99
  %101 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 7 ; [#uses=3 type=[3 x i32]*]
  %102 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 7 ; [#uses=3 type=[3 x i32]*]
  %103 = getelementptr [3 x i32]* %101, i32 0, i32 0 ; [#uses=1 type=i32*]
  %104 = getelementptr [3 x i32]* %102, i32 0, i32 0 ; [#uses=1 type=i32*]
  %105 = load i32* %103                           ; [#uses=1 type=i32]
  store volatile i32 %105, i32* %104
  %106 = getelementptr [3 x i32]* %101, i32 0, i32 1 ; [#uses=1 type=i32*]
  %107 = getelementptr [3 x i32]* %102, i32 0, i32 1 ; [#uses=1 type=i32*]
  %108 = load i32* %106                           ; [#uses=1 type=i32]
  store volatile i32 %108, i32* %107
  %109 = getelementptr [3 x i32]* %101, i32 0, i32 2 ; [#uses=1 type=i32*]
  %110 = getelementptr [3 x i32]* %102, i32 0, i32 2 ; [#uses=1 type=i32*]
  %111 = load i32* %109                           ; [#uses=1 type=i32]
  store volatile i32 %111, i32* %110
  %112 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 8 ; [#uses=1 type=i8**]
  %113 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 8 ; [#uses=1 type=i8**]
  %114 = load i8** %112                           ; [#uses=1 type=i8*]
  %115 = bitcast i8* %114 to i8*                  ; [#uses=1 type=i8*]
  store volatile i8* %115, i8** %113
  %116 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 9 ; [#uses=1 type=i1*]
  %117 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 9 ; [#uses=1 type=i8*]
  %118 = load i1* %116                            ; [#uses=1 type=i1]
  %119 = zext i1 %118 to i8                       ; [#uses=1 type=i8]
  store volatile i8 %119, i8* %117
  %120 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 10 ; [#uses=1 type=i8**]
  %121 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 10 ; [#uses=1 type=i8**]
  %122 = load i8** %120                           ; [#uses=1 type=i8*]
  %123 = bitcast i8* %122 to i8*                  ; [#uses=1 type=i8*]
  store volatile i8* %123, i8** %121
  %124 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 11 ; [#uses=1 type=i8**]
  %125 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 11 ; [#uses=1 type=i8**]
  %126 = load i8** %124                           ; [#uses=1 type=i8*]
  %127 = bitcast i8* %126 to i8*                  ; [#uses=1 type=i8*]
  store volatile i8* %127, i8** %125
  %128 = getelementptr %struct.__spir_rt_info_tT.2* @rt_info, i32 0, i32 12 ; [#uses=1 type=i64*]
  %129 = getelementptr %struct.__spir_rt_info_tT* %.cast.i, i32 0, i32 12 ; [#uses=1 type=i64*]
  %130 = load i64* %128                           ; [#uses=1 type=i64]
  %131 = bitcast i64 %130 to i64                  ; [#uses=1 type=i64]
  store volatile i64 %131, i64* %129
  %132 = bitcast %union.anon.0* %x.i19.i.i.i8.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %133 = bitcast %union.anon.0* %x.i.i.i12.i.i.i14.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %134 = bitcast %union.anon* %x.i.i8.i.i.i23.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %135 = bitcast %union.anon.1* %ux.i.i.i.i24.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %136 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i31.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %137 = bitcast %union.anon* %x.i1.i.i.i.i.i35.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %138 = bitcast %union.anon.0* %x.i.i2.i.i.i.i36.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %139 = bitcast %union.anon.0* %x.i1.i.i.i.i41.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %140 = bitcast %union.anon* %x.i.i5.i.i.i42.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %141 = bitcast %union.anon.0* %x.i.i.i.i.i.i43.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %142 = bitcast %union.anon.13* %x.i.i.i.i55.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %143 = bitcast %union.anon.13* %y.i.i.i.i56.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %144 = bitcast %union.anon.0* %x.i.i1.i.i.i57.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %145 = bitcast %union.anon.0* %x.i.i.i.i.i61.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %146 = bitcast %class.sw_em_force_ftz* %fftz.i.i.i65.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %147 = bitcast %union.anon.0* %x.i19.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %148 = bitcast %union.anon.0* %x.i.i.i12.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %149 = bitcast %union.anon* %x.i.i8.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %150 = bitcast %union.anon.1* %ux.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %151 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %152 = bitcast %union.anon* %x.i1.i.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %153 = bitcast %union.anon.0* %x.i.i2.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %154 = bitcast %union.anon.0* %x.i1.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %155 = bitcast %union.anon* %x.i.i5.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %156 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %157 = bitcast %union.anon.13* %x.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %158 = bitcast %union.anon.13* %y.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %159 = bitcast %union.anon.0* %x.i.i1.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %160 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %161 = bitcast %class.sw_em_force_ftz* %fftz.i.i.i.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %162 = bitcast [3 x [3 x i32]]* %GX.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  %163 = bitcast [3 x [3 x i32]]* %GY.i.i to i8*, !dbg !160 ; [#uses=0 type=i8*] [debug line = 69:56]
  call spir_func void @llvm.dbg.declare(metadata !{[3 x [3 x i32]]* %GX.i.i}, metadata !161) nounwind, !dbg !165 ; [debug line = 82:6] [debug variable = GX]
  %164 = bitcast [3 x [3 x i32]]* %GX.i.i to i8*, !dbg !166 ; [#uses=1 type=i8*] [debug line = 86:3]
  call spir_func void @llvm.memset.p0i8.i64(i8* %164, i8 0, i64 36, i32 4, i1 false) nounwind, !dbg !166 ; [debug line = 86:3]
  %165 = getelementptr [3 x [3 x i32]]* %GX.i.i, i64 0, i64 0, i64 0, !dbg !166 ; [#uses=1 type=i32*] [debug line = 86:3]
  store i32 -1, i32* %165, align 4, !dbg !166     ; [debug line = 86:3]
  %166 = getelementptr [3 x [3 x i32]]* %GX.i.i, i64 0, i64 0, i64 2, !dbg !166 ; [#uses=1 type=i32*] [debug line = 86:3]
  store i32 1, i32* %166, align 4, !dbg !166      ; [debug line = 86:3]
  %167 = getelementptr [3 x [3 x i32]]* %GX.i.i, i64 0, i64 1, i64 0, !dbg !166 ; [#uses=1 type=i32*] [debug line = 86:3]
  store i32 -2, i32* %167, align 4, !dbg !166     ; [debug line = 86:3]
  %168 = getelementptr [3 x [3 x i32]]* %GX.i.i, i64 0, i64 1, i64 2, !dbg !166 ; [#uses=1 type=i32*] [debug line = 86:3]
  store i32 2, i32* %168, align 4, !dbg !166      ; [debug line = 86:3]
  %169 = getelementptr [3 x [3 x i32]]* %GX.i.i, i64 0, i64 2, i64 0, !dbg !166 ; [#uses=1 type=i32*] [debug line = 86:3]
  store i32 -1, i32* %169, align 4, !dbg !166     ; [debug line = 86:3]
  %170 = getelementptr [3 x [3 x i32]]* %GX.i.i, i64 0, i64 2, i64 2, !dbg !166 ; [#uses=1 type=i32*] [debug line = 86:3]
  store i32 1, i32* %170, align 4, !dbg !166      ; [debug line = 86:3]
  call spir_func void @llvm.dbg.declare(metadata !{[3 x [3 x i32]]* %GY.i.i}, metadata !167) nounwind, !dbg !168 ; [debug line = 88:6] [debug variable = GY]
  %171 = bitcast [3 x [3 x i32]]* %GY.i.i to i8*, !dbg !169 ; [#uses=1 type=i8*] [debug line = 92:3]
  call spir_func void @llvm.memset.p0i8.i64(i8* %171, i8 0, i64 36, i32 4, i1 false) nounwind, !dbg !169 ; [debug line = 92:3]
  %172 = getelementptr [3 x [3 x i32]]* %GY.i.i, i64 0, i64 0, i64 0, !dbg !169 ; [#uses=1 type=i32*] [debug line = 92:3]
  store i32 1, i32* %172, align 4, !dbg !169      ; [debug line = 92:3]
  %173 = getelementptr [3 x [3 x i32]]* %GY.i.i, i64 0, i64 0, i64 1, !dbg !169 ; [#uses=1 type=i32*] [debug line = 92:3]
  store i32 2, i32* %173, align 4, !dbg !169      ; [debug line = 92:3]
  %174 = getelementptr [3 x [3 x i32]]* %GY.i.i, i64 0, i64 0, i64 2, !dbg !169 ; [#uses=1 type=i32*] [debug line = 92:3]
  store i32 1, i32* %174, align 4, !dbg !169      ; [debug line = 92:3]
  %175 = getelementptr [3 x [3 x i32]]* %GY.i.i, i64 0, i64 2, i64 0, !dbg !169 ; [#uses=1 type=i32*] [debug line = 92:3]
  store i32 -1, i32* %175, align 4, !dbg !169     ; [debug line = 92:3]
  %176 = getelementptr [3 x [3 x i32]]* %GY.i.i, i64 0, i64 2, i64 1, !dbg !169 ; [#uses=1 type=i32*] [debug line = 92:3]
  store i32 -2, i32* %176, align 4, !dbg !169     ; [debug line = 92:3]
  %177 = getelementptr [3 x [3 x i32]]* %GY.i.i, i64 0, i64 2, i64 2, !dbg !169 ; [#uses=1 type=i32*] [debug line = 92:3]
  store i32 -1, i32* %177, align 4, !dbg !169     ; [debug line = 92:3]
  br label %178, !dbg !170                        ; [debug line = 105:16]

; <label>:178                                     ; preds = %180, %0
  %i.0.reg2mem739.0.i.i = phi i32 [ 0, %0 ], [ %.reg2mem567.0.i.i, %180 ] ; [#uses=3 type=i32]
  %179 = icmp slt i32 %i.0.reg2mem739.0.i.i, 4096, !dbg !170 ; [#uses=1 type=i1] [debug line = 105:16]
  br i1 %179, label %180, label %183, !dbg !170   ; [debug line = 105:16]

; <label>:180                                     ; preds = %178
  %181 = sext i32 %i.0.reg2mem739.0.i.i to i64, !dbg !172 ; [#uses=1 type=i64] [debug line = 106:9]
  %182 = getelementptr inbounds [4096 x i8] addrspace(3)* @krnl_sobel.resbuf, i64 0, i64 %181, !dbg !172 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 106:9]
  store i8 -1, i8 addrspace(3)* %182, align 1, !dbg !172 ; [debug line = 106:9]
  %.reg2mem567.0.i.i = add nsw i32 %i.0.reg2mem739.0.i.i, 1, !dbg !173 ; [#uses=1 type=i32] [debug line = 105:28]
  br label %178, !dbg !173                        ; [debug line = 105:28]

; <label>:183                                     ; preds = %178
  %szrow.0.reg2mem.0.i.i = mul nsw i32 %arg_width.i.0, %arg_nchannels.i.0, !dbg !174 ; [#uses=14 type=i32] [debug line = 108:34]
  br label %.rentry.i.i, !dbg !175                ; [debug line = 111:13]

.rentry.i.i:                                      ; preds = %_Z21async_work_grou.rexit.i.i, %183
  %y.0.reg2mem737.0.i.i = phi i32 [ 0, %183 ], [ %.reg2mem546.0.i.i, %_Z21async_work_grou.rexit.i.i ] ; [#uses=3 type=i32]
  %184 = icmp slt i32 %y.0.reg2mem737.0.i.i, %arg_height.i.0, !dbg !175 ; [#uses=1 type=i1] [debug line = 111:13]
  br i1 %184, label %_Z21async_work_grou.rexit.i.i, label %_Z21async_work_grou.i.i, !dbg !175 ; [debug line = 111:13]

_Z21async_work_grou.rexit.i.i:                    ; preds = %.rentry.i.i
  %185 = mul nsw i32 %y.0.reg2mem737.0.i.i, %szrow.0.reg2mem.0.i.i, !dbg !177 ; [#uses=1 type=i32] [debug line = 112:9]
  %.reg2mem549.0.i.i = sext i32 %185 to i64, !dbg !177 ; [#uses=2 type=i64] [debug line = 112:9]
  %bus_addr314.i.i = lshr i64 %.reg2mem549.0.i.i, 2 ; [#uses=1 type=i64]
  %.0167.reg2mem.0.i.i = getelementptr i32 addrspace(1)* %arg_out_pixels.i.0, i64 %bus_addr314.i.i ; [#uses=2 type=i32 addrspace(1)*]
  %.0165.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !177 ; [#uses=1 type=i64] [debug line = 112:9]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %.0167.reg2mem.0.i.i, i32 addrspace(1)* %arg_out_pixels.i.0, i64 %.reg2mem549.0.i.i, i64 1) nounwind
  %CI326.i.i = bitcast i32 addrspace(1)* %.0167.reg2mem.0.i.i to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* %CI326.i.i, i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.resbuf to i8*), i64 %.0165.reg2mem.0.i.i, i32 1, i1 false) nounwind
  %.reg2mem546.0.i.i = add nsw i32 %y.0.reg2mem737.0.i.i, 1, !dbg !179 ; [#uses=1 type=i32] [debug line = 111:27]
  br label %.rentry.i.i, !dbg !179                ; [debug line = 111:27]

_Z21async_work_grou.i.i:                          ; preds = %.rentry.i.i
  %.0168.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !180 ; [#uses=1 type=i64] [debug line = 118:5]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %arg_in_pixels.i.0, i32 addrspace(1)* %arg_in_pixels.i.0, i32 0, i64 1) nounwind
  %CI.i.i = bitcast i32 addrspace(1)* %arg_in_pixels.i.0 to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf0 to i8*), i8* %CI.i.i, i64 %.0168.reg2mem.0.i.i, i32 1, i1 false) nounwind
  %.reg2mem543.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !181 ; [#uses=2 type=i64] [debug line = 119:5]
  %bus_addr.i.i = lshr i64 %.reg2mem543.0.i.i, 2  ; [#uses=1 type=i64]
  %.0161.reg2mem.0.i.i = getelementptr i32 addrspace(1)* %arg_in_pixels.i.0, i64 %bus_addr.i.i ; [#uses=2 type=i32 addrspace(1)*]
  %.0162.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !181 ; [#uses=1 type=i64] [debug line = 119:5]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %.0161.reg2mem.0.i.i, i32 addrspace(1)* %arg_in_pixels.i.0, i64 %.reg2mem543.0.i.i, i64 1) nounwind
  %CI216.i.i = bitcast i32 addrspace(1)* %.0161.reg2mem.0.i.i to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf1 to i8*), i8* %CI216.i.i, i64 %.0162.reg2mem.0.i.i, i32 1, i1 false) nounwind
  br label %.rentry743.i.i, !dbg !182             ; [debug line = 124:13]

.rentry743.i.i:                                   ; preds = %446, %_Z21async_work_grou.i.i
  %prow0.0.reg2mem735.0.i.i = phi i8 addrspace(3)* [ getelementptr inbounds ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf0, i64 0, i64 0), %_Z21async_work_grou.i.i ], [ %prow1.0.reg2mem733.0.i.i, %446 ] ; [#uses=2 type=i8 addrspace(3)*]
  %prow1.0.reg2mem733.0.i.i = phi i8 addrspace(3)* [ getelementptr inbounds ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf1, i64 0, i64 0), %_Z21async_work_grou.i.i ], [ getelementptr inbounds ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2, i64 0, i64 0), %446 ] ; [#uses=3 type=i8 addrspace(3)*]
  %ming.0.reg2mem731.0.i.i = phi float [ 0x47EFFFFFE0000000, %_Z21async_work_grou.i.i ], [ %ming.1.reg2mem725.0.i.i, %446 ] ; [#uses=3 type=float]
  %maxg.0.reg2mem729.0.i.i = phi float [ 0x3810000000000000, %_Z21async_work_grou.i.i ], [ %maxg.1.reg2mem723.0.i.i, %446 ] ; [#uses=2 type=float]
  %y1.0.reg2mem727.0.i.i = phi i32 [ 1, %_Z21async_work_grou.i.i ], [ %.reg2mem356.0.i.i, %446 ] ; [#uses=3 type=i32]
  %186 = add nsw i32 %arg_height.i.0, -1, !dbg !182 ; [#uses=1 type=i32] [debug line = 124:13]
  %187 = icmp slt i32 %y1.0.reg2mem727.0.i.i, %186, !dbg !182 ; [#uses=1 type=i1] [debug line = 124:13]
  br i1 %187, label %_Z21async_work_grou745.rexit.i.i, label %_Z21async_work_grou746.i.i, !dbg !182 ; [debug line = 124:13]

_Z21async_work_grou745.rexit.i.i:                 ; preds = %.rentry743.i.i
  %188 = add nsw i32 %y1.0.reg2mem727.0.i.i, 1, !dbg !184 ; [#uses=1 type=i32] [debug line = 127:9]
  %189 = mul nsw i32 %188, %szrow.0.reg2mem.0.i.i, !dbg !184 ; [#uses=1 type=i32] [debug line = 127:9]
  %.reg2mem531.0.i.i = sext i32 %189 to i64, !dbg !184 ; [#uses=2 type=i64] [debug line = 127:9]
  %bus_addr295.i.i = lshr i64 %.reg2mem531.0.i.i, 2 ; [#uses=1 type=i64]
  %.0158.reg2mem.0.i.i = getelementptr i32 addrspace(1)* %arg_in_pixels.i.0, i64 %bus_addr295.i.i ; [#uses=2 type=i32 addrspace(1)*]
  %.0159.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !184 ; [#uses=1 type=i64] [debug line = 127:9]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %.0158.reg2mem.0.i.i, i32 addrspace(1)* %arg_in_pixels.i.0, i64 %.reg2mem531.0.i.i, i64 1) nounwind
  %CI307.i.i = bitcast i32 addrspace(1)* %.0158.reg2mem.0.i.i to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2 to i8*), i8* %CI307.i.i, i64 %.0159.reg2mem.0.i.i, i32 1, i1 false) nounwind
  br label %190, !dbg !186                        ; [debug line = 134:14]

; <label>:190                                     ; preds = %_Z4sqrtf.exit.i.i, %_Z21async_work_grou745.rexit.i.i
  %ming.1.reg2mem725.0.i.i = phi float [ %ming.0.reg2mem731.0.i.i, %_Z21async_work_grou745.rexit.i.i ], [ %ming.2.reg2mem647.0.i.i, %_Z4sqrtf.exit.i.i ] ; [#uses=3 type=float]
  %maxg.1.reg2mem723.0.i.i = phi float [ %maxg.0.reg2mem729.0.i.i, %_Z21async_work_grou745.rexit.i.i ], [ %maxg.2.reg2mem649.0.i.i, %_Z4sqrtf.exit.i.i ] ; [#uses=3 type=float]
  %x.0.reg2mem721.0.i.i = phi i32 [ 1, %_Z21async_work_grou745.rexit.i.i ], [ %.reg2mem358.0.i.i, %_Z4sqrtf.exit.i.i ] ; [#uses=8 type=i32]
  %191 = add nsw i32 %arg_width.i.0, -1, !dbg !186 ; [#uses=1 type=i32] [debug line = 134:14]
  %192 = icmp slt i32 %x.0.reg2mem721.0.i.i, %191, !dbg !186 ; [#uses=1 type=i1] [debug line = 134:14]
  br i1 %192, label %193, label %446, !dbg !186   ; [debug line = 134:14]

; <label>:193                                     ; preds = %190
  call spir_func void (...)* @_ssdm_RegionBegin(i8* getelementptr inbounds ([13 x i8]* @hls_region, i64 0, i64 0)) nounwind
  call spir_func void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, i8* getelementptr inbounds ([13 x i8]* @hls_region, i64 0, i64 0)) nounwind
  br label %194, !dbg !188                        ; [debug line = 141:16]

; <label>:194                                     ; preds = %196, %193
  %sumx.0.reg2mem719.0.i.i = phi i16 [ 0, %193 ], [ %.reg2mem500.0.i.i, %196 ] ; [#uses=3 type=i16]
  %sumy.0.reg2mem717.0.i.i = phi i16 [ 0, %193 ], [ %.reg2mem498.0.i.i, %196 ] ; [#uses=3 type=i16]
  %i2.0.reg2mem715.0.i.i = phi i32 [ -1, %193 ], [ %.reg2mem496.0.i.i, %196 ] ; [#uses=14 type=i32]
  %195 = icmp slt i32 %i2.0.reg2mem715.0.i.i, 2, !dbg !188 ; [#uses=1 type=i1] [debug line = 141:16]
  br i1 %195, label %196, label %._crit_edge.i.i, !dbg !188 ; [debug line = 141:16]

; <label>:196                                     ; preds = %194
  %197 = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !191 ; [#uses=1 type=i32] [debug line = 142:17]
  %198 = sext i32 %197 to i64, !dbg !191          ; [#uses=1 type=i64] [debug line = 142:17]
  %199 = getelementptr inbounds [3 x [3 x i32]]* %GX.i.i, i64 0, i64 %198, i64 0, !dbg !191 ; [#uses=1 type=i32*] [debug line = 142:17]
  %200 = load i32* %199, align 4, !dbg !191       ; [#uses=1 type=i32] [debug line = 142:17]
  %201 = add nsw i32 %x.0.reg2mem721.0.i.i, %i2.0.reg2mem715.0.i.i, !dbg !191 ; [#uses=1 type=i32] [debug line = 142:17]
  %202 = sext i32 %201 to i64, !dbg !191          ; [#uses=1 type=i64] [debug line = 142:17]
  %203 = getelementptr inbounds i8 addrspace(3)* %prow0.0.reg2mem735.0.i.i, i64 %202, !dbg !191 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 142:17]
  %204 = load i8 addrspace(3)* %203, align 1, !dbg !191 ; [#uses=1 type=i8] [debug line = 142:17]
  %205 = trunc i32 %200 to i16, !dbg !191         ; [#uses=1 type=i16] [debug line = 142:17]
  %206 = zext i8 %204 to i16, !dbg !191           ; [#uses=1 type=i16] [debug line = 142:17]
  %207 = mul i16 %205, %206, !dbg !191            ; [#uses=1 type=i16] [debug line = 142:17]
  %208 = add i16 %sumx.0.reg2mem719.0.i.i, %207, !dbg !191 ; [#uses=1 type=i16] [debug line = 142:17]
  %209 = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !193 ; [#uses=1 type=i32] [debug line = 143:17]
  %210 = sext i32 %209 to i64, !dbg !193          ; [#uses=1 type=i64] [debug line = 143:17]
  %211 = getelementptr inbounds [3 x [3 x i32]]* %GX.i.i, i64 0, i64 %210, i64 1, !dbg !193 ; [#uses=1 type=i32*] [debug line = 143:17]
  %212 = load i32* %211, align 4, !dbg !193       ; [#uses=1 type=i32] [debug line = 143:17]
  %213 = add nsw i32 %x.0.reg2mem721.0.i.i, %i2.0.reg2mem715.0.i.i, !dbg !193 ; [#uses=1 type=i32] [debug line = 143:17]
  %214 = sext i32 %213 to i64, !dbg !193          ; [#uses=1 type=i64] [debug line = 143:17]
  %215 = getelementptr inbounds i8 addrspace(3)* %prow1.0.reg2mem733.0.i.i, i64 %214, !dbg !193 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 143:17]
  %216 = load i8 addrspace(3)* %215, align 1, !dbg !193 ; [#uses=1 type=i8] [debug line = 143:17]
  %217 = trunc i32 %212 to i16, !dbg !193         ; [#uses=1 type=i16] [debug line = 143:17]
  %218 = zext i8 %216 to i16, !dbg !193           ; [#uses=1 type=i16] [debug line = 143:17]
  %219 = mul i16 %217, %218, !dbg !193            ; [#uses=1 type=i16] [debug line = 143:17]
  %220 = add i16 %208, %219, !dbg !193            ; [#uses=1 type=i16] [debug line = 143:17]
  %221 = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !194 ; [#uses=1 type=i32] [debug line = 144:17]
  %222 = sext i32 %221 to i64, !dbg !194          ; [#uses=1 type=i64] [debug line = 144:17]
  %223 = getelementptr inbounds [3 x [3 x i32]]* %GX.i.i, i64 0, i64 %222, i64 2, !dbg !194 ; [#uses=1 type=i32*] [debug line = 144:17]
  %224 = load i32* %223, align 4, !dbg !194       ; [#uses=1 type=i32] [debug line = 144:17]
  %225 = add nsw i32 %x.0.reg2mem721.0.i.i, %i2.0.reg2mem715.0.i.i, !dbg !194 ; [#uses=1 type=i32] [debug line = 144:17]
  %226 = sext i32 %225 to i64, !dbg !194          ; [#uses=1 type=i64] [debug line = 144:17]
  %227 = getelementptr inbounds [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2, i64 0, i64 %226, !dbg !194 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 144:17]
  %228 = load i8 addrspace(3)* %227, align 1, !dbg !194 ; [#uses=1 type=i8] [debug line = 144:17]
  %229 = trunc i32 %224 to i16, !dbg !194         ; [#uses=1 type=i16] [debug line = 144:17]
  %230 = zext i8 %228 to i16, !dbg !194           ; [#uses=1 type=i16] [debug line = 144:17]
  %231 = mul i16 %229, %230, !dbg !194            ; [#uses=1 type=i16] [debug line = 144:17]
  %.reg2mem500.0.i.i = add i16 %220, %231, !dbg !194 ; [#uses=1 type=i16] [debug line = 144:17]
  %232 = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !195 ; [#uses=1 type=i32] [debug line = 146:17]
  %233 = sext i32 %232 to i64, !dbg !195          ; [#uses=1 type=i64] [debug line = 146:17]
  %234 = getelementptr inbounds [3 x [3 x i32]]* %GY.i.i, i64 0, i64 %233, i64 0, !dbg !195 ; [#uses=1 type=i32*] [debug line = 146:17]
  %235 = load i32* %234, align 4, !dbg !195       ; [#uses=1 type=i32] [debug line = 146:17]
  %236 = add nsw i32 %x.0.reg2mem721.0.i.i, %i2.0.reg2mem715.0.i.i, !dbg !195 ; [#uses=1 type=i32] [debug line = 146:17]
  %237 = sext i32 %236 to i64, !dbg !195          ; [#uses=1 type=i64] [debug line = 146:17]
  %238 = getelementptr inbounds i8 addrspace(3)* %prow0.0.reg2mem735.0.i.i, i64 %237, !dbg !195 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 146:17]
  %239 = load i8 addrspace(3)* %238, align 1, !dbg !195 ; [#uses=1 type=i8] [debug line = 146:17]
  %240 = trunc i32 %235 to i16, !dbg !195         ; [#uses=1 type=i16] [debug line = 146:17]
  %241 = zext i8 %239 to i16, !dbg !195           ; [#uses=1 type=i16] [debug line = 146:17]
  %242 = mul i16 %240, %241, !dbg !195            ; [#uses=1 type=i16] [debug line = 146:17]
  %243 = add i16 %sumy.0.reg2mem717.0.i.i, %242, !dbg !195 ; [#uses=1 type=i16] [debug line = 146:17]
  %244 = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !196 ; [#uses=1 type=i32] [debug line = 147:17]
  %245 = sext i32 %244 to i64, !dbg !196          ; [#uses=1 type=i64] [debug line = 147:17]
  %246 = getelementptr inbounds [3 x [3 x i32]]* %GY.i.i, i64 0, i64 %245, i64 1, !dbg !196 ; [#uses=1 type=i32*] [debug line = 147:17]
  %247 = load i32* %246, align 4, !dbg !196       ; [#uses=1 type=i32] [debug line = 147:17]
  %248 = add nsw i32 %x.0.reg2mem721.0.i.i, %i2.0.reg2mem715.0.i.i, !dbg !196 ; [#uses=1 type=i32] [debug line = 147:17]
  %249 = sext i32 %248 to i64, !dbg !196          ; [#uses=1 type=i64] [debug line = 147:17]
  %250 = getelementptr inbounds i8 addrspace(3)* %prow1.0.reg2mem733.0.i.i, i64 %249, !dbg !196 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 147:17]
  %251 = load i8 addrspace(3)* %250, align 1, !dbg !196 ; [#uses=1 type=i8] [debug line = 147:17]
  %252 = trunc i32 %247 to i16, !dbg !196         ; [#uses=1 type=i16] [debug line = 147:17]
  %253 = zext i8 %251 to i16, !dbg !196           ; [#uses=1 type=i16] [debug line = 147:17]
  %254 = mul i16 %252, %253, !dbg !196            ; [#uses=1 type=i16] [debug line = 147:17]
  %255 = add i16 %243, %254, !dbg !196            ; [#uses=1 type=i16] [debug line = 147:17]
  %256 = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !197 ; [#uses=1 type=i32] [debug line = 148:17]
  %257 = sext i32 %256 to i64, !dbg !197          ; [#uses=1 type=i64] [debug line = 148:17]
  %258 = getelementptr inbounds [3 x [3 x i32]]* %GY.i.i, i64 0, i64 %257, i64 2, !dbg !197 ; [#uses=1 type=i32*] [debug line = 148:17]
  %259 = load i32* %258, align 4, !dbg !197       ; [#uses=1 type=i32] [debug line = 148:17]
  %260 = add nsw i32 %x.0.reg2mem721.0.i.i, %i2.0.reg2mem715.0.i.i, !dbg !197 ; [#uses=1 type=i32] [debug line = 148:17]
  %261 = sext i32 %260 to i64, !dbg !197          ; [#uses=1 type=i64] [debug line = 148:17]
  %262 = getelementptr inbounds [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2, i64 0, i64 %261, !dbg !197 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 148:17]
  %263 = load i8 addrspace(3)* %262, align 1, !dbg !197 ; [#uses=1 type=i8] [debug line = 148:17]
  %264 = trunc i32 %259 to i16, !dbg !197         ; [#uses=1 type=i16] [debug line = 148:17]
  %265 = zext i8 %263 to i16, !dbg !197           ; [#uses=1 type=i16] [debug line = 148:17]
  %266 = mul i16 %264, %265, !dbg !197            ; [#uses=1 type=i16] [debug line = 148:17]
  %.reg2mem498.0.i.i = add i16 %255, %266, !dbg !197 ; [#uses=1 type=i16] [debug line = 148:17]
  %.reg2mem496.0.i.i = add nsw i32 %i2.0.reg2mem715.0.i.i, 1, !dbg !198 ; [#uses=1 type=i32] [debug line = 141:24]
  br label %194, !dbg !198                        ; [debug line = 141:24]

._crit_edge.i.i:                                  ; preds = %194
  %267 = zext i16 %sumx.0.reg2mem719.0.i.i to i32, !dbg !199 ; [#uses=1 type=i32] [debug line = 151:19]
  %268 = zext i16 %sumx.0.reg2mem719.0.i.i to i32, !dbg !199 ; [#uses=1 type=i32] [debug line = 151:19]
  %269 = mul nsw i32 %267, %268, !dbg !199        ; [#uses=1 type=i32] [debug line = 151:19]
  %270 = sitofp i32 %269 to float, !dbg !199      ; [#uses=1 type=float] [debug line = 151:19]
  %271 = zext i16 %sumy.0.reg2mem717.0.i.i to i32, !dbg !199 ; [#uses=1 type=i32] [debug line = 151:19]
  %272 = zext i16 %sumy.0.reg2mem717.0.i.i to i32, !dbg !199 ; [#uses=1 type=i32] [debug line = 151:19]
  %273 = mul nsw i32 %271, %272, !dbg !199        ; [#uses=1 type=i32] [debug line = 151:19]
  %274 = sitofp i32 %273 to float, !dbg !199      ; [#uses=1 type=float] [debug line = 151:19]
  %.reg2mem171.0.reg2mem.0.i.i = fadd float %270, %274, !dbg !199 ; [#uses=9 type=float] [debug line = 151:19]
  call spir_func void @_ZN15sw_em_force_ftzC1Ev(%class.sw_em_force_ftz* %fftz.i.i.i.i.i) nounwind
  %275 = getelementptr inbounds %union.anon.0* %x.i.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem171.0.reg2mem.0.i.i, float* %275, align 4
  %276 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %277 = load i32* %276, align 4                  ; [#uses=2 type=i32]
  %.0111.0.i.i = and i32 %277, 2139095040         ; [#uses=1 type=i32]
  %.0110.0.reg2mem.0.i.i = and i32 %277, 8388607  ; [#uses=1 type=i32]
  %278 = icmp ne i32 %.0111.0.i.i, 2139095040     ; [#uses=1 type=i1]
  %279 = icmp eq i32 %.0110.0.reg2mem.0.i.i, 0    ; [#uses=1 type=i1]
  %or.cond.i.i = or i1 %278, %279                 ; [#uses=1 type=i1]
  %or.cond.not.i.i = xor i1 %or.cond.i.i, true    ; [#uses=1 type=i1]
  %280 = fcmp olt float %.reg2mem171.0.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  %or.cond879.i.i = or i1 %or.cond.not.i.i, %280  ; [#uses=1 type=i1]
  br i1 %or.cond879.i.i, label %_Z4sqrtf.exit.i.i, label %._crit_edge100.i.i

._crit_edge100.i.i:                               ; preds = %._crit_edge.i.i
  %281 = getelementptr inbounds %union.anon.0* %x.i.i1.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem171.0.reg2mem.0.i.i, float* %281, align 4
  %282 = bitcast %union.anon.0* %x.i.i1.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %283 = load i32* %282, align 4                  ; [#uses=2 type=i32]
  %.0117.0.i.i = and i32 %283, 2139095040         ; [#uses=1 type=i32]
  %.0116.0.reg2mem.0.i.i = and i32 %283, 8388607  ; [#uses=1 type=i32]
  %284 = icmp eq i32 %.0117.0.i.i, 2139095040     ; [#uses=1 type=i1]
  %285 = icmp eq i32 %.0116.0.reg2mem.0.i.i, 0    ; [#uses=1 type=i1]
  %or.cond880.i.i = and i1 %284, %285             ; [#uses=1 type=i1]
  br i1 %or.cond880.i.i, label %hls_isinf.exit.i.i.i.i.i, label %._crit_edge103.i.i

._crit_edge103.i.i:                               ; preds = %._crit_edge100.i.i
  %286 = fcmp une float %.reg2mem171.0.reg2mem.0.i.i, 0.000000e+00 ; [#uses=0 type=i1]
  %287 = fcmp oeq float %.reg2mem171.0.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  br i1 %287, label %_Z4sqrtf.exit.i.i, label %._crit_edge109.i.i

hls_isinf.exit.i.i.i.i.i:                         ; preds = %._crit_edge100.i.i
  br label %_Z4sqrtf.exit.i.i

._crit_edge109.i.i:                               ; preds = %._crit_edge103.i.i
  %288 = getelementptr inbounds %union.anon.0* %x.i19.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem171.0.reg2mem.0.i.i, float* %288, align 4
  %289 = bitcast %union.anon.0* %x.i19.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %290 = load i32* %289, align 4                  ; [#uses=2 type=i32]
  %291 = lshr i32 %290, 23                        ; [#uses=1 type=i32]
  %.069.0.reg2mem.0.i.i = and i32 %291, 255       ; [#uses=2 type=i32]
  %.reg2mem479.0.i.i = and i32 %290, 8388607      ; [#uses=2 type=i32]
  %292 = icmp eq i32 %.069.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  %.reg2mem477.0.i.i = or i32 %.reg2mem479.0.i.i, 8388608 ; [#uses=1 type=i32]
  %.068.0.reg2mem.0.i.i = select i1 %292, i32 %.reg2mem479.0.i.i, i32 %.reg2mem477.0.i.i ; [#uses=2 type=i32]
  %xe.i.i.i.0.reg2mem.0.i.i = add nsw i32 %.069.0.reg2mem.0.i.i, 386 ; [#uses=1 type=i32]
  %xm.i.i.i.0.reg2mem.0.i.i = zext i32 %.068.0.reg2mem.0.i.i to i64 ; [#uses=1 type=i64]
  %293 = icmp eq i32 %.068.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  br i1 %293, label %294, label %295

; <label>:294                                     ; preds = %._crit_edge109.i.i
  br label %_Z4sqrtf.exit.i.i

; <label>:295                                     ; preds = %._crit_edge109.i.i
  %.reg2mem473.0.i.i = shl i64 %xm.i.i.i.0.reg2mem.0.i.i, 38 ; [#uses=1 type=i64]
  store i64 4611686018427387904, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 0), align 8
  store i64 2697663385880076776, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 1), align 8
  store i64 1484631294131014398, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 2), align 8
  store i64 783640753332765648, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 3), align 8
  store i64 403351162126124447, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 4), align 8
  store i64 204731739545776358, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 5), align 8
  store i64 103153330606121625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 6), align 8
  store i64 51776576860734092, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 7), align 8
  store i64 25938654877364701, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 8), align 8
  store i64 12981968116705994, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 9), align 8
  store i64 6494150392542292, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 10), align 8
  store i64 3247867552377826, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 11), align 8
  store i64 1624131961909234, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 12), align 8
  store i64 812115539479148, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 13), align 8
  store i64 406070160882998, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 14), align 8
  store i64 203038178416421, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 15), align 8
  store i64 101519863725577, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 16), align 8
  store i64 50760125495084, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 17), align 8
  store i64 25380111155985, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 18), align 8
  store i64 12690067680150, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 19), align 8
  store i64 6345036865620, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 20), align 8
  store i64 3172519189197, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 21), align 8
  store i64 1586259783695, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 22), align 8
  store i64 793129939122, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 23), align 8
  store i64 396564981379, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 24), align 8
  store i64 198282493644, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 25), align 8
  store i64 99141247561, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 26), align 8
  store i64 49570623965, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 27), align 8
  store i64 24785312029, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 28), align 8
  store i64 12392656026, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 29), align 8
  store i64 6196328016, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 30), align 8
  store i64 3098164009, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 31), align 8
  store i64 1549082004, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 32), align 8
  store i64 774541002, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 33), align 8
  store i64 387270501, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 34), align 8
  store i64 193635251, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 35), align 8
  store i64 96817625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 36), align 8
  store i64 48408813, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 37), align 8
  store i64 24204406, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 38), align 8
  store i64 12102203, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 39), align 8
  store i64 6051102, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 40), align 8
  store i64 3025551, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 41), align 8
  store i64 1512775, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 42), align 8
  store i64 756388, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 43), align 8
  store i64 378194, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 44), align 8
  store i64 189097, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 45), align 8
  store i64 94548, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 46), align 8
  br label %296

; <label>:296                                     ; preds = %_ZL16hls_leading_on.i.i, %295
  %.063.reg2mem709.0.i.i = phi i64 [ %.reg2mem473.0.i.i, %295 ], [ %.164.reg2mem697.0.i.i, %_ZL16hls_leading_on.i.i ] ; [#uses=5 type=i64]
  %log2xm.i.i.i.0.reg2mem707.0.i.i = phi i64 [ 0, %295 ], [ %y.i17.i.i.i.1.reg2mem695.0.i.i, %_ZL16hls_leading_on.i.i ] ; [#uses=3 type=i64]
  %i.i18.i.i.i.0.reg2mem705.0.i.i = phi i32 [ 0, %295 ], [ %.reg2mem453.0.i.i, %_ZL16hls_leading_on.i.i ] ; [#uses=2 type=i32]
  %297 = icmp slt i32 %i.i18.i.i.i.0.reg2mem705.0.i.i, 47 ; [#uses=1 type=i1]
  br i1 %297, label %298, label %hls_log2_frac.exit.i.i.i.i.i

; <label>:298                                     ; preds = %296
  %299 = and i64 %.063.reg2mem709.0.i.i, 2305843009213693952 ; [#uses=1 type=i64]
  %300 = icmp eq i64 %299, 0                      ; [#uses=1 type=i1]
  br i1 %300, label %_ZL16hls_leading_onesx.exit.i.i.i.i.i.i, label %301

; <label>:301                                     ; preds = %306, %298
  %mask.i.i.i.i.i.0.reg2mem703.0.i.i = phi i64 [ %phitmp171.reg2mem.0.i.i, %306 ], [ 1152921504606846976, %298 ] ; [#uses=2 type=i64]
  %i.i.i.i.i.i.0.reg2mem701.0.i.i = phi i32 [ %.reg2mem461.0.i.i, %306 ], [ 2, %298 ] ; [#uses=3 type=i32]
  %302 = icmp slt i32 %i.i.i.i.i.i.0.reg2mem701.0.i.i, 47 ; [#uses=1 type=i1]
  br i1 %302, label %303, label %._crit_edge113.i.i

; <label>:303                                     ; preds = %301
  %304 = and i64 %.063.reg2mem709.0.i.i, %mask.i.i.i.i.i.0.reg2mem703.0.i.i ; [#uses=1 type=i64]
  %305 = icmp eq i64 %304, 0                      ; [#uses=1 type=i1]
  br i1 %305, label %._crit_edge113.i.i, label %306

; <label>:306                                     ; preds = %303
  %.reg2mem461.0.i.i = add nsw i32 %i.i.i.i.i.i.0.reg2mem701.0.i.i, 1 ; [#uses=1 type=i32]
  %phitmp171.reg2mem.0.i.i = lshr i64 %mask.i.i.i.i.i.0.reg2mem703.0.i.i, 1 ; [#uses=1 type=i64]
  br label %301

._crit_edge113.i.i:                               ; preds = %303, %301
  br label %_ZL16hls_leading_onesx.exit.i.i.i.i.i.i

_ZL16hls_leading_onesx.exit.i.i.i.i.i.i:          ; preds = %._crit_edge113.i.i, %298
  %.067.reg2mem699.0.i.i = phi i32 [ %i.i.i.i.i.i.0.reg2mem701.0.i.i, %._crit_edge113.i.i ], [ 47, %298 ] ; [#uses=3 type=i32]
  %307 = icmp slt i32 %.067.reg2mem699.0.i.i, 47  ; [#uses=1 type=i1]
  br i1 %307, label %308, label %_ZL16hls_leading_on.i.i

; <label>:308                                     ; preds = %_ZL16hls_leading_onesx.exit.i.i.i.i.i.i
  %309 = zext i32 %.067.reg2mem699.0.i.i to i64   ; [#uses=1 type=i64]
  %310 = ashr i64 %.063.reg2mem709.0.i.i, %309    ; [#uses=1 type=i64]
  %.reg2mem457.0.i.i = add nsw i64 %.063.reg2mem709.0.i.i, %310 ; [#uses=1 type=i64]
  %311 = sext i32 %.067.reg2mem699.0.i.i to i64   ; [#uses=1 type=i64]
  %312 = getelementptr inbounds [47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 %311 ; [#uses=1 type=i64*]
  %313 = load i64* %312, align 8                  ; [#uses=1 type=i64]
  %.reg2mem455.0.i.i = sub nsw i64 %log2xm.i.i.i.0.reg2mem707.0.i.i, %313 ; [#uses=1 type=i64]
  br label %_ZL16hls_leading_on.i.i

_ZL16hls_leading_on.i.i:                          ; preds = %308, %_ZL16hls_leading_onesx.exit.i.i.i.i.i.i
  %.164.reg2mem697.0.i.i = phi i64 [ %.reg2mem457.0.i.i, %308 ], [ %.063.reg2mem709.0.i.i, %_ZL16hls_leading_onesx.exit.i.i.i.i.i.i ] ; [#uses=1 type=i64]
  %y.i17.i.i.i.1.reg2mem695.0.i.i = phi i64 [ %.reg2mem455.0.i.i, %308 ], [ %log2xm.i.i.i.0.reg2mem707.0.i.i, %_ZL16hls_leading_onesx.exit.i.i.i.i.i.i ] ; [#uses=1 type=i64]
  %.reg2mem453.0.i.i = add nsw i32 %i.i18.i.i.i.0.reg2mem705.0.i.i, 1 ; [#uses=1 type=i32]
  br label %296

hls_log2_frac.exit.i.i.i.i.i:                     ; preds = %296
  %314 = zext i32 %xe.i.i.i.0.reg2mem.0.i.i to i64 ; [#uses=1 type=i64]
  %315 = shl i64 %314, 55                         ; [#uses=1 type=i64]
  %316 = ashr i64 %log2xm.i.i.i.0.reg2mem707.0.i.i, 7 ; [#uses=1 type=i64]
  %F.i.i.i.0.i.i = add nsw i64 %315, %316         ; [#uses=1 type=i64]
  %Foy.i.i.i.0.reg2mem.0.i.i = sdiv i64 %F.i.i.i.0.i.i, 2 ; [#uses=2 type=i64]
  %317 = shl i64 %Foy.i.i.i.0.reg2mem.0.i.i, 5    ; [#uses=1 type=i64]
  %FF.i.i.i.0.reg2mem.0.i.i = and i64 %317, 1152921504606846944 ; [#uses=2 type=i64]
  %318 = getelementptr inbounds %union.anon.0* %x.i.i.i12.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float 1.000000e+00, float* %318, align 4
  %319 = bitcast %union.anon.0* %x.i.i.i12.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %.reg2mem447.0.i.i = load i32* %319, align 4    ; [#uses=3 type=i32]
  %320 = lshr i32 %.reg2mem447.0.i.i, 23          ; [#uses=1 type=i32]
  %.060.0.reg2mem.0.i.i = and i32 %320, 255       ; [#uses=3 type=i32]
  %.059.0.i.i = and i32 %.reg2mem447.0.i.i, 8388607 ; [#uses=1 type=i32]
  %.reg2mem442.0.i.i = zext i32 %.059.0.i.i to i64 ; [#uses=2 type=i64]
  %321 = icmp eq i32 %.060.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  %.reg2mem440.0.i.i = or i64 %.reg2mem442.0.i.i, 8388608 ; [#uses=1 type=i64]
  %m.i.i15.i.i.i.0.reg2mem.0.i.i = select i1 %321, i64 %.reg2mem442.0.i.i, i64 %.reg2mem440.0.i.i ; [#uses=1 type=i64]
  %.reg2mem437.0.i.i = shl nsw i64 %m.i.i15.i.i.i.0.reg2mem.0.i.i, 36 ; [#uses=2 type=i64]
  %shift.i.i.i.i.i.0.reg2mem.0.i.i = add i32 %.060.0.reg2mem.0.i.i, -126 ; [#uses=4 type=i32]
  %322 = icmp sgt i32 %shift.i.i.i.i.i.0.reg2mem.0.i.i, 3 ; [#uses=1 type=i1]
  %323 = icmp slt i32 %shift.i.i.i.i.i.0.reg2mem.0.i.i, -64 ; [#uses=1 type=i1]
  %or.cond882.i.i = or i1 %322, %323              ; [#uses=1 type=i1]
  br i1 %or.cond882.i.i, label %._crit_edge114.i.i, label %324

; <label>:324                                     ; preds = %hls_log2_frac.exit.i.i.i.i.i
  %325 = icmp sgt i32 %shift.i.i.i.i.i.0.reg2mem.0.i.i, 0 ; [#uses=1 type=i1]
  br i1 %325, label %326, label %328

; <label>:326                                     ; preds = %324
  %327 = zext i32 %shift.i.i.i.i.i.0.reg2mem.0.i.i to i64 ; [#uses=1 type=i64]
  %.reg2mem432.0.i.i = shl i64 %.reg2mem437.0.i.i, %327 ; [#uses=1 type=i64]
  br label %._crit_edge114.i.i

; <label>:328                                     ; preds = %324
  %329 = sub i32 126, %.060.0.reg2mem.0.i.i       ; [#uses=1 type=i32]
  %330 = zext i32 %329 to i64                     ; [#uses=1 type=i64]
  %.reg2mem430.0.i.i = ashr i64 %.reg2mem437.0.i.i, %330 ; [#uses=1 type=i64]
  br label %._crit_edge114.i.i

._crit_edge114.i.i:                               ; preds = %328, %326, %hls_log2_frac.exit.i.i.i.i.i
  %m.i.i15.i.i.i.2.reg2mem691.0.i.i = phi i64 [ %.reg2mem432.0.i.i, %326 ], [ %.reg2mem430.0.i.i, %328 ], [ 0, %hls_log2_frac.exit.i.i.i.i.i ] ; [#uses=2 type=i64]
  %331 = icmp sgt i32 %.reg2mem447.0.i.i, -1      ; [#uses=1 type=i1]
  %.reg2mem427.0.i.i = sub nsw i64 0, %m.i.i15.i.i.i.2.reg2mem691.0.i.i ; [#uses=1 type=i64]
  %.058.reg2mem689.0.i.i = select i1 %331, i64 %m.i.i15.i.i.i.2.reg2mem691.0.i.i, i64 %.reg2mem427.0.i.i ; [#uses=1 type=i64]
  store i64 4611686018427387904, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 0), align 8
  store i64 2697663385880076776, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 1), align 8
  store i64 1484631294131014398, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 2), align 8
  store i64 783640753332765648, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 3), align 8
  store i64 403351162126124447, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 4), align 8
  store i64 204731739545776358, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 5), align 8
  store i64 103153330606121625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 6), align 8
  store i64 51776576860734092, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 7), align 8
  store i64 25938654877364701, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 8), align 8
  store i64 12981968116705994, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 9), align 8
  store i64 6494150392542292, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 10), align 8
  store i64 3247867552377826, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 11), align 8
  store i64 1624131961909234, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 12), align 8
  store i64 812115539479148, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 13), align 8
  store i64 406070160882998, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 14), align 8
  store i64 203038178416421, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 15), align 8
  store i64 101519863725577, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 16), align 8
  store i64 50760125495084, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 17), align 8
  store i64 25380111155985, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 18), align 8
  store i64 12690067680150, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 19), align 8
  store i64 6345036865620, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 20), align 8
  store i64 3172519189197, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 21), align 8
  store i64 1586259783695, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 22), align 8
  store i64 793129939122, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 23), align 8
  store i64 396564981379, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 24), align 8
  store i64 198282493644, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 25), align 8
  store i64 99141247561, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 26), align 8
  store i64 49570623965, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 27), align 8
  store i64 24785312029, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 28), align 8
  store i64 12392656026, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 29), align 8
  store i64 6196328016, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 30), align 8
  store i64 3098164009, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 31), align 8
  store i64 1549082004, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 32), align 8
  store i64 774541002, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 33), align 8
  store i64 387270501, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 34), align 8
  store i64 193635251, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 35), align 8
  store i64 96817625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 36), align 8
  store i64 48408813, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 37), align 8
  store i64 24204406, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 38), align 8
  store i64 12102203, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 39), align 8
  store i64 6051102, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 40), align 8
  store i64 3025551, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 41), align 8
  store i64 1512775, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 42), align 8
  store i64 756388, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 43), align 8
  store i64 378194, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 44), align 8
  store i64 189097, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 45), align 8
  store i64 94548, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 46), align 8
  br label %332

; <label>:332                                     ; preds = %._crit_edge116.i.i, %._crit_edge114.i.i
  %i.i.i.i.i.0.reg2mem687.0.i.i = phi i32 [ 1, %._crit_edge114.i.i ], [ %.reg2mem414.0.i.i, %._crit_edge116.i.i ] ; [#uses=4 type=i32]
  %.056.reg2mem685.0.i.i = phi i64 [ %FF.i.i.i.0.reg2mem.0.i.i, %._crit_edge114.i.i ], [ %.157.reg2mem681.0.i.i, %._crit_edge116.i.i ] ; [#uses=2 type=i64]
  %.0130.reg2mem683.0.i.i = phi i64 [ %.058.reg2mem689.0.i.i, %._crit_edge114.i.i ], [ %y.i16.i.i.i.1.reg2mem679.0.i.i, %._crit_edge116.i.i ] ; [#uses=5 type=i64]
  %333 = icmp slt i32 %i.i.i.i.i.0.reg2mem687.0.i.i, 47 ; [#uses=1 type=i1]
  br i1 %333, label %334, label %hls_exp2_frac.exit.i.i.i.i.i

; <label>:334                                     ; preds = %332
  %335 = sext i32 %i.i.i.i.i.0.reg2mem687.0.i.i to i64 ; [#uses=1 type=i64]
  %336 = getelementptr inbounds [47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 %335 ; [#uses=1 type=i64*]
  %337 = load i64* %336, align 8                  ; [#uses=1 type=i64]
  %338 = ashr i64 %337, 2                         ; [#uses=1 type=i64]
  %D.i.i.i.i.0.reg2mem.0.i.i = sub nsw i64 %.056.reg2mem685.0.i.i, %338 ; [#uses=2 type=i64]
  %339 = icmp sgt i64 %D.i.i.i.i.0.reg2mem.0.i.i, -1 ; [#uses=1 type=i1]
  br i1 %339, label %340, label %._crit_edge116.i.i

; <label>:340                                     ; preds = %334
  %341 = zext i32 %i.i.i.i.i.0.reg2mem687.0.i.i to i64 ; [#uses=1 type=i64]
  %342 = ashr i64 %.0130.reg2mem683.0.i.i, %341   ; [#uses=1 type=i64]
  %.reg2mem416.0.i.i = add nsw i64 %.0130.reg2mem683.0.i.i, %342 ; [#uses=1 type=i64]
  br label %._crit_edge116.i.i

._crit_edge116.i.i:                               ; preds = %340, %334
  %y.i16.i.i.i.1.reg2mem679.0.i.i = phi i64 [ %.reg2mem416.0.i.i, %340 ], [ %.0130.reg2mem683.0.i.i, %334 ] ; [#uses=1 type=i64]
  %.157.reg2mem681.0.i.i = phi i64 [ %D.i.i.i.i.0.reg2mem.0.i.i, %340 ], [ %.056.reg2mem685.0.i.i, %334 ] ; [#uses=1 type=i64]
  %.reg2mem414.0.i.i = add nsw i32 %i.i.i.i.i.0.reg2mem687.0.i.i, 1 ; [#uses=1 type=i32]
  br label %332

hls_exp2_frac.exit.i.i.i.i.i:                     ; preds = %332
  %343 = lshr exact i64 %FF.i.i.i.0.reg2mem.0.i.i, 5 ; [#uses=1 type=i64]
  %344 = sub nsw i64 %Foy.i.i.i.0.reg2mem.0.i.i, %343 ; [#uses=1 type=i64]
  %FI.i.i.i.0.reg2mem.0.i.i = ashr i64 %344, 55   ; [#uses=1 type=i64]
  %345 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  store i64 %.0130.reg2mem683.0.i.i, i64* %345, align 8
  %346 = icmp slt i64 %.0130.reg2mem683.0.i.i, 0  ; [#uses=1 type=i1]
  br i1 %346, label %347, label %hls_exp2_frac.exit.i.i.i._crit_edge.i.i

; <label>:347                                     ; preds = %hls_exp2_frac.exit.i.i.i.i.i
  %348 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %349 = load i64* %348, align 8                  ; [#uses=1 type=i64]
  %350 = sub i64 0, %349                          ; [#uses=1 type=i64]
  %351 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  store i64 %350, i64* %351, align 8
  br label %hls_exp2_frac.exit.i.i.i._crit_edge.i.i

hls_exp2_frac.exit.i.i.i._crit_edge.i.i:          ; preds = %347, %hls_exp2_frac.exit.i.i.i.i.i
  %s.i9.i.i.i.0.reg2mem677.0.i.i = phi i32 [ -2147483648, %347 ], [ 0, %hls_exp2_frac.exit.i.i.i.i.i ] ; [#uses=1 type=i32]
  br label %._crit_edge117.i.i

._crit_edge117.i.i:                               ; preds = %._crit_edge118.i.i, %hls_exp2_frac.exit.i.i.i._crit_edge.i.i
  %e.i10.i.i.i.0.reg2mem671.0.i.i = phi i32 [ 90, %hls_exp2_frac.exit.i.i.i._crit_edge.i.i ], [ %.reg2mem401.0.i.i, %._crit_edge118.i.i ] ; [#uses=6 type=i32]
  %fract.i.i.i.i.0.reg2mem673.0.i.i = phi i32 [ 0, %hls_exp2_frac.exit.i.i.i._crit_edge.i.i ], [ %.reg2mem405.0.i.i, %._crit_edge118.i.i ] ; [#uses=2 type=i32]
  %rnd.i.i.i.i.0.reg2mem675.0.i.i = phi i32 [ 0, %hls_exp2_frac.exit.i.i.i._crit_edge.i.i ], [ %.reg2mem403.0.i.i, %._crit_edge118.i.i ] ; [#uses=2 type=i32]
  %352 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %353 = load i64* %352, align 8                  ; [#uses=1 type=i64]
  %354 = icmp ugt i64 %353, 16777215              ; [#uses=1 type=i1]
  %.reg2mem169.0.reg2mem.0.i.i = icmp ult i32 %e.i10.i.i.i.0.reg2mem671.0.i.i, 255 ; [#uses=1 type=i1]
  %.reg2mem185.0.reg2mem.0.i.i = select i1 %354, i1 %.reg2mem169.0.reg2mem.0.i.i, i1 false ; [#uses=1 type=i1]
  br i1 %.reg2mem185.0.reg2mem.0.i.i, label %._crit_edge118.i.i, label %361

._crit_edge118.i.i:                               ; preds = %._crit_edge117.i.i
  %355 = icmp eq i32 %fract.i.i.i.i.0.reg2mem673.0.i.i, 0 ; [#uses=1 type=i1]
  %.reg2mem167.0.reg2mem.0.i.i = icmp ne i32 %rnd.i.i.i.i.0.reg2mem675.0.i.i, 0 ; [#uses=1 type=i1]
  %.reg2mem183.0.reg2mem.0.i.i = select i1 %355, i1 %.reg2mem167.0.reg2mem.0.i.i, i1 true ; [#uses=1 type=i1]
  %.reg2mem405.0.i.i = zext i1 %.reg2mem183.0.reg2mem.0.i.i to i32 ; [#uses=1 type=i32]
  %356 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %357 = load i64* %356, align 8                  ; [#uses=2 type=i64]
  %358 = trunc i64 %357 to i32                    ; [#uses=1 type=i32]
  %.reg2mem403.0.i.i = and i32 %358, 1            ; [#uses=1 type=i32]
  %.reg2mem401.0.i.i = add i32 %e.i10.i.i.i.0.reg2mem671.0.i.i, 1 ; [#uses=1 type=i32]
  %359 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %360 = lshr i64 %357, 1                         ; [#uses=1 type=i64]
  store i64 %360, i64* %359, align 8
  br label %._crit_edge117.i.i

; <label>:361                                     ; preds = %._crit_edge117.i.i
  %362 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %363 = load i64* %362, align 8                  ; [#uses=1 type=i64]
  %364 = trunc i64 %363 to i32                    ; [#uses=1 type=i32]
  %odd.i.i.i.i.0.reg2mem.0.i.i = and i32 %364, 1  ; [#uses=1 type=i32]
  %365 = icmp eq i32 %rnd.i.i.i.i.0.reg2mem675.0.i.i, 0 ; [#uses=1 type=i1]
  br i1 %365, label %._crit_edge119.i.i, label %366

; <label>:366                                     ; preds = %361
  %367 = icmp eq i32 %fract.i.i.i.i.0.reg2mem673.0.i.i, 0 ; [#uses=1 type=i1]
  %368 = icmp eq i32 %odd.i.i.i.i.0.reg2mem.0.i.i, 0 ; [#uses=1 type=i1]
  %or.cond883.i.i = and i1 %367, %368             ; [#uses=1 type=i1]
  br i1 %or.cond883.i.i, label %._crit_edge119.i.i, label %._crit_edge120.i.i

._crit_edge120.i.i:                               ; preds = %366
  %369 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=2 type=i64*]
  %370 = load i64* %369, align 8                  ; [#uses=1 type=i64]
  %371 = add i64 %370, 1                          ; [#uses=2 type=i64]
  store i64 %371, i64* %369, align 8
  %372 = icmp ugt i64 %371, 16777215              ; [#uses=1 type=i1]
  br i1 %372, label %373, label %._crit_edge119.i.i

; <label>:373                                     ; preds = %._crit_edge120.i.i
  %.reg2mem399.0.i.i = add i32 %e.i10.i.i.i.0.reg2mem671.0.i.i, 1 ; [#uses=1 type=i32]
  %374 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=2 type=i64*]
  %375 = load i64* %374, align 8                  ; [#uses=1 type=i64]
  %376 = lshr i64 %375, 1                         ; [#uses=1 type=i64]
  store i64 %376, i64* %374, align 8
  br label %._crit_edge119.i.i

._crit_edge119.i.i:                               ; preds = %381, %373, %._crit_edge120.i.i, %366, %361
  %e.i10.i.i.i.3.reg2mem665.0.i.i = phi i32 [ %.reg2mem395.0.i.i, %381 ], [ %e.i10.i.i.i.0.reg2mem671.0.i.i, %361 ], [ %.reg2mem399.0.i.i, %373 ], [ %e.i10.i.i.i.0.reg2mem671.0.i.i, %._crit_edge120.i.i ], [ %e.i10.i.i.i.0.reg2mem671.0.i.i, %366 ] ; [#uses=3 type=i32]
  %377 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %378 = load i64* %377, align 8                  ; [#uses=1 type=i64]
  %379 = and i64 %378, 8388608                    ; [#uses=1 type=i64]
  %380 = icmp eq i64 %379, 0                      ; [#uses=1 type=i1]
  %.reg2mem165.0.reg2mem.0.i.i = icmp ne i32 %e.i10.i.i.i.3.reg2mem665.0.i.i, 0 ; [#uses=1 type=i1]
  %.reg2mem181.0.reg2mem.0.i.i = select i1 %380, i1 %.reg2mem165.0.reg2mem.0.i.i, i1 false ; [#uses=1 type=i1]
  br i1 %.reg2mem181.0.reg2mem.0.i.i, label %381, label %hls_fixed_to_float.exit.i.i.i.i.i

; <label>:381                                     ; preds = %._crit_edge119.i.i
  %.reg2mem395.0.i.i = add i32 %e.i10.i.i.i.3.reg2mem665.0.i.i, -1 ; [#uses=1 type=i32]
  %382 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=2 type=i64*]
  %383 = load i64* %382, align 8                  ; [#uses=1 type=i64]
  %384 = shl i64 %383, 1                          ; [#uses=1 type=i64]
  store i64 %384, i64* %382, align 8
  br label %._crit_edge119.i.i

hls_fixed_to_float.exit.i.i.i.i.i:                ; preds = %._crit_edge119.i.i
  %385 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %386 = load i64* %385, align 8                  ; [#uses=1 type=i64]
  %m.i11.i.i.i.0.i.i = trunc i64 %386 to i32      ; [#uses=1 type=i32]
  %387 = shl i32 %e.i10.i.i.i.3.reg2mem665.0.i.i, 23 ; [#uses=1 type=i32]
  %388 = and i32 %387, 2139095040                 ; [#uses=1 type=i32]
  %389 = or i32 %s.i9.i.i.i.0.reg2mem677.0.i.i, %388 ; [#uses=1 type=i32]
  %390 = and i32 %m.i11.i.i.i.0.i.i, 8388607      ; [#uses=1 type=i32]
  %391 = or i32 %389, %390                        ; [#uses=1 type=i32]
  %392 = bitcast %union.anon* %x.i.i8.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  store i32 %391, i32* %392, align 4
  %393 = getelementptr inbounds %union.anon* %x.i.i8.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.0157.reg2mem.0.i.i = load float* %393, align 4 ; [#uses=7 type=float]
  %.0124.reg2mem.0.i.i = trunc i64 %FI.i.i.i.0.reg2mem.0.i.i to i32 ; [#uses=4 type=i32]
  %394 = icmp eq i32 %.0124.reg2mem.0.i.i, 0      ; [#uses=1 type=i1]
  %395 = fcmp oeq float %.0157.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  %or.cond884.i.i = or i1 %394, %395              ; [#uses=1 type=i1]
  br i1 %or.cond884.i.i, label %hls_fixed_to_float.exit.i.i.i._crit_edge.i.i, label %hls_isfinite.exit.i.i.i.i.i.i

hls_isfinite.exit.i.i.i.i.i.i:                    ; preds = %hls_fixed_to_float.exit.i.i.i.i.i
  %396 = getelementptr inbounds %union.anon.0* %x.i.i.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.0157.reg2mem.0.i.i, float* %396, align 4
  %397 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %398 = load i32* %397, align 4                  ; [#uses=1 type=i32]
  %.0132.0.i.i = and i32 %398, 2139095040         ; [#uses=1 type=i32]
  %399 = icmp eq i32 %.0132.0.i.i, 2139095040     ; [#uses=1 type=i1]
  %.0129.reg2mem.0.i.i = select i1 %399, i1 false, i1 true ; [#uses=1 type=i1]
  br i1 %.0129.reg2mem.0.i.i, label %hls_isfinite.exit.i.i.i.i.i.i.i, label %hls_fixed_to_float.exit.i.i.i._crit_edge.i.i

hls_fixed_to_float.exit.i.i.i._crit_edge.i.i:     ; preds = %hls_isfinite.exit.i.i.i.i.i.i, %hls_fixed_to_float.exit.i.i.i.i.i
  br label %hls_ldexp.exit.i.i.i.i.i

hls_isfinite.exit.i.i.i.i.i.i.i:                  ; preds = %hls_isfinite.exit.i.i.i.i.i.i
  %400 = getelementptr inbounds %union.anon.0* %x.i.i2.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.0157.reg2mem.0.i.i, float* %400, align 4
  %401 = bitcast %union.anon.0* %x.i.i2.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %.reg2mem383.0.i.i = load i32* %401, align 4    ; [#uses=2 type=i32]
  %402 = lshr i32 %.reg2mem383.0.i.i, 23          ; [#uses=1 type=i32]
  %.0146.0.reg2mem.0.i.i = and i32 %402, 255      ; [#uses=1 type=i32]
  %403 = getelementptr inbounds %union.anon.0* %x.i.i.i.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.0157.reg2mem.0.i.i, float* %403, align 4
  %404 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %405 = load i32* %404, align 4                  ; [#uses=1 type=i32]
  %.0155.0.i.i = and i32 %405, 2139095040         ; [#uses=1 type=i32]
  %406 = icmp eq i32 %.0155.0.i.i, 2139095040     ; [#uses=1 type=i1]
  %.0153.reg2mem.0.i.i = select i1 %406, i1 false, i1 true ; [#uses=1 type=i1]
  %.0153.reg2mem.0.not.i.i = xor i1 %.0153.reg2mem.0.i.i, true ; [#uses=1 type=i1]
  %407 = fcmp oeq float %.0157.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  %or.cond885.i.i = or i1 %.0153.reg2mem.0.not.i.i, %407 ; [#uses=1 type=i1]
  br i1 %or.cond885.i.i, label %hls_frexp.exit.i.i.i.i.i.i, label %408

; <label>:408                                     ; preds = %hls_isfinite.exit.i.i.i.i.i.i.i
  %.reg2mem381.0.i.i = add nsw i32 %.0146.0.reg2mem.0.i.i, -126 ; [#uses=1 type=i32]
  %409 = and i32 %.reg2mem383.0.i.i, -2139095041  ; [#uses=1 type=i32]
  %410 = or i32 %409, 1056964608                  ; [#uses=1 type=i32]
  %411 = bitcast %union.anon* %x.i1.i.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  store i32 %410, i32* %411, align 4
  %412 = getelementptr inbounds %union.anon* %x.i1.i.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.reg2mem379.0.i.i = load float* %412, align 4  ; [#uses=1 type=float]
  br label %hls_frexp.exit.i.i.i.i.i.i

hls_frexp.exit.i.i.i.i.i.i:                       ; preds = %408, %hls_isfinite.exit.i.i.i.i.i.i.i
  %.0144.reg2mem.0.i.i = phi float [ %.reg2mem379.0.i.i, %408 ], [ %.0157.reg2mem.0.i.i, %hls_isfinite.exit.i.i.i.i.i.i.i ] ; [#uses=1 type=float]
  %.0142.0.reg2mem663.0.i.i = phi i32 [ %.reg2mem381.0.i.i, %408 ], [ 0, %hls_isfinite.exit.i.i.i.i.i.i.i ] ; [#uses=1 type=i32]
  %413 = getelementptr inbounds %union.anon.0* %x.i1.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.0144.reg2mem.0.i.i, float* %413, align 4
  %414 = bitcast %union.anon.0* %x.i1.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %.reg2mem376.0.i.i = load i32* %414, align 4    ; [#uses=2 type=i32]
  %.0138.0.reg2mem.0.i.i = and i32 %.reg2mem376.0.i.i, 8388607 ; [#uses=1 type=i32]
  %415 = icmp sgt i32 %.0124.reg2mem.0.i.i, 279   ; [#uses=1 type=i1]
  br i1 %415, label %420, label %416

; <label>:416                                     ; preds = %hls_frexp.exit.i.i.i.i.i.i
  %417 = icmp slt i32 %.0124.reg2mem.0.i.i, -279  ; [#uses=1 type=i1]
  br i1 %417, label %420, label %418

; <label>:418                                     ; preds = %416
  %419 = add nsw i32 %.0142.0.reg2mem663.0.i.i, %.0124.reg2mem.0.i.i ; [#uses=1 type=i32]
  %.reg2mem374.0.i.i = add nsw i32 %419, -1       ; [#uses=1 type=i32]
  br label %420

; <label>:420                                     ; preds = %418, %416, %hls_frexp.exit.i.i.i.i.i.i
  %ye.i.i.i.i.1.reg2mem659.0.i.i = phi i32 [ 128, %hls_frexp.exit.i.i.i.i.i.i ], [ %.reg2mem374.0.i.i, %418 ], [ -151, %416 ] ; [#uses=3 type=i32]
  %421 = icmp slt i32 %ye.i.i.i.i.1.reg2mem659.0.i.i, -126 ; [#uses=1 type=i1]
  br i1 %421, label %424, label %422

; <label>:422                                     ; preds = %420
  %423 = icmp sgt i32 %ye.i.i.i.i.1.reg2mem659.0.i.i, 127 ; [#uses=2 type=i1]
  %.reg2mem370.0.i.i = add nsw i32 %ye.i.i.i.i.1.reg2mem659.0.i.i, 127 ; [#uses=1 type=i32]
  %m.i7.i.i.i.0.reg2mem655.0.i.i = select i1 %423, i32 0, i32 %.0138.0.reg2mem.0.i.i ; [#uses=1 type=i32]
  %e.i6.i.i.i.0.reg2mem657.0.i.i = select i1 %423, i32 255, i32 %.reg2mem370.0.i.i ; [#uses=1 type=i32]
  br label %424

; <label>:424                                     ; preds = %422, %420
  %m.i7.i.i.i.1.reg2mem.0.i.i = phi i32 [ %m.i7.i.i.i.0.reg2mem655.0.i.i, %422 ], [ 0, %420 ] ; [#uses=1 type=i32]
  %e.i6.i.i.i.1.reg2mem.0.i.i = phi i32 [ %e.i6.i.i.i.0.reg2mem657.0.i.i, %422 ], [ 0, %420 ] ; [#uses=1 type=i32]
  %425 = and i32 %.reg2mem376.0.i.i, -2147483648  ; [#uses=1 type=i32]
  %426 = shl i32 %e.i6.i.i.i.1.reg2mem.0.i.i, 23  ; [#uses=1 type=i32]
  %427 = and i32 %426, 2139095040                 ; [#uses=1 type=i32]
  %428 = or i32 %425, %427                        ; [#uses=1 type=i32]
  %429 = and i32 %m.i7.i.i.i.1.reg2mem.0.i.i, 8388607 ; [#uses=1 type=i32]
  %430 = or i32 %428, %429                        ; [#uses=1 type=i32]
  %431 = bitcast %union.anon* %x.i.i5.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  store i32 %430, i32* %431, align 4
  %432 = getelementptr inbounds %union.anon* %x.i.i5.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.reg2mem368.0.i.i = load float* %432, align 4  ; [#uses=1 type=float]
  br label %hls_ldexp.exit.i.i.i.i.i

hls_ldexp.exit.i.i.i.i.i:                         ; preds = %424, %hls_fixed_to_float.exit.i.i.i._crit_edge.i.i
  %.0126.reg2mem653.0.i.i = phi float [ %.0157.reg2mem.0.i.i, %hls_fixed_to_float.exit.i.i.i._crit_edge.i.i ], [ %.reg2mem368.0.i.i, %424 ] ; [#uses=1 type=float]
  %433 = getelementptr inbounds %union.anon.13* %x.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.0126.reg2mem653.0.i.i, float* %433, align 4
  %434 = getelementptr inbounds %union.anon.13* %y.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem171.0.reg2mem.0.i.i, float* %434, align 4
  %435 = bitcast %union.anon.13* %x.i.i.i.i.i.i to i32* ; [#uses=2 type=i32*]
  %436 = load i32* %435, align 4                  ; [#uses=1 type=i32]
  %437 = and i32 %436, 2147483647                 ; [#uses=2 type=i32]
  store i32 %437, i32* %435, align 4
  %438 = bitcast %union.anon.13* %y.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %439 = load i32* %438, align 4                  ; [#uses=1 type=i32]
  %440 = and i32 %439, -2147483648                ; [#uses=1 type=i32]
  %441 = bitcast %union.anon.13* %x.i.i.i.i.i.i to i32* ; [#uses=1 type=i32*]
  %442 = or i32 %437, %440                        ; [#uses=1 type=i32]
  store i32 %442, i32* %441, align 4
  %443 = getelementptr inbounds %union.anon.13* %x.i.i.i.i.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.reg2mem363.0.i.i = load float* %443, align 4  ; [#uses=1 type=float]
  br label %_Z4sqrtf.exit.i.i

_Z4sqrtf.exit.i.i:                                ; preds = %hls_ldexp.exit.i.i.i.i.i, %294, %hls_isinf.exit.i.i.i.i.i, %._crit_edge103.i.i, %._crit_edge.i.i
  %.0107.reg2mem651.0.i.i = phi float [ %.reg2mem171.0.reg2mem.0.i.i, %hls_isinf.exit.i.i.i.i.i ], [ 0.000000e+00, %294 ], [ %.reg2mem363.0.i.i, %hls_ldexp.exit.i.i.i.i.i ], [ %.reg2mem171.0.reg2mem.0.i.i, %._crit_edge103.i.i ], [ 0x7FF8000000000000, %._crit_edge.i.i ] ; [#uses=4 type=float]
  call spir_func void @_ZN15sw_em_force_ftzD1Ev(%class.sw_em_force_ftz* %fftz.i.i.i.i.i) nounwind
  %444 = fcmp ogt float %.0107.reg2mem651.0.i.i, %maxg.1.reg2mem723.0.i.i, !dbg !200 ; [#uses=1 type=i1] [debug line = 152:13]
  %maxg.2.reg2mem649.0.i.i = select i1 %444, float %.0107.reg2mem651.0.i.i, float %maxg.1.reg2mem723.0.i.i, !dbg !200 ; [#uses=1 type=float] [debug line = 152:13]
  %445 = fcmp olt float %.0107.reg2mem651.0.i.i, %ming.1.reg2mem725.0.i.i, !dbg !201 ; [#uses=1 type=i1] [debug line = 154:13]
  %ming.2.reg2mem647.0.i.i = select i1 %445, float %.0107.reg2mem651.0.i.i, float %ming.1.reg2mem725.0.i.i, !dbg !201 ; [#uses=1 type=float] [debug line = 154:13]
  %.reg2mem358.0.i.i = add nsw i32 %x.0.reg2mem721.0.i.i, 1, !dbg !202 ; [#uses=1 type=i32] [debug line = 134:31]
  call spir_func void (...)* @_ssdm_RegionEnd(i8* getelementptr inbounds ([13 x i8]* @hls_region, i64 0, i64 0)) nounwind
  br label %190, !dbg !202, !xcl.pipeline !203, !xcl.pipeline.N !204 ; [debug line = 134:31]

; <label>:446                                     ; preds = %190
  %.reg2mem356.0.i.i = add nsw i32 %y1.0.reg2mem727.0.i.i, 1, !dbg !205 ; [#uses=1 type=i32] [debug line = 124:31]
  br label %.rentry743.i.i, !dbg !205             ; [debug line = 124:31]

_Z21async_work_grou746.i.i:                       ; preds = %.rentry743.i.i
  %.074.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !206 ; [#uses=1 type=i64] [debug line = 167:5]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %arg_in_pixels.i.0, i32 addrspace(1)* %arg_in_pixels.i.0, i32 0, i64 1) nounwind
  %CI231.i.i = bitcast i32 addrspace(1)* %arg_in_pixels.i.0 to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf0 to i8*), i8* %CI231.i.i, i64 %.074.reg2mem.0.i.i, i32 1, i1 false) nounwind
  %.reg2mem353.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !207 ; [#uses=2 type=i64] [debug line = 168:5]
  %bus_addr238.i.i = lshr i64 %.reg2mem353.0.i.i, 2 ; [#uses=1 type=i64]
  %.078.reg2mem.0.i.i = getelementptr i32 addrspace(1)* %arg_in_pixels.i.0, i64 %bus_addr238.i.i ; [#uses=2 type=i32 addrspace(1)*]
  %.077.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !207 ; [#uses=1 type=i64] [debug line = 168:5]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %.078.reg2mem.0.i.i, i32 addrspace(1)* %arg_in_pixels.i.0, i64 %.reg2mem353.0.i.i, i64 1) nounwind
  %CI250.i.i = bitcast i32 addrspace(1)* %.078.reg2mem.0.i.i to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf1 to i8*), i8* %CI250.i.i, i64 %.077.reg2mem.0.i.i, i32 1, i1 false) nounwind
  br label %.rentry749.rentry.i.i, !dbg !208      ; [debug line = 172:13]

.rentry749.rentry.i.i:                            ; preds = %_Z21async_work_grou753.rexit.i.i, %_Z21async_work_grou746.i.i
  %prow0.1.reg2mem645.0.i.i = phi i8 addrspace(3)* [ getelementptr inbounds ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf0, i64 0, i64 0), %_Z21async_work_grou746.i.i ], [ %prow1.1.reg2mem643.0.i.i, %_Z21async_work_grou753.rexit.i.i ] ; [#uses=2 type=i8 addrspace(3)*]
  %prow1.1.reg2mem643.0.i.i = phi i8 addrspace(3)* [ getelementptr inbounds ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf1, i64 0, i64 0), %_Z21async_work_grou746.i.i ], [ getelementptr inbounds ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2, i64 0, i64 0), %_Z21async_work_grou753.rexit.i.i ] ; [#uses=3 type=i8 addrspace(3)*]
  %y3.0.reg2mem641.0.i.i = phi i32 [ 1, %_Z21async_work_grou746.i.i ], [ %.reg2mem.0.i.i, %_Z21async_work_grou753.rexit.i.i ] ; [#uses=4 type=i32]
  %447 = add nsw i32 %arg_height.i.0, -1, !dbg !208 ; [#uses=1 type=i32] [debug line = 172:13]
  %448 = icmp slt i32 %y3.0.reg2mem641.0.i.i, %447, !dbg !208 ; [#uses=1 type=i1] [debug line = 172:13]
  br i1 %448, label %_Z21async_work_grou751.rexit.i.i, label %__AESL_call_work_item_NA9.exit, !dbg !208 ; [debug line = 172:13]

_Z21async_work_grou751.rexit.i.i:                 ; preds = %.rentry749.rentry.i.i
  %449 = add nsw i32 %y3.0.reg2mem641.0.i.i, 1, !dbg !210 ; [#uses=1 type=i32] [debug line = 175:9]
  %450 = mul nsw i32 %449, %szrow.0.reg2mem.0.i.i, !dbg !210 ; [#uses=1 type=i32] [debug line = 175:9]
  %.reg2mem343.0.i.i = sext i32 %450 to i64, !dbg !210 ; [#uses=2 type=i64] [debug line = 175:9]
  %bus_addr257.i.i = lshr i64 %.reg2mem343.0.i.i, 2 ; [#uses=1 type=i64]
  %.081.reg2mem.0.i.i = getelementptr i32 addrspace(1)* %arg_in_pixels.i.0, i64 %bus_addr257.i.i ; [#uses=2 type=i32 addrspace(1)*]
  %.080.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !210 ; [#uses=1 type=i64] [debug line = 175:9]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %.081.reg2mem.0.i.i, i32 addrspace(1)* %arg_in_pixels.i.0, i64 %.reg2mem343.0.i.i, i64 1) nounwind
  %CI269.i.i = bitcast i32 addrspace(1)* %.081.reg2mem.0.i.i to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2 to i8*), i8* %CI269.i.i, i64 %.080.reg2mem.0.i.i, i32 1, i1 false) nounwind
  br label %451, !dbg !212                        ; [debug line = 182:14]

; <label>:451                                     ; preds = %_Z4sqrtf.exit95.i.i, %_Z21async_work_grou751.rexit.i.i
  %x4.0.reg2mem639.0.i.i = phi i32 [ 1, %_Z21async_work_grou751.rexit.i.i ], [ %.reg2mem176.0.i.i, %_Z4sqrtf.exit95.i.i ] ; [#uses=9 type=i32]
  %452 = add nsw i32 %arg_width.i.0, -1, !dbg !212 ; [#uses=1 type=i32] [debug line = 182:14]
  %453 = icmp slt i32 %x4.0.reg2mem639.0.i.i, %452, !dbg !212 ; [#uses=1 type=i1] [debug line = 182:14]
  br i1 %453, label %454, label %_Z21async_work_grou753.rexit.i.i, !dbg !212 ; [debug line = 182:14]

; <label>:454                                     ; preds = %451
  call spir_func void (...)* @_ssdm_RegionBegin(i8* getelementptr inbounds ([13 x i8]* @hls_region7, i64 0, i64 0)) nounwind
  call spir_func void (...)* @_ssdm_op_SpecPipeline(i32 1, i32 1, i32 1, i32 0, i8* getelementptr inbounds ([13 x i8]* @hls_region7, i64 0, i64 0)) nounwind
  br label %455, !dbg !214                        ; [debug line = 189:16]

; <label>:455                                     ; preds = %457, %454
  %sumx.1.reg2mem637.0.i.i = phi i16 [ 0, %454 ], [ %.reg2mem315.0.i.i, %457 ] ; [#uses=3 type=i16]
  %sumy.1.reg2mem635.0.i.i = phi i16 [ 0, %454 ], [ %.reg2mem313.0.i.i, %457 ] ; [#uses=3 type=i16]
  %i5.0.reg2mem633.0.i.i = phi i32 [ -1, %454 ], [ %.reg2mem311.0.i.i, %457 ] ; [#uses=14 type=i32]
  %456 = icmp slt i32 %i5.0.reg2mem633.0.i.i, 2, !dbg !214 ; [#uses=1 type=i1] [debug line = 189:16]
  br i1 %456, label %457, label %._crit_edge128.i.i, !dbg !214 ; [debug line = 189:16]

; <label>:457                                     ; preds = %455
  %458 = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !217 ; [#uses=1 type=i32] [debug line = 190:17]
  %459 = sext i32 %458 to i64, !dbg !217          ; [#uses=1 type=i64] [debug line = 190:17]
  %460 = getelementptr inbounds [3 x [3 x i32]]* %GX.i.i, i64 0, i64 %459, i64 0, !dbg !217 ; [#uses=1 type=i32*] [debug line = 190:17]
  %461 = load i32* %460, align 4, !dbg !217       ; [#uses=1 type=i32] [debug line = 190:17]
  %462 = add nsw i32 %x4.0.reg2mem639.0.i.i, %i5.0.reg2mem633.0.i.i, !dbg !217 ; [#uses=1 type=i32] [debug line = 190:17]
  %463 = sext i32 %462 to i64, !dbg !217          ; [#uses=1 type=i64] [debug line = 190:17]
  %464 = getelementptr inbounds i8 addrspace(3)* %prow0.1.reg2mem645.0.i.i, i64 %463, !dbg !217 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 190:17]
  %465 = load i8 addrspace(3)* %464, align 1, !dbg !217 ; [#uses=1 type=i8] [debug line = 190:17]
  %466 = trunc i32 %461 to i16, !dbg !217         ; [#uses=1 type=i16] [debug line = 190:17]
  %467 = zext i8 %465 to i16, !dbg !217           ; [#uses=1 type=i16] [debug line = 190:17]
  %468 = mul i16 %466, %467, !dbg !217            ; [#uses=1 type=i16] [debug line = 190:17]
  %469 = add i16 %sumx.1.reg2mem637.0.i.i, %468, !dbg !217 ; [#uses=1 type=i16] [debug line = 190:17]
  %470 = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !219 ; [#uses=1 type=i32] [debug line = 191:17]
  %471 = sext i32 %470 to i64, !dbg !219          ; [#uses=1 type=i64] [debug line = 191:17]
  %472 = getelementptr inbounds [3 x [3 x i32]]* %GX.i.i, i64 0, i64 %471, i64 1, !dbg !219 ; [#uses=1 type=i32*] [debug line = 191:17]
  %473 = load i32* %472, align 4, !dbg !219       ; [#uses=1 type=i32] [debug line = 191:17]
  %474 = add nsw i32 %x4.0.reg2mem639.0.i.i, %i5.0.reg2mem633.0.i.i, !dbg !219 ; [#uses=1 type=i32] [debug line = 191:17]
  %475 = sext i32 %474 to i64, !dbg !219          ; [#uses=1 type=i64] [debug line = 191:17]
  %476 = getelementptr inbounds i8 addrspace(3)* %prow1.1.reg2mem643.0.i.i, i64 %475, !dbg !219 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 191:17]
  %477 = load i8 addrspace(3)* %476, align 1, !dbg !219 ; [#uses=1 type=i8] [debug line = 191:17]
  %478 = trunc i32 %473 to i16, !dbg !219         ; [#uses=1 type=i16] [debug line = 191:17]
  %479 = zext i8 %477 to i16, !dbg !219           ; [#uses=1 type=i16] [debug line = 191:17]
  %480 = mul i16 %478, %479, !dbg !219            ; [#uses=1 type=i16] [debug line = 191:17]
  %481 = add i16 %469, %480, !dbg !219            ; [#uses=1 type=i16] [debug line = 191:17]
  %482 = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !220 ; [#uses=1 type=i32] [debug line = 192:17]
  %483 = sext i32 %482 to i64, !dbg !220          ; [#uses=1 type=i64] [debug line = 192:17]
  %484 = getelementptr inbounds [3 x [3 x i32]]* %GX.i.i, i64 0, i64 %483, i64 2, !dbg !220 ; [#uses=1 type=i32*] [debug line = 192:17]
  %485 = load i32* %484, align 4, !dbg !220       ; [#uses=1 type=i32] [debug line = 192:17]
  %486 = add nsw i32 %x4.0.reg2mem639.0.i.i, %i5.0.reg2mem633.0.i.i, !dbg !220 ; [#uses=1 type=i32] [debug line = 192:17]
  %487 = sext i32 %486 to i64, !dbg !220          ; [#uses=1 type=i64] [debug line = 192:17]
  %488 = getelementptr inbounds [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2, i64 0, i64 %487, !dbg !220 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 192:17]
  %489 = load i8 addrspace(3)* %488, align 1, !dbg !220 ; [#uses=1 type=i8] [debug line = 192:17]
  %490 = trunc i32 %485 to i16, !dbg !220         ; [#uses=1 type=i16] [debug line = 192:17]
  %491 = zext i8 %489 to i16, !dbg !220           ; [#uses=1 type=i16] [debug line = 192:17]
  %492 = mul i16 %490, %491, !dbg !220            ; [#uses=1 type=i16] [debug line = 192:17]
  %.reg2mem315.0.i.i = add i16 %481, %492, !dbg !220 ; [#uses=1 type=i16] [debug line = 192:17]
  %493 = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !221 ; [#uses=1 type=i32] [debug line = 194:17]
  %494 = sext i32 %493 to i64, !dbg !221          ; [#uses=1 type=i64] [debug line = 194:17]
  %495 = getelementptr inbounds [3 x [3 x i32]]* %GY.i.i, i64 0, i64 %494, i64 0, !dbg !221 ; [#uses=1 type=i32*] [debug line = 194:17]
  %496 = load i32* %495, align 4, !dbg !221       ; [#uses=1 type=i32] [debug line = 194:17]
  %497 = add nsw i32 %x4.0.reg2mem639.0.i.i, %i5.0.reg2mem633.0.i.i, !dbg !221 ; [#uses=1 type=i32] [debug line = 194:17]
  %498 = sext i32 %497 to i64, !dbg !221          ; [#uses=1 type=i64] [debug line = 194:17]
  %499 = getelementptr inbounds i8 addrspace(3)* %prow0.1.reg2mem645.0.i.i, i64 %498, !dbg !221 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 194:17]
  %500 = load i8 addrspace(3)* %499, align 1, !dbg !221 ; [#uses=1 type=i8] [debug line = 194:17]
  %501 = trunc i32 %496 to i16, !dbg !221         ; [#uses=1 type=i16] [debug line = 194:17]
  %502 = zext i8 %500 to i16, !dbg !221           ; [#uses=1 type=i16] [debug line = 194:17]
  %503 = mul i16 %501, %502, !dbg !221            ; [#uses=1 type=i16] [debug line = 194:17]
  %504 = add i16 %sumy.1.reg2mem635.0.i.i, %503, !dbg !221 ; [#uses=1 type=i16] [debug line = 194:17]
  %505 = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !222 ; [#uses=1 type=i32] [debug line = 195:17]
  %506 = sext i32 %505 to i64, !dbg !222          ; [#uses=1 type=i64] [debug line = 195:17]
  %507 = getelementptr inbounds [3 x [3 x i32]]* %GY.i.i, i64 0, i64 %506, i64 1, !dbg !222 ; [#uses=1 type=i32*] [debug line = 195:17]
  %508 = load i32* %507, align 4, !dbg !222       ; [#uses=1 type=i32] [debug line = 195:17]
  %509 = add nsw i32 %x4.0.reg2mem639.0.i.i, %i5.0.reg2mem633.0.i.i, !dbg !222 ; [#uses=1 type=i32] [debug line = 195:17]
  %510 = sext i32 %509 to i64, !dbg !222          ; [#uses=1 type=i64] [debug line = 195:17]
  %511 = getelementptr inbounds i8 addrspace(3)* %prow1.1.reg2mem643.0.i.i, i64 %510, !dbg !222 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 195:17]
  %512 = load i8 addrspace(3)* %511, align 1, !dbg !222 ; [#uses=1 type=i8] [debug line = 195:17]
  %513 = trunc i32 %508 to i16, !dbg !222         ; [#uses=1 type=i16] [debug line = 195:17]
  %514 = zext i8 %512 to i16, !dbg !222           ; [#uses=1 type=i16] [debug line = 195:17]
  %515 = mul i16 %513, %514, !dbg !222            ; [#uses=1 type=i16] [debug line = 195:17]
  %516 = add i16 %504, %515, !dbg !222            ; [#uses=1 type=i16] [debug line = 195:17]
  %517 = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !223 ; [#uses=1 type=i32] [debug line = 196:17]
  %518 = sext i32 %517 to i64, !dbg !223          ; [#uses=1 type=i64] [debug line = 196:17]
  %519 = getelementptr inbounds [3 x [3 x i32]]* %GY.i.i, i64 0, i64 %518, i64 2, !dbg !223 ; [#uses=1 type=i32*] [debug line = 196:17]
  %520 = load i32* %519, align 4, !dbg !223       ; [#uses=1 type=i32] [debug line = 196:17]
  %521 = add nsw i32 %x4.0.reg2mem639.0.i.i, %i5.0.reg2mem633.0.i.i, !dbg !223 ; [#uses=1 type=i32] [debug line = 196:17]
  %522 = sext i32 %521 to i64, !dbg !223          ; [#uses=1 type=i64] [debug line = 196:17]
  %523 = getelementptr inbounds [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2, i64 0, i64 %522, !dbg !223 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 196:17]
  %524 = load i8 addrspace(3)* %523, align 1, !dbg !223 ; [#uses=1 type=i8] [debug line = 196:17]
  %525 = trunc i32 %520 to i16, !dbg !223         ; [#uses=1 type=i16] [debug line = 196:17]
  %526 = zext i8 %524 to i16, !dbg !223           ; [#uses=1 type=i16] [debug line = 196:17]
  %527 = mul i16 %525, %526, !dbg !223            ; [#uses=1 type=i16] [debug line = 196:17]
  %.reg2mem313.0.i.i = add i16 %516, %527, !dbg !223 ; [#uses=1 type=i16] [debug line = 196:17]
  %.reg2mem311.0.i.i = add nsw i32 %i5.0.reg2mem633.0.i.i, 1, !dbg !224 ; [#uses=1 type=i32] [debug line = 189:24]
  br label %455, !dbg !224                        ; [debug line = 189:24]

._crit_edge128.i.i:                               ; preds = %455
  %528 = zext i16 %sumx.1.reg2mem637.0.i.i to i32, !dbg !225 ; [#uses=1 type=i32] [debug line = 200:19]
  %529 = zext i16 %sumx.1.reg2mem637.0.i.i to i32, !dbg !225 ; [#uses=1 type=i32] [debug line = 200:19]
  %530 = mul nsw i32 %528, %529, !dbg !225        ; [#uses=1 type=i32] [debug line = 200:19]
  %531 = sitofp i32 %530 to float, !dbg !225      ; [#uses=1 type=float] [debug line = 200:19]
  %532 = zext i16 %sumy.1.reg2mem635.0.i.i to i32, !dbg !225 ; [#uses=1 type=i32] [debug line = 200:19]
  %533 = zext i16 %sumy.1.reg2mem635.0.i.i to i32, !dbg !225 ; [#uses=1 type=i32] [debug line = 200:19]
  %534 = mul nsw i32 %532, %533, !dbg !225        ; [#uses=1 type=i32] [debug line = 200:19]
  %535 = sitofp i32 %534 to float, !dbg !225      ; [#uses=1 type=float] [debug line = 200:19]
  %.reg2mem163.0.reg2mem.0.i.i = fadd float %531, %535, !dbg !225 ; [#uses=9 type=float] [debug line = 200:19]
  call spir_func void @_ZN15sw_em_force_ftzC1Ev(%class.sw_em_force_ftz* %fftz.i.i.i65.i.i) nounwind
  %536 = getelementptr inbounds %union.anon.0* %x.i.i.i.i.i61.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem163.0.reg2mem.0.i.i, float* %536, align 4
  %537 = bitcast %union.anon.0* %x.i.i.i.i.i61.i.i to i32* ; [#uses=1 type=i32*]
  %538 = load i32* %537, align 4                  ; [#uses=2 type=i32]
  %.095.0.i.i = and i32 %538, 2139095040          ; [#uses=1 type=i32]
  %.094.0.reg2mem.0.i.i = and i32 %538, 8388607   ; [#uses=1 type=i32]
  %539 = icmp ne i32 %.095.0.i.i, 2139095040      ; [#uses=1 type=i1]
  %540 = icmp eq i32 %.094.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  %or.cond886.i.i = or i1 %539, %540              ; [#uses=1 type=i1]
  %or.cond886.not.i.i = xor i1 %or.cond886.i.i, true ; [#uses=1 type=i1]
  %541 = fcmp olt float %.reg2mem163.0.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  %or.cond887.i.i = or i1 %or.cond886.not.i.i, %541 ; [#uses=1 type=i1]
  br i1 %or.cond887.i.i, label %_Z4sqrtf.exit95.i.i, label %._crit_edge132.i.i

._crit_edge132.i.i:                               ; preds = %._crit_edge128.i.i
  %542 = getelementptr inbounds %union.anon.0* %x.i.i1.i.i.i57.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem163.0.reg2mem.0.i.i, float* %542, align 4
  %543 = bitcast %union.anon.0* %x.i.i1.i.i.i57.i.i to i32* ; [#uses=1 type=i32*]
  %544 = load i32* %543, align 4                  ; [#uses=2 type=i32]
  %.0100.0.i.i = and i32 %544, 2139095040         ; [#uses=1 type=i32]
  %.0101.0.reg2mem.0.i.i = and i32 %544, 8388607  ; [#uses=1 type=i32]
  %545 = icmp eq i32 %.0100.0.i.i, 2139095040     ; [#uses=1 type=i1]
  %546 = icmp eq i32 %.0101.0.reg2mem.0.i.i, 0    ; [#uses=1 type=i1]
  %or.cond888.i.i = and i1 %545, %546             ; [#uses=1 type=i1]
  br i1 %or.cond888.i.i, label %hls_isinf.exit.i.i.i84.i.i, label %._crit_edge135.i.i

._crit_edge135.i.i:                               ; preds = %._crit_edge132.i.i
  %547 = fcmp une float %.reg2mem163.0.reg2mem.0.i.i, 0.000000e+00 ; [#uses=0 type=i1]
  %548 = fcmp oeq float %.reg2mem163.0.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  br i1 %548, label %_Z4sqrtf.exit95.i.i, label %._crit_edge141.i.i

hls_isinf.exit.i.i.i84.i.i:                       ; preds = %._crit_edge132.i.i
  br label %_Z4sqrtf.exit95.i.i

._crit_edge141.i.i:                               ; preds = %._crit_edge135.i.i
  %549 = getelementptr inbounds %union.anon.0* %x.i19.i.i.i8.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem163.0.reg2mem.0.i.i, float* %549, align 4
  %550 = bitcast %union.anon.0* %x.i19.i.i.i8.i.i to i32* ; [#uses=1 type=i32*]
  %551 = load i32* %550, align 4                  ; [#uses=2 type=i32]
  %552 = lshr i32 %551, 23                        ; [#uses=1 type=i32]
  %.049.0.reg2mem.0.i.i = and i32 %552, 255       ; [#uses=2 type=i32]
  %.reg2mem294.0.i.i = and i32 %551, 8388607      ; [#uses=2 type=i32]
  %553 = icmp eq i32 %.049.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  %.reg2mem292.0.i.i = or i32 %.reg2mem294.0.i.i, 8388608 ; [#uses=1 type=i32]
  %.048.0.reg2mem.0.i.i = select i1 %553, i32 %.reg2mem294.0.i.i, i32 %.reg2mem292.0.i.i ; [#uses=2 type=i32]
  %xe.i.i.i70.0.reg2mem.0.i.i = add nsw i32 %.049.0.reg2mem.0.i.i, 386 ; [#uses=1 type=i32]
  %xm.i.i.i71.0.reg2mem.0.i.i = zext i32 %.048.0.reg2mem.0.i.i to i64 ; [#uses=1 type=i64]
  %554 = icmp eq i32 %.048.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  br i1 %554, label %555, label %556

; <label>:555                                     ; preds = %._crit_edge141.i.i
  br label %_Z4sqrtf.exit95.i.i

; <label>:556                                     ; preds = %._crit_edge141.i.i
  %.reg2mem288.0.i.i = shl i64 %xm.i.i.i71.0.reg2mem.0.i.i, 38 ; [#uses=1 type=i64]
  store i64 4611686018427387904, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 0), align 8
  store i64 2697663385880076776, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 1), align 8
  store i64 1484631294131014398, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 2), align 8
  store i64 783640753332765648, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 3), align 8
  store i64 403351162126124447, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 4), align 8
  store i64 204731739545776358, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 5), align 8
  store i64 103153330606121625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 6), align 8
  store i64 51776576860734092, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 7), align 8
  store i64 25938654877364701, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 8), align 8
  store i64 12981968116705994, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 9), align 8
  store i64 6494150392542292, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 10), align 8
  store i64 3247867552377826, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 11), align 8
  store i64 1624131961909234, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 12), align 8
  store i64 812115539479148, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 13), align 8
  store i64 406070160882998, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 14), align 8
  store i64 203038178416421, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 15), align 8
  store i64 101519863725577, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 16), align 8
  store i64 50760125495084, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 17), align 8
  store i64 25380111155985, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 18), align 8
  store i64 12690067680150, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 19), align 8
  store i64 6345036865620, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 20), align 8
  store i64 3172519189197, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 21), align 8
  store i64 1586259783695, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 22), align 8
  store i64 793129939122, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 23), align 8
  store i64 396564981379, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 24), align 8
  store i64 198282493644, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 25), align 8
  store i64 99141247561, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 26), align 8
  store i64 49570623965, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 27), align 8
  store i64 24785312029, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 28), align 8
  store i64 12392656026, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 29), align 8
  store i64 6196328016, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 30), align 8
  store i64 3098164009, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 31), align 8
  store i64 1549082004, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 32), align 8
  store i64 774541002, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 33), align 8
  store i64 387270501, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 34), align 8
  store i64 193635251, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 35), align 8
  store i64 96817625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 36), align 8
  store i64 48408813, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 37), align 8
  store i64 24204406, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 38), align 8
  store i64 12102203, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 39), align 8
  store i64 6051102, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 40), align 8
  store i64 3025551, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 41), align 8
  store i64 1512775, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 42), align 8
  store i64 756388, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 43), align 8
  store i64 378194, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 44), align 8
  store i64 189097, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 45), align 8
  store i64 94548, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 46), align 8
  br label %557

; <label>:557                                     ; preds = %_ZL16hls_leading_on752.i.i, %556
  %.042.reg2mem627.0.i.i = phi i64 [ %.reg2mem288.0.i.i, %556 ], [ %.143.reg2mem615.0.i.i, %_ZL16hls_leading_on752.i.i ] ; [#uses=5 type=i64]
  %log2xm.i.i.i72.0.reg2mem625.0.i.i = phi i64 [ 0, %556 ], [ %y.i17.i.i.i11.1.reg2mem613.0.i.i, %_ZL16hls_leading_on752.i.i ] ; [#uses=3 type=i64]
  %i.i18.i.i.i12.0.reg2mem623.0.i.i = phi i32 [ 0, %556 ], [ %.reg2mem268.0.i.i, %_ZL16hls_leading_on752.i.i ] ; [#uses=2 type=i32]
  %558 = icmp slt i32 %i.i18.i.i.i12.0.reg2mem623.0.i.i, 47 ; [#uses=1 type=i1]
  br i1 %558, label %559, label %hls_log2_frac.exit.i.i.i87.i.i

; <label>:559                                     ; preds = %557
  %560 = and i64 %.042.reg2mem627.0.i.i, 2305843009213693952 ; [#uses=1 type=i64]
  %561 = icmp eq i64 %560, 0                      ; [#uses=1 type=i1]
  br i1 %561, label %_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i, label %562

; <label>:562                                     ; preds = %567, %559
  %mask.i.i.i.i.i9.0.reg2mem621.0.i.i = phi i64 [ %phitmp.reg2mem.0.i.i, %567 ], [ 1152921504606846976, %559 ] ; [#uses=2 type=i64]
  %i.i.i.i.i.i10.0.reg2mem619.0.i.i = phi i32 [ %.reg2mem276.0.i.i, %567 ], [ 2, %559 ] ; [#uses=3 type=i32]
  %563 = icmp slt i32 %i.i.i.i.i.i10.0.reg2mem619.0.i.i, 47 ; [#uses=1 type=i1]
  br i1 %563, label %564, label %._crit_edge145.i.i

; <label>:564                                     ; preds = %562
  %565 = and i64 %.042.reg2mem627.0.i.i, %mask.i.i.i.i.i9.0.reg2mem621.0.i.i ; [#uses=1 type=i64]
  %566 = icmp eq i64 %565, 0                      ; [#uses=1 type=i1]
  br i1 %566, label %._crit_edge145.i.i, label %567

; <label>:567                                     ; preds = %564
  %.reg2mem276.0.i.i = add nsw i32 %i.i.i.i.i.i10.0.reg2mem619.0.i.i, 1 ; [#uses=1 type=i32]
  %phitmp.reg2mem.0.i.i = lshr i64 %mask.i.i.i.i.i9.0.reg2mem621.0.i.i, 1 ; [#uses=1 type=i64]
  br label %562

._crit_edge145.i.i:                               ; preds = %564, %562
  br label %_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i

_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i:        ; preds = %._crit_edge145.i.i, %559
  %.046.reg2mem617.0.i.i = phi i32 [ %i.i.i.i.i.i10.0.reg2mem619.0.i.i, %._crit_edge145.i.i ], [ 47, %559 ] ; [#uses=3 type=i32]
  %568 = icmp slt i32 %.046.reg2mem617.0.i.i, 47  ; [#uses=1 type=i1]
  br i1 %568, label %569, label %_ZL16hls_leading_on752.i.i

; <label>:569                                     ; preds = %_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i
  %570 = zext i32 %.046.reg2mem617.0.i.i to i64   ; [#uses=1 type=i64]
  %571 = ashr i64 %.042.reg2mem627.0.i.i, %570    ; [#uses=1 type=i64]
  %.reg2mem272.0.i.i = add nsw i64 %.042.reg2mem627.0.i.i, %571 ; [#uses=1 type=i64]
  %572 = sext i32 %.046.reg2mem617.0.i.i to i64   ; [#uses=1 type=i64]
  %573 = getelementptr inbounds [47 x i64]* @_ZZL13hls_log2_fracE3pos, i64 0, i64 %572 ; [#uses=1 type=i64*]
  %574 = load i64* %573, align 8                  ; [#uses=1 type=i64]
  %.reg2mem270.0.i.i = sub nsw i64 %log2xm.i.i.i72.0.reg2mem625.0.i.i, %574 ; [#uses=1 type=i64]
  br label %_ZL16hls_leading_on752.i.i

_ZL16hls_leading_on752.i.i:                       ; preds = %569, %_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i
  %.143.reg2mem615.0.i.i = phi i64 [ %.reg2mem272.0.i.i, %569 ], [ %.042.reg2mem627.0.i.i, %_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i ] ; [#uses=1 type=i64]
  %y.i17.i.i.i11.1.reg2mem613.0.i.i = phi i64 [ %.reg2mem270.0.i.i, %569 ], [ %log2xm.i.i.i72.0.reg2mem625.0.i.i, %_ZL16hls_leading_onesx.exit.i.i.i.i86.i.i ] ; [#uses=1 type=i64]
  %.reg2mem268.0.i.i = add nsw i32 %i.i18.i.i.i12.0.reg2mem623.0.i.i, 1 ; [#uses=1 type=i32]
  br label %557

hls_log2_frac.exit.i.i.i87.i.i:                   ; preds = %557
  %575 = zext i32 %xe.i.i.i70.0.reg2mem.0.i.i to i64 ; [#uses=1 type=i64]
  %576 = shl i64 %575, 55                         ; [#uses=1 type=i64]
  %577 = ashr i64 %log2xm.i.i.i72.0.reg2mem625.0.i.i, 7 ; [#uses=1 type=i64]
  %F.i.i.i73.0.i.i = add nsw i64 %576, %577       ; [#uses=1 type=i64]
  %Foy.i.i.i74.0.reg2mem.0.i.i = sdiv i64 %F.i.i.i73.0.i.i, 2 ; [#uses=2 type=i64]
  %578 = shl i64 %Foy.i.i.i74.0.reg2mem.0.i.i, 5  ; [#uses=1 type=i64]
  %FF.i.i.i75.0.reg2mem.0.i.i = and i64 %578, 1152921504606846944 ; [#uses=2 type=i64]
  %579 = getelementptr inbounds %union.anon.0* %x.i.i.i12.i.i.i14.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float 1.000000e+00, float* %579, align 4
  %580 = bitcast %union.anon.0* %x.i.i.i12.i.i.i14.i.i to i32* ; [#uses=1 type=i32*]
  %.reg2mem262.0.i.i = load i32* %580, align 4    ; [#uses=3 type=i32]
  %581 = lshr i32 %.reg2mem262.0.i.i, 23          ; [#uses=1 type=i32]
  %.039.0.reg2mem.0.i.i = and i32 %581, 255       ; [#uses=3 type=i32]
  %.038.0.i.i = and i32 %.reg2mem262.0.i.i, 8388607 ; [#uses=1 type=i32]
  %.reg2mem257.0.i.i = zext i32 %.038.0.i.i to i64 ; [#uses=2 type=i64]
  %582 = icmp eq i32 %.039.0.reg2mem.0.i.i, 0     ; [#uses=1 type=i1]
  %.reg2mem255.0.i.i = or i64 %.reg2mem257.0.i.i, 8388608 ; [#uses=1 type=i64]
  %m.i.i15.i.i.i18.0.reg2mem.0.i.i = select i1 %582, i64 %.reg2mem257.0.i.i, i64 %.reg2mem255.0.i.i ; [#uses=1 type=i64]
  %.reg2mem252.0.i.i = shl nsw i64 %m.i.i15.i.i.i18.0.reg2mem.0.i.i, 36 ; [#uses=2 type=i64]
  %shift.i.i.i.i.i19.0.reg2mem.0.i.i = add i32 %.039.0.reg2mem.0.i.i, -126 ; [#uses=4 type=i32]
  %583 = icmp sgt i32 %shift.i.i.i.i.i19.0.reg2mem.0.i.i, 3 ; [#uses=1 type=i1]
  %584 = icmp slt i32 %shift.i.i.i.i.i19.0.reg2mem.0.i.i, -64 ; [#uses=1 type=i1]
  %or.cond890.i.i = or i1 %583, %584              ; [#uses=1 type=i1]
  br i1 %or.cond890.i.i, label %._crit_edge146.i.i, label %585

; <label>:585                                     ; preds = %hls_log2_frac.exit.i.i.i87.i.i
  %586 = icmp sgt i32 %shift.i.i.i.i.i19.0.reg2mem.0.i.i, 0 ; [#uses=1 type=i1]
  br i1 %586, label %587, label %589

; <label>:587                                     ; preds = %585
  %588 = zext i32 %shift.i.i.i.i.i19.0.reg2mem.0.i.i to i64 ; [#uses=1 type=i64]
  %.reg2mem247.0.i.i = shl i64 %.reg2mem252.0.i.i, %588 ; [#uses=1 type=i64]
  br label %._crit_edge146.i.i

; <label>:589                                     ; preds = %585
  %590 = sub i32 126, %.039.0.reg2mem.0.i.i       ; [#uses=1 type=i32]
  %591 = zext i32 %590 to i64                     ; [#uses=1 type=i64]
  %.reg2mem245.0.i.i = ashr i64 %.reg2mem252.0.i.i, %591 ; [#uses=1 type=i64]
  br label %._crit_edge146.i.i

._crit_edge146.i.i:                               ; preds = %589, %587, %hls_log2_frac.exit.i.i.i87.i.i
  %m.i.i15.i.i.i18.2.reg2mem609.0.i.i = phi i64 [ %.reg2mem247.0.i.i, %587 ], [ %.reg2mem245.0.i.i, %589 ], [ 0, %hls_log2_frac.exit.i.i.i87.i.i ] ; [#uses=2 type=i64]
  %592 = icmp sgt i32 %.reg2mem262.0.i.i, -1      ; [#uses=1 type=i1]
  %.reg2mem242.0.i.i = sub nsw i64 0, %m.i.i15.i.i.i18.2.reg2mem609.0.i.i ; [#uses=1 type=i64]
  %.037.reg2mem607.0.i.i = select i1 %592, i64 %m.i.i15.i.i.i18.2.reg2mem609.0.i.i, i64 %.reg2mem242.0.i.i ; [#uses=1 type=i64]
  store i64 4611686018427387904, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 0), align 8
  store i64 2697663385880076776, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 1), align 8
  store i64 1484631294131014398, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 2), align 8
  store i64 783640753332765648, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 3), align 8
  store i64 403351162126124447, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 4), align 8
  store i64 204731739545776358, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 5), align 8
  store i64 103153330606121625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 6), align 8
  store i64 51776576860734092, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 7), align 8
  store i64 25938654877364701, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 8), align 8
  store i64 12981968116705994, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 9), align 8
  store i64 6494150392542292, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 10), align 8
  store i64 3247867552377826, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 11), align 8
  store i64 1624131961909234, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 12), align 8
  store i64 812115539479148, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 13), align 8
  store i64 406070160882998, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 14), align 8
  store i64 203038178416421, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 15), align 8
  store i64 101519863725577, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 16), align 8
  store i64 50760125495084, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 17), align 8
  store i64 25380111155985, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 18), align 8
  store i64 12690067680150, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 19), align 8
  store i64 6345036865620, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 20), align 8
  store i64 3172519189197, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 21), align 8
  store i64 1586259783695, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 22), align 8
  store i64 793129939122, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 23), align 8
  store i64 396564981379, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 24), align 8
  store i64 198282493644, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 25), align 8
  store i64 99141247561, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 26), align 8
  store i64 49570623965, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 27), align 8
  store i64 24785312029, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 28), align 8
  store i64 12392656026, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 29), align 8
  store i64 6196328016, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 30), align 8
  store i64 3098164009, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 31), align 8
  store i64 1549082004, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 32), align 8
  store i64 774541002, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 33), align 8
  store i64 387270501, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 34), align 8
  store i64 193635251, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 35), align 8
  store i64 96817625, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 36), align 8
  store i64 48408813, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 37), align 8
  store i64 24204406, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 38), align 8
  store i64 12102203, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 39), align 8
  store i64 6051102, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 40), align 8
  store i64 3025551, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 41), align 8
  store i64 1512775, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 42), align 8
  store i64 756388, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 43), align 8
  store i64 378194, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 44), align 8
  store i64 189097, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 45), align 8
  store i64 94548, i64* getelementptr inbounds ([47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 46), align 8
  br label %593

; <label>:593                                     ; preds = %._crit_edge148.i.i, %._crit_edge146.i.i
  %.036.reg2mem605.0.i.i = phi i64 [ %FF.i.i.i75.0.reg2mem.0.i.i, %._crit_edge146.i.i ], [ %.1.reg2mem599.0.i.i, %._crit_edge148.i.i ] ; [#uses=2 type=i64]
  %exp2F.i.i.i76.0.reg2mem603.0.i.i = phi i64 [ %.037.reg2mem607.0.i.i, %._crit_edge146.i.i ], [ %y.i16.i.i.i20.1.reg2mem597.0.i.i, %._crit_edge148.i.i ] ; [#uses=5 type=i64]
  %i.i.i.i.i21.0.reg2mem601.0.i.i = phi i32 [ 1, %._crit_edge146.i.i ], [ %.reg2mem229.0.i.i, %._crit_edge148.i.i ] ; [#uses=4 type=i32]
  %594 = icmp slt i32 %i.i.i.i.i21.0.reg2mem601.0.i.i, 47 ; [#uses=1 type=i1]
  br i1 %594, label %595, label %hls_exp2_frac.exit.i.i.i89.i.i

; <label>:595                                     ; preds = %593
  %596 = sext i32 %i.i.i.i.i21.0.reg2mem601.0.i.i to i64 ; [#uses=1 type=i64]
  %597 = getelementptr inbounds [47 x i64]* @_ZZL13hls_exp2_fracE3pos, i64 0, i64 %596 ; [#uses=1 type=i64*]
  %598 = load i64* %597, align 8                  ; [#uses=1 type=i64]
  %599 = ashr i64 %598, 2                         ; [#uses=1 type=i64]
  %D.i.i.i.i22.0.reg2mem.0.i.i = sub nsw i64 %.036.reg2mem605.0.i.i, %599 ; [#uses=2 type=i64]
  %600 = icmp sgt i64 %D.i.i.i.i22.0.reg2mem.0.i.i, -1 ; [#uses=1 type=i1]
  br i1 %600, label %601, label %._crit_edge148.i.i

; <label>:601                                     ; preds = %595
  %602 = zext i32 %i.i.i.i.i21.0.reg2mem601.0.i.i to i64 ; [#uses=1 type=i64]
  %603 = ashr i64 %exp2F.i.i.i76.0.reg2mem603.0.i.i, %602 ; [#uses=1 type=i64]
  %.reg2mem231.0.i.i = add nsw i64 %exp2F.i.i.i76.0.reg2mem603.0.i.i, %603 ; [#uses=1 type=i64]
  br label %._crit_edge148.i.i

._crit_edge148.i.i:                               ; preds = %601, %595
  %.1.reg2mem599.0.i.i = phi i64 [ %D.i.i.i.i22.0.reg2mem.0.i.i, %601 ], [ %.036.reg2mem605.0.i.i, %595 ] ; [#uses=1 type=i64]
  %y.i16.i.i.i20.1.reg2mem597.0.i.i = phi i64 [ %.reg2mem231.0.i.i, %601 ], [ %exp2F.i.i.i76.0.reg2mem603.0.i.i, %595 ] ; [#uses=1 type=i64]
  %.reg2mem229.0.i.i = add nsw i32 %i.i.i.i.i21.0.reg2mem601.0.i.i, 1 ; [#uses=1 type=i32]
  br label %593

hls_exp2_frac.exit.i.i.i89.i.i:                   ; preds = %593
  %604 = lshr exact i64 %FF.i.i.i75.0.reg2mem.0.i.i, 5 ; [#uses=1 type=i64]
  %605 = sub nsw i64 %Foy.i.i.i74.0.reg2mem.0.i.i, %604 ; [#uses=1 type=i64]
  %FI.i.i.i77.0.reg2mem.0.i.i = ashr i64 %605, 55 ; [#uses=1 type=i64]
  %606 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  store i64 %exp2F.i.i.i76.0.reg2mem603.0.i.i, i64* %606, align 8
  %607 = icmp slt i64 %exp2F.i.i.i76.0.reg2mem603.0.i.i, 0 ; [#uses=1 type=i1]
  br i1 %607, label %608, label %hls_exp2_frac.exit.i.i.i89._crit_edge.i.i

; <label>:608                                     ; preds = %hls_exp2_frac.exit.i.i.i89.i.i
  %609 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %610 = load i64* %609, align 8                  ; [#uses=1 type=i64]
  %611 = sub i64 0, %610                          ; [#uses=1 type=i64]
  %612 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  store i64 %611, i64* %612, align 8
  br label %hls_exp2_frac.exit.i.i.i89._crit_edge.i.i

hls_exp2_frac.exit.i.i.i89._crit_edge.i.i:        ; preds = %608, %hls_exp2_frac.exit.i.i.i89.i.i
  %s.i9.i.i.i25.0.reg2mem595.0.i.i = phi i32 [ -2147483648, %608 ], [ 0, %hls_exp2_frac.exit.i.i.i89.i.i ] ; [#uses=1 type=i32]
  br label %._crit_edge149.i.i

._crit_edge149.i.i:                               ; preds = %._crit_edge150.i.i, %hls_exp2_frac.exit.i.i.i89._crit_edge.i.i
  %e.i10.i.i.i26.0.reg2mem593.0.i.i = phi i32 [ 90, %hls_exp2_frac.exit.i.i.i89._crit_edge.i.i ], [ %.reg2mem216.0.i.i, %._crit_edge150.i.i ] ; [#uses=6 type=i32]
  %fract.i.i.i.i28.0.reg2mem591.0.i.i = phi i32 [ 0, %hls_exp2_frac.exit.i.i.i89._crit_edge.i.i ], [ %.reg2mem220.0.i.i, %._crit_edge150.i.i ] ; [#uses=2 type=i32]
  %rnd.i.i.i.i29.0.reg2mem589.0.i.i = phi i32 [ 0, %hls_exp2_frac.exit.i.i.i89._crit_edge.i.i ], [ %.reg2mem218.0.i.i, %._crit_edge150.i.i ] ; [#uses=2 type=i32]
  %613 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %614 = load i64* %613, align 8                  ; [#uses=1 type=i64]
  %615 = icmp ugt i64 %614, 16777215              ; [#uses=1 type=i1]
  %.reg2mem161.0.reg2mem.0.i.i = icmp ult i32 %e.i10.i.i.i26.0.reg2mem593.0.i.i, 255 ; [#uses=1 type=i1]
  %.reg2mem177.0.reg2mem.0.i.i = select i1 %615, i1 %.reg2mem161.0.reg2mem.0.i.i, i1 false ; [#uses=1 type=i1]
  br i1 %.reg2mem177.0.reg2mem.0.i.i, label %._crit_edge150.i.i, label %622

._crit_edge150.i.i:                               ; preds = %._crit_edge149.i.i
  %616 = icmp eq i32 %fract.i.i.i.i28.0.reg2mem591.0.i.i, 0 ; [#uses=1 type=i1]
  %.reg2mem159.0.reg2mem.0.i.i = icmp ne i32 %rnd.i.i.i.i29.0.reg2mem589.0.i.i, 0 ; [#uses=1 type=i1]
  %.reg2mem175.0.reg2mem.0.i.i = select i1 %616, i1 %.reg2mem159.0.reg2mem.0.i.i, i1 true ; [#uses=1 type=i1]
  %.reg2mem220.0.i.i = zext i1 %.reg2mem175.0.reg2mem.0.i.i to i32 ; [#uses=1 type=i32]
  %617 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %618 = load i64* %617, align 8                  ; [#uses=2 type=i64]
  %619 = trunc i64 %618 to i32                    ; [#uses=1 type=i32]
  %.reg2mem218.0.i.i = and i32 %619, 1            ; [#uses=1 type=i32]
  %.reg2mem216.0.i.i = add i32 %e.i10.i.i.i26.0.reg2mem593.0.i.i, 1 ; [#uses=1 type=i32]
  %620 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %621 = lshr i64 %618, 1                         ; [#uses=1 type=i64]
  store i64 %621, i64* %620, align 8
  br label %._crit_edge149.i.i

; <label>:622                                     ; preds = %._crit_edge149.i.i
  %623 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %624 = load i64* %623, align 8                  ; [#uses=1 type=i64]
  %625 = trunc i64 %624 to i32                    ; [#uses=1 type=i32]
  %odd.i.i.i.i30.0.reg2mem.0.i.i = and i32 %625, 1 ; [#uses=1 type=i32]
  %626 = icmp eq i32 %rnd.i.i.i.i29.0.reg2mem589.0.i.i, 0 ; [#uses=1 type=i1]
  br i1 %626, label %._crit_edge151.i.i, label %627

; <label>:627                                     ; preds = %622
  %628 = icmp eq i32 %fract.i.i.i.i28.0.reg2mem591.0.i.i, 0 ; [#uses=1 type=i1]
  %629 = icmp eq i32 %odd.i.i.i.i30.0.reg2mem.0.i.i, 0 ; [#uses=1 type=i1]
  %or.cond891.i.i = and i1 %628, %629             ; [#uses=1 type=i1]
  br i1 %or.cond891.i.i, label %._crit_edge151.i.i, label %._crit_edge152.i.i

._crit_edge152.i.i:                               ; preds = %627
  %630 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=2 type=i64*]
  %631 = load i64* %630, align 8                  ; [#uses=1 type=i64]
  %632 = add i64 %631, 1                          ; [#uses=2 type=i64]
  store i64 %632, i64* %630, align 8
  %633 = icmp ugt i64 %632, 16777215              ; [#uses=1 type=i1]
  br i1 %633, label %634, label %._crit_edge151.i.i

; <label>:634                                     ; preds = %._crit_edge152.i.i
  %.reg2mem214.0.i.i = add i32 %e.i10.i.i.i26.0.reg2mem593.0.i.i, 1 ; [#uses=1 type=i32]
  %635 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=2 type=i64*]
  %636 = load i64* %635, align 8                  ; [#uses=1 type=i64]
  %637 = lshr i64 %636, 1                         ; [#uses=1 type=i64]
  store i64 %637, i64* %635, align 8
  br label %._crit_edge151.i.i

._crit_edge151.i.i:                               ; preds = %642, %634, %._crit_edge152.i.i, %627, %622
  %e.i10.i.i.i26.3.reg2mem583.0.i.i = phi i32 [ %.reg2mem210.0.i.i, %642 ], [ %e.i10.i.i.i26.0.reg2mem593.0.i.i, %622 ], [ %.reg2mem214.0.i.i, %634 ], [ %e.i10.i.i.i26.0.reg2mem593.0.i.i, %._crit_edge152.i.i ], [ %e.i10.i.i.i26.0.reg2mem593.0.i.i, %627 ] ; [#uses=3 type=i32]
  %638 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %639 = load i64* %638, align 8                  ; [#uses=1 type=i64]
  %640 = and i64 %639, 8388608                    ; [#uses=1 type=i64]
  %641 = icmp eq i64 %640, 0                      ; [#uses=1 type=i1]
  %.reg2mem.0.reg2mem.0.i.i = icmp ne i32 %e.i10.i.i.i26.3.reg2mem583.0.i.i, 0 ; [#uses=1 type=i1]
  %.reg2mem173.0.reg2mem.0.i.i = select i1 %641, i1 %.reg2mem.0.reg2mem.0.i.i, i1 false ; [#uses=1 type=i1]
  br i1 %.reg2mem173.0.reg2mem.0.i.i, label %642, label %hls_fixed_to_float.exit.i.i.i90.i.i

; <label>:642                                     ; preds = %._crit_edge151.i.i
  %.reg2mem210.0.i.i = add i32 %e.i10.i.i.i26.3.reg2mem583.0.i.i, -1 ; [#uses=1 type=i32]
  %643 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=2 type=i64*]
  %644 = load i64* %643, align 8                  ; [#uses=1 type=i64]
  %645 = shl i64 %644, 1                          ; [#uses=1 type=i64]
  store i64 %645, i64* %643, align 8
  br label %._crit_edge151.i.i

hls_fixed_to_float.exit.i.i.i90.i.i:              ; preds = %._crit_edge151.i.i
  %646 = getelementptr inbounds %union.anon.1* %ux.i.i.i.i24.i.i, i64 0, i32 0 ; [#uses=1 type=i64*]
  %647 = load i64* %646, align 8                  ; [#uses=1 type=i64]
  %.033.i.i = trunc i64 %647 to i32               ; [#uses=1 type=i32]
  %648 = shl i32 %e.i10.i.i.i26.3.reg2mem583.0.i.i, 23 ; [#uses=1 type=i32]
  %649 = and i32 %648, 2139095040                 ; [#uses=1 type=i32]
  %650 = or i32 %s.i9.i.i.i25.0.reg2mem595.0.i.i, %649 ; [#uses=1 type=i32]
  %651 = and i32 %.033.i.i, 8388607               ; [#uses=1 type=i32]
  %652 = or i32 %650, %651                        ; [#uses=1 type=i32]
  %653 = bitcast %union.anon* %x.i.i8.i.i.i23.i.i to i32* ; [#uses=1 type=i32*]
  store i32 %652, i32* %653, align 4
  %654 = getelementptr inbounds %union.anon* %x.i.i8.i.i.i23.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.031.reg2mem.0.i.i = load float* %654, align 4 ; [#uses=7 type=float]
  %.0.reg2mem.0.i.i = trunc i64 %FI.i.i.i77.0.reg2mem.0.i.i to i32 ; [#uses=4 type=i32]
  %655 = icmp eq i32 %.0.reg2mem.0.i.i, 0         ; [#uses=1 type=i1]
  %656 = fcmp oeq float %.031.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  %or.cond892.i.i = or i1 %655, %656              ; [#uses=1 type=i1]
  br i1 %or.cond892.i.i, label %hls_fixed_to_float..i.i, label %hls_isfinite.exit.i.i.i.i91.i.i

hls_isfinite.exit.i.i.i.i91.i.i:                  ; preds = %hls_fixed_to_float.exit.i.i.i90.i.i
  %657 = getelementptr inbounds %union.anon.0* %x.i.i.i.i.i.i43.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.031.reg2mem.0.i.i, float* %657, align 4
  %658 = bitcast %union.anon.0* %x.i.i.i.i.i.i43.i.i to i32* ; [#uses=1 type=i32*]
  %659 = load i32* %658, align 4                  ; [#uses=1 type=i32]
  %.06.0.i.i = and i32 %659, 2139095040           ; [#uses=1 type=i32]
  %660 = icmp eq i32 %.06.0.i.i, 2139095040       ; [#uses=1 type=i1]
  %.04.reg2mem.0.i.i = select i1 %660, i1 false, i1 true ; [#uses=1 type=i1]
  br i1 %.04.reg2mem.0.i.i, label %hls_isfinite.exit.i.i.i.i.i92.i.i, label %hls_fixed_to_float..i.i

hls_fixed_to_float..i.i:                          ; preds = %hls_isfinite.exit.i.i.i.i91.i.i, %hls_fixed_to_float.exit.i.i.i90.i.i
  br label %hls_ldexp.exit.i.i.i94.i.i

hls_isfinite.exit.i.i.i.i.i92.i.i:                ; preds = %hls_isfinite.exit.i.i.i.i91.i.i
  %661 = getelementptr inbounds %union.anon.0* %x.i.i2.i.i.i.i36.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.031.reg2mem.0.i.i, float* %661, align 4
  %662 = bitcast %union.anon.0* %x.i.i2.i.i.i.i36.i.i to i32* ; [#uses=1 type=i32*]
  %.reg2mem198.0.i.i = load i32* %662, align 4    ; [#uses=2 type=i32]
  %663 = lshr i32 %.reg2mem198.0.i.i, 23          ; [#uses=1 type=i32]
  %.020.0.reg2mem.0.i.i = and i32 %663, 255       ; [#uses=1 type=i32]
  %664 = getelementptr inbounds %union.anon.0* %x.i.i.i.i.i.i.i31.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.031.reg2mem.0.i.i, float* %664, align 4
  %665 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i31.i.i to i32* ; [#uses=1 type=i32*]
  %666 = load i32* %665, align 4                  ; [#uses=1 type=i32]
  %.029.0.i.i = and i32 %666, 2139095040          ; [#uses=1 type=i32]
  %667 = icmp eq i32 %.029.0.i.i, 2139095040      ; [#uses=1 type=i1]
  %.027.reg2mem.0.i.i = select i1 %667, i1 false, i1 true ; [#uses=1 type=i1]
  %.027.reg2mem.0.not.i.i = xor i1 %.027.reg2mem.0.i.i, true ; [#uses=1 type=i1]
  %668 = fcmp oeq float %.031.reg2mem.0.i.i, 0.000000e+00 ; [#uses=1 type=i1]
  %or.cond893.i.i = or i1 %.027.reg2mem.0.not.i.i, %668 ; [#uses=1 type=i1]
  br i1 %or.cond893.i.i, label %hls_frexp.exit.i.i.i.i93.i.i, label %669

; <label>:669                                     ; preds = %hls_isfinite.exit.i.i.i.i.i92.i.i
  %.reg2mem196.0.i.i = add nsw i32 %.020.0.reg2mem.0.i.i, -126 ; [#uses=1 type=i32]
  %670 = and i32 %.reg2mem198.0.i.i, -2139095041  ; [#uses=1 type=i32]
  %671 = or i32 %670, 1056964608                  ; [#uses=1 type=i32]
  %672 = bitcast %union.anon* %x.i1.i.i.i.i.i35.i.i to i32* ; [#uses=1 type=i32*]
  store i32 %671, i32* %672, align 4
  %673 = getelementptr inbounds %union.anon* %x.i1.i.i.i.i.i35.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.reg2mem194.0.i.i = load float* %673, align 4  ; [#uses=1 type=float]
  br label %hls_frexp.exit.i.i.i.i93.i.i

hls_frexp.exit.i.i.i.i93.i.i:                     ; preds = %669, %hls_isfinite.exit.i.i.i.i.i92.i.i
  %.016.0.reg2mem581.0.i.i = phi i32 [ %.reg2mem196.0.i.i, %669 ], [ 0, %hls_isfinite.exit.i.i.i.i.i92.i.i ] ; [#uses=1 type=i32]
  %.018.reg2mem.0.i.i = phi float [ %.reg2mem194.0.i.i, %669 ], [ %.031.reg2mem.0.i.i, %hls_isfinite.exit.i.i.i.i.i92.i.i ] ; [#uses=1 type=float]
  %674 = getelementptr inbounds %union.anon.0* %x.i1.i.i.i.i41.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.018.reg2mem.0.i.i, float* %674, align 4
  %675 = bitcast %union.anon.0* %x.i1.i.i.i.i41.i.i to i32* ; [#uses=1 type=i32*]
  %.reg2mem191.0.i.i = load i32* %675, align 4    ; [#uses=2 type=i32]
  %.012.0.reg2mem.0.i.i = and i32 %.reg2mem191.0.i.i, 8388607 ; [#uses=1 type=i32]
  %676 = icmp sgt i32 %.0.reg2mem.0.i.i, 279      ; [#uses=1 type=i1]
  br i1 %676, label %681, label %677

; <label>:677                                     ; preds = %hls_frexp.exit.i.i.i.i93.i.i
  %678 = icmp slt i32 %.0.reg2mem.0.i.i, -279     ; [#uses=1 type=i1]
  br i1 %678, label %681, label %679

; <label>:679                                     ; preds = %677
  %680 = add nsw i32 %.016.0.reg2mem581.0.i.i, %.0.reg2mem.0.i.i ; [#uses=1 type=i32]
  %.reg2mem189.0.i.i = add nsw i32 %680, -1       ; [#uses=1 type=i32]
  br label %681

; <label>:681                                     ; preds = %679, %677, %hls_frexp.exit.i.i.i.i93.i.i
  %ye.i.i.i.i54.1.reg2mem577.0.i.i = phi i32 [ 128, %hls_frexp.exit.i.i.i.i93.i.i ], [ %.reg2mem189.0.i.i, %679 ], [ -151, %677 ] ; [#uses=3 type=i32]
  %682 = icmp slt i32 %ye.i.i.i.i54.1.reg2mem577.0.i.i, -126 ; [#uses=1 type=i1]
  br i1 %682, label %685, label %683

; <label>:683                                     ; preds = %681
  %684 = icmp sgt i32 %ye.i.i.i.i54.1.reg2mem577.0.i.i, 127 ; [#uses=2 type=i1]
  %.reg2mem185.0.i.i = add nsw i32 %ye.i.i.i.i54.1.reg2mem577.0.i.i, 127 ; [#uses=1 type=i32]
  %m.i7.i.i.i53.0.reg2mem575.0.i.i = select i1 %684, i32 0, i32 %.012.0.reg2mem.0.i.i ; [#uses=1 type=i32]
  %e.i6.i.i.i52.0.reg2mem573.0.i.i = select i1 %684, i32 255, i32 %.reg2mem185.0.i.i ; [#uses=1 type=i32]
  br label %685

; <label>:685                                     ; preds = %683, %681
  %m.i7.i.i.i53.1.reg2mem.0.i.i = phi i32 [ %m.i7.i.i.i53.0.reg2mem575.0.i.i, %683 ], [ 0, %681 ] ; [#uses=1 type=i32]
  %e.i6.i.i.i52.1.reg2mem.0.i.i = phi i32 [ %e.i6.i.i.i52.0.reg2mem573.0.i.i, %683 ], [ 0, %681 ] ; [#uses=1 type=i32]
  %686 = and i32 %.reg2mem191.0.i.i, -2147483648  ; [#uses=1 type=i32]
  %687 = shl i32 %e.i6.i.i.i52.1.reg2mem.0.i.i, 23 ; [#uses=1 type=i32]
  %688 = and i32 %687, 2139095040                 ; [#uses=1 type=i32]
  %689 = or i32 %686, %688                        ; [#uses=1 type=i32]
  %690 = and i32 %m.i7.i.i.i53.1.reg2mem.0.i.i, 8388607 ; [#uses=1 type=i32]
  %691 = or i32 %689, %690                        ; [#uses=1 type=i32]
  %692 = bitcast %union.anon* %x.i.i5.i.i.i42.i.i to i32* ; [#uses=1 type=i32*]
  store i32 %691, i32* %692, align 4
  %693 = getelementptr inbounds %union.anon* %x.i.i5.i.i.i42.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.reg2mem183.0.i.i = load float* %693, align 4  ; [#uses=1 type=float]
  br label %hls_ldexp.exit.i.i.i94.i.i

hls_ldexp.exit.i.i.i94.i.i:                       ; preds = %685, %hls_fixed_to_float..i.i
  %.02.reg2mem571.0.i.i = phi float [ %.031.reg2mem.0.i.i, %hls_fixed_to_float..i.i ], [ %.reg2mem183.0.i.i, %685 ] ; [#uses=1 type=float]
  %694 = getelementptr inbounds %union.anon.13* %x.i.i.i.i55.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.02.reg2mem571.0.i.i, float* %694, align 4
  %695 = getelementptr inbounds %union.anon.13* %y.i.i.i.i56.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  store float %.reg2mem163.0.reg2mem.0.i.i, float* %695, align 4
  %696 = bitcast %union.anon.13* %x.i.i.i.i55.i.i to i32* ; [#uses=2 type=i32*]
  %697 = load i32* %696, align 4                  ; [#uses=1 type=i32]
  %698 = and i32 %697, 2147483647                 ; [#uses=2 type=i32]
  store i32 %698, i32* %696, align 4
  %699 = bitcast %union.anon.13* %y.i.i.i.i56.i.i to i32* ; [#uses=1 type=i32*]
  %700 = load i32* %699, align 4                  ; [#uses=1 type=i32]
  %701 = and i32 %700, -2147483648                ; [#uses=1 type=i32]
  %702 = bitcast %union.anon.13* %x.i.i.i.i55.i.i to i32* ; [#uses=1 type=i32*]
  %703 = or i32 %698, %701                        ; [#uses=1 type=i32]
  store i32 %703, i32* %702, align 4
  %704 = getelementptr inbounds %union.anon.13* %x.i.i.i.i55.i.i, i64 0, i32 0 ; [#uses=1 type=float*]
  %.reg2mem178.0.i.i = load float* %704, align 4  ; [#uses=1 type=float]
  br label %_Z4sqrtf.exit95.i.i

_Z4sqrtf.exit95.i.i:                              ; preds = %hls_ldexp.exit.i.i.i94.i.i, %555, %hls_isinf.exit.i.i.i84.i.i, %._crit_edge135.i.i, %._crit_edge128.i.i
  %.089.reg2mem.0.i.i = phi float [ %.reg2mem163.0.reg2mem.0.i.i, %hls_isinf.exit.i.i.i84.i.i ], [ 0.000000e+00, %555 ], [ %.reg2mem178.0.i.i, %hls_ldexp.exit.i.i.i94.i.i ], [ %.reg2mem163.0.reg2mem.0.i.i, %._crit_edge135.i.i ], [ 0x7FF8000000000000, %._crit_edge128.i.i ] ; [#uses=1 type=float]
  call spir_func void @_ZN15sw_em_force_ftzD1Ev(%class.sw_em_force_ftz* %fftz.i.i.i65.i.i) nounwind
  %705 = fsub float %.089.reg2mem.0.i.i, %ming.0.reg2mem731.0.i.i, !dbg !226 ; [#uses=1 type=float] [debug line = 203:62]
  %706 = fmul float %705, 2.550000e+02, !dbg !226 ; [#uses=1 type=float] [debug line = 203:62]
  %707 = fsub float %maxg.0.reg2mem729.0.i.i, %ming.0.reg2mem731.0.i.i, !dbg !226 ; [#uses=1 type=float] [debug line = 203:62]
  %708 = fdiv float %706, %707, !dbg !226, !fpmath !227 ; [#uses=1 type=float] [debug line = 203:62]
  %intensity.0.i.i = fptoui float %708 to i8, !dbg !226 ; [#uses=1 type=i8] [debug line = 203:62]
  %709 = xor i8 %intensity.0.i.i, -1, !dbg !228   ; [#uses=1 type=i8] [debug line = 204:13]
  %710 = sext i32 %x4.0.reg2mem639.0.i.i to i64, !dbg !228 ; [#uses=1 type=i64] [debug line = 204:13]
  %711 = getelementptr inbounds [4096 x i8] addrspace(3)* @krnl_sobel.resbuf, i64 0, i64 %710, !dbg !228 ; [#uses=1 type=i8 addrspace(3)*] [debug line = 204:13]
  store i8 %709, i8 addrspace(3)* %711, align 1, !dbg !228 ; [debug line = 204:13]
  %.reg2mem176.0.i.i = add nsw i32 %x4.0.reg2mem639.0.i.i, 1, !dbg !229 ; [#uses=1 type=i32] [debug line = 182:31]
  call spir_func void (...)* @_ssdm_RegionEnd(i8* getelementptr inbounds ([13 x i8]* @hls_region7, i64 0, i64 0)) nounwind
  br label %451, !dbg !229, !xcl.pipeline !230, !xcl.pipeline.N !204 ; [debug line = 182:31]

_Z21async_work_grou753.rexit.i.i:                 ; preds = %451
  %712 = mul nsw i32 %y3.0.reg2mem641.0.i.i, %szrow.0.reg2mem.0.i.i, !dbg !231 ; [#uses=1 type=i32] [debug line = 207:9]
  %.reg2mem173.0.i.i = sext i32 %712 to i64, !dbg !231 ; [#uses=2 type=i64] [debug line = 207:9]
  %bus_addr276.i.i = lshr i64 %.reg2mem173.0.i.i, 2 ; [#uses=1 type=i64]
  %.047.reg2mem.0.i.i = getelementptr i32 addrspace(1)* %arg_out_pixels.i.0, i64 %bus_addr276.i.i ; [#uses=2 type=i32 addrspace(1)*]
  %.055.reg2mem.0.i.i = sext i32 %szrow.0.reg2mem.0.i.i to i64, !dbg !231 ; [#uses=1 type=i64] [debug line = 207:9]
  call spir_func void (...)* @_ssdm_xcl_PointerMap(i32 addrspace(1)* %.047.reg2mem.0.i.i, i32 addrspace(1)* %arg_out_pixels.i.0, i64 %.reg2mem173.0.i.i, i64 1) nounwind
  %CI288.i.i = bitcast i32 addrspace(1)* %.047.reg2mem.0.i.i to i8* ; [#uses=1 type=i8*]
  call spir_func void @llvm.memcpy.p0i8.p0i8.i64(i8* %CI288.i.i, i8* bitcast ([4096 x i8] addrspace(3)* @krnl_sobel.resbuf to i8*), i64 %.055.reg2mem.0.i.i, i32 1, i1 false) nounwind
  %.reg2mem.0.i.i = add nsw i32 %y3.0.reg2mem641.0.i.i, 1, !dbg !232 ; [#uses=1 type=i32] [debug line = 172:31]
  br label %.rentry749.rentry.i.i, !dbg !232      ; [debug line = 172:31]

__AESL_call_work_item_NA9.exit:                   ; preds = %.rentry749.rentry.i.i
  %713 = bitcast %union.anon.0* %x.i19.i.i.i8.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %714 = bitcast %union.anon.0* %x.i.i.i12.i.i.i14.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %715 = bitcast %union.anon* %x.i.i8.i.i.i23.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %716 = bitcast %union.anon.1* %ux.i.i.i.i24.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %717 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i31.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %718 = bitcast %union.anon* %x.i1.i.i.i.i.i35.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %719 = bitcast %union.anon.0* %x.i.i2.i.i.i.i36.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %720 = bitcast %union.anon.0* %x.i1.i.i.i.i41.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %721 = bitcast %union.anon* %x.i.i5.i.i.i42.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %722 = bitcast %union.anon.0* %x.i.i.i.i.i.i43.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %723 = bitcast %union.anon.13* %x.i.i.i.i55.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %724 = bitcast %union.anon.13* %y.i.i.i.i56.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %725 = bitcast %union.anon.0* %x.i.i1.i.i.i57.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %726 = bitcast %union.anon.0* %x.i.i.i.i.i61.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %727 = bitcast %class.sw_em_force_ftz* %fftz.i.i.i65.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %728 = bitcast %union.anon.0* %x.i19.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %729 = bitcast %union.anon.0* %x.i.i.i12.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %730 = bitcast %union.anon* %x.i.i8.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %731 = bitcast %union.anon.1* %ux.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %732 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %733 = bitcast %union.anon* %x.i1.i.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %734 = bitcast %union.anon.0* %x.i.i2.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %735 = bitcast %union.anon.0* %x.i1.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %736 = bitcast %union.anon* %x.i.i5.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %737 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %738 = bitcast %union.anon.13* %x.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %739 = bitcast %union.anon.13* %y.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %740 = bitcast %union.anon.0* %x.i.i1.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %741 = bitcast %union.anon.0* %x.i.i.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %742 = bitcast %class.sw_em_force_ftz* %fftz.i.i.i.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %743 = bitcast [3 x [3 x i32]]* %GX.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %744 = bitcast [3 x [3 x i32]]* %GY.i.i to i8*, !dbg !233 ; [#uses=0 type=i8*] [debug line = 215:1]
  %745 = bitcast %struct.__spir_rt_info_tT* %.cast.i to i8*, !dbg !234 ; [#uses=0 type=i8*] [debug line = 52:3]
  ret void, !dbg !235                             ; [debug line = 69:1]
}

; [#uses=11]
declare void @llvm.dbg.value(metadata, i64, metadata) nounwind readnone

!llvm.dbg.cu = !{!0, !24}
!hls.encrypted.func = !{}
!xcl.libspir = !{!87}
!xcl.reqd_rt_info = !{!88}
!xcl.portmap = !{!89, !91, !93, !94, !95}
!axi4.master.portmap = !{!96}
!xcl.portlist = !{!90, !92}
!xcl.lmem_info = !{!97, !98, !99, !100}
!xcl.progvar_info = !{}

!0 = metadata !{i32 786449, i32 0, i32 12, metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/solution_OCL_REGION_0/.autopilot/db/krnl_sobelfilter_pipelined_asyncmem.pragma.2.cl", metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !3, metadata !14} ; [ DW_TAG_compile_unit ]
!1 = metadata !{metadata !2}
!2 = metadata !{i32 0}
!3 = metadata !{metadata !4}
!4 = metadata !{metadata !5}
!5 = metadata !{i32 786478, i32 0, metadata !6, metadata !"krnl_sobel", metadata !"krnl_sobel", metadata !"", metadata !6, i32 69, metadata !7, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !12, i32 70} ; [ DW_TAG_subprogram ]
!6 = metadata !{i32 786473, metadata !"/proj/picasso/pourya/playground/edge_detection/src/krnl_sobelfilter_pipelined_asyncmem.cl", metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel", null} ; [ DW_TAG_file_type ]
!7 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !8, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!8 = metadata !{null, metadata !9, metadata !11, metadata !11, metadata !11, metadata !9}
!9 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !10} ; [ DW_TAG_pointer_type ]
!10 = metadata !{i32 786468, null, metadata !"unsigned char", null, i32 0, i64 8, i64 8, i64 0, i32 0, i32 8} ; [ DW_TAG_base_type ]
!11 = metadata !{i32 786468, null, metadata !"int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 5} ; [ DW_TAG_base_type ]
!12 = metadata !{metadata !13}
!13 = metadata !{i32 786468}                      ; [ DW_TAG_base_type ]
!14 = metadata !{metadata !15}
!15 = metadata !{metadata !16, metadata !21, metadata !22, metadata !23}
!16 = metadata !{i32 786484, i32 0, metadata !5, metadata !"rowbuf0", metadata !"rowbuf0", metadata !"", metadata !6, i32 71, metadata !17, i32 1, i32 1, [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf0} ; [ DW_TAG_variable ]
!17 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 32768, i64 8, i32 0, i32 0, metadata !18, metadata !19, i32 0, i32 0} ; [ DW_TAG_array_type ]
!18 = metadata !{i32 786454, null, metadata !"uchar", metadata !6, i32 57, i64 0, i64 0, i64 0, i32 0, metadata !10} ; [ DW_TAG_typedef ]
!19 = metadata !{metadata !20}
!20 = metadata !{i32 786465, i64 0, i64 4095}     ; [ DW_TAG_subrange_type ]
!21 = metadata !{i32 786484, i32 0, metadata !5, metadata !"rowbuf1", metadata !"rowbuf1", metadata !"", metadata !6, i32 72, metadata !17, i32 1, i32 1, [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf1} ; [ DW_TAG_variable ]
!22 = metadata !{i32 786484, i32 0, metadata !5, metadata !"rowbuf2", metadata !"rowbuf2", metadata !"", metadata !6, i32 73, metadata !17, i32 1, i32 1, [4096 x i8] addrspace(3)* @krnl_sobel.rowbuf2} ; [ DW_TAG_variable ]
!23 = metadata !{i32 786484, i32 0, metadata !5, metadata !"resbuf", metadata !"resbuf", metadata !"", metadata !6, i32 74, metadata !17, i32 1, i32 1, [4096 x i8] addrspace(3)* @krnl_sobel.resbuf} ; [ DW_TAG_variable ]
!24 = metadata !{i32 786449, i32 0, i32 4, metadata !"aesl_gen-tmpA.cpp", metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/solution_OCL_REGION_0/.autopilot/db", metadata !"clang version 3.1 ", i1 true, i1 false, metadata !"", i32 0, metadata !1, metadata !1, metadata !25, metadata !83} ; [ DW_TAG_compile_unit ]
!25 = metadata !{metadata !26}
!26 = metadata !{metadata !27, metadata !79, metadata !82}
!27 = metadata !{i32 786478, i32 0, metadata !28, metadata !"__AESL_call_work_item_NA", metadata !"__AESL_call_work_item_NA", metadata !"", metadata !28, i32 44, metadata !29, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !12, i32 45} ; [ DW_TAG_subprogram ]
!28 = metadata !{i32 786473, metadata !"krnl_sobel_compute_unit", metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/solution_OCL_REGION_0/.autopilot/db", null} ; [ DW_TAG_file_type ]
!29 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !30, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!30 = metadata !{null, metadata !31, metadata !34, metadata !63}
!31 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !32} ; [ DW_TAG_pointer_type ]
!32 = metadata !{i32 786485, null, metadata !"", null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !33} ; [ DW_TAG_volatile_type ]
!33 = metadata !{i32 786468, null, metadata !"unsigned int", null, i32 0, i64 32, i64 32, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ]
!34 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !35} ; [ DW_TAG_pointer_type ]
!35 = metadata !{i32 786454, null, metadata !"__spir_rt_info_t", metadata !28, i32 143, i64 0, i64 0, i64 0, i32 0, metadata !36} ; [ DW_TAG_typedef ]
!36 = metadata !{i32 786434, null, metadata !"__spir_rt_info_tT", metadata !37, i32 120, i64 1024, i64 64, i32 0, i32 0, null, metadata !38, i32 0, null, null} ; [ DW_TAG_class_type ]
!37 = metadata !{i32 786473, metadata !"/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/common/technology/autopilot/opencl/libspir_types.h", metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/solution_OCL_REGION_0/.autopilot/db", null} ; [ DW_TAG_file_type ]
!38 = metadata !{metadata !39, metadata !40, metadata !44, metadata !45, metadata !46, metadata !47, metadata !48, metadata !49, metadata !50, metadata !52, metadata !55, metadata !56, metadata !57, metadata !59}
!39 = metadata !{i32 786445, metadata !36, metadata !"work_dim", metadata !37, i32 122, i64 32, i64 32, i64 0, i32 0, metadata !33} ; [ DW_TAG_member ]
!40 = metadata !{i32 786445, metadata !36, metadata !"global_size", metadata !37, i32 124, i64 96, i64 32, i64 32, i32 0, metadata !41} ; [ DW_TAG_member ]
!41 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 96, i64 32, i32 0, i32 0, metadata !33, metadata !42, i32 0, i32 0} ; [ DW_TAG_array_type ]
!42 = metadata !{metadata !43}
!43 = metadata !{i32 786465, i64 0, i64 2}        ; [ DW_TAG_subrange_type ]
!44 = metadata !{i32 786445, metadata !36, metadata !"global_id", metadata !37, i32 125, i64 96, i64 32, i64 128, i32 0, metadata !41} ; [ DW_TAG_member ]
!45 = metadata !{i32 786445, metadata !36, metadata !"local_size", metadata !37, i32 127, i64 96, i64 32, i64 224, i32 0, metadata !41} ; [ DW_TAG_member ]
!46 = metadata !{i32 786445, metadata !36, metadata !"local_id", metadata !37, i32 128, i64 96, i64 32, i64 320, i32 0, metadata !41} ; [ DW_TAG_member ]
!47 = metadata !{i32 786445, metadata !36, metadata !"num_groups", metadata !37, i32 130, i64 96, i64 32, i64 416, i32 0, metadata !41} ; [ DW_TAG_member ]
!48 = metadata !{i32 786445, metadata !36, metadata !"group_id", metadata !37, i32 131, i64 96, i64 32, i64 512, i32 0, metadata !41} ; [ DW_TAG_member ]
!49 = metadata !{i32 786445, metadata !36, metadata !"global_offset", metadata !37, i32 132, i64 96, i64 32, i64 608, i32 0, metadata !41} ; [ DW_TAG_member ]
!50 = metadata !{i32 786445, metadata !36, metadata !"pthread_barrier", metadata !37, i32 135, i64 64, i64 64, i64 704, i32 0, metadata !51} ; [ DW_TAG_member ]
!51 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, null} ; [ DW_TAG_pointer_type ]
!52 = metadata !{i32 786445, metadata !36, metadata !"barriertoscheduler", metadata !37, i32 138, i64 8, i64 8, i64 768, i32 0, metadata !53} ; [ DW_TAG_member ]
!53 = metadata !{i32 786485, null, metadata !"", null, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !54} ; [ DW_TAG_volatile_type ]
!54 = metadata !{i32 786468, null, metadata !"bool", null, i32 0, i64 8, i64 8, i64 0, i32 0, i32 2} ; [ DW_TAG_base_type ]
!55 = metadata !{i32 786445, metadata !36, metadata !"scheduler_context", metadata !37, i32 139, i64 64, i64 64, i64 832, i32 0, metadata !51} ; [ DW_TAG_member ]
!56 = metadata !{i32 786445, metadata !36, metadata !"pe_context", metadata !37, i32 140, i64 64, i64 64, i64 896, i32 0, metadata !51} ; [ DW_TAG_member ]
!57 = metadata !{i32 786445, metadata !36, metadata !"printf_buffer", metadata !37, i32 142, i64 64, i64 64, i64 960, i32 0, metadata !58} ; [ DW_TAG_member ]
!58 = metadata !{i32 786468, null, metadata !"long long unsigned int", null, i32 0, i64 64, i64 64, i64 0, i32 0, i32 7} ; [ DW_TAG_base_type ]
!59 = metadata !{i32 786478, i32 0, metadata !36, metadata !"__spir_rt_info_tT", metadata !"__spir_rt_info_tT", metadata !"", metadata !37, i32 120, metadata !60, i1 false, i1 false, i32 0, i32 0, null, i32 320, i1 false, null, null, i32 0, metadata !12, i32 120} ; [ DW_TAG_subprogram ]
!60 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !61, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!61 = metadata !{null, metadata !62}
!62 = metadata !{i32 786447, i32 0, metadata !"", i32 0, i32 0, i64 64, i64 64, i64 0, i32 64, metadata !36} ; [ DW_TAG_pointer_type ]
!63 = metadata !{i32 786447, null, metadata !"", null, i32 0, i64 64, i64 64, i64 0, i32 0, metadata !64} ; [ DW_TAG_pointer_type ]
!64 = metadata !{i32 786454, null, metadata !"krnl_sobel_args_t", metadata !28, i32 24, i64 0, i64 0, i64 0, i32 0, metadata !65} ; [ DW_TAG_typedef ]
!65 = metadata !{i32 786434, null, metadata !"", metadata !28, i32 17, i64 256, i64 64, i32 0, i32 0, null, metadata !66, i32 0, null, null} ; [ DW_TAG_class_type ]
!66 = metadata !{metadata !67, metadata !69, metadata !70, metadata !71, metadata !72, metadata !73}
!67 = metadata !{i32 786445, metadata !65, metadata !"in_pixels", metadata !28, i32 18, i64 64, i64 64, i64 0, i32 0, metadata !68} ; [ DW_TAG_member ]
!68 = metadata !{i32 786454, null, metadata !"__spir_size_t", metadata !28, i32 110, i64 0, i64 0, i64 0, i32 0, metadata !58} ; [ DW_TAG_typedef ]
!69 = metadata !{i32 786445, metadata !65, metadata !"nchannels", metadata !28, i32 19, i64 32, i64 32, i64 64, i32 0, metadata !33} ; [ DW_TAG_member ]
!70 = metadata !{i32 786445, metadata !65, metadata !"width", metadata !28, i32 20, i64 32, i64 32, i64 96, i32 0, metadata !33} ; [ DW_TAG_member ]
!71 = metadata !{i32 786445, metadata !65, metadata !"height", metadata !28, i32 21, i64 32, i64 32, i64 128, i32 0, metadata !33} ; [ DW_TAG_member ]
!72 = metadata !{i32 786445, metadata !65, metadata !"out_pixels", metadata !28, i32 22, i64 64, i64 64, i64 192, i32 0, metadata !68} ; [ DW_TAG_member ]
!73 = metadata !{i32 786474, metadata !65, null, metadata !28, i32 0, i64 0, i64 0, i64 0, i32 0, metadata !74} ; [ DW_TAG_friend ]
!74 = metadata !{i32 786434, null, metadata !"aesl_keep_name_class", metadata !28, i32 26, i64 8, i64 8, i32 0, i32 0, null, metadata !75, i32 0, null, null} ; [ DW_TAG_class_type ]
!75 = metadata !{metadata !76}
!76 = metadata !{i32 786478, i32 0, metadata !74, metadata !"aesl_keep_name_0_args", metadata !"aesl_keep_name_0_args", metadata !"_ZN20aesl_keep_name_class21aesl_keep_name_0_argsEP17krnl_sobel_args_t", metadata !28, i32 29, metadata !77, i1 false, i1 false, i32 0, i32 0, null, i32 256, i1 false, null, null, i32 0, metadata !12, i32 29} ; [ DW_TAG_subprogram ]
!77 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !78, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!78 = metadata !{null, metadata !63}
!79 = metadata !{i32 786478, i32 0, metadata !28, metadata !"__AESL_work_groupA", metadata !"__AESL_work_groupA", metadata !"", metadata !28, i32 56, metadata !80, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, null, metadata !12, i32 57} ; [ DW_TAG_subprogram ]
!80 = metadata !{i32 786453, i32 0, metadata !"", i32 0, i32 0, i64 0, i64 0, i64 0, i32 0, null, metadata !81, i32 0, i32 0} ; [ DW_TAG_subroutine_type ]
!81 = metadata !{null, metadata !31, metadata !63}
!82 = metadata !{i32 786478, i32 0, null, metadata !"aesl_keep_name_0_args", metadata !"aesl_keep_name_0_args", metadata !"_ZN20aesl_keep_name_class21aesl_keep_name_0_argsEP17krnl_sobel_args_t", metadata !28, i32 29, metadata !77, i1 false, i1 true, i32 0, i32 0, null, i32 256, i1 false, null, null, metadata !76, metadata !12, i32 29} ; [ DW_TAG_subprogram ]
!83 = metadata !{metadata !84}
!84 = metadata !{metadata !85}
!85 = metadata !{i32 786484, i32 0, metadata !79, metadata !"rt_info", metadata !"rt_info", metadata !"", metadata !86, i32 49, metadata !35, i32 1, i32 1, %struct.__spir_rt_info_tT.2* @rt_info} ; [ DW_TAG_variable ]
!86 = metadata !{i32 786473, metadata !"/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/common/technology/autopilot/opencl/aesl_gen_cu_body.inc", metadata !"/proj/picasso/pourya/playground/edge_detection/edgedetection_example/impl/kernels/krnl_sobel/krnl_sobel/solution_OCL_REGION_0/.autopilot/db", null} ; [ DW_TAG_file_type ]
!87 = metadata !{metadata !"/proj/xbuilds/2016.1_sdaccel_daily_latest/installs/lin64/SDAccel/2016.1/Vivado_HLS/lnx64/lib/libspir64-hls.a"}
!88 = metadata !{metadata !"krnl_sobel"}
!89 = metadata !{metadata !"krnl_sobel", i32 0, metadata !90}
!90 = metadata !{metadata !"krnl_sobel", metadata !"gmem", metadata !"addressable", metadata !"master", i32 32}
!91 = metadata !{metadata !"krnl_sobel", i32 1, metadata !92}
!92 = metadata !{metadata !"krnl_sobel", metadata !"control", metadata !"addressable", metadata !"slave", i32 32}
!93 = metadata !{metadata !"krnl_sobel", i32 2, metadata !92}
!94 = metadata !{metadata !"krnl_sobel", i32 3, metadata !92}
!95 = metadata !{metadata !"krnl_sobel", i32 4, metadata !90}
!96 = metadata !{metadata !"gmem", metadata !"in_pixels", metadata !"", metadata !"out_pixels", metadata !""}
!97 = metadata !{metadata !"krnl_sobel", metadata !"krnl_sobel.rowbuf1", i32 4096}
!98 = metadata !{metadata !"krnl_sobel", metadata !"krnl_sobel.rowbuf2", i32 4096}
!99 = metadata !{metadata !"krnl_sobel", metadata !"krnl_sobel.resbuf", i32 4096}
!100 = metadata !{metadata !"krnl_sobel", metadata !"krnl_sobel.rowbuf0", i32 4096}
!101 = metadata !{i32 786689, metadata !79, metadata !"gmem", metadata !28, i32 16777272, metadata !31, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!102 = metadata !{i32 56, i32 84, metadata !79, null}
!103 = metadata !{i32 786689, metadata !79, metadata !"args", metadata !28, i32 33554488, metadata !63, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!104 = metadata !{i32 56, i32 109, metadata !79, null}
!105 = metadata !{i32 786689, metadata !82, metadata !"args", metadata !28, i32 16777245, metadata !63, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!106 = metadata !{i32 29, i32 44, metadata !82, metadata !107}
!107 = metadata !{i32 61, i32 1, metadata !108, null}
!108 = metadata !{i32 786443, metadata !79, i32 57, i32 1, metadata !28, i32 1} ; [ DW_TAG_lexical_block ]
!109 = metadata !{i32 30, i32 5, metadata !110, metadata !107}
!110 = metadata !{i32 786443, metadata !82, i32 29, i32 50, metadata !28, i32 2} ; [ DW_TAG_lexical_block ]
!111 = metadata !{i32 31, i32 5, metadata !110, metadata !107}
!112 = metadata !{i32 32, i32 5, metadata !110, metadata !107}
!113 = metadata !{i32 33, i32 5, metadata !110, metadata !107}
!114 = metadata !{i32 34, i32 5, metadata !110, metadata !107}
!115 = metadata !{i32 62, i32 1, metadata !108, null}
!116 = metadata !{i32 63, i32 1, metadata !108, null}
!117 = metadata !{i32 64, i32 1, metadata !108, null}
!118 = metadata !{i32 46, i32 3, metadata !119, null}
!119 = metadata !{i32 786443, metadata !108, metadata !86} ; [ DW_TAG_lexical_block ]
!120 = metadata !{i32 54, i32 3, metadata !119, null}
!121 = metadata !{i32 63, i32 3, metadata !119, null}
!122 = metadata !{i32 64, i32 3, metadata !119, null}
!123 = metadata !{i32 65, i32 3, metadata !119, null}
!124 = metadata !{i32 70, i32 3, metadata !119, null}
!125 = metadata !{i32 79, i32 3, metadata !119, null}
!126 = metadata !{i32 88, i32 3, metadata !119, null}
!127 = metadata !{i32 103, i32 3, metadata !119, null}
!128 = metadata !{i32 104, i32 3, metadata !119, null}
!129 = metadata !{i32 105, i32 3, metadata !119, null}
!130 = metadata !{i32 114, i32 3, metadata !119, null}
!131 = metadata !{i32 115, i32 3, metadata !119, null}
!132 = metadata !{i32 116, i32 3, metadata !119, null}
!133 = metadata !{i32 125, i32 3, metadata !119, null}
!134 = metadata !{i32 126, i32 3, metadata !119, null}
!135 = metadata !{i32 127, i32 3, metadata !119, null}
!136 = metadata !{i32 136, i32 3, metadata !119, null}
!137 = metadata !{i32 137, i32 3, metadata !119, null}
!138 = metadata !{i32 138, i32 3, metadata !119, null}
!139 = metadata !{i32 147, i32 3, metadata !119, null}
!140 = metadata !{i32 148, i32 3, metadata !119, null}
!141 = metadata !{i32 149, i32 3, metadata !119, null}
!142 = metadata !{i32 786689, metadata !27, metadata !"gmem", metadata !28, i32 16777260, metadata !31, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!143 = metadata !{i32 44, i32 90, metadata !27, null}
!144 = metadata !{%struct.__spir_rt_info_tT.2* @rt_info}
!145 = metadata !{i32 786689, metadata !27, metadata !"rt_info", metadata !28, i32 33554476, metadata !34, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!146 = metadata !{i32 44, i32 114, metadata !27, null}
!147 = metadata !{i32 786689, metadata !27, metadata !"args", metadata !28, i32 50331692, metadata !63, i32 0, i32 0} ; [ DW_TAG_arg_variable ]
!148 = metadata !{i32 44, i32 142, metadata !27, null}
!149 = metadata !{i32 46, i32 126, metadata !150, null}
!150 = metadata !{i32 786443, metadata !27, i32 45, i32 1, metadata !28, i32 0} ; [ DW_TAG_lexical_block ]
!151 = metadata !{i32 786688, metadata !150, metadata !"arg_in_pixels", metadata !28, i32 46, metadata !31, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!152 = metadata !{i32 47, i32 47, metadata !150, null}
!153 = metadata !{i32 786688, metadata !150, metadata !"arg_nchannels", metadata !28, i32 47, metadata !33, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!154 = metadata !{i32 48, i32 39, metadata !150, null}
!155 = metadata !{i32 786688, metadata !150, metadata !"arg_width", metadata !28, i32 48, metadata !33, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!156 = metadata !{i32 49, i32 41, metadata !150, null}
!157 = metadata !{i32 786688, metadata !150, metadata !"arg_height", metadata !28, i32 49, metadata !33, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!158 = metadata !{i32 50, i32 128, metadata !150, null}
!159 = metadata !{i32 786688, metadata !150, metadata !"arg_out_pixels", metadata !28, i32 50, metadata !31, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!160 = metadata !{i32 69, i32 56, metadata !5, null}
!161 = metadata !{i32 786688, metadata !162, metadata !"GX", metadata !6, i32 82, metadata !163, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!162 = metadata !{i32 786443, metadata !5, i32 70, i32 1, metadata !6, i32 0} ; [ DW_TAG_lexical_block ]
!163 = metadata !{i32 786433, null, metadata !"", null, i32 0, i64 288, i64 32, i32 0, i32 0, metadata !11, metadata !164, i32 0, i32 0} ; [ DW_TAG_array_type ]
!164 = metadata !{metadata !43, metadata !43}
!165 = metadata !{i32 82, i32 6, metadata !162, null}
!166 = metadata !{i32 86, i32 3, metadata !162, null}
!167 = metadata !{i32 786688, metadata !162, metadata !"GY", metadata !6, i32 88, metadata !163, i32 0, i32 0} ; [ DW_TAG_auto_variable ]
!168 = metadata !{i32 88, i32 6, metadata !162, null}
!169 = metadata !{i32 92, i32 3, metadata !162, null}
!170 = metadata !{i32 105, i32 16, metadata !171, null}
!171 = metadata !{i32 786443, metadata !162, i32 105, i32 5, metadata !6, i32 1} ; [ DW_TAG_lexical_block ]
!172 = metadata !{i32 106, i32 9, metadata !171, null}
!173 = metadata !{i32 105, i32 28, metadata !171, null}
!174 = metadata !{i32 108, i32 34, metadata !162, null}
!175 = metadata !{i32 111, i32 13, metadata !176, null}
!176 = metadata !{i32 786443, metadata !162, i32 111, i32 2, metadata !6, i32 2} ; [ DW_TAG_lexical_block ]
!177 = metadata !{i32 112, i32 9, metadata !178, null}
!178 = metadata !{i32 786443, metadata !176, i32 111, i32 32, metadata !6, i32 3} ; [ DW_TAG_lexical_block ]
!179 = metadata !{i32 111, i32 27, metadata !176, null}
!180 = metadata !{i32 118, i32 5, metadata !162, null}
!181 = metadata !{i32 119, i32 5, metadata !162, null}
!182 = metadata !{i32 124, i32 13, metadata !183, null}
!183 = metadata !{i32 786443, metadata !162, i32 124, i32 2, metadata !6, i32 4} ; [ DW_TAG_lexical_block ]
!184 = metadata !{i32 127, i32 9, metadata !185, null}
!185 = metadata !{i32 786443, metadata !183, i32 124, i32 36, metadata !6, i32 5} ; [ DW_TAG_lexical_block ]
!186 = metadata !{i32 134, i32 14, metadata !187, null}
!187 = metadata !{i32 786443, metadata !185, i32 134, i32 3, metadata !6, i32 6} ; [ DW_TAG_lexical_block ]
!188 = metadata !{i32 141, i32 16, metadata !189, null}
!189 = metadata !{i32 786443, metadata !190, i32 141, i32 4, metadata !6, i32 8} ; [ DW_TAG_lexical_block ]
!190 = metadata !{i32 786443, metadata !187, i32 134, i32 36, metadata !6, i32 7} ; [ DW_TAG_lexical_block ]
!191 = metadata !{i32 142, i32 17, metadata !192, null}
!192 = metadata !{i32 786443, metadata !189, i32 141, i32 29, metadata !6, i32 9} ; [ DW_TAG_lexical_block ]
!193 = metadata !{i32 143, i32 17, metadata !192, null}
!194 = metadata !{i32 144, i32 17, metadata !192, null}
!195 = metadata !{i32 146, i32 17, metadata !192, null}
!196 = metadata !{i32 147, i32 17, metadata !192, null}
!197 = metadata !{i32 148, i32 17, metadata !192, null}
!198 = metadata !{i32 141, i32 24, metadata !189, null}
!199 = metadata !{i32 151, i32 19, metadata !190, null}
!200 = metadata !{i32 152, i32 13, metadata !190, null}
!201 = metadata !{i32 154, i32 13, metadata !190, null}
!202 = metadata !{i32 134, i32 31, metadata !187, null}
!203 = metadata !{metadata !203}
!204 = metadata !{i32 1}
!205 = metadata !{i32 124, i32 31, metadata !183, null}
!206 = metadata !{i32 167, i32 5, metadata !162, null}
!207 = metadata !{i32 168, i32 5, metadata !162, null}
!208 = metadata !{i32 172, i32 13, metadata !209, null}
!209 = metadata !{i32 786443, metadata !162, i32 172, i32 2, metadata !6, i32 10} ; [ DW_TAG_lexical_block ]
!210 = metadata !{i32 175, i32 9, metadata !211, null}
!211 = metadata !{i32 786443, metadata !209, i32 172, i32 36, metadata !6, i32 11} ; [ DW_TAG_lexical_block ]
!212 = metadata !{i32 182, i32 14, metadata !213, null}
!213 = metadata !{i32 786443, metadata !211, i32 182, i32 3, metadata !6, i32 12} ; [ DW_TAG_lexical_block ]
!214 = metadata !{i32 189, i32 16, metadata !215, null}
!215 = metadata !{i32 786443, metadata !216, i32 189, i32 4, metadata !6, i32 14} ; [ DW_TAG_lexical_block ]
!216 = metadata !{i32 786443, metadata !213, i32 182, i32 36, metadata !6, i32 13} ; [ DW_TAG_lexical_block ]
!217 = metadata !{i32 190, i32 17, metadata !218, null}
!218 = metadata !{i32 786443, metadata !215, i32 189, i32 29, metadata !6, i32 15} ; [ DW_TAG_lexical_block ]
!219 = metadata !{i32 191, i32 17, metadata !218, null}
!220 = metadata !{i32 192, i32 17, metadata !218, null}
!221 = metadata !{i32 194, i32 17, metadata !218, null}
!222 = metadata !{i32 195, i32 17, metadata !218, null}
!223 = metadata !{i32 196, i32 17, metadata !218, null}
!224 = metadata !{i32 189, i32 24, metadata !215, null}
!225 = metadata !{i32 200, i32 19, metadata !216, null}
!226 = metadata !{i32 203, i32 62, metadata !216, null}
!227 = metadata !{float 2.500000e+00}
!228 = metadata !{i32 204, i32 13, metadata !216, null}
!229 = metadata !{i32 182, i32 31, metadata !213, null}
!230 = metadata !{metadata !230}
!231 = metadata !{i32 207, i32 9, metadata !211, null}
!232 = metadata !{i32 172, i32 31, metadata !209, null}
!233 = metadata !{i32 215, i32 1, metadata !162, null}
!234 = metadata !{i32 52, i32 3, metadata !150, null}
!235 = metadata !{i32 69, i32 1, metadata !236, null}
!236 = metadata !{i32 786443, metadata !108, metadata !28} ; [ DW_TAG_lexical_block ]
