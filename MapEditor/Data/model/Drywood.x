xof 0302txt 0064
template Header {
 <3D82AB43-62DA-11cf-AB39-0020AF71E433>
 WORD major;
 WORD minor;
 DWORD flags;
}

template Vector {
 <3D82AB5E-62DA-11cf-AB39-0020AF71E433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template Coords2d {
 <F6F23F44-7686-11cf-8F52-0040333594A3>
 FLOAT u;
 FLOAT v;
}

template Matrix4x4 {
 <F6F23F45-7686-11cf-8F52-0040333594A3>
 array FLOAT matrix[16];
}

template ColorRGBA {
 <35FF44E0-6C7C-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template ColorRGB {
 <D3E16E81-7835-11cf-8F52-0040333594A3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template IndexedColor {
 <1630B820-7842-11cf-8F52-0040333594A3>
 DWORD index;
 ColorRGBA indexColor;
}

template Boolean {
 <4885AE61-78E8-11cf-8F52-0040333594A3>
 WORD truefalse;
}

template Boolean2d {
 <4885AE63-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template MaterialWrap {
 <4885AE60-78E8-11cf-8F52-0040333594A3>
 Boolean u;
 Boolean v;
}

template TextureFilename {
 <A42790E1-7810-11cf-8F52-0040333594A3>
 STRING filename;
}

template Material {
 <3D82AB4D-62DA-11cf-AB39-0020AF71E433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}

template MeshFace {
 <3D82AB5F-62DA-11cf-AB39-0020AF71E433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template MeshFaceWraps {
 <4885AE62-78E8-11cf-8F52-0040333594A3>
 DWORD nFaceWrapValues;
 Boolean2d faceWrapValues;
}

template MeshTextureCoords {
 <F6F23F40-7686-11cf-8F52-0040333594A3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template MeshMaterialList {
 <F6F23F42-7686-11cf-8F52-0040333594A3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material]
}

template MeshNormals {
 <F6F23F43-7686-11cf-8F52-0040333594A3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template MeshVertexColors {
 <1630B821-7842-11cf-8F52-0040333594A3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template Mesh {
 <3D82AB44-62DA-11cf-AB39-0020AF71E433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}

Header{
1;
0;
1;
}

Mesh {
 234;
 0.00295;-0.28760;-0.30062;,
 0.04292;-0.94612;-8.54622;,
 2.70574;-0.82610;-6.08465;,
 2.47112;-0.36850;-13.49010;,
 4.96504;-0.28760;-11.03524;,
 -1.22885;-0.33752;-14.65107;,
 6.52132;-0.94868;-6.12654;,
 8.66796;-0.36796;-11.17979;,
 12.20135;-0.33513;-9.66469;,
 6.50420;-0.82693;-2.63319;,
 11.98246;-0.28760;-4.74705;,
 9.24598;-0.96591;-0.24394;,
 16.00515;-0.32802;-1.39930;,
 6.49318;-0.82822;2.05840;,
 14.70953;-0.35443;1.91023;,
 11.98246;-0.28760;4.14582;,
 6.56155;-0.94916;5.49216;,
 12.16342;-0.36887;7.46151;,
 10.45345;-0.33297;10.61693;,
 2.70242;-0.83044;5.49447;,
 4.96504;-0.28760;10.43397;,
 0.08788;-0.96273;7.97681;,
 2.47794;-0.36267;12.89151;,
 -1.22511;-0.33584;14.04951;,
 -2.66830;-0.82852;5.50035;,
 -2.66830;-0.82852;5.50035;,
 -4.95915;-0.28760;10.43397;,
 -6.58086;-0.95993;5.49809;,
 -10.45286;-0.33693;10.62591;,
 -6.58086;-0.95993;5.49809;,
 -6.48218;-0.82987;2.07679;,
 -12.15878;-0.36496;7.46063;,
 -6.48218;-0.82987;2.07679;,
 -11.97657;-0.28760;4.14582;,
 -9.23780;-0.96544;-0.29626;,
 -14.71738;-0.36683;1.90669;,
 -9.23780;-0.96544;-0.29626;,
 -16.00948;-0.33189;-1.40613;,
 -6.46524;-0.83044;-2.71725;,
 -6.46524;-0.83044;-2.71725;,
 -11.97657;-0.28760;-4.74705;,
 -6.55321;-0.96850;-6.14452;,
 -12.15358;-0.36661;-8.06680;,
 -6.55321;-0.96850;-6.14452;,
 -10.44379;-0.32683;-11.21976;,
 -2.73527;-0.82773;-6.07667;,
 -2.73527;-0.82773;-6.07667;,
 -4.95915;-0.28760;-11.03524;,
 -1.22885;-0.33752;-14.65107;,
 0.04292;-0.94612;-8.54622;,
 2.15040;52.91530;0.01211;,
 4.01355;45.59456;-3.19848;,
 -1.75403;43.68686;-3.87718;,
 1.01179;6.57115;-4.46322;,
 5.55922;8.41886;0.00003;,
 4.36576;44.73488;2.37011;,
 1.00947;5.60779;4.11341;,
 -1.42786;44.03455;3.94711;,
 -2.33429;7.75241;4.16647;,
 -4.16035;43.13304;0.58002;,
 -5.16609;6.10125;1.48113;,
 -4.25935;5.95875;-2.83759;,
 -1.75403;43.68686;-3.87718;,
 1.01179;6.57115;-4.46322;,
 5.30944;2.92269;-6.60202;,
 -0.41043;3.39323;-8.74586;,
 -0.41043;3.39323;-8.74586;,
 2.47112;-0.36850;-13.49010;,
 5.30944;2.92269;-6.60202;,
 4.96504;-0.28760;-11.03524;,
 9.10451;2.35636;-0.89539;,
 6.38120;2.43689;4.86589;,
 -0.31742;3.17209;8.03682;,
 -6.16809;3.40270;5.94886;,
 -8.91345;2.85121;-0.49937;,
 -6.05947;2.95185;-6.43325;,
 -9.01005;51.32915;-9.17278;,
 -7.06286;46.61219;-6.37576;,
 -6.67828;46.87469;-4.15233;,
 -10.14344;56.86749;-13.87098;,
 -8.13894;50.90396;-11.54818;,
 -5.70348;46.35948;-8.18474;,
 -3.33402;46.26891;-8.47594;,
 -5.55874;51.10549;-10.80863;,
 -1.23678;46.47617;-6.37244;,
 -6.42985;51.53064;-8.43324;,
 -1.99303;46.84516;-3.49599;,
 -4.69931;46.98969;-2.82734;,
 0.46117;42.08333;0.23444;,
 -1.73032;42.65103;2.11478;,
 -2.76082;43.89910;0.48343;,
 -2.48355;43.27860;-1.54966;,
 -0.70405;42.49572;-2.88089;,
 1.34452;43.52147;-2.88741;,
 3.17882;42.53587;-0.65753;,
 2.37499;41.92732;2.15696;,
 -0.31205;41.95130;2.98944;,
 -2.48355;43.27860;-1.54966;,
 -0.70405;42.49572;-2.88089;,
 1.34452;43.52147;-2.88741;,
 3.17882;42.53587;-0.65753;,
 2.37499;41.92732;2.15696;,
 -6.53653;51.60864;5.97220;,
 -3.37085;46.93259;5.95264;,
 -2.27691;47.32767;3.10756;,
 -8.67360;55.58438;8.48526;,
 -8.19006;51.22092;7.75785;,
 -5.59792;46.45923;6.29648;,
 -9.98281;50.84086;6.82319;,
 -7.25020;46.20877;4.86851;,
 -9.80438;50.90803;4.82422;,
 -7.49821;46.29098;2.66166;,
 -6.19668;46.65773;0.96860;,
 -7.80705;51.35496;4.19217;,
 -4.10802;47.09416;0.78114;,
 -0.13612;40.36995;-0.28431;,
 2.47521;40.57690;-0.39365;,
 1.81333;42.09493;2.08734;,
 0.08009;41.50549;2.97941;,
 -1.92553;40.76175;2.31999;,
 -3.04684;41.73617;0.72936;,
 -2.31107;40.79987;-1.91314;,
 0.31715;40.22177;-2.82119;,
 1.81333;42.09493;2.08734;,
 2.47521;40.57690;-0.39365;,
 -1.74888;48.91175;-18.06266;,
 -0.21277;45.05594;-16.42466;,
 -2.13549;44.92908;-16.90035;,
 -1.29376;40.46602;-11.82367;,
 -2.76759;41.77913;-11.28628;,
 -1.77650;43.46848;-10.20670;,
 -1.60533;46.12198;-15.55931;,
 0.67679;42.82042;-10.23958;,
 0.67747;40.97657;-11.27397;,
 -0.34573;38.84725;0.92221;,
 -2.35076;37.58857;-0.93067;,
 -0.07870;36.50390;0.99428;,
 -2.56745;40.24427;-0.22847;,
 -0.99715;41.28931;-0.75676;,
 1.06816;40.87496;0.78193;,
 1.82000;38.62457;1.73288;,
 -1.84286;40.54048;-0.99591;,
 -1.61646;38.68506;-0.72981;,
 0.79905;39.59174;-1.01107;,
 -0.01847;41.72028;-1.06336;,
 1.06816;40.87496;0.78193;,
 0.67679;42.82042;-10.23958;,
 -1.77650;43.46848;-10.20670;,
 0.67747;40.97657;-11.27397;,
 -0.07870;36.50390;0.99428;,
 -1.29376;40.46602;-11.82367;,
 2.99433;43.72461;-6.35714;,
 0.79905;39.59174;-1.01107;,
 -1.61646;38.68506;-0.72981;,
 -0.01847;41.72028;-1.06336;,
 -1.84286;40.54048;-0.99591;,
 13.66991;45.85988;6.57912;,
 8.48797;38.98956;5.97135;,
 9.23963;38.55096;4.05716;,
 7.49775;40.68008;5.97807;,
 7.57877;41.58541;3.63625;,
 8.69419;40.18866;2.48442;,
 -2.19888;36.53026;-0.90078;,
 -2.21034;34.17066;-0.89499;,
 -1.44794;35.56684;1.84612;,
 -2.10140;38.20943;1.41921;,
 -0.90974;39.07673;0.12895;,
 -1.39755;38.38081;-2.33732;,
 -1.98344;36.03262;-3.15980;,
 11.48950;42.57136;-3.78825;,
 5.96396;40.37747;-4.28206;,
 5.97161;42.41512;-3.95049;,
 5.85429;41.09269;-0.12555;,
 -1.04902;38.66404;1.31246;,
 0.06013;37.18743;-1.16050;,
 -1.09218;36.37587;0.55277;,
 -0.19341;39.39794;-0.65926;,
 -1.39755;38.38081;-2.33732;,
 -1.98344;36.03262;-3.15980;,
 -1.09218;36.37587;0.55277;,
 0.06013;37.18743;-1.16050;,
 -0.19341;39.39794;-0.65926;,
 5.97161;42.41512;-3.95049;,
 -12.63415;46.43077;6.73927;,
 -10.52008;38.02113;4.21956;,
 -9.49207;38.47879;6.00112;,
 -8.02946;39.98627;5.80882;,
 -8.08366;40.61995;3.63625;,
 -9.81528;39.22194;2.63527;,
 0.05244;33.20639;-0.90080;,
 -0.92227;32.47018;1.84612;,
 -0.54719;30.92425;-0.89499;,
 0.39289;34.85361;1.41921;,
 -0.53368;35.99976;0.12894;,
 -0.24261;35.20130;-2.33732;,
 -0.28445;32.78147;-3.15982;,
 -11.66911;42.49299;-3.84626;,
 -6.35847;40.87522;-4.07670;,
 -6.87518;38.87828;-4.27146;,
 -6.45379;40.08730;-0.20551;,
 -0.67907;34.40783;1.02513;,
 -1.95950;34.42588;-1.16050;,
 -1.14247;36.49545;-0.65926;,
 -0.54719;30.92425;-0.89499;,
 -0.92227;32.47018;1.84612;,
 -0.53368;35.99976;0.12894;,
 -0.24261;35.20130;-2.33732;,
 -0.28445;32.78147;-3.15982;,
 5.65034;48.44866;17.76953;,
 3.65125;40.75953;11.72564;,
 5.58647;41.89974;10.99260;,
 4.85555;43.87563;9.98254;,
 4.96203;51.97373;18.86440;,
 4.57289;49.77061;16.42299;,
 1.84651;43.62815;10.30954;,
 3.45257;48.46255;17.58829;,
 1.57421;41.74999;11.33076;,
 -0.33714;38.60789;-1.65417;,
 2.66988;37.78966;-0.45180;,
 -0.07000;36.00167;-1.75427;,
 2.00702;40.69931;-1.13593;,
 0.32396;41.46207;0.01412;,
 -2.23162;40.46220;-0.91874;,
 -2.78985;37.81232;-1.77473;,
 1.45692;40.86509;-0.06187;,
 1.58061;38.79176;-0.35658;,
 -1.02318;39.19023;0.81704;,
 -0.67962;41.69811;0.69604;,
 -0.07000;36.00167;-1.75427;,
 2.66988;37.78966;-0.45180;,
 2.00702;40.69931;-1.13593;,
 0.32396;41.46207;0.01412;,
 -2.23162;40.46220;-0.91874;,
 -2.30335;43.19870;7.42121;;
 
 328;
 3;0,1,2;,
 3;1,3,2;,
 3;2,3,4;,
 3;1,5,3;,
 3;0,2,6;,
 3;2,7,6;,
 3;6,7,8;,
 3;2,4,7;,
 3;0,6,9;,
 3;6,8,9;,
 3;9,8,10;,
 3;0,9,11;,
 3;9,12,11;,
 3;9,10,12;,
 3;0,11,13;,
 3;11,14,13;,
 3;13,14,15;,
 3;11,12,14;,
 3;0,13,16;,
 3;13,17,16;,
 3;16,17,18;,
 3;13,15,17;,
 3;0,16,19;,
 3;16,18,19;,
 3;19,18,20;,
 3;0,19,21;,
 3;19,22,21;,
 3;21,22,23;,
 3;19,20,22;,
 3;0,21,24;,
 3;21,23,25;,
 3;25,23,26;,
 3;0,24,27;,
 3;25,28,29;,
 3;25,26,28;,
 3;0,27,30;,
 3;29,31,32;,
 3;32,31,33;,
 3;29,28,31;,
 3;0,30,34;,
 3;32,35,36;,
 3;36,35,37;,
 3;32,33,35;,
 3;0,34,38;,
 3;36,37,39;,
 3;39,37,40;,
 3;0,38,41;,
 3;39,42,43;,
 3;43,42,44;,
 3;39,40,42;,
 3;0,41,45;,
 3;43,44,46;,
 3;46,44,47;,
 3;0,45,1;,
 3;46,48,49;,
 3;46,47,48;,
 3;50,51,52;,
 3;51,53,52;,
 3;51,54,53;,
 3;50,55,51;,
 3;55,54,51;,
 3;55,56,54;,
 3;50,57,55;,
 3;55,57,56;,
 3;57,58,56;,
 3;50,59,57;,
 3;59,60,58;,
 3;59,58,57;,
 3;59,61,60;,
 3;50,52,59;,
 3;62,61,59;,
 3;62,63,61;,
 3;53,64,65;,
 3;66,67,48;,
 3;66,68,69;,
 3;66,69,67;,
 3;64,7,4;,
 3;64,8,7;,
 3;54,70,64;,
 3;54,64,53;,
 3;64,70,10;,
 3;64,10,8;,
 3;70,12,10;,
 3;54,71,70;,
 3;70,14,12;,
 3;70,71,15;,
 3;70,15,14;,
 3;54,56,71;,
 3;71,17,15;,
 3;71,18,17;,
 3;71,20,18;,
 3;56,72,71;,
 3;72,22,20;,
 3;72,20,71;,
 3;72,23,22;,
 3;56,58,72;,
 3;58,73,72;,
 3;72,73,26;,
 3;72,26,23;,
 3;60,73,58;,
 3;73,28,26;,
 3;60,74,73;,
 3;73,31,28;,
 3;73,74,33;,
 3;73,33,31;,
 3;74,35,33;,
 3;74,37,35;,
 3;61,74,60;,
 3;74,40,37;,
 3;61,75,74;,
 3;75,42,40;,
 3;75,40,74;,
 3;75,44,42;,
 3;75,47,44;,
 3;61,63,66;,
 3;61,66,75;,
 3;66,48,47;,
 3;66,47,75;,
 3;76,77,78;,
 3;79,80,76;,
 3;80,77,76;,
 3;80,81,77;,
 3;80,82,81;,
 3;79,83,80;,
 3;83,82,80;,
 3;83,84,82;,
 3;79,85,83;,
 3;85,84,83;,
 3;85,86,84;,
 3;85,87,86;,
 3;79,76,85;,
 3;76,87,85;,
 3;76,78,87;,
 3;88,89,90;,
 3;88,90,91;,
 3;88,91,92;,
 3;88,92,93;,
 3;88,93,94;,
 3;88,94,95;,
 3;88,95,96;,
 3;88,96,89;,
 3;78,90,89;,
 3;78,77,97;,
 3;78,97,90;,
 3;81,97,77;,
 3;81,98,97;,
 3;82,98,81;,
 3;82,99,98;,
 3;84,100,99;,
 3;84,99,82;,
 3;84,101,100;,
 3;86,101,84;,
 3;86,87,101;,
 3;87,96,95;,
 3;87,78,89;,
 3;87,89,96;,
 3;102,103,104;,
 3;105,106,102;,
 3;106,103,102;,
 3;106,107,103;,
 3;105,108,106;,
 3;108,109,106;,
 3;106,109,107;,
 3;105,110,108;,
 3;110,111,108;,
 3;108,111,109;,
 3;110,112,111;,
 3;105,113,110;,
 3;113,112,110;,
 3;113,114,112;,
 3;113,104,114;,
 3;105,102,113;,
 3;102,104,113;,
 3;115,116,117;,
 3;115,117,118;,
 3;115,118,119;,
 3;115,119,120;,
 3;115,120,121;,
 3;115,121,122;,
 3;115,122,116;,
 3;104,123,124;,
 3;103,123,104;,
 3;103,118,123;,
 3;103,107,118;,
 3;107,119,118;,
 3;107,109,119;,
 3;109,120,119;,
 3;109,111,120;,
 3;111,121,120;,
 3;112,121,111;,
 3;112,122,121;,
 3;114,122,112;,
 3;104,124,122;,
 3;104,122,114;,
 3;125,126,127;,
 3;127,126,128;,
 3;127,128,129;,
 3;127,129,130;,
 3;125,127,131;,
 3;131,127,130;,
 3;131,130,132;,
 3;125,131,126;,
 3;126,131,132;,
 3;126,132,133;,
 3;126,133,128;,
 3;134,135,136;,
 3;134,137,135;,
 3;134,138,137;,
 3;134,139,138;,
 3;134,140,139;,
 3;134,136,140;,
 3;141,142,143;,
 3;141,143,144;,
 3;128,136,135;,
 3;135,129,128;,
 3;135,137,129;,
 3;137,130,129;,
 3;130,137,138;,
 3;138,145,130;,
 3;139,146,147;,
 3;139,140,146;,
 3;140,148,146;,
 3;148,140,149;,
 3;148,149,150;,
 3;151,152,153;,
 3;151,154,152;,
 3;151,155,154;,
 3;151,153,155;,
 3;156,157,158;,
 3;156,159,157;,
 3;156,160,159;,
 3;156,161,160;,
 3;156,158,161;,
 3;162,163,164;,
 3;162,164,165;,
 3;162,165,166;,
 3;162,166,167;,
 3;162,167,168;,
 3;162,168,163;,
 3;169,170,171;,
 3;169,171,172;,
 3;169,172,170;,
 3;173,174,175;,
 3;173,176,174;,
 3;158,157,164;,
 3;158,164,163;,
 3;159,164,157;,
 3;159,165,164;,
 3;159,166,165;,
 3;160,166,159;,
 3;160,177,166;,
 3;160,178,177;,
 3;161,178,160;,
 3;161,158,178;,
 3;158,163,178;,
 3;170,179,180;,
 3;170,180,181;,
 3;170,181,171;,
 3;176,173,182;,
 3;173,172,171;,
 3;173,175,172;,
 3;172,175,170;,
 3;183,184,185;,
 3;183,185,186;,
 3;183,186,187;,
 3;183,187,188;,
 3;183,188,184;,
 3;189,190,191;,
 3;189,192,190;,
 3;189,193,192;,
 3;189,194,193;,
 3;189,195,194;,
 3;189,191,195;,
 3;196,197,198;,
 3;196,199,197;,
 3;196,198,199;,
 3;200,201,202;,
 3;184,203,204;,
 3;184,204,185;,
 3;204,192,186;,
 3;204,186,185;,
 3;186,192,205;,
 3;205,187,186;,
 3;205,206,187;,
 3;206,207,187;,
 3;207,188,187;,
 3;188,207,203;,
 3;188,203,184;,
 3;198,201,200;,
 3;198,202,201;,
 3;198,197,202;,
 3;197,200,202;,
 3;199,200,197;,
 3;199,198,200;,
 3;208,209,210;,
 3;208,210,211;,
 3;212,208,213;,
 3;213,208,211;,
 3;213,211,214;,
 3;212,213,215;,
 3;215,213,214;,
 3;215,214,216;,
 3;215,216,209;,
 3;212,215,208;,
 3;208,215,209;,
 3;217,218,219;,
 3;217,220,218;,
 3;217,221,220;,
 3;217,222,221;,
 3;217,223,222;,
 3;217,219,223;,
 3;224,225,226;,
 3;224,226,227;,
 3;209,228,229;,
 3;209,229,210;,
 3;229,230,211;,
 3;229,211,210;,
 3;211,230,231;,
 3;231,214,211;,
 3;231,232,214;,
 3;222,223,214;,
 3;214,223,216;,
 3;216,223,228;,
 3;216,228,209;,
 3;233,226,225;,
 3;233,227,226;,
 3;233,224,227;,
 3;233,225,224;;
 
 MeshMaterialList {
  3;
  328;
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  1,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0;;
  Material {
   0.483200;0.426400;0.344800;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\Cedar.png";
   }
  }
  Material {
   0.448800;0.392000;0.320000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\Cedar.png";
   }
  }
  Material {
   0.696750;0.726750;0.750000;1.000000;;
   8.000000;
   0.020000;0.020000;0.020000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\Cedar.png";
   }
  }
 }
 MeshNormals {
  331;
  -0.071648;0.142397;-0.987213;,
  0.286801;0.140761;-0.947593;,
  0.173051;0.445563;-0.878366;,
  0.852439;0.394101;-0.343558;,
  0.966074;0.097393;0.239200;,
  0.375009;0.378805;0.846094;,
  0.166677;0.118483;0.978867;,
  -0.546823;0.301853;0.780941;,
  -0.838418;0.506847;0.200405;,
  -0.462847;0.503341;-0.729671;,
  -0.963575;0.221118;0.150436;,
  -0.659840;0.536346;-0.526254;,
  0.358624;0.807979;-0.467502;,
  0.074886;-0.994152;-0.077810;,
  0.034780;-0.995117;-0.092371;,
  -0.003403;-0.993491;-0.113859;,
  0.094075;-0.995457;-0.014686;,
  0.083674;-0.995798;-0.037220;,
  0.542219;0.840236;0.001199;,
  0.077731;-0.994838;-0.065228;,
  0.072630;-0.993494;0.087721;,
  0.084451;-0.995784;0.035817;,
  0.102947;-0.994680;-0.003726;,
  0.013640;-0.994424;0.104568;,
  0.400166;0.825242;0.398550;,
  0.041503;-0.995046;0.090342;,
  0.078243;-0.993709;0.080128;,
  -0.057532;-0.994667;0.085601;,
  0.106031;0.801981;0.587864;,
  -0.034412;-0.995060;0.093119;,
  -0.455027;0.794119;0.402897;,
  -0.013535;-0.994338;0.105397;,
  -0.105416;-0.994416;-0.004967;,
  -0.083749;-0.995740;0.038573;,
  -0.071363;-0.993730;0.086072;,
  -0.077606;-0.994766;-0.066463;,
  -0.538406;0.842564;-0.014285;,
  -0.086735;-0.995755;-0.030797;,
  -0.105637;-0.994395;0.004360;,
  -0.012166;-0.993927;-0.109369;,
  -0.390136;0.845901;-0.363656;,
  -0.035804;-0.995084;-0.092335;,
  -0.015555;0.827621;-0.561072;,
  -0.056031;-0.994892;-0.083965;,
  0.000218;-1.000000;-0.000209;,
  0.013568;-0.999232;-0.036760;,
  0.003819;-0.999844;-0.017222;,
  0.008743;-0.999852;-0.014807;,
  0.037224;-0.999117;-0.019459;,
  0.016506;-0.999854;0.004450;,
  0.033524;-0.999289;0.017273;,
  0.013540;-0.999861;0.009743;,
  0.018148;-0.999102;0.038299;,
  0.004146;-0.999832;0.017875;,
  -0.015864;-0.999003;0.041742;,
  -0.014091;-0.999858;0.009276;,
  -0.033902;-0.999295;0.016121;,
  -0.016071;-0.999865;0.003318;,
  -0.037254;-0.999198;-0.014652;,
  -0.012881;-0.999853;-0.011357;,
  -0.013131;-0.998970;-0.043433;,
  0.966564;0.255506;-0.021690;,
  0.988342;0.146946;-0.039826;,
  0.514278;0.327483;0.792637;,
  0.211965;0.323246;0.922271;,
  0.238987;0.174061;0.955295;,
  -0.733175;0.499762;0.461186;,
  -0.781713;0.270316;0.562008;,
  -0.859907;0.274941;-0.430078;,
  0.283283;0.827777;-0.484288;,
  -0.126624;0.846440;-0.517209;,
  0.223562;0.813812;-0.536404;,
  0.095637;0.840191;-0.533791;,
  0.325303;0.914462;-0.240703;,
  0.412136;0.889260;-0.198395;,
  0.353196;0.928880;-0.111507;,
  0.325708;0.915974;0.234321;,
  0.393653;0.902788;0.173235;,
  0.400951;0.911462;0.092061;,
  0.181275;0.930057;0.319582;,
  0.229781;0.865061;0.445949;,
  0.269903;0.845708;0.460359;,
  -0.118345;0.865349;0.486997;,
  0.447776;0.683895;0.576007;,
  -0.198684;0.789795;0.580301;,
  -0.239799;0.853459;0.462714;,
  -0.506828;0.853749;0.119321;,
  -0.484737;0.855736;0.180960;,
  -0.377013;0.884775;0.273925;,
  -0.394451;0.911818;-0.114000;,
  -0.451232;0.867097;-0.211029;,
  -0.453201;0.884959;-0.107034;,
  -0.212565;0.885965;-0.412167;,
  -0.240498;0.801046;-0.548165;,
  -0.801389;-0.570813;0.178742;,
  -0.566456;-0.824090;0.001562;,
  -0.158770;-0.974771;-0.156888;,
  -0.543041;-0.839075;0.032551;,
  -0.767318;-0.634711;-0.091461;,
  -0.045511;-0.935490;-0.350409;,
  -0.379362;-0.817140;-0.434012;,
  0.498525;-0.627634;-0.597954;,
  0.343368;-0.503994;-0.792520;,
  0.059733;-0.951786;-0.300892;,
  0.716875;-0.117851;-0.687169;,
  0.038719;-0.992132;-0.119055;,
  0.463689;0.813039;0.352079;,
  -0.198068;-0.974834;-0.102308;,
  -0.113851;0.731704;0.672047;,
  -0.183562;-0.881263;-0.435524;,
  -0.882986;-0.395355;-0.253043;,
  -0.914121;-0.393792;-0.096496;,
  -0.678125;-0.584253;-0.445864;,
  0.440848;-0.201709;-0.874624;,
  0.454409;0.816396;0.356384;,
  0.284756;-0.263301;-0.921730;,
  0.284604;-0.285346;-0.915193;,
  0.733207;0.663214;0.150181;,
  0.702177;0.699605;0.132289;,
  0.615456;0.773956;0.149015;,
  -0.264464;0.591821;0.761451;,
  -0.337943;0.616692;0.710975;,
  -0.502411;0.497424;0.707214;,
  0.357367;-0.619040;-0.699341;,
  0.730851;-0.147525;-0.666403;,
  0.377536;0.837229;0.395618;,
  0.389495;0.870952;0.299559;,
  0.063295;0.777487;0.625706;,
  -0.292969;0.624356;0.724120;,
  0.377047;-0.689424;0.618491;,
  -0.028384;-0.981263;0.190572;,
  0.588706;0.145843;0.795082;,
  0.299046;-0.645498;0.702783;,
  -0.322134;-0.873739;0.364430;,
  -0.124373;-0.501764;0.856017;,
  -0.630150;-0.658948;0.410730;,
  -0.599486;-0.799365;0.040399;,
  -0.433754;-0.895031;0.103809;,
  -0.851293;-0.481057;-0.209488;,
  -0.451950;0.239286;-0.859351;,
  0.192975;0.633055;-0.749668;,
  -0.063896;-0.996858;0.046810;,
  0.088073;-0.945193;0.314411;,
  0.676332;0.703044;-0.219782;,
  0.736721;-0.030967;0.675487;,
  0.739912;0.315163;0.594309;,
  0.556069;0.069646;0.828213;,
  -0.589480;-0.465819;0.659944;,
  -0.878892;0.065516;-0.472500;,
  0.116382;0.701841;-0.702762;,
  -0.420773;-0.194346;0.886104;,
  -0.424478;-0.410580;0.806996;,
  -0.739520;0.516638;-0.431502;,
  -0.993830;-0.063629;-0.090848;,
  -0.359037;0.627622;-0.690784;,
  0.583694;0.634229;-0.507006;,
  0.528638;0.701908;-0.477355;,
  0.793237;0.601168;0.096817;,
  0.653439;0.655940;-0.377835;,
  -0.547141;0.048168;-0.835653;,
  0.188687;0.547076;-0.815540;,
  -0.136499;-0.865838;-0.481344;,
  -0.438241;0.161569;0.884217;,
  -0.844058;-0.483380;-0.232185;,
  -0.813461;-0.142319;0.563939;,
  -0.714106;0.676861;0.178640;,
  -0.462674;0.464725;0.754959;,
  -0.287046;0.768234;0.572208;,
  0.717023;0.677340;0.164582;,
  -0.155229;0.774838;0.612805;,
  -0.335043;0.135762;0.932370;,
  0.890925;-0.408346;-0.198761;,
  -0.514264;-0.032244;0.857026;,
  0.247790;-0.293507;-0.923284;,
  0.237207;-0.521259;-0.819769;,
  -0.957652;0.228141;0.175654;,
  0.279763;-0.588723;-0.758379;,
  0.310933;0.179727;0.933284;,
  0.443511;0.191849;0.875495;,
  0.243682;-0.813165;-0.528567;,
  0.038061;0.090084;0.995207;,
  0.059092;0.148779;0.987103;,
  -0.685081;-0.599668;-0.413597;,
  -0.940220;0.297777;0.165273;,
  -0.886582;0.448969;0.111354;,
  -0.958433;0.161652;0.235107;,
  0.558209;0.731689;0.391197;,
  0.247271;0.920753;0.301781;,
  0.699524;0.496868;0.513604;,
  0.857717;0.471308;0.205402;,
  0.990724;0.066764;-0.118358;,
  0.354107;-0.702370;-0.617483;,
  0.051034;-0.952778;-0.299348;,
  -0.474161;-0.838791;-0.267582;,
  -0.978866;0.199400;0.045394;,
  0.945108;0.325880;0.023962;,
  0.992053;-0.091742;-0.086103;,
  0.763162;-0.620834;-0.179301;,
  0.771141;0.309840;0.556184;,
  -0.542769;0.839833;0.009076;,
  -0.672554;-0.184838;-0.716593;,
  0.445140;-0.879622;0.167679;,
  -0.757484;-0.100319;0.645100;,
  -0.982074;0.187793;-0.016259;,
  0.480395;-0.794832;0.370760;,
  -0.277901;-0.065965;0.958342;,
  -0.978542;0.184248;-0.092239;,
  -0.577419;0.816336;0.013514;,
  -0.425869;0.896485;0.122267;,
  -0.764987;0.631881;-0.124583;,
  -0.980779;0.148734;-0.126300;,
  0.032995;0.651428;-0.757993;,
  -0.996267;0.005050;0.086177;,
  0.710367;-0.572066;0.410023;,
  -0.349909;0.149286;-0.924812;,
  -0.792172;0.102875;-0.601565;,
  -0.679663;0.089701;-0.728019;,
  -0.257397;0.156139;-0.953608;,
  -0.148001;0.936092;0.319104;,
  -0.889862;0.082927;-0.448629;,
  -0.853535;0.178606;-0.489466;,
  0.024469;0.160471;-0.986737;,
  -0.062873;-0.040792;0.997187;,
  -0.193498;-0.117213;0.974074;,
  -0.635562;0.727253;0.259161;,
  -0.465573;0.837410;0.286331;,
  -0.048332;0.612223;-0.789207;,
  0.200561;0.518095;-0.831476;,
  0.779507;-0.278977;-0.560839;,
  0.673242;-0.383119;-0.632429;,
  -0.036325;0.944827;0.325549;,
  -0.216094;0.935967;0.277973;,
  0.350802;-0.921296;0.167786;,
  0.454087;-0.763264;0.459600;,
  0.447872;-0.892284;0.056918;,
  0.183293;-0.917670;0.352542;,
  0.165390;-0.896643;0.410703;,
  -0.436515;0.037280;0.898924;,
  -0.358231;0.893763;0.269923;,
  0.510150;-0.097458;-0.854546;,
  0.502695;0.171354;-0.847311;,
  0.492338;-0.695906;-0.522798;,
  0.493343;-0.869835;0.000076;,
  0.405345;-0.901065;-0.154199;,
  -0.347349;0.918080;0.190992;,
  -0.303412;0.919342;0.250502;,
  0.296128;-0.305989;0.904809;,
  0.997215;-0.072788;-0.016256;,
  -0.600008;-0.620045;0.505503;,
  0.303488;-0.098029;0.947779;,
  0.717068;-0.268682;0.643136;,
  0.965258;0.258828;0.035854;,
  0.633651;0.772386;0.043652;,
  0.764271;0.644737;-0.014281;,
  0.902466;0.412353;-0.124580;,
  0.012093;0.572174;-0.820043;,
  0.985855;-0.110180;-0.126297;,
  -0.528917;-0.699875;0.480023;,
  0.963627;-0.252973;0.086181;,
  -0.768218;-0.353116;0.533994;,
  0.710811;-0.112451;-0.694336;,
  0.649735;-0.092034;-0.754569;,
  0.263203;0.025952;-0.964391;,
  0.495738;0.848557;0.184917;,
  0.842344;-0.212599;-0.495235;,
  0.358750;0.015574;-0.933304;,
  -0.012617;0.100295;-0.994878;,
  0.159286;-0.028663;0.986816;,
  0.240051;-0.109867;0.964523;,
  0.814910;0.561553;0.143460;,
  0.671616;0.711906;0.205238;,
  0.076810;0.515798;-0.853260;,
  -0.144040;0.495574;-0.856539;,
  -0.884786;-0.085151;-0.458153;,
  -0.752918;-0.365345;-0.547391;,
  -0.783965;-0.274502;-0.556819;,
  0.293498;0.935315;0.197596;,
  0.361065;0.835058;0.415102;,
  -0.559903;-0.776547;0.288935;,
  -0.675657;-0.657877;0.332695;,
  -0.634727;-0.720243;0.279948;,
  -0.376184;-0.828123;0.415570;,
  -0.373890;-0.826451;0.420933;,
  0.425488;-0.073219;0.901997;,
  -0.441211;0.295630;-0.847311;,
  -0.255515;0.475574;-0.841749;,
  -0.672416;-0.532194;-0.514419;,
  -0.657588;-0.491613;-0.570872;,
  -0.740288;-0.517274;0.429419;,
  -0.726383;-0.590895;0.351015;,
  0.389167;0.756441;0.525687;,
  0.021272;0.630653;0.775774;,
  0.094213;0.230998;-0.968382;,
  0.571857;-0.730137;0.374004;,
  0.927759;0.239812;-0.285927;,
  0.727140;0.075353;-0.682341;,
  0.097262;0.539343;-0.836451;,
  -0.084002;0.853620;-0.514078;,
  -0.745528;0.659216;-0.098090;,
  0.037185;0.401011;-0.915318;,
  -0.010642;0.181813;-0.983276;,
  -0.960340;0.227155;0.161701;,
  0.129071;-0.825644;0.549229;,
  0.215181;0.059495;-0.974760;,
  0.866107;0.294552;-0.403853;,
  0.149470;-0.541074;0.827585;,
  0.868371;0.340869;-0.360194;,
  -0.902972;0.410022;-0.128546;,
  -0.622009;0.083035;-0.778595;,
  -0.731165;0.067410;-0.678862;,
  -0.365358;0.053330;-0.929338;,
  0.110937;-0.839897;0.531288;,
  -0.395055;0.106138;-0.912505;,
  0.897350;0.305337;-0.318641;,
  0.939908;0.210122;-0.269112;,
  -0.653698;0.632962;-0.414775;,
  -0.010600;0.912436;-0.409083;,
  -0.838583;0.464159;-0.285192;,
  -0.189433;-0.504632;0.842295;,
  -0.464947;-0.717833;0.518209;,
  -0.080085;-0.309893;0.947393;,
  0.014265;-0.944118;0.329297;,
  0.512819;-0.842652;0.164181;,
  0.946903;0.148691;-0.285072;,
  -0.311796;0.938034;-0.151245;,
  -0.943957;0.096936;0.315515;,
  -0.944233;0.180460;0.275423;,
  -0.510245;-0.761953;0.398845;,
  -0.958795;0.118898;-0.258022;,
  0.318940;0.938482;-0.132399;,
  0.892098;-0.010987;0.451708;;
  328;
  3;44,46,45;,
  3;46,13,45;,
  3;45,13,14;,
  3;46,43,13;,
  3;44,45,47;,
  3;45,15,47;,
  3;47,15,16;,
  3;45,14,15;,
  3;44,47,48;,
  3;47,16,48;,
  3;48,16,17;,
  3;44,48,49;,
  3;48,19,49;,
  3;48,17,19;,
  3;44,49,50;,
  3;49,20,50;,
  3;50,20,21;,
  3;49,19,20;,
  3;44,50,51;,
  3;50,22,51;,
  3;51,22,23;,
  3;50,21,22;,
  3;44,51,52;,
  3;51,23,52;,
  3;52,23,25;,
  3;44,52,53;,
  3;52,26,53;,
  3;53,26,27;,
  3;52,25,26;,
  3;44,53,54;,
  3;53,27,54;,
  3;54,27,29;,
  3;44,54,55;,
  3;54,31,55;,
  3;54,29,31;,
  3;44,55,56;,
  3;55,32,56;,
  3;56,32,33;,
  3;55,31,32;,
  3;44,56,57;,
  3;56,34,57;,
  3;57,34,35;,
  3;56,33,34;,
  3;44,57,58;,
  3;57,35,58;,
  3;58,35,37;,
  3;44,58,59;,
  3;58,38,59;,
  3;59,38,39;,
  3;58,37,38;,
  3;44,59,60;,
  3;59,39,60;,
  3;60,39,41;,
  3;44,60,46;,
  3;60,43,46;,
  3;60,41,43;,
  3;9,1,0;,
  3;1,2,0;,
  3;1,3,2;,
  3;61,4,62;,
  3;4,3,62;,
  3;4,5,63;,
  3;64,6,65;,
  3;65,6,5;,
  3;6,7,5;,
  3;66,10,67;,
  3;10,8,7;,
  3;10,7,67;,
  3;10,11,8;,
  3;9,68,10;,
  3;68,11,10;,
  3;0,2,11;,
  3;2,12,42;,
  3;42,69,70;,
  3;42,12,71;,
  3;42,71,69;,
  3;12,72,71;,
  3;12,73,72;,
  3;3,18,12;,
  3;3,12,2;,
  3;12,18,74;,
  3;12,74,73;,
  3;18,75,74;,
  3;3,24,18;,
  3;18,76,75;,
  3;18,24,77;,
  3;18,77,76;,
  3;63,5,24;,
  3;24,78,77;,
  3;24,79,78;,
  3;24,80,79;,
  3;5,28,24;,
  3;28,81,80;,
  3;28,80,24;,
  3;28,82,81;,
  3;5,83,28;,
  3;7,30,28;,
  3;28,30,84;,
  3;28,84,82;,
  3;8,30,7;,
  3;30,85,84;,
  3;8,36,30;,
  3;30,86,85;,
  3;30,36,87;,
  3;30,87,86;,
  3;36,88,87;,
  3;36,89,88;,
  3;11,36,8;,
  3;36,90,89;,
  3;11,40,36;,
  3;40,91,90;,
  3;40,90,36;,
  3;40,92,91;,
  3;40,93,92;,
  3;11,2,42;,
  3;11,42,40;,
  3;42,70,93;,
  3;42,93,40;,
  3;111,98,94;,
  3;110,112,111;,
  3;112,98,111;,
  3;112,100,98;,
  3;112,102,100;,
  3;115,113,116;,
  3;113,102,116;,
  3;113,104,102;,
  3;117,114,118;,
  3;114,119,118;,
  3;114,106,119;,
  3;114,108,106;,
  3;120,121,120;,
  3;121,108,114;,
  3;121,122,108;,
  3;96,109,95;,
  3;96,95,97;,
  3;96,97,99;,
  3;96,99,101;,
  3;96,101,103;,
  3;96,103,105;,
  3;96,105,107;,
  3;96,107,109;,
  3;123,123,109;,
  3;94,98,97;,
  3;94,97,95;,
  3;100,97,98;,
  3;100,99,97;,
  3;102,99,100;,
  3;102,101,99;,
  3;104,124,101;,
  3;104,101,102;,
  3;119,125,126;,
  3;106,125,119;,
  3;106,108,125;,
  3;108,127,125;,
  3;108,122,128;,
  3;108,128,127;,
  3;145,131,143;,
  3;144,146,145;,
  3;146,131,145;,
  3;146,134,131;,
  3;150,147,151;,
  3;147,135,151;,
  3;151,135,134;,
  3;152,148,153;,
  3;148,138,153;,
  3;147,138,135;,
  3;148,139,138;,
  3;152,149,154;,
  3;149,139,148;,
  3;149,140,139;,
  3;149,143,140;,
  3;155,156,149;,
  3;156,143,149;,
  3;130,142,129;,
  3;130,129,132;,
  3;130,132,133;,
  3;130,133,136;,
  3;130,136,137;,
  3;130,137,141;,
  3;130,141,142;,
  3;143,157,158;,
  3;131,157,143;,
  3;131,132,129;,
  3;131,134,132;,
  3;134,133,132;,
  3;134,135,133;,
  3;135,136,133;,
  3;135,138,136;,
  3;138,137,136;,
  3;139,159,138;,
  3;139,160,159;,
  3;140,160,139;,
  3;143,158,160;,
  3;143,160,140;,
  3;173,176,174;,
  3;174,176,161;,
  3;182,161,163;,
  3;183,184,165;,
  3;185,183,175;,
  3;175,183,165;,
  3;186,187,168;,
  3;188,186,189;,
  3;189,186,168;,
  3;189,190,171;,
  3;176,191,161;,
  3;162,164,172;,
  3;162,166,164;,
  3;162,167,166;,
  3;162,169,167;,
  3;162,170,169;,
  3;162,172,170;,
  3;180,181,177;,
  3;180,177,178;,
  3;161,192,193;,
  3;193,163,161;,
  3;164,194,163;,
  3;194,165,184;,
  3;165,166,167;,
  3;167,169,165;,
  3;169,168,187;,
  3;195,196,168;,
  3;196,171,168;,
  3;171,196,197;,
  3;171,192,161;,
  3;179,179,179;,
  3;198,178,177;,
  3;199,199,199;,
  3;200,200,200;,
  3;213,204,201;,
  3;222,205,223;,
  3;224,208,225;,
  3;226,211,227;,
  3;228,229,229;,
  3;203,212,202;,
  3;203,202,206;,
  3;203,206,207;,
  3;203,207,209;,
  3;203,209,210;,
  3;203,210,212;,
  3;221,214,217;,
  3;230,231,218;,
  3;232,233,234;,
  3;219,215,220;,
  3;219,216,215;,
  3;201,204,235;,
  3;201,235,236;,
  3;205,202,223;,
  3;205,237,202;,
  3;225,207,238;,
  3;208,207,225;,
  3;208,209,207;,
  3;227,239,240;,
  3;211,239,227;,
  3;229,229,239;,
  3;201,241,239;,
  3;234,242,243;,
  3;214,215,216;,
  3;214,216,217;,
  3;244,245,231;,
  3;245,218,231;,
  3;246,246,233;,
  3;233,242,234;,
  3;259,257,248;,
  3;267,268,249;,
  3;269,270,252;,
  3;271,272,255;,
  3;273,274,275;,
  3;247,250,258;,
  3;247,251,250;,
  3;247,253,251;,
  3;247,254,253;,
  3;247,256,254;,
  3;247,258,256;,
  3;266,262,265;,
  3;276,263,277;,
  3;278,279,280;,
  3;264,260,261;,
  3;257,281,282;,
  3;257,282,248;,
  3;250,283,249;,
  3;250,249,268;,
  3;270,251,253;,
  3;253,252,270;,
  3;253,254,252;,
  3;284,285,272;,
  3;285,255,272;,
  3;274,286,287;,
  3;274,287,275;,
  3;279,288,289;,
  3;265,261,260;,
  3;265,262,261;,
  3;277,290,291;,
  3;263,290,277;,
  3;280,279,289;,
  3;305,302,293;,
  3;313,314,294;,
  3;304,313,306;,
  3;306,313,294;,
  3;315,316,298;,
  3;317,315,307;,
  3;307,315,298;,
  3;307,298,301;,
  3;318,319,302;,
  3;320,318,305;,
  3;305,318,302;,
  3;292,295,303;,
  3;292,296,295;,
  3;292,297,296;,
  3;292,299,297;,
  3;292,300,299;,
  3;292,303,300;,
  3;310,312,308;,
  3;310,308,309;,
  3;302,321,322;,
  3;302,322,293;,
  3;295,323,294;,
  3;295,294,314;,
  3;316,296,297;,
  3;297,298,316;,
  3;297,324,298;,
  3;325,326,298;,
  3;298,326,301;,
  3;319,327,327;,
  3;319,321,302;,
  3;311,311,311;,
  3;328,309,308;,
  3;329,329,329;,
  3;330,330,330;;
 }
 MeshTextureCoords {
  234;
  0.001562;1.224604;,
  0.000799;1.249756;,
  0.066594;1.245172;,
  0.028834;1.227694;,
  0.067289;1.224604;,
  -0.013318;1.226511;,
  0.129966;1.249854;,
  0.104965;1.227674;,
  0.143381;1.226420;,
  0.188777;1.245204;,
  0.189967;1.224604;,
  0.245802;1.250512;,
  0.236121;1.226148;,
  0.298859;1.245253;,
  0.270553;1.227157;,
  0.303014;1.224604;,
  0.360917;1.249872;,
  0.337574;1.227708;,
  0.376235;1.226337;,
  0.427250;1.245338;,
  0.429312;1.224604;,
  0.498247;1.250391;,
  0.469777;1.227472;,
  0.513843;1.226447;,
  -0.428115;1.245265;,
  0.571885;1.245265;,
  0.570615;1.224604;,
  -0.360771;1.250284;,
  0.623693;1.226488;,
  0.639229;1.250284;,
  -0.299346;1.245316;,
  0.662408;1.227559;,
  0.700654;1.245316;,
  0.696962;1.224604;,
  -0.244898;1.250494;,
  0.729495;1.227630;,
  0.755102;1.250494;,
  0.763943;1.226296;,
  -0.186677;1.245338;,
  0.813323;1.245338;,
  0.810060;1.224604;,
  -0.130121;1.250611;,
  0.843260;1.227622;,
  0.869879;1.250611;,
  0.880698;1.226103;,
  -0.067316;1.245234;,
  0.932684;1.245234;,
  0.932781;1.224604;,
  0.986682;1.226511;,
  1.000799;1.249756;,
  0.250896;-0.807468;,
  0.142911;-0.527854;,
  -0.067616;-0.454990;,
  0.035480;0.962636;,
  0.250001;0.892063;,
  0.329158;-0.495019;,
  0.461699;0.999431;,
  0.555243;-0.468270;,
  0.581278;0.917518;,
  0.727953;-0.433837;,
  0.705562;0.980584;,
  0.843532;0.986026;,
  0.932384;-0.454990;,
  1.035480;0.962636;,
  0.107796;1.101988;,
  -0.007463;1.084016;,
  0.992537;1.084016;,
  1.028834;1.227694;,
  1.107797;1.101988;,
  1.067289;1.224604;,
  0.234398;1.123619;,
  0.353686;1.120543;,
  0.506283;1.092462;,
  0.627879;1.083654;,
  0.758907;1.104718;,
  0.879760;1.100874;,
  0.876424;-0.746885;,
  0.866870;-0.566722;,
  0.838533;-0.576748;,
  0.899509;-0.958421;,
  0.902290;-0.730645;,
  0.903138;-0.557070;,
  0.940355;-0.553610;,
  0.924399;-0.738343;,
  0.969490;-0.561527;,
  0.896324;-0.754581;,
  0.917536;-0.575620;,
  0.836203;-0.581141;,
  0.324853;-0.393743;,
  0.609139;-0.415426;,
  0.722411;-0.463096;,
  -0.161214;-0.439396;,
  -0.038148;-0.409494;,
  0.069358;-0.448673;,
  0.217537;-0.411028;,
  0.367349;-0.387784;,
  0.516553;-0.388700;,
  0.838786;-0.439396;,
  0.961852;-0.409494;,
  1.069358;-0.448673;,
  1.217537;-0.411028;,
  1.367349;-0.387784;,
  0.632175;-0.757560;,
  0.582005;-0.578960;,
  0.600640;-0.594050;,
  0.626747;-0.909413;,
  0.629312;-0.742751;,
  0.615664;-0.560880;,
  0.654577;-0.728235;,
  0.655885;-0.551314;,
  0.677224;-0.730801;,
  0.695713;-0.554453;,
  0.725322;-0.568461;,
  0.671571;-0.747871;,
  0.720094;-0.585131;,
  0.928934;-0.328301;,
  1.224899;-0.336206;,
  1.386162;-0.394186;,
  0.495723;-0.371673;,
  0.610255;-0.343266;,
  0.712605;-0.380484;,
  0.860051;-0.344722;,
  1.017817;-0.322641;,
  0.386162;-0.394186;,
  0.224899;-0.336206;,
  0.984638;-0.654553;,
  0.997938;-0.507281;,
  0.979996;-0.502436;,
  0.982654;-0.331970;,
  0.961728;-0.382124;,
  0.972573;-0.446649;,
  0.983637;-0.547999;,
  1.010504;-0.421896;,
  1.009552;-0.351471;,
  0.557085;-0.270142;,
  0.809996;-0.222067;,
  0.512571;-0.180638;,
  0.764126;-0.323501;,
  0.853321;-0.363416;,
  0.350571;-0.347590;,
  0.371098;-0.261637;,
  0.828854;-0.334814;,
  0.817496;-0.263947;,
  1.106443;-0.298578;,
  0.997236;-0.379877;,
  1.350571;-0.347590;,
  0.010504;-0.421896;,
  -0.027427;-0.446649;,
  0.009552;-0.351471;,
  -0.487429;-0.180638;,
  -0.017346;-0.331970;,
  0.070059;-0.456432;,
  0.106443;-0.298578;,
  -0.182504;-0.263947;,
  -0.002764;-0.379877;,
  -0.171146;-0.334814;,
  0.321391;-0.537988;,
  0.347574;-0.275577;,
  0.315851;-0.258825;,
  0.357127;-0.340147;,
  0.321198;-0.374725;,
  0.294299;-0.321377;,
  0.811880;-0.181645;,
  0.811232;-0.091521;,
  0.605855;-0.144847;,
  0.655462;-0.245781;,
  0.727590;-0.278907;,
  0.914232;-0.252326;,
  0.910786;-0.162638;,
  0.199311;-0.412383;,
  0.150895;-0.328588;,
  0.156982;-0.406416;,
  0.246587;-0.355906;,
  0.607318;-0.263144;,
  1.008239;-0.206746;,
  0.675431;-0.175748;,
  0.954582;-0.291175;,
  -0.085768;-0.252326;,
  -0.089214;-0.162638;,
  -0.324569;-0.175748;,
  0.008239;-0.206746;,
  -0.045418;-0.291175;,
  1.156982;-0.406416;,
  0.672011;-0.559793;,
  0.689290;-0.238589;,
  0.660272;-0.256069;,
  0.650324;-0.313647;,
  0.682724;-0.337850;,
  0.708254;-0.284453;,
  0.009255;-0.054691;,
  -0.426263;-0.026571;,
  -0.087337;0.032475;,
  0.457016;-0.117606;,
  -0.287730;-0.161383;,
  -0.016461;-0.130886;,
  -0.014289;-0.038461;,
  0.800674;-0.409390;,
  0.840738;-0.347600;,
  0.838478;-0.271327;,
  0.755066;-0.317505;,
  0.593115;-0.100579;,
  0.835100;-0.101269;,
  0.833297;-0.180315;,
  0.912663;0.032475;,
  0.573737;-0.026571;,
  0.712270;-0.161383;,
  0.983539;-0.130886;,
  0.985711;-0.038461;,
  0.451001;-0.636865;,
  0.451955;-0.343181;,
  0.425167;-0.386731;,
  0.427949;-0.462200;,
  0.459064;-0.771505;,
  0.456779;-0.687357;,
  0.471793;-0.452747;,
  0.469150;-0.637396;,
  0.478029;-0.381011;,
  0.968001;-0.261000;,
  1.223320;-0.229748;,
  0.993653;-0.161456;,
  1.168031;-0.340881;,
  1.256932;-0.370014;,
  0.812157;-0.331825;,
  0.840172;-0.230613;,
  0.243245;-0.347213;,
  0.214686;-0.268023;,
  0.642754;-0.283242;,
  0.623100;-0.379030;,
  -0.006347;-0.161456;,
  0.223320;-0.229748;,
  0.168031;-0.340881;,
  0.256932;-0.370014;,
  -0.187843;-0.331825;,
  0.547897;-0.436345;;
 }
}