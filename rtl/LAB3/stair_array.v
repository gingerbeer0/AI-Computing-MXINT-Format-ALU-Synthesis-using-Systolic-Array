module stair_array(
    input CLK,          // Clock
    input RSTN,         // Reset (active low)
	input [1:0] operation,       // Operation code: 00:mul, 01:add, 10:sub
	input enable, // Enable signal

	input [4:0] GROUP1_SE, // Group1 shared exponent
	input [4:0] GROUP2_SE,
	input [4:0] GROUP3_SE,
	input [4:0] GROUP4_SE,
	input [4:0] GROUP5_SE,
	input [4:0] GROUP6_SE,
	input [4:0] GROUP7_SE,
	input [4:0] GROUP8_SE,

	input wire signed [15:0] MXINT_0,
	input wire signed [15:0] MXINT_1,
	input wire signed [15:0] MXINT_2,
	input wire signed [15:0] MXINT_3,
	input wire signed [15:0] MXINT_4,
	input wire signed [15:0] MXINT_5,
	input wire signed [15:0] MXINT_6,
	input wire signed [15:0] MXINT_7,
	input wire signed [15:0] MXINT_8,
	input wire signed [15:0] MXINT_9,
	input wire signed [15:0] MXINT_10,
	input wire signed [15:0] MXINT_11,
	input wire signed [15:0] MXINT_12,
	input wire signed [15:0] MXINT_13,
	input wire signed [15:0] MXINT_14,
	input wire signed [15:0] MXINT_15,
	input wire signed [15:0] MXINT_16,
	input wire signed [15:0] MXINT_17,
	input wire signed [15:0] MXINT_18,
	input wire signed [15:0] MXINT_19,
	input wire signed [15:0] MXINT_20,
	input wire signed [15:0] MXINT_21,
	input wire signed [15:0] MXINT_22,
	input wire signed [15:0] MXINT_23,
	input wire signed [15:0] MXINT_24,
	input wire signed [15:0] MXINT_25,
	input wire signed [15:0] MXINT_26,
	input wire signed [15:0] MXINT_27,
	input wire signed [15:0] MXINT_28,
	input wire signed [15:0] MXINT_29,
	input wire signed [15:0] MXINT_30,
	input wire signed [15:0] MXINT_31,
	input wire signed [15:0] MXINT_32,
	input wire signed [15:0] MXINT_33,
	input wire signed [15:0] MXINT_34,
	input wire signed [15:0] MXINT_35,
	input wire signed [15:0] MXINT_36,
	input wire signed [15:0] MXINT_37,
	input wire signed [15:0] MXINT_38,
	input wire signed [15:0] MXINT_39,
	input wire signed [15:0] MXINT_40,
	input wire signed [15:0] MXINT_41,
	input wire signed [15:0] MXINT_42,
	input wire signed [15:0] MXINT_43,
	input wire signed [15:0] MXINT_44,
	input wire signed [15:0] MXINT_45,
	input wire signed [15:0] MXINT_46,
	input wire signed [15:0] MXINT_47,
	input wire signed [15:0] MXINT_48,
	input wire signed [15:0] MXINT_49,
	input wire signed [15:0] MXINT_50,
	input wire signed [15:0] MXINT_51,
	input wire signed [15:0] MXINT_52,
	input wire signed [15:0] MXINT_53,
	input wire signed [15:0] MXINT_54,
	input wire signed [15:0] MXINT_55,
	input wire signed [15:0] MXINT_56,
	input wire signed [15:0] MXINT_57,
	input wire signed [15:0] MXINT_58,
	input wire signed [15:0] MXINT_59,
	input wire signed [15:0] MXINT_60,
	input wire signed [15:0] MXINT_61,
	input wire signed [15:0] MXINT_62,
	input wire signed [15:0] MXINT_63,
	input wire signed [15:0] MXINT_64,
	input wire signed [15:0] MXINT_65,
	input wire signed [15:0] MXINT_66,
	input wire signed [15:0] MXINT_67,
	input wire signed [15:0] MXINT_68,
	input wire signed [15:0] MXINT_69,
	input wire signed [15:0] MXINT_70,
	input wire signed [15:0] MXINT_71,
	input wire signed [15:0] MXINT_72,
	input wire signed [15:0] MXINT_73,
	input wire signed [15:0] MXINT_74,
	input wire signed [15:0] MXINT_75,
	input wire signed [15:0] MXINT_76,
	input wire signed [15:0] MXINT_77,
	input wire signed [15:0] MXINT_78,
	input wire signed [15:0] MXINT_79,
	input wire signed [15:0] MXINT_80,
	input wire signed [15:0] MXINT_81,
	input wire signed [15:0] MXINT_82,
	input wire signed [15:0] MXINT_83,
	input wire signed [15:0] MXINT_84,
	input wire signed [15:0] MXINT_85,
	input wire signed [15:0] MXINT_86,
	input wire signed [15:0] MXINT_87,
	input wire signed [15:0] MXINT_88,
	input wire signed [15:0] MXINT_89,
	input wire signed [15:0] MXINT_90,
	input wire signed [15:0] MXINT_91,
	input wire signed [15:0] MXINT_92,
	input wire signed [15:0] MXINT_93,
	input wire signed [15:0] MXINT_94,
	input wire signed [15:0] MXINT_95,
	input wire signed [15:0] MXINT_96,
	input wire signed [15:0] MXINT_97,
	input wire signed [15:0] MXINT_98,
	input wire signed [15:0] MXINT_99,
	input wire signed [15:0] MXINT_100,
	input wire signed [15:0] MXINT_101,
	input wire signed [15:0] MXINT_102,
	input wire signed [15:0] MXINT_103,
	input wire signed [15:0] MXINT_104,
	input wire signed [15:0] MXINT_105,
	input wire signed [15:0] MXINT_106,
	input wire signed [15:0] MXINT_107,
	input wire signed [15:0] MXINT_108,
	input wire signed [15:0] MXINT_109,
	input wire signed [15:0] MXINT_110,
	input wire signed [15:0] MXINT_111,
	input wire signed [15:0] MXINT_112,
	input wire signed [15:0] MXINT_113,
	input wire signed [15:0] MXINT_114,
	input wire signed [15:0] MXINT_115,
	input wire signed [15:0] MXINT_116,
	input wire signed [15:0] MXINT_117,
	input wire signed [15:0] MXINT_118,
	input wire signed [15:0] MXINT_119,
	input wire signed [15:0] MXINT_120,
	input wire signed [15:0] MXINT_121,
	input wire signed [15:0] MXINT_122,
	input wire signed [15:0] MXINT_123,
	input wire signed [15:0] MXINT_124,
	input wire signed [15:0] MXINT_125,
	input wire signed [15:0] MXINT_126,
	input wire signed [15:0] MXINT_127,
	input wire signed [15:0] MXINT_128,
	input wire signed [15:0] MXINT_129,
	input wire signed [15:0] MXINT_130,
	input wire signed [15:0] MXINT_131,
	input wire signed [15:0] MXINT_132,
	input wire signed [15:0] MXINT_133,
	input wire signed [15:0] MXINT_134,
	input wire signed [15:0] MXINT_135,
	input wire signed [15:0] MXINT_136,
	input wire signed [15:0] MXINT_137,
	input wire signed [15:0] MXINT_138,
	input wire signed [15:0] MXINT_139,
	input wire signed [15:0] MXINT_140,
	input wire signed [15:0] MXINT_141,
	input wire signed [15:0] MXINT_142,
	input wire signed [15:0] MXINT_143,
	input wire signed [15:0] MXINT_144,
	input wire signed [15:0] MXINT_145,
	input wire signed [15:0] MXINT_146,
	input wire signed [15:0] MXINT_147,
	input wire signed [15:0] MXINT_148,
	input wire signed [15:0] MXINT_149,
	input wire signed [15:0] MXINT_150,
	input wire signed [15:0] MXINT_151,
	input wire signed [15:0] MXINT_152,
	input wire signed [15:0] MXINT_153,
	input wire signed [15:0] MXINT_154,
	input wire signed [15:0] MXINT_155,
	input wire signed [15:0] MXINT_156,
	input wire signed [15:0] MXINT_157,
	input wire signed [15:0] MXINT_158,
	input wire signed [15:0] MXINT_159,
	input wire signed [15:0] MXINT_160,
	input wire signed [15:0] MXINT_161,
	input wire signed [15:0] MXINT_162,
	input wire signed [15:0] MXINT_163,
	input wire signed [15:0] MXINT_164,
	input wire signed [15:0] MXINT_165,
	input wire signed [15:0] MXINT_166,
	input wire signed [15:0] MXINT_167,
	input wire signed [15:0] MXINT_168,
	input wire signed [15:0] MXINT_169,
	input wire signed [15:0] MXINT_170,
	input wire signed [15:0] MXINT_171,
	input wire signed [15:0] MXINT_172,
	input wire signed [15:0] MXINT_173,
	input wire signed [15:0] MXINT_174,
	input wire signed [15:0] MXINT_175,
	input wire signed [15:0] MXINT_176,
	input wire signed [15:0] MXINT_177,
	input wire signed [15:0] MXINT_178,
	input wire signed [15:0] MXINT_179,
	input wire signed [15:0] MXINT_180,
	input wire signed [15:0] MXINT_181,
	input wire signed [15:0] MXINT_182,
	input wire signed [15:0] MXINT_183,
	input wire signed [15:0] MXINT_184,
	input wire signed [15:0] MXINT_185,
	input wire signed [15:0] MXINT_186,
	input wire signed [15:0] MXINT_187,
	input wire signed [15:0] MXINT_188,
	input wire signed [15:0] MXINT_189,
	input wire signed [15:0] MXINT_190,
	input wire signed [15:0] MXINT_191,
	input wire signed [15:0] MXINT_192,
	input wire signed [15:0] MXINT_193,
	input wire signed [15:0] MXINT_194,
	input wire signed [15:0] MXINT_195,
	input wire signed [15:0] MXINT_196,
	input wire signed [15:0] MXINT_197,
	input wire signed [15:0] MXINT_198,
	input wire signed [15:0] MXINT_199,
	input wire signed [15:0] MXINT_200,
	input wire signed [15:0] MXINT_201,
	input wire signed [15:0] MXINT_202,
	input wire signed [15:0] MXINT_203,
	input wire signed [15:0] MXINT_204,
	input wire signed [15:0] MXINT_205,
	input wire signed [15:0] MXINT_206,
	input wire signed [15:0] MXINT_207,
	input wire signed [15:0] MXINT_208,
	input wire signed [15:0] MXINT_209,
	input wire signed [15:0] MXINT_210,
	input wire signed [15:0] MXINT_211,
	input wire signed [15:0] MXINT_212,
	input wire signed [15:0] MXINT_213,
	input wire signed [15:0] MXINT_214,
	input wire signed [15:0] MXINT_215,
	input wire signed [15:0] MXINT_216,
	input wire signed [15:0] MXINT_217,
	input wire signed [15:0] MXINT_218,
	input wire signed [15:0] MXINT_219,
	input wire signed [15:0] MXINT_220,
	input wire signed [15:0] MXINT_221,
	input wire signed [15:0] MXINT_222,
	input wire signed [15:0] MXINT_223,
	input wire signed [15:0] MXINT_224,
	input wire signed [15:0] MXINT_225,
	input wire signed [15:0] MXINT_226,
	input wire signed [15:0] MXINT_227,
	input wire signed [15:0] MXINT_228,
	input wire signed [15:0] MXINT_229,
	input wire signed [15:0] MXINT_230,
	input wire signed [15:0] MXINT_231,
	input wire signed [15:0] MXINT_232,
	input wire signed [15:0] MXINT_233,
	input wire signed [15:0] MXINT_234,
	input wire signed [15:0] MXINT_235,
	input wire signed [15:0] MXINT_236,
	input wire signed [15:0] MXINT_237,
	input wire signed [15:0] MXINT_238,
	input wire signed [15:0] MXINT_239,
	input wire signed [15:0] MXINT_240,
	input wire signed [15:0] MXINT_241,
	input wire signed [15:0] MXINT_242,
	input wire signed [15:0] MXINT_243,
	input wire signed [15:0] MXINT_244,
	input wire signed [15:0] MXINT_245,
	input wire signed [15:0] MXINT_246,
	input wire signed [15:0] MXINT_247,
	input wire signed [15:0] MXINT_248,
	input wire signed [15:0] MXINT_249,
	input wire signed [15:0] MXINT_250,
	input wire signed [15:0] MXINT_251,
	input wire signed [15:0] MXINT_252,
	input wire signed [15:0] MXINT_253,
	input wire signed [15:0] MXINT_254,
	input wire signed [15:0] MXINT_255,

	output wire signed [15:0] RESULT_P18, // Output array
	output wire signed [15:0] RESULT_P17, // Output array
	output wire signed [15:0] RESULT_P16, // Output array
	output wire signed [15:0] RESULT_P15, // Output array
	output wire signed [15:0] RESULT_P14, // Output array
	output wire signed [15:0] RESULT_P13, // Output array
	output wire signed [15:0] RESULT_P12, // Output array
	output wire signed [15:0] RESULT_P28, // Output array
	output wire signed [15:0] RESULT_P27, // Output array
	output wire signed [15:0] RESULT_P26, // Output array
	output wire signed [15:0] RESULT_P25, // Output array
	output wire signed [15:0] RESULT_P24, // Output array
	output wire signed [15:0] RESULT_P23, // Output array
	output wire signed [15:0] RESULT_P38, // Output array
	output wire signed [15:0] RESULT_P37, // Output array
	output wire signed [15:0] RESULT_P36, // Output array
	output wire signed [15:0] RESULT_P35, // Output array
	output wire signed [15:0] RESULT_P34, // Output array
	output wire signed [15:0] RESULT_P48, // Output array
	output wire signed [15:0] RESULT_P47, // Output array
	output wire signed [15:0] RESULT_P46, // Output array
	output wire signed [15:0] RESULT_P45, // Output array
	output wire signed [15:0] RESULT_P58, // Output array
	output wire signed [15:0] RESULT_P57, // Output array
	output wire signed [15:0] RESULT_P56, // Output array
	output wire signed [15:0] RESULT_P68, // Output array
	output wire signed [15:0] RESULT_P67, // Output array
	output wire signed [15:0] RESULT_P78, // Output array

	output reg result_enable // Enable signal for output array
);
    reg [5:0] count; // Cycle counter

    // Weight and data inputs for processing elements
	reg [15:0] D_IN_P18, D_IN_P28, D_IN_P38, D_IN_P48, D_IN_P58, D_IN_P68, D_IN_P78;
	reg [15:0] W_IN_P18, W_IN_P17, W_IN_P16, W_IN_P15, W_IN_P14, W_IN_P13, W_IN_P12;

	wire signed [15:0] W_OUT_P18, W_OUT_P17, W_OUT_P16, W_OUT_P15, W_OUT_P14, W_OUT_P13,  W_OUT_P28, W_OUT_P27, W_OUT_P26, W_OUT_P25, W_OUT_P24, W_OUT_P38, W_OUT_P37, W_OUT_P36, W_OUT_P35, W_OUT_P48, W_OUT_P47, W_OUT_P46, W_OUT_P58, W_OUT_P57, W_OUT_P68;
	wire signed [15:0] D_OUT_P18, D_OUT_P17, D_OUT_P16, D_OUT_P15, D_OUT_P14, D_OUT_P13,  D_OUT_P28, D_OUT_P27, D_OUT_P26, D_OUT_P25, D_OUT_P24, D_OUT_P38, D_OUT_P37, D_OUT_P36, D_OUT_P35, D_OUT_P48, D_OUT_P47, D_OUT_P46, D_OUT_P58, D_OUT_P57, D_OUT_P68;

    // Sequential logic for weight inputs
    always @(posedge CLK or negedge RSTN) begin
        if (!RSTN) begin
            // Reset all weight inputs
			W_IN_P18 <= 0;
			W_IN_P17 <= 0;
			W_IN_P16 <= 0;
			W_IN_P15 <= 0;
			W_IN_P14 <= 0;
			W_IN_P13 <= 0;
			W_IN_P12 <= 0;

			D_IN_P18 <= 0;
			D_IN_P28 <= 0;
			D_IN_P38 <= 0;
			D_IN_P48 <= 0;
			D_IN_P58 <= 0;
			D_IN_P68 <= 0;
			D_IN_P78 <= 0;

        end else if(enable) begin
            case (count)
				0: begin
					D_IN_P18 <= MXINT_0;
					D_IN_P28 <= 0;
					D_IN_P38 <= 0;
					D_IN_P48 <= 0;
					D_IN_P58 <= 0;
					D_IN_P68 <= 0;
					D_IN_P78 <= 0;
					W_IN_P18 <= MXINT_224;
					W_IN_P17 <= 0;
					W_IN_P16 <= 0;
					W_IN_P15 <= 0;
					W_IN_P14 <= 0;
					W_IN_P13 <= 0;
					W_IN_P12 <= 0;
				end
				1: begin
					D_IN_P18 <= MXINT_1;
					D_IN_P28 <= MXINT_32;
					D_IN_P38 <= 0;
					D_IN_P48 <= 0;
					D_IN_P58 <= 0;
					D_IN_P68 <= 0;
					D_IN_P78 <= 0;
					W_IN_P18 <= MXINT_225;
					W_IN_P17 <= MXINT_192;
					W_IN_P16 <= 0;
					W_IN_P15 <= 0;
					W_IN_P14 <= 0;
					W_IN_P13 <= 0;
					W_IN_P12 <= 0;
				end
				2: begin
					D_IN_P18 <= MXINT_2;
					D_IN_P28 <= MXINT_33;
					D_IN_P38 <= MXINT_64;
					D_IN_P48 <= 0;
					D_IN_P58 <= 0;
					D_IN_P68 <= 0;
					D_IN_P78 <= 0;
					W_IN_P18 <= MXINT_226;
					W_IN_P17 <= MXINT_193;
					W_IN_P16 <= MXINT_160;
					W_IN_P15 <= 0;
					W_IN_P14 <= 0;
					W_IN_P13 <= 0;
					W_IN_P12 <= 0;
				end	
				3: begin
					D_IN_P18 <= MXINT_3;
					D_IN_P28 <= MXINT_34;
					D_IN_P38 <= MXINT_65;
					D_IN_P48 <= MXINT_96;
					D_IN_P58 <= 0;
					D_IN_P68 <= 0;
					D_IN_P78 <= 0;
					W_IN_P18 <= MXINT_227;
					W_IN_P17 <= MXINT_194;
					W_IN_P16 <= MXINT_161;
					W_IN_P15 <= MXINT_128;
					W_IN_P14 <= 0;
					W_IN_P13 <= 0;
					W_IN_P12 <= 0;
				end
				4: begin
					D_IN_P18 <= MXINT_4;
					D_IN_P28 <= MXINT_35;
					D_IN_P38 <= MXINT_66;
					D_IN_P48 <= MXINT_97;
					D_IN_P58 <= MXINT_128;
					D_IN_P68 <= 0;
					D_IN_P78 <= 0;
					W_IN_P18 <= MXINT_228;
					W_IN_P17 <= MXINT_195;
					W_IN_P16 <= MXINT_162;
					W_IN_P15 <= MXINT_129;
					W_IN_P14 <= MXINT_96;
					W_IN_P13 <= 0;
					W_IN_P12 <= 0;
				end
				5: begin
					D_IN_P18 <= MXINT_5;
					D_IN_P28 <= MXINT_36;
					D_IN_P38 <= MXINT_67;
					D_IN_P48 <= MXINT_98;
					D_IN_P58 <= MXINT_129;
					D_IN_P68 <= MXINT_160;
					D_IN_P78 <= 0;
					W_IN_P18 <= MXINT_229;
					W_IN_P17 <= MXINT_196;
					W_IN_P16 <= MXINT_163;
					W_IN_P15 <= MXINT_130;
					W_IN_P14 <= MXINT_97;
					W_IN_P13 <= MXINT_64;
					W_IN_P12 <= 0;
				end
				6: begin
					D_IN_P18 <= MXINT_6;
					D_IN_P28 <= MXINT_37;
					D_IN_P38 <= MXINT_68;
					D_IN_P48 <= MXINT_99;
					D_IN_P58 <= MXINT_130;
					D_IN_P68 <= MXINT_161;
					D_IN_P78 <= MXINT_192;
					W_IN_P18 <= MXINT_230;
					W_IN_P17 <= MXINT_197;
					W_IN_P16 <= MXINT_164;
					W_IN_P15 <= MXINT_131;
					W_IN_P14 <= MXINT_98;
					W_IN_P13 <= MXINT_65;
					W_IN_P12 <= MXINT_32;
				end
				7: begin
					D_IN_P18 <= MXINT_7;
					D_IN_P28 <= MXINT_38;
					D_IN_P38 <= MXINT_69;
					D_IN_P48 <= MXINT_100;
					D_IN_P58 <= MXINT_131;
					D_IN_P68 <= MXINT_162;
					D_IN_P78 <= MXINT_193;
					W_IN_P18 <= MXINT_231;
					W_IN_P17 <= MXINT_198;
					W_IN_P16 <= MXINT_165;
					W_IN_P15 <= MXINT_132;
					W_IN_P14 <= MXINT_99;
					W_IN_P13 <= MXINT_66;
					W_IN_P12 <= MXINT_33;
				end
				8: begin
					D_IN_P18 <= MXINT_8;
					D_IN_P28 <= MXINT_39;
					D_IN_P38 <= MXINT_70;
					D_IN_P48 <= MXINT_101;
					D_IN_P58 <= MXINT_132;
					D_IN_P68 <= MXINT_163;
					D_IN_P78 <= MXINT_194;
					W_IN_P18 <= MXINT_232;
					W_IN_P17 <= MXINT_199;
					W_IN_P16 <= MXINT_166;
					W_IN_P15 <= MXINT_133;
					W_IN_P14 <= MXINT_100;
					W_IN_P13 <= MXINT_67;
					W_IN_P12 <= MXINT_34;
				end
				9: begin
					D_IN_P18 <= MXINT_9;
					D_IN_P28 <= MXINT_40;
					D_IN_P38 <= MXINT_71;
					D_IN_P48 <= MXINT_102;
					D_IN_P58 <= MXINT_133;
					D_IN_P68 <= MXINT_164;
					D_IN_P78 <= MXINT_195;
					W_IN_P18 <= MXINT_233;
					W_IN_P17 <= MXINT_200;
					W_IN_P16 <= MXINT_167;
					W_IN_P15 <= MXINT_134;
					W_IN_P14 <= MXINT_101;
					W_IN_P13 <= MXINT_68;
					W_IN_P12 <= MXINT_35;
				end
				10: begin
					D_IN_P18 <= MXINT_10;
					D_IN_P28 <= MXINT_41;
					D_IN_P38 <= MXINT_72;
					D_IN_P48 <= MXINT_103;
					D_IN_P58 <= MXINT_134;
					D_IN_P68 <= MXINT_165;
					D_IN_P78 <= MXINT_196;
					W_IN_P18 <= MXINT_234;
					W_IN_P17 <= MXINT_201;
					W_IN_P16 <= MXINT_168;
					W_IN_P15 <= MXINT_135;
					W_IN_P14 <= MXINT_102;
					W_IN_P13 <= MXINT_69;
					W_IN_P12 <= MXINT_36;
				end
				11: begin
					D_IN_P18 <= MXINT_11;
					D_IN_P28 <= MXINT_42;
					D_IN_P38 <= MXINT_73;
					D_IN_P48 <= MXINT_104;
					D_IN_P58 <= MXINT_135;
					D_IN_P68 <= MXINT_166;
					D_IN_P78 <= MXINT_197;
					W_IN_P18 <= MXINT_235;
					W_IN_P17 <= MXINT_202;
					W_IN_P16 <= MXINT_169;
					W_IN_P15 <= MXINT_136;
					W_IN_P14 <= MXINT_103;
					W_IN_P13 <= MXINT_70;
					W_IN_P12 <= MXINT_37;
				end
				12: begin
					D_IN_P18 <= MXINT_12;
					D_IN_P28 <= MXINT_43;
					D_IN_P38 <= MXINT_74;
					D_IN_P48 <= MXINT_105;
					D_IN_P58 <= MXINT_136;
					D_IN_P68 <= MXINT_167;
					D_IN_P78 <= MXINT_198;
					W_IN_P18 <= MXINT_236;
					W_IN_P17 <= MXINT_203;
					W_IN_P16 <= MXINT_170;
					W_IN_P15 <= MXINT_137;
					W_IN_P14 <= MXINT_104;
					W_IN_P13 <= MXINT_71;
					W_IN_P12 <= MXINT_38;
				end
				13: begin
					D_IN_P18 <= MXINT_13;
					D_IN_P28 <= MXINT_44;
					D_IN_P38 <= MXINT_75;
					D_IN_P48 <= MXINT_106;
					D_IN_P58 <= MXINT_137;
					D_IN_P68 <= MXINT_168;
					D_IN_P78 <= MXINT_199;
					W_IN_P18 <= MXINT_237;
					W_IN_P17 <= MXINT_204;
					W_IN_P16 <= MXINT_171;
					W_IN_P15 <= MXINT_138;
					W_IN_P14 <= MXINT_105;
					W_IN_P13 <= MXINT_72;
					W_IN_P12 <= MXINT_39;
				end
				14: begin
					D_IN_P18 <= MXINT_14;
					D_IN_P28 <= MXINT_45;
					D_IN_P38 <= MXINT_76;
					D_IN_P48 <= MXINT_107;
					D_IN_P58 <= MXINT_138;
					D_IN_P68 <= MXINT_169;
					D_IN_P78 <= MXINT_200;
					W_IN_P18 <= MXINT_238;
					W_IN_P17 <= MXINT_205;
					W_IN_P16 <= MXINT_172;
					W_IN_P15 <= MXINT_139;
					W_IN_P14 <= MXINT_106;
					W_IN_P13 <= MXINT_73;
					W_IN_P12 <= MXINT_40;
				end
				15: begin
					D_IN_P18 <= MXINT_15;
					D_IN_P28 <= MXINT_46;
					D_IN_P38 <= MXINT_77;
					D_IN_P48 <= MXINT_108;
					D_IN_P58 <= MXINT_139;
					D_IN_P68 <= MXINT_170;
					D_IN_P78 <= MXINT_201;
					W_IN_P18 <= MXINT_239;
					W_IN_P17 <= MXINT_206;
					W_IN_P16 <= MXINT_173;
					W_IN_P15 <= MXINT_140;
					W_IN_P14 <= MXINT_107;
					W_IN_P13 <= MXINT_74;
					W_IN_P12 <= MXINT_41;
				end
				16: begin
					D_IN_P18 <= MXINT_16;
					D_IN_P28 <= MXINT_47;
					D_IN_P38 <= MXINT_78;
					D_IN_P48 <= MXINT_109;
					D_IN_P58 <= MXINT_140;
					D_IN_P68 <= MXINT_171;
					D_IN_P78 <= MXINT_202;
					W_IN_P18 <= MXINT_240;
					W_IN_P17 <= MXINT_207;
					W_IN_P16 <= MXINT_174;
					W_IN_P15 <= MXINT_141;
					W_IN_P14 <= MXINT_108;
					W_IN_P13 <= MXINT_75;
					W_IN_P12 <= MXINT_42;
				end
				17: begin
					D_IN_P18 <= MXINT_17;
					D_IN_P28 <= MXINT_48;
					D_IN_P38 <= MXINT_79;
					D_IN_P48 <= MXINT_110;
					D_IN_P58 <= MXINT_141;
					D_IN_P68 <= MXINT_172;
					D_IN_P78 <= MXINT_203;
					W_IN_P18 <= MXINT_241;
					W_IN_P17 <= MXINT_208;
					W_IN_P16 <= MXINT_175;
					W_IN_P15 <= MXINT_142;
					W_IN_P14 <= MXINT_109;
					W_IN_P13 <= MXINT_76;
					W_IN_P12 <= MXINT_43;
				end
				18: begin
					D_IN_P18 <= MXINT_18;
					D_IN_P28 <= MXINT_49;
					D_IN_P38 <= MXINT_80;
					D_IN_P48 <= MXINT_111;
					D_IN_P58 <= MXINT_142;
					D_IN_P68 <= MXINT_173;
					D_IN_P78 <= MXINT_204;
					W_IN_P18 <= MXINT_242;
					W_IN_P17 <= MXINT_209;
					W_IN_P16 <= MXINT_176;
					W_IN_P15 <= MXINT_143;
					W_IN_P14 <= MXINT_110;
					W_IN_P13 <= MXINT_77;
					W_IN_P12 <= MXINT_44;
				end
				19: begin
					D_IN_P18 <= MXINT_19;
					D_IN_P28 <= MXINT_50;
					D_IN_P38 <= MXINT_81;
					D_IN_P48 <= MXINT_112;
					D_IN_P58 <= MXINT_143;
					D_IN_P68 <= MXINT_174;
					D_IN_P78 <= MXINT_205;
					W_IN_P18 <= MXINT_243;
					W_IN_P17 <= MXINT_210;
					W_IN_P16 <= MXINT_177;
					W_IN_P15 <= MXINT_144;
					W_IN_P14 <= MXINT_111;
					W_IN_P13 <= MXINT_78;
					W_IN_P12 <= MXINT_45;
				end
				20: begin
					D_IN_P18 <= MXINT_20;
					D_IN_P28 <= MXINT_51;
					D_IN_P38 <= MXINT_82;
					D_IN_P48 <= MXINT_113;
					D_IN_P58 <= MXINT_144;
					D_IN_P68 <= MXINT_175;
					D_IN_P78 <= MXINT_206;
					W_IN_P18 <= MXINT_244;
					W_IN_P17 <= MXINT_211;
					W_IN_P16 <= MXINT_178;
					W_IN_P15 <= MXINT_145;
					W_IN_P14 <= MXINT_112;
					W_IN_P13 <= MXINT_79;
					W_IN_P12 <= MXINT_46;
				end
				21: begin
					D_IN_P18 <= MXINT_21;
					D_IN_P28 <= MXINT_52;
					D_IN_P38 <= MXINT_83;
					D_IN_P48 <= MXINT_114;
					D_IN_P58 <= MXINT_145;
					D_IN_P68 <= MXINT_176;
					D_IN_P78 <= MXINT_207;
					W_IN_P18 <= MXINT_245;
					W_IN_P17 <= MXINT_212;
					W_IN_P16 <= MXINT_179;
					W_IN_P15 <= MXINT_146;
					W_IN_P14 <= MXINT_113;
					W_IN_P13 <= MXINT_80;
					W_IN_P12 <= MXINT_47;
				end
				22: begin
					D_IN_P18 <= MXINT_22;
					D_IN_P28 <= MXINT_53;
					D_IN_P38 <= MXINT_84;
					D_IN_P48 <= MXINT_115;
					D_IN_P58 <= MXINT_146;
					D_IN_P68 <= MXINT_177;
					D_IN_P78 <= MXINT_208;
					W_IN_P18 <= MXINT_246;
					W_IN_P17 <= MXINT_213;
					W_IN_P16 <= MXINT_180;
					W_IN_P15 <= MXINT_147;
					W_IN_P14 <= MXINT_114;
					W_IN_P13 <= MXINT_81;
					W_IN_P12 <= MXINT_48;
				end
				23: begin
					D_IN_P18 <= MXINT_23;
					D_IN_P28 <= MXINT_54;
					D_IN_P38 <= MXINT_85;
					D_IN_P48 <= MXINT_116;
					D_IN_P58 <= MXINT_147;
					D_IN_P68 <= MXINT_178;
					D_IN_P78 <= MXINT_209;
					W_IN_P18 <= MXINT_247;
					W_IN_P17 <= MXINT_214;
					W_IN_P16 <= MXINT_181;
					W_IN_P15 <= MXINT_148;
					W_IN_P14 <= MXINT_115;
					W_IN_P13 <= MXINT_82;
					W_IN_P12 <= MXINT_49;
				end
				24: begin
					D_IN_P18 <= MXINT_24;
					D_IN_P28 <= MXINT_55;
					D_IN_P38 <= MXINT_86;
					D_IN_P48 <= MXINT_117;
					D_IN_P58 <= MXINT_148;
					D_IN_P68 <= MXINT_179;
					D_IN_P78 <= MXINT_210;
					W_IN_P18 <= MXINT_248;
					W_IN_P17 <= MXINT_215;
					W_IN_P16 <= MXINT_182;
					W_IN_P15 <= MXINT_149;
					W_IN_P14 <= MXINT_116;
					W_IN_P13 <= MXINT_83;
					W_IN_P12 <= MXINT_50;
				end
				25: begin
					D_IN_P18 <= MXINT_25;
					D_IN_P28 <= MXINT_56;
					D_IN_P38 <= MXINT_87;
					D_IN_P48 <= MXINT_118;
					D_IN_P58 <= MXINT_149;
					D_IN_P68 <= MXINT_180;
					D_IN_P78 <= MXINT_211;
					W_IN_P18 <= MXINT_249;
					W_IN_P17 <= MXINT_216;
					W_IN_P16 <= MXINT_183;
					W_IN_P15 <= MXINT_150;
					W_IN_P14 <= MXINT_117;
					W_IN_P13 <= MXINT_84;
					W_IN_P12 <= MXINT_51;
				end
				26: begin
					D_IN_P18 <= MXINT_26;
					D_IN_P28 <= MXINT_57;
					D_IN_P38 <= MXINT_88;
					D_IN_P48 <= MXINT_119;
					D_IN_P58 <= MXINT_150;
					D_IN_P68 <= MXINT_181;
					D_IN_P78 <= MXINT_212;
					W_IN_P18 <= MXINT_250;
					W_IN_P17 <= MXINT_217;
					W_IN_P16 <= MXINT_184;
					W_IN_P15 <= MXINT_151;
					W_IN_P14 <= MXINT_118;
					W_IN_P13 <= MXINT_85;
					W_IN_P12 <= MXINT_52;
				end
				27: begin
					D_IN_P18 <= MXINT_27;
					D_IN_P28 <= MXINT_58;
					D_IN_P38 <= MXINT_89;
					D_IN_P48 <= MXINT_120;
					D_IN_P58 <= MXINT_151;
					D_IN_P68 <= MXINT_182;
					D_IN_P78 <= MXINT_213;
					W_IN_P18 <= MXINT_251;
					W_IN_P17 <= MXINT_218;
					W_IN_P16 <= MXINT_185;
					W_IN_P15 <= MXINT_152;
					W_IN_P14 <= MXINT_119;
					W_IN_P13 <= MXINT_86;
					W_IN_P12 <= MXINT_53;
				end
				28: begin
					D_IN_P18 <= MXINT_28;
					D_IN_P28 <= MXINT_59;
					D_IN_P38 <= MXINT_90;
					D_IN_P48 <= MXINT_121;
					D_IN_P58 <= MXINT_152;
					D_IN_P68 <= MXINT_183;
					D_IN_P78 <= MXINT_214;
					W_IN_P18 <= MXINT_252;
					W_IN_P17 <= MXINT_219;
					W_IN_P16 <= MXINT_186;
					W_IN_P15 <= MXINT_153;
					W_IN_P14 <= MXINT_120;
					W_IN_P13 <= MXINT_87;
					W_IN_P12 <= MXINT_54;
				end
				29: begin
					D_IN_P18 <= MXINT_29;
					D_IN_P28 <= MXINT_60;
					D_IN_P38 <= MXINT_91;
					D_IN_P48 <= MXINT_122;
					D_IN_P58 <= MXINT_153;
					D_IN_P68 <= MXINT_184;
					D_IN_P78 <= MXINT_215;
					W_IN_P18 <= MXINT_253;
					W_IN_P17 <= MXINT_220;
					W_IN_P16 <= MXINT_187;
					W_IN_P15 <= MXINT_154;
					W_IN_P14 <= MXINT_121;
					W_IN_P13 <= MXINT_88;
					W_IN_P12 <= MXINT_55;
				end
				30: begin
					D_IN_P18 <= MXINT_30;
					D_IN_P28 <= MXINT_61;
					D_IN_P38 <= MXINT_92;
					D_IN_P48 <= MXINT_123;
					D_IN_P58 <= MXINT_154;
					D_IN_P68 <= MXINT_185;
					D_IN_P78 <= MXINT_216;
					W_IN_P18 <= MXINT_254;
					W_IN_P17 <= MXINT_221;
					W_IN_P16 <= MXINT_188;
					W_IN_P15 <= MXINT_155;
					W_IN_P14 <= MXINT_122;
					W_IN_P13 <= MXINT_89;
					W_IN_P12 <= MXINT_56;
				end
				31: begin
					D_IN_P18 <= MXINT_31;
					D_IN_P28 <= MXINT_62;
					D_IN_P38 <= MXINT_93;
					D_IN_P48 <= MXINT_124;
					D_IN_P58 <= MXINT_155;
					D_IN_P68 <= MXINT_186;
					D_IN_P78 <= MXINT_217;
					W_IN_P18 <= MXINT_255;
					W_IN_P17 <= MXINT_222;
					W_IN_P16 <= MXINT_189;
					W_IN_P15 <= MXINT_156;
					W_IN_P14 <= MXINT_123;
					W_IN_P13 <= MXINT_90;
					W_IN_P12 <= MXINT_57;
				end
				32: begin
					D_IN_P18 <= 0;
					D_IN_P28 <= MXINT_63;
					D_IN_P38 <= MXINT_94;
					D_IN_P48 <= MXINT_125;
					D_IN_P58 <= MXINT_156;
					D_IN_P68 <= MXINT_187;
					D_IN_P78 <= MXINT_218;
					W_IN_P18 <= 0;
					W_IN_P17 <= MXINT_223;
					W_IN_P16 <= MXINT_190;
					W_IN_P15 <= MXINT_157;
					W_IN_P14 <= MXINT_124;
					W_IN_P13 <= MXINT_91;
					W_IN_P12 <= MXINT_58;
				end
				33: begin
					D_IN_P28 <= 0;
					D_IN_P38 <= MXINT_95;
					D_IN_P48 <= MXINT_126;
					D_IN_P58 <= MXINT_157;
					D_IN_P68 <= MXINT_188;
					D_IN_P78 <= MXINT_219;
					W_IN_P17 <= 0;
					W_IN_P16 <= MXINT_191;
					W_IN_P15 <= MXINT_158;
					W_IN_P14 <= MXINT_125;
					W_IN_P13 <= MXINT_92;
					W_IN_P12 <= MXINT_59;
				end
				34: begin
					D_IN_P38 <= 0;
					D_IN_P48 <= MXINT_127;
					D_IN_P58 <= MXINT_158;
					D_IN_P68 <= MXINT_189;
					D_IN_P78 <= MXINT_220;
					W_IN_P16 <= 0;
					W_IN_P15 <= MXINT_159;
					W_IN_P14 <= MXINT_126;
					W_IN_P13 <= MXINT_93;
					W_IN_P12 <= MXINT_60;
				end
				35: begin
					D_IN_P48 <= 0;
					D_IN_P58 <= MXINT_159;
					D_IN_P68 <= MXINT_190;
					D_IN_P78 <= MXINT_221;
					W_IN_P15 <= 0;
					W_IN_P14 <= MXINT_127;
					W_IN_P13 <= MXINT_94;
					W_IN_P12 <= MXINT_61;
				end
				36: begin
					D_IN_P58 <= 0;
					D_IN_P68 <= MXINT_191;
					D_IN_P78 <= MXINT_222;
					W_IN_P14 <= 0;
					W_IN_P13 <= MXINT_95;
					W_IN_P12 <= MXINT_62;
				end
				37: begin
					D_IN_P68 <= 0;
					D_IN_P78 <= MXINT_223;
					W_IN_P13 <= 0;
					W_IN_P12 <= MXINT_63;
				end
				38: begin
					D_IN_P78 <= 0;
					W_IN_P12 <= 0;
				end
				default: begin
					D_IN_P18 <= 0;
					D_IN_P28 <= 0;
					D_IN_P38 <= 0;
					D_IN_P48 <= 0;
					D_IN_P58 <= 0;
					D_IN_P68 <= 0;
					D_IN_P78 <= 0;
					W_IN_P18 <= 0;
					W_IN_P17 <= 0;
					W_IN_P16 <= 0;
					W_IN_P15 <= 0;
					W_IN_P14 <= 0;
					W_IN_P13 <= 0;
					W_IN_P12 <= 0;
				end
			endcase
		end else begin
			W_IN_P18 <= 0;
			W_IN_P17 <= 0;
			W_IN_P16 <= 0;
			W_IN_P15 <= 0;
			W_IN_P14 <= 0;
			W_IN_P13 <= 0;
			W_IN_P12 <= 0;

			D_IN_P18 <= 0;
			D_IN_P28 <= 0;
			D_IN_P38 <= 0;
			D_IN_P48 <= 0;
			D_IN_P58 <= 0;
			D_IN_P68 <= 0;
			D_IN_P78 <= 0;
		end
	end

    // Processing elements

		PE P18(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P18), .D_IN(D_IN_P18), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP1_SE), .W_OUT(W_OUT_P18), .D_OUT(D_OUT_P18), .RESULT(RESULT_P18));
		PE P17(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P17), .D_IN(D_OUT_P18), .operation(operation), .W_SE(GROUP7_SE), .D_SE(GROUP1_SE), .W_OUT(W_OUT_P17), .D_OUT(D_OUT_P17), .RESULT(RESULT_P17));
		PE P16(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P16), .D_IN(D_OUT_P17), .operation(operation), .W_SE(GROUP6_SE), .D_SE(GROUP1_SE), .W_OUT(W_OUT_P16), .D_OUT(D_OUT_P16), .RESULT(RESULT_P16));
		PE P15(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P15), .D_IN(D_OUT_P16), .operation(operation), .W_SE(GROUP5_SE), .D_SE(GROUP1_SE), .W_OUT(W_OUT_P15), .D_OUT(D_OUT_P15), .RESULT(RESULT_P15));
		PE P14(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P14), .D_IN(D_OUT_P15), .operation(operation), .W_SE(GROUP4_SE), .D_SE(GROUP1_SE), .W_OUT(W_OUT_P14), .D_OUT(D_OUT_P14), .RESULT(RESULT_P14));
		PE P13(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P13), .D_IN(D_OUT_P14), .operation(operation), .W_SE(GROUP3_SE), .D_SE(GROUP1_SE), .W_OUT(W_OUT_P13), .D_OUT(D_OUT_P13), .RESULT(RESULT_P13));
		PE P12(.CLK(CLK), .RSTN(RSTN), .W_IN(W_IN_P12), .D_IN(D_OUT_P13), .operation(operation), .W_SE(GROUP2_SE), .D_SE(GROUP1_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P12));
		PE P28(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P18), .D_IN(D_IN_P28), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP2_SE), .W_OUT(W_OUT_P28), .D_OUT(D_OUT_P28), .RESULT(RESULT_P28));
		PE P27(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P17), .D_IN(D_OUT_P28), .operation(operation), .W_SE(GROUP7_SE), .D_SE(GROUP2_SE), .W_OUT(W_OUT_P27), .D_OUT(D_OUT_P27), .RESULT(RESULT_P27));
		PE P26(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P16), .D_IN(D_OUT_P27), .operation(operation), .W_SE(GROUP6_SE), .D_SE(GROUP2_SE), .W_OUT(W_OUT_P26), .D_OUT(D_OUT_P26), .RESULT(RESULT_P26));
		PE P25(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P15), .D_IN(D_OUT_P26), .operation(operation), .W_SE(GROUP5_SE), .D_SE(GROUP2_SE), .W_OUT(W_OUT_P25), .D_OUT(D_OUT_P25), .RESULT(RESULT_P25));
		PE P24(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P14), .D_IN(D_OUT_P25), .operation(operation), .W_SE(GROUP4_SE), .D_SE(GROUP2_SE), .W_OUT(W_OUT_P24), .D_OUT(D_OUT_P24), .RESULT(RESULT_P24));
		PE P23(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P13), .D_IN(D_OUT_P24), .operation(operation), .W_SE(GROUP3_SE), .D_SE(GROUP2_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P23));
		PE P38(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P28), .D_IN(D_IN_P38), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP3_SE), .W_OUT(W_OUT_P38), .D_OUT(D_OUT_P38), .RESULT(RESULT_P38));
		PE P37(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P27), .D_IN(D_OUT_P38), .operation(operation), .W_SE(GROUP7_SE), .D_SE(GROUP3_SE), .W_OUT(W_OUT_P37), .D_OUT(D_OUT_P37), .RESULT(RESULT_P37));
		PE P36(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P26), .D_IN(D_OUT_P37), .operation(operation), .W_SE(GROUP6_SE), .D_SE(GROUP3_SE), .W_OUT(W_OUT_P36), .D_OUT(D_OUT_P36), .RESULT(RESULT_P36));
		PE P35(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P25), .D_IN(D_OUT_P36), .operation(operation), .W_SE(GROUP5_SE), .D_SE(GROUP3_SE), .W_OUT(W_OUT_P35), .D_OUT(D_OUT_P35), .RESULT(RESULT_P35));
		PE P34(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P24), .D_IN(D_OUT_P35), .operation(operation), .W_SE(GROUP4_SE), .D_SE(GROUP3_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P34));
		PE P48(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P38), .D_IN(D_IN_P48), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP4_SE), .W_OUT(W_OUT_P48), .D_OUT(D_OUT_P48), .RESULT(RESULT_P48));
		PE P47(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P37), .D_IN(D_OUT_P48), .operation(operation), .W_SE(GROUP7_SE), .D_SE(GROUP4_SE), .W_OUT(W_OUT_P47), .D_OUT(D_OUT_P47), .RESULT(RESULT_P47));
		PE P46(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P36), .D_IN(D_OUT_P47), .operation(operation), .W_SE(GROUP6_SE), .D_SE(GROUP4_SE), .W_OUT(W_OUT_P46), .D_OUT(D_OUT_P46), .RESULT(RESULT_P46));
		PE P45(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P35), .D_IN(D_OUT_P46), .operation(operation), .W_SE(GROUP5_SE), .D_SE(GROUP4_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P45));
		PE P58(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P48), .D_IN(D_IN_P58), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP5_SE), .W_OUT(W_OUT_P58), .D_OUT(D_OUT_P58), .RESULT(RESULT_P58));
		PE P57(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P47), .D_IN(D_OUT_P58), .operation(operation), .W_SE(GROUP7_SE), .D_SE(GROUP5_SE), .W_OUT(W_OUT_P57), .D_OUT(D_OUT_P57), .RESULT(RESULT_P57));
		PE P56(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P46), .D_IN(D_OUT_P57), .operation(operation), .W_SE(GROUP6_SE), .D_SE(GROUP5_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P56));
		PE P68(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P58), .D_IN(D_IN_P68), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP6_SE), .W_OUT(W_OUT_P68), .D_OUT(D_OUT_P68), .RESULT(RESULT_P68));
		PE P67(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P57), .D_IN(D_OUT_P68), .operation(operation), .W_SE(GROUP7_SE), .D_SE(GROUP6_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P67));
		PE P78(.CLK(CLK), .RSTN(RSTN), .W_IN(W_OUT_P68), .D_IN(D_IN_P78), .operation(operation), .W_SE(GROUP8_SE), .D_SE(GROUP7_SE), .W_OUT(), .D_OUT(), .RESULT(RESULT_P78));


    // Done signal and cycle counter
    always @(posedge CLK or negedge RSTN) begin
        if (!RSTN) begin
            count <= 0;
			result_enable <= 0;
        end else if(enable) begin
                if (count == 40) begin
					count <= 0;
					result_enable <= 0;
                end else begin
                    count <= count + 1;
					result_enable <= 1;
                end
		end else begin
			count <= 0;
			result_enable <= 0;
		end
        end


endmodule
