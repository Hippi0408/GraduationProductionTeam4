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
 290;
 -4.03727;0.24393;-2.88241;,
 -4.03727;0.24393;11.49804;,
 -6.19523;2.46786;9.56889;,
 -6.19523;2.46786;-2.88241;,
 -4.03727;12.73261;-2.88241;,
 -6.19523;12.73261;-2.88241;,
 -5.04950;12.73261;9.56889;,
 -3.29063;12.73261;11.49804;,
 4.01686;0.24393;-2.88241;,
 6.19523;2.46786;-2.88241;,
 6.19523;2.46786;9.56889;,
 4.01686;0.24393;11.49804;,
 4.01686;12.73261;-2.88241;,
 3.27398;12.73261;11.49804;,
 5.04950;12.73261;9.56889;,
 6.19523;12.73261;-2.88241;,
 3.37181;12.73261;-9.14817;,
 -3.39222;12.73261;-9.14817;,
 -4.03727;12.73261;-2.88241;,
 4.01686;12.73261;-2.88241;,
 -2.89332;12.09468;-13.05610;,
 2.87291;12.09468;-13.05610;,
 2.21426;2.46786;-9.14817;,
 -2.23468;2.46786;-9.14817;,
 -4.03727;0.24393;-2.88241;,
 -3.70989;10.00045;-2.88241;,
 3.68948;10.00045;-2.88241;,
 4.01686;0.24393;-2.88241;,
 -5.04950;10.00045;9.56889;,
 -6.19523;2.46786;9.56889;,
 -4.03727;0.24393;11.49804;,
 -3.29063;10.00045;11.49804;,
 -3.29063;12.73261;11.49804;,
 -5.04950;12.73261;9.56889;,
 5.04950;10.00045;9.56889;,
 5.04950;12.73261;9.56889;,
 3.27398;12.73261;11.49804;,
 3.27398;10.00045;11.49804;,
 4.01686;0.24393;11.49804;,
 6.19523;2.46786;9.56889;,
 1.57445;-1.44442;-14.00654;,
 -1.59486;-1.44442;-14.00654;,
 2.85857;-1.44442;-7.74078;,
 -2.87898;-1.44442;-7.74078;,
 -4.03727;2.46786;-6.09568;,
 -3.70989;10.00045;-8.82036;,
 -6.19523;2.46786;-6.09568;,
 -6.19523;2.46786;-2.88241;,
 -6.19523;10.00045;-8.82036;,
 -6.19523;10.00045;-2.88241;,
 -6.19523;12.73261;-6.09568;,
 -6.19523;12.73261;-2.88241;,
 -4.03727;12.73261;-6.09568;,
 4.01686;12.73261;-6.09568;,
 3.68948;10.00045;-8.82036;,
 6.19523;12.73261;-6.09568;,
 6.19523;12.73261;-2.88241;,
 6.19523;10.00045;-8.82036;,
 6.19523;10.00045;-2.88241;,
 6.19523;2.46786;-6.09568;,
 6.19523;2.46786;-2.88241;,
 4.01686;2.46786;-6.09568;,
 -7.19523;2.46786;-2.88241;,
 -7.19523;10.00045;-2.88241;,
 -6.19523;10.00045;-2.88241;,
 -6.19523;2.46786;-2.88241;,
 -7.19523;2.46786;9.56889;,
 -5.86456;10.00045;9.56889;,
 -5.04950;10.00045;9.56889;,
 -5.86456;12.73261;9.56889;,
 -7.19523;12.73261;-2.88241;,
 -6.19523;12.73261;-2.88241;,
 7.19523;12.73261;-2.88241;,
 7.19523;10.00045;-2.88241;,
 6.19523;10.00045;-2.88241;,
 6.19523;12.73261;-2.88241;,
 5.86456;12.73261;9.56889;,
 5.86456;10.00045;9.56889;,
 5.04950;10.00045;9.56889;,
 7.19523;2.46786;9.56889;,
 7.19523;2.46786;-2.88241;,
 6.19523;2.46786;-2.88241;,
 -8.36036;2.36711;-4.40346;,
 -8.36036;7.83745;-7.19075;,
 -11.61943;24.38770;30.53385;,
 -11.61943;27.35046;29.60827;,
 -11.61943;27.62309;26.73563;,
 -8.36036;9.82163;-8.20173;,
 8.36036;9.82163;-8.20173;,
 8.36036;7.83745;-7.19075;,
 11.61943;27.62309;26.73563;,
 11.61943;27.35046;29.60827;,
 11.61943;24.38770;30.53385;,
 8.36036;2.36711;-4.40346;,
 0.00000;3.32201;11.07248;,
 0.00000;-2.72086;13.95267;,
 3.93416;-1.45439;14.97818;,
 1.89515;3.93206;11.56650;,
 5.56375;1.60302;17.45404;,
 2.68015;5.40489;12.75915;,
 3.93416;4.66046;19.92986;,
 1.89515;6.87769;13.95181;,
 0.00000;5.92685;20.95542;,
 0.00000;7.48774;14.44581;,
 -3.93416;4.66046;19.92986;,
 -1.89515;6.87769;13.95181;,
 -5.56375;1.60302;17.45404;,
 -2.68015;5.40489;12.75915;,
 -3.93416;-1.45439;14.97818;,
 -1.89515;3.93206;11.56650;,
 0.00000;-2.72086;13.95267;,
 0.00000;3.32201;11.07248;,
 0.00000;-3.56013;13.23657;,
 4.71404;-2.04265;14.46541;,
 6.66667;1.62081;17.43207;,
 4.71404;5.28432;20.39868;,
 0.00000;6.80183;21.62752;,
 -4.71405;5.28432;20.39868;,
 -6.66667;1.62081;17.43207;,
 -4.71405;-2.04265;14.46541;,
 0.00000;-3.56013;13.23657;,
 0.00000;6.61880;8.61173;,
 0.00000;10.01178;7.07012;,
 1.17851;6.99818;8.91894;,
 0.00000;10.01178;7.07012;,
 1.66667;7.91404;9.66061;,
 0.00000;10.01178;7.07012;,
 1.17851;8.82991;10.40226;,
 0.00000;10.01178;7.07012;,
 0.00000;9.20930;10.70946;,
 0.00000;10.01178;7.07012;,
 -1.17851;8.82991;10.40226;,
 0.00000;10.01178;7.07012;,
 -1.66667;7.91404;9.66061;,
 0.00000;10.01178;7.07012;,
 -1.17851;6.99818;8.91894;,
 0.00000;10.01178;7.07012;,
 0.00000;6.61880;8.61173;,
 -2.93630;2.50328;11.67650;,
 -2.12365;4.58131;10.40166;,
 0.00000;3.89772;9.84808;,
 0.00000;1.55809;10.91110;,
 -4.15255;4.78521;13.52437;,
 -3.00329;6.23170;11.73809;,
 0.00000;1.55809;10.91110;,
 0.00000;3.89772;9.84808;,
 2.12365;4.58131;10.40166;,
 2.93629;2.50328;11.67650;,
 -2.93630;7.06715;15.37224;,
 -2.12365;7.88208;13.07455;,
 3.00329;6.23170;11.73809;,
 4.15255;4.78521;13.52437;,
 0.00000;8.01237;16.13765;,
 0.00000;8.56570;13.62813;,
 2.12365;7.88208;13.07455;,
 2.93629;7.06715;15.37224;,
 -3.79258;0.31367;13.01980;,
 -3.18365;1.87079;12.06452;,
 0.00000;0.84596;11.23464;,
 0.00000;-0.90720;12.03119;,
 -5.36351;3.26104;15.40656;,
 -4.50236;4.34493;14.06807;,
 0.00000;-0.90720;12.03119;,
 0.00000;0.84596;11.23464;,
 3.18365;1.87079;12.06452;,
 3.79257;0.31367;13.01980;,
 -3.79258;6.20843;17.79329;,
 -3.18365;6.81910;16.07161;,
 4.50236;4.34493;14.06807;,
 5.36351;3.26104;15.40656;,
 0.00000;7.42926;18.78192;,
 0.00000;7.84392;16.90150;,
 3.18365;6.81910;16.07161;,
 3.79257;6.20843;17.79329;,
 -4.02005;5.98030;18.43648;,
 -5.68522;2.85616;15.90658;,
 0.00000;7.27439;19.48440;,
 -4.02005;-0.26799;13.37666;,
 4.02005;5.98030;18.43648;,
 0.00000;-1.56207;12.32877;,
 5.68522;2.85616;15.90658;,
 0.00000;-1.56207;12.32877;,
 4.02005;-0.26799;13.37666;,
 -1.34181;8.66614;10.86397;,
 -1.89761;7.62336;10.01955;,
 -2.75197;6.54803;11.34745;,
 -1.94593;8.06032;12.57207;,
 0.00000;8.68672;13.07933;,
 0.00000;9.09809;11.21374;,
 -1.34181;6.58059;9.17512;,
 -1.94593;5.03578;10.12285;,
 1.94593;8.06032;12.57207;,
 1.34181;8.66614;10.86397;,
 0.00000;6.14865;8.82535;,
 0.00000;4.40937;9.61559;,
 2.75197;6.54803;11.34745;,
 1.89761;7.62336;10.01955;,
 0.00000;6.14865;8.82535;,
 1.34181;6.58059;9.17512;,
 1.94593;5.03578;10.12285;,
 0.00000;4.40937;9.61559;,
 1.89515;3.74326;11.79964;,
 0.00000;3.13322;11.30562;,
 0.00000;3.32201;11.07248;,
 1.89515;3.93206;11.56650;,
 0.00000;5.21609;12.99229;,
 2.68015;5.21609;12.99229;,
 2.68015;5.40489;12.75915;,
 1.89515;6.68887;14.18497;,
 1.89515;6.87769;13.95181;,
 0.00000;7.29897;14.67897;,
 0.00000;7.48774;14.44581;,
 -1.89515;6.68887;14.18497;,
 -1.89515;6.87769;13.95181;,
 -2.68015;5.21609;12.99229;,
 -2.68015;5.40489;12.75915;,
 -1.89515;3.74326;11.79964;,
 -1.89515;3.93206;11.56650;,
 0.00000;4.29301;9.35949;,
 -2.12385;4.97668;9.91311;,
 -2.30157;4.52223;10.19192;,
 0.00000;3.78135;9.59195;,
 -3.25491;6.31089;11.64033;,
 -3.00358;6.62722;11.24968;,
 2.12385;4.97668;9.91311;,
 0.00000;4.29301;9.35949;,
 0.00000;3.78135;9.59195;,
 2.30157;4.52223;10.19192;,
 -2.30157;8.09955;13.08875;,
 -2.12385;8.27776;12.58627;,
 3.00358;6.62722;11.24968;,
 3.25491;6.31089;11.64033;,
 0.00000;8.84043;13.68870;,
 0.00000;8.96144;13.13989;,
 2.12385;8.27776;12.58627;,
 2.30157;8.09955;13.08875;,
 0.00000;1.44170;10.65498;,
 -3.11421;2.44417;11.46677;,
 -3.36157;1.81163;11.85482;,
 0.00000;0.72958;10.97853;,
 -4.75397;4.42412;13.97030;,
 -4.40416;4.86437;13.42661;,
 3.11421;2.44417;11.46677;,
 0.00000;1.44170;10.65498;,
 0.00000;0.72958;10.97853;,
 3.36157;1.81163;11.85482;,
 -3.36157;7.03655;16.08580;,
 -3.11421;7.28456;15.38645;,
 4.40416;4.86437;13.42661;,
 4.75397;4.42412;13.97030;,
 0.00000;8.11864;16.96207;,
 0.00000;8.28705;16.19824;,
 3.11421;7.28456;15.38645;,
 3.36157;7.03655;16.08580;,
 -5.61513;3.34023;15.30879;,
 -3.97049;6.42588;17.80749;,
 -4.19797;6.19774;18.45068;,
 -5.93683;2.93531;15.80880;,
 0.00000;7.54908;19.54496;,
 0.00000;7.70400;18.84249;,
 -3.97049;0.25457;12.81007;,
 -4.19797;-0.32713;13.16693;,
 4.19797;6.19774;18.45068;,
 3.97049;6.42588;17.80749;,
 0.00000;-1.02356;11.77507;,
 0.00000;-1.67845;12.07265;,
 5.93683;2.93531;15.80880;,
 5.61513;3.34023;15.30879;,
 3.97049;0.25457;12.81007;,
 0.00000;-1.02356;11.77507;,
 0.00000;-1.67845;12.07265;,
 4.19797;-0.32713;13.16693;,
 -1.91828;7.99323;9.56282;,
 -1.35643;9.04737;10.41644;,
 -1.51973;8.88359;10.87818;,
 -2.14922;7.70255;9.92178;,
 0.00000;9.37281;11.27432;,
 0.00000;9.48401;10.77001;,
 -1.35643;6.93910;8.70921;,
 -1.51973;6.52148;8.96539;,
 1.51973;8.88359;10.87818;,
 1.35643;9.04737;10.41644;,
 0.00000;6.50244;8.35563;,
 0.00000;6.03227;8.56923;,
 2.14922;7.70255;9.92178;,
 1.91828;7.99323;9.56282;,
 1.35643;6.93910;8.70921;,
 0.00000;6.50244;8.35563;,
 0.00000;6.03227;8.56923;,
 1.51973;6.52148;8.96539;;
 
 236;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;8,11,1,0;,
 4;12,4,7,13;,
 4;12,13,14,15;,
 4;16,17,18,19;,
 4;20,17,16,21;,
 4;20,21,22,23;,
 4;20,23,24,25;,
 4;20,25,18,17;,
 4;21,16,19,26;,
 4;21,26,27,22;,
 4;28,29,30,31;,
 4;28,31,32,33;,
 4;34,35,36,37;,
 4;34,37,38,39;,
 4;31,30,38,37;,
 4;31,37,36,32;,
 4;40,41,23,22;,
 4;42,40,22,27;,
 4;43,42,27,24;,
 4;41,43,24,23;,
 4;41,40,42,43;,
 4;44,45,25,24;,
 4;46,44,24,47;,
 4;48,46,47,49;,
 4;45,44,46,48;,
 4;50,48,49,51;,
 4;52,50,51,18;,
 4;45,52,18,25;,
 4;45,48,50,52;,
 4;53,54,26,19;,
 4;55,53,19,56;,
 4;57,55,56,58;,
 4;54,53,55,57;,
 4;59,57,58,60;,
 4;61,59,60,27;,
 4;54,61,27,26;,
 4;54,57,59,61;,
 4;62,63,64,65;,
 4;66,62,65,2;,
 4;67,66,2,68;,
 4;69,67,68,6;,
 4;70,69,6,71;,
 4;63,70,71,64;,
 4;72,73,74,75;,
 4;76,72,75,14;,
 4;77,76,14,78;,
 4;79,77,78,10;,
 4;80,79,10,81;,
 4;73,80,81,74;,
 4;82,83,63,62;,
 4;84,82,62,66;,
 4;85,84,66,67;,
 4;83,82,84,85;,
 4;86,85,67,69;,
 4;87,86,69,70;,
 4;83,87,70,63;,
 4;83,85,86,87;,
 4;88,89,73,72;,
 4;90,88,72,76;,
 4;91,90,76,77;,
 4;89,88,90,91;,
 4;92,91,77,79;,
 4;93,92,79,80;,
 4;89,93,80,73;,
 4;89,91,92,93;,
 4;94,95,96,97;,
 4;97,96,98,99;,
 4;99,98,100,101;,
 4;101,100,102,103;,
 4;103,102,104,105;,
 4;105,104,106,107;,
 4;107,106,108,109;,
 4;109,108,110,111;,
 4;95,112,113,96;,
 4;96,113,114,98;,
 4;98,114,115,100;,
 4;100,115,116,102;,
 4;102,116,117,104;,
 4;104,117,118,106;,
 4;106,118,119,108;,
 4;108,119,120,110;,
 3;121,122,123;,
 3;123,124,125;,
 3;125,126,127;,
 3;127,128,129;,
 3;129,130,131;,
 3;131,132,133;,
 3;133,134,135;,
 3;135,136,137;,
 4;138,139,140,141;,
 4;138,142,143,139;,
 4;144,145,146,147;,
 4;142,148,149,143;,
 4;147,146,150,151;,
 4;148,152,153,149;,
 4;151,150,154,155;,
 4;152,155,154,153;,
 4;156,157,158,159;,
 4;156,160,161,157;,
 4;162,163,164,165;,
 4;160,166,167,161;,
 4;165,164,168,169;,
 4;166,170,171,167;,
 4;169,168,172,173;,
 4;170,173,172,171;,
 4;174,175,118,117;,
 4;174,117,116,176;,
 4;175,177,119,118;,
 4;176,116,115,178;,
 4;177,179,120,119;,
 4;178,115,114,180;,
 4;181,182,113,112;,
 4;180,114,113,182;,
 4;183,184,185,186;,
 4;183,186,187,188;,
 4;184,189,190,185;,
 4;188,187,191,192;,
 4;189,193,194,190;,
 4;192,191,195,196;,
 4;197,198,199,200;,
 4;196,195,199,198;,
 4;201,202,203,204;,
 3;205,202,201;,
 4;206,201,204,207;,
 3;205,201,206;,
 4;208,206,207,209;,
 3;205,206,208;,
 4;210,208,209,211;,
 3;205,208,210;,
 4;212,210,211,213;,
 3;205,210,212;,
 4;214,212,213,215;,
 3;205,212,214;,
 4;216,214,215,217;,
 3;205,214,216;,
 4;202,216,217,203;,
 3;205,216,202;,
 4;218,219,190,194;,
 4;220,221,140,139;,
 4;220,219,218,221;,
 4;222,220,139,143;,
 4;219,223,185,190;,
 4;220,222,223,219;,
 4;224,225,200,199;,
 4;226,227,146,145;,
 4;226,225,224,227;,
 4;228,222,143,149;,
 4;223,229,186,185;,
 4;222,228,229,223;,
 4;230,224,199,195;,
 4;227,231,150,146;,
 4;227,224,230,231;,
 4;232,228,149,153;,
 4;229,233,187,186;,
 4;228,232,233,229;,
 4;234,230,195,191;,
 4;231,235,154,150;,
 4;231,230,234,235;,
 4;235,232,153,154;,
 4;233,234,191,187;,
 4;232,235,234,233;,
 4;236,237,138,141;,
 4;238,239,158,157;,
 4;238,237,236,239;,
 4;240,238,157,161;,
 4;237,241,142,138;,
 4;238,240,241,237;,
 4;242,243,144,147;,
 4;244,245,164,163;,
 4;244,243,242,245;,
 4;246,240,161,167;,
 4;241,247,148,142;,
 4;240,246,247,241;,
 4;248,242,147,151;,
 4;245,249,168,164;,
 4;245,242,248,249;,
 4;250,246,167,171;,
 4;247,251,152,148;,
 4;246,250,251,247;,
 4;252,248,151,155;,
 4;249,253,172,168;,
 4;249,248,252,253;,
 4;253,250,171,172;,
 4;251,252,155,152;,
 4;250,253,252,251;,
 4;254,255,166,160;,
 4;256,257,175,174;,
 4;256,255,254,257;,
 4;258,256,174,176;,
 4;255,259,170,166;,
 4;256,258,259,255;,
 4;260,254,160,156;,
 4;257,261,177,175;,
 4;257,254,260,261;,
 4;262,258,176,178;,
 4;259,263,173,170;,
 4;258,262,263,259;,
 4;264,260,156,159;,
 4;261,265,179,177;,
 4;261,260,264,265;,
 4;266,262,178,180;,
 4;263,267,169,173;,
 4;262,266,267,263;,
 4;268,269,162,165;,
 4;270,271,182,181;,
 4;270,269,268,271;,
 4;271,266,180,182;,
 4;267,268,165,169;,
 4;266,271,268,267;,
 4;272,273,131,133;,
 4;274,275,184,183;,
 4;274,273,272,275;,
 4;276,274,183,188;,
 4;273,277,129,131;,
 4;274,276,277,273;,
 4;278,272,133,135;,
 4;275,279,189,184;,
 4;275,272,278,279;,
 4;280,276,188,192;,
 4;277,281,127,129;,
 4;276,280,281,277;,
 4;282,278,135,137;,
 4;279,283,193,189;,
 4;279,278,282,283;,
 4;284,280,192,196;,
 4;281,285,125,127;,
 4;280,284,285,281;,
 4;286,287,121,123;,
 4;288,289,198,197;,
 4;288,287,286,289;,
 4;289,284,196,198;,
 4;285,286,123,125;,
 4;284,289,286,285;;
 
 MeshMaterialList {
  5;
  236;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  4,
  4,
  4,
  4,
  4,
  2,
  4,
  2,
  4,
  4,
  4,
  4,
  4,
  2,
  4,
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
  0;;
  Material {
   0.332800;0.332800;0.332800;1.000000;;
   5.000000;
   0.870000;0.870000;0.870000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.731200;0.000000;1.000000;;
   5.000000;
   0.820000;0.820000;0.820000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.000000;0.034400;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.398400;0.000000;1.000000;;
   5.000000;
   0.870000;0.870000;0.870000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  239;
  0.000000;1.000000;0.000000;,
  -0.622571;-0.779228;-0.072172;,
  0.620957;-0.780494;-0.072405;,
  0.387458;-0.921887;-0.000000;,
  -0.389626;-0.920973;0.000000;,
  -0.290517;-0.956577;0.023649;,
  0.288851;-0.957087;0.023430;,
  0.000000;-0.376132;-0.926566;,
  0.000000;0.996729;-0.080818;,
  0.000000;0.986937;-0.161108;,
  -0.986224;-0.080672;-0.144409;,
  0.986224;-0.080673;-0.144409;,
  -1.000000;0.000000;0.000000;,
  1.000000;0.000000;0.000000;,
  -0.387330;0.021844;0.921682;,
  0.385242;0.021693;0.922560;,
  0.000000;-0.986050;0.166451;,
  0.970774;0.078261;-0.226875;,
  0.000000;0.778864;-0.627193;,
  -0.204649;-0.709380;-0.674462;,
  0.000000;0.923617;-0.383316;,
  0.999192;-0.038477;-0.011603;,
  0.000000;0.923617;-0.383317;,
  0.203310;-0.709550;-0.674688;,
  -0.992897;0.118974;0.000000;,
  0.999168;0.040374;-0.005820;,
  -0.999168;0.040374;-0.005820;,
  0.249667;0.951971;-0.177252;,
  0.000000;0.000000;-1.000000;,
  0.467000;-0.873745;0.135941;,
  -0.249667;0.951971;-0.177252;,
  0.000000;0.000000;1.000000;,
  -0.467000;-0.873745;0.135941;,
  0.475351;0.812496;-0.337477;,
  0.906129;-0.054728;-0.419446;,
  -0.975821;-0.053403;-0.211946;,
  0.952383;-0.292405;0.086410;,
  -0.830371;0.549493;-0.092426;,
  -0.954529;-0.047142;0.294369;,
  0.830371;0.549493;-0.092426;,
  -0.952383;-0.292405;0.086410;,
  0.946662;-0.054392;-0.317604;,
  -0.946662;-0.054392;-0.317604;,
  0.970271;0.049865;0.236829;,
  -0.970271;0.049865;0.236829;,
  -0.978294;0.019892;-0.206267;,
  -0.987059;-0.122516;-0.103466;,
  0.987059;-0.122516;-0.103466;,
  0.978293;0.019893;-0.206267;,
  -0.370694;0.043367;0.927742;,
  -0.403893;0.000000;0.914806;,
  0.401745;0.000000;0.915752;,
  0.368669;0.043069;0.928562;,
  -0.970775;0.078258;-0.226875;,
  0.000000;-1.000000;-0.000000;,
  0.000000;-0.340150;-0.940371;,
  0.992897;0.118974;0.000000;,
  0.000000;0.706137;-0.708075;,
  0.000000;0.706137;-0.708075;,
  -0.999192;-0.038477;-0.011603;,
  0.000000;-0.340150;-0.940371;,
  0.954529;-0.047142;0.294369;,
  -0.996522;-0.059458;-0.058381;,
  0.973430;0.146225;0.176218;,
  0.975821;-0.053403;-0.211946;,
  -0.995068;-0.089087;-0.043634;,
  -0.475351;0.812496;-0.337477;,
  -0.973430;0.146225;0.176218;,
  0.996522;-0.059458;-0.058381;,
  0.995068;-0.089087;-0.043634;,
  -0.906129;-0.054728;-0.419446;,
  0.000000;0.430254;0.902708;,
  -0.638138;0.224836;0.736362;,
  -0.902464;-0.271089;0.334769;,
  -0.638136;-0.767018;-0.066827;,
  0.000000;-0.972435;-0.233173;,
  0.638136;-0.767018;-0.066827;,
  0.902464;-0.271089;0.334769;,
  0.638138;0.224836;0.736362;,
  -0.000001;-0.649056;0.760741;,
  0.018131;-0.643211;0.765474;,
  0.025623;-0.629114;0.776890;,
  0.018123;-0.615022;0.788302;,
  0.000001;-0.609185;0.793028;,
  -0.018122;-0.615024;0.788300;,
  -0.025623;-0.629115;0.776890;,
  -0.018132;-0.643213;0.765473;,
  0.000000;-0.413657;-0.910433;,
  0.632459;-0.210067;-0.745565;,
  0.894427;0.281442;-0.347549;,
  0.632462;0.772945;0.050466;,
  0.000000;0.976542;0.215328;,
  -0.632462;0.772945;0.050466;,
  -0.894427;0.281442;-0.347549;,
  -0.632459;-0.210067;-0.745565;,
  -0.632454;-0.210067;-0.745570;,
  0.000000;-0.413655;-0.910434;,
  -0.894425;0.281442;-0.347555;,
  0.632454;-0.210067;-0.745570;,
  -0.632455;0.772952;0.050463;,
  0.894425;0.281442;-0.347555;,
  0.000000;0.976542;0.215326;,
  0.632455;0.772952;0.050463;,
  -0.632452;-0.210067;-0.745571;,
  0.000000;-0.413657;-0.910433;,
  -0.894425;0.281442;-0.347555;,
  0.632452;-0.210069;-0.745570;,
  -0.632455;0.772952;0.050458;,
  0.894426;0.281441;-0.347554;,
  0.000000;0.976544;0.215320;,
  0.632455;0.772952;0.050460;,
  -0.632456;-0.210069;-0.745567;,
  0.000000;-0.413660;-0.910432;,
  -0.894429;0.281439;-0.347548;,
  0.632456;-0.210071;-0.745566;,
  -0.632457;0.772949;0.050473;,
  0.894430;0.281438;-0.347546;,
  0.000000;0.976539;0.215342;,
  0.632457;0.772949;0.050475;,
  -0.632459;0.772948;0.050470;,
  -0.894430;0.281438;-0.347544;,
  0.000000;0.976541;0.215331;,
  -0.632456;-0.210069;-0.745567;,
  0.632459;0.772947;0.050471;,
  0.000000;-0.413656;-0.910433;,
  0.894431;0.281437;-0.347544;,
  0.632457;-0.210071;-0.745566;,
  0.000000;-0.777144;-0.629323;,
  0.707106;-0.549523;-0.445001;,
  1.000000;-0.000001;0.000002;,
  0.707106;0.549532;0.444989;,
  0.000000;0.777166;0.629295;,
  -0.707106;0.549532;0.444989;,
  -1.000000;-0.000001;0.000002;,
  -0.707106;-0.549523;-0.445001;,
  0.000000;0.910442;-0.413636;,
  -0.316267;0.808643;-0.496056;,
  -0.447282;0.562857;-0.695076;,
  -0.316277;0.317060;-0.894115;,
  0.000000;0.215255;-0.976558;,
  0.316277;0.317060;-0.894115;,
  0.447282;0.562857;-0.695076;,
  0.316267;0.808643;-0.496056;,
  -0.000000;-0.629322;0.777144;,
  0.316240;0.808638;-0.496081;,
  0.000000;0.910435;-0.413653;,
  0.447226;0.562880;-0.695093;,
  -0.316240;0.808638;-0.496081;,
  0.316234;0.317114;-0.894111;,
  -0.447226;0.562880;-0.695093;,
  0.000000;0.215310;-0.976546;,
  -0.316234;0.317114;-0.894111;,
  -0.316233;-0.808640;0.496083;,
  0.000000;-0.910441;0.413639;,
  -0.447216;-0.562879;0.695100;,
  0.316233;-0.808640;0.496083;,
  -0.316230;-0.317118;0.894111;,
  0.447216;-0.562879;0.695100;,
  0.000000;-0.215312;0.976545;,
  0.316230;-0.317118;0.894111;,
  0.316198;0.808626;-0.496127;,
  0.000000;0.910410;-0.413707;,
  0.447167;0.562899;-0.695117;,
  -0.316194;0.808626;-0.496131;,
  0.316185;0.317180;-0.894105;,
  -0.447159;0.562901;-0.695120;,
  0.000000;0.215406;-0.976525;,
  -0.316181;0.317184;-0.894105;,
  -0.316155;-0.808604;0.496191;,
  0.000000;-0.910368;0.413799;,
  -0.447187;-0.562870;0.695126;,
  0.316155;-0.808604;0.496191;,
  -0.316246;-0.317105;0.894110;,
  0.447187;-0.562870;0.695126;,
  0.000000;-0.215306;0.976547;,
  0.316246;-0.317105;0.894110;,
  0.316233;0.808638;-0.496086;,
  0.000001;0.910434;-0.413655;,
  0.447220;0.562878;-0.695099;,
  -0.316229;0.808637;-0.496090;,
  0.316237;0.317112;-0.894111;,
  -0.447214;0.562880;-0.695101;,
  0.000001;0.215313;-0.976545;,
  -0.316233;0.317116;-0.894111;,
  -0.316228;-0.317122;0.894111;,
  -0.447177;-0.562884;0.695122;,
  0.000000;-0.215318;0.976544;,
  -0.316177;-0.808620;0.496151;,
  0.316228;-0.317122;0.894111;,
  0.000000;-0.910398;0.413735;,
  0.447177;-0.562884;0.695122;,
  0.316177;-0.808620;0.496151;,
  -0.316221;-0.317138;0.894107;,
  -0.447216;-0.562880;0.695100;,
  0.000000;-0.215356;0.976536;,
  -0.316219;-0.808625;0.496117;,
  0.316221;-0.317138;0.894107;,
  0.000000;-0.910409;0.413710;,
  0.447216;-0.562880;0.695100;,
  0.316219;-0.808625;0.496117;,
  0.000000;-0.629321;0.777146;,
  -0.000004;-0.629318;0.777148;,
  0.000000;-0.629324;0.777143;,
  -0.000009;-0.629327;0.777141;,
  0.000000;-0.629320;0.777146;,
  0.000009;-0.629327;0.777141;,
  0.000004;-0.629318;0.777148;,
  -0.632455;-0.210069;-0.745568;,
  0.000000;-0.413650;-0.910436;,
  -0.894428;0.281438;-0.347550;,
  0.632455;-0.210069;-0.745568;,
  -0.632453;0.772953;0.050458;,
  0.894428;0.281438;-0.347550;,
  0.000000;0.976545;0.215315;,
  0.632453;0.772953;0.050458;,
  -0.632452;-0.210064;-0.745572;,
  0.000000;-0.413652;-0.910435;,
  -0.894417;0.281451;-0.347567;,
  0.632452;-0.210064;-0.745572;,
  -0.632444;0.772963;0.050433;,
  0.894417;0.281451;-0.347567;,
  0.000000;0.976549;0.215294;,
  0.632444;0.772963;0.050433;,
  -0.632459;0.772947;0.050480;,
  -0.894428;0.281441;-0.347548;,
  0.000000;0.976537;0.215348;,
  -0.632455;-0.210074;-0.745567;,
  0.632459;0.772947;0.050480;,
  0.000000;-0.413671;-0.910426;,
  0.894428;0.281441;-0.347548;,
  0.632455;-0.210074;-0.745567;,
  -0.632459;0.772947;0.050481;,
  -0.894432;0.281435;-0.347542;,
  0.000000;0.976539;0.215342;,
  -0.632452;-0.210054;-0.745574;,
  0.632459;0.772947;0.050481;,
  0.000000;-0.413623;-0.910448;,
  0.894432;0.281435;-0.347542;,
  0.632452;-0.210054;-0.745574;;
  236;
  4;5,4,4,1;,
  4;0,0,0,0;,
  4;6,2,3,3;,
  4;6,3,4,5;,
  4;0,0,0,0;,
  4;0,0,0,0;,
  4;8,8,0,0;,
  4;9,8,8,9;,
  4;7,7,7,7;,
  4;10,45,45,10;,
  4;10,10,46,46;,
  4;11,47,47,11;,
  4;11,11,48,48;,
  4;14,49,49,14;,
  4;14,14,50,50;,
  4;15,51,51,15;,
  4;15,15,52,52;,
  4;14,49,52,15;,
  4;14,15,51,50;,
  4;18,18,18,18;,
  4;17,17,48,48;,
  4;16,16,6,5;,
  4;53,53,45,45;,
  4;54,54,16,16;,
  4;21,25,25,21;,
  4;19,19,5,1;,
  4;12,12,1,12;,
  4;55,19,19,55;,
  4;12,12,12,12;,
  4;22,22,0,0;,
  4;25,56,56,25;,
  4;57,57,22,22;,
  4;24,26,26,24;,
  4;20,20,0,0;,
  4;13,13,13,13;,
  4;58,20,20,58;,
  4;13,13,13,2;,
  4;23,23,2,6;,
  4;26,59,59,26;,
  4;60,60,23,23;,
  4;28,28,28,28;,
  4;32,32,1,4;,
  4;31,31,49,14;,
  4;31,31,14,50;,
  4;27,27,0,0;,
  4;28,28,28,28;,
  4;28,28,28,28;,
  4;30,30,0,0;,
  4;31,31,51,15;,
  4;31,31,15,52;,
  4;29,29,3,2;,
  4;28,28,28,28;,
  4;34,41,41,34;,
  4;40,40,32,32;,
  4;43,61,61,43;,
  4;62,40,40,62;,
  4;39,43,43,63;,
  4;33,39,27,27;,
  4;41,64,64,41;,
  4;62,62,65,65;,
  4;35,42,42,35;,
  4;37,66,30,30;,
  4;44,37,67,44;,
  4;68,69,69,68;,
  4;38,44,44,38;,
  4;36,36,29,29;,
  4;42,70,70,42;,
  4;68,68,36,36;,
  4;71,71,72,72;,
  4;72,72,73,73;,
  4;73,73,74,74;,
  4;74,74,75,75;,
  4;75,75,76,76;,
  4;76,76,77,77;,
  4;77,77,78,78;,
  4;78,78,71,71;,
  4;79,79,80,80;,
  4;80,80,81,81;,
  4;81,81,82,82;,
  4;82,82,83,83;,
  4;83,83,84,84;,
  4;84,84,85,85;,
  4;85,85,86,86;,
  4;86,86,79,79;,
  3;87,88,88;,
  3;88,88,89;,
  3;89,90,90;,
  3;90,90,91;,
  3;91,92,92;,
  3;92,92,93;,
  3;93,94,94;,
  3;94,94,87;,
  4;103,103,104,104;,
  4;103,105,105,103;,
  4;104,104,106,106;,
  4;105,107,107,105;,
  4;106,106,108,108;,
  4;107,109,109,107;,
  4;108,108,110,110;,
  4;109,110,110,109;,
  4;111,111,112,112;,
  4;111,113,113,111;,
  4;112,112,114,114;,
  4;113,115,115,113;,
  4;114,114,116,116;,
  4;115,117,117,115;,
  4;116,116,118,118;,
  4;117,118,118,117;,
  4;119,120,120,119;,
  4;119,119,121,121;,
  4;120,122,122,120;,
  4;121,121,123,123;,
  4;122,124,124,122;,
  4;123,123,125,125;,
  4;124,126,126,124;,
  4;125,125,126,126;,
  4;99,97,97,99;,
  4;99,99,101,101;,
  4;97,95,95,97;,
  4;101,101,102,102;,
  4;95,96,96,95;,
  4;102,102,100,100;,
  4;96,98,98,96;,
  4;100,100,98,98;,
  4;128,127,127,128;,
  3;143,200,201;,
  4;129,128,128,129;,
  3;143,201,202;,
  4;130,129,129,130;,
  3;143,202,203;,
  4;131,130,130,131;,
  3;143,203,204;,
  4;132,131,131,132;,
  3;143,204,205;,
  4;133,132,132,133;,
  3;143,205,202;,
  4;134,133,133,134;,
  3;143,202,206;,
  4;127,134,134,127;,
  3;143,206,200;,
  4;145,144,144,145;,
  4;152,153,153,152;,
  4;207,207,208,208;,
  4;154,152,152,154;,
  4;144,146,146,144;,
  4;207,209,209,207;,
  4;147,145,145,147;,
  4;153,155,155,153;,
  4;208,208,210,210;,
  4;156,154,154,156;,
  4;146,148,148,146;,
  4;209,211,211,209;,
  4;149,147,147,149;,
  4;155,157,157,155;,
  4;210,210,212,212;,
  4;158,156,156,158;,
  4;148,150,150,148;,
  4;211,213,213,211;,
  4;151,149,149,151;,
  4;157,159,159,157;,
  4;212,212,214,214;,
  4;159,158,158,159;,
  4;150,151,151,150;,
  4;213,214,214,213;,
  4;161,160,160,161;,
  4;168,169,169,168;,
  4;215,215,216,216;,
  4;170,168,168,170;,
  4;160,162,162,160;,
  4;215,217,217,215;,
  4;163,161,161,163;,
  4;169,171,171,169;,
  4;216,216,218,218;,
  4;172,170,170,172;,
  4;162,164,164,162;,
  4;217,219,219,217;,
  4;165,163,163,165;,
  4;171,173,173,171;,
  4;218,218,220,220;,
  4;174,172,172,174;,
  4;164,166,166,164;,
  4;219,221,221,219;,
  4;167,165,165,167;,
  4;173,175,175,173;,
  4;220,220,222,222;,
  4;175,174,174,175;,
  4;166,167,167,166;,
  4;221,222,222,221;,
  4;178,180,180,178;,
  4;184,185,185,184;,
  4;223,223,224,224;,
  4;186,184,184,186;,
  4;180,182,182,180;,
  4;223,225,225,223;,
  4;176,178,178,176;,
  4;185,187,187,185;,
  4;224,224,226,226;,
  4;188,186,186,188;,
  4;182,183,183,182;,
  4;225,227,227,225;,
  4;177,176,176,177;,
  4;187,189,189,187;,
  4;226,226,228,228;,
  4;190,188,188,190;,
  4;183,181,181,183;,
  4;227,229,229,227;,
  4;179,177,177,179;,
  4;189,191,191,189;,
  4;228,228,230,230;,
  4;191,190,190,191;,
  4;181,179,179,181;,
  4;229,230,230,229;,
  4;141,140,140,141;,
  4;192,193,193,192;,
  4;231,231,232,232;,
  4;194,192,192,194;,
  4;140,139,139,140;,
  4;231,233,233,231;,
  4;142,141,141,142;,
  4;193,195,195,193;,
  4;232,232,234,234;,
  4;196,194,194,196;,
  4;139,138,138,139;,
  4;233,235,235,233;,
  4;135,142,142,135;,
  4;195,197,197,195;,
  4;234,234,236,236;,
  4;198,196,196,198;,
  4;138,137,137,138;,
  4;235,237,237,235;,
  4;136,135,135,136;,
  4;197,199,199,197;,
  4;236,236,238,238;,
  4;199,198,198,199;,
  4;137,136,136,137;,
  4;237,238,238,237;;
 }
 MeshTextureCoords {
  290;
  0.174160;0.000000;,
  0.174160;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.174160;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  0.174160;0.000000;,
  0.824190;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.824190;1.000000;,
  0.824190;1.000000;,
  0.824190;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.824190;0.000000;,
  0.174160;0.000000;,
  0.174160;0.000000;,
  0.824190;0.000000;,
  0.174160;0.266170;,
  0.824190;0.266170;,
  0.824190;1.000000;,
  0.174160;1.000000;,
  0.174160;1.000000;,
  0.174160;0.266170;,
  0.824190;0.266170;,
  0.824190;1.000000;,
  1.000000;0.266170;,
  1.000000;1.000000;,
  0.825840;1.000000;,
  0.825840;0.266170;,
  0.825840;0.000000;,
  1.000000;0.000000;,
  0.000000;0.266170;,
  0.000000;0.000000;,
  0.175810;0.000000;,
  0.175810;0.266170;,
  0.175810;1.000000;,
  0.000000;1.000000;,
  0.824190;1.000000;,
  0.174160;1.000000;,
  0.824190;1.000000;,
  0.174160;1.000000;,
  0.174160;1.000000;,
  0.174160;0.266170;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.266170;,
  0.000000;0.266170;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.174160;0.000000;,
  0.824190;0.000000;,
  0.824190;0.266170;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.266170;,
  1.000000;0.266170;,
  1.000000;1.000000;,
  1.000000;1.000000;,
  0.824190;1.000000;,
  1.000000;1.000000;,
  1.000000;0.266170;,
  1.000000;0.266170;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.266170;,
  0.000000;0.266170;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.266170;,
  0.000000;0.266170;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;0.266170;,
  1.000000;0.266170;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.266170;,
  0.000000;1.000000;,
  0.000000;0.266170;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.266170;,
  1.000000;0.000000;,
  1.000000;0.266170;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.833330;,
  0.125000;0.833330;,
  0.125000;1.000000;,
  0.250000;0.833330;,
  0.250000;1.000000;,
  0.375000;0.833330;,
  0.375000;1.000000;,
  0.500000;0.833330;,
  0.500000;1.000000;,
  0.625000;0.833330;,
  0.625000;1.000000;,
  0.750000;0.833330;,
  0.750000;1.000000;,
  0.875000;0.833330;,
  0.875000;1.000000;,
  1.000000;0.833330;,
  1.000000;1.000000;,
  0.000000;0.666670;,
  0.125000;0.666670;,
  0.250000;0.666670;,
  0.375000;0.666670;,
  0.500000;0.666670;,
  0.625000;0.666670;,
  0.750000;0.666670;,
  0.875000;0.666670;,
  1.000000;0.666670;,
  0.000000;0.166670;,
  0.062500;0.000000;,
  0.125000;0.166670;,
  0.125000;0.000000;,
  0.250000;0.166670;,
  0.187500;0.000000;,
  0.375000;0.166670;,
  0.250000;0.000000;,
  0.500000;0.166670;,
  0.312500;0.000000;,
  0.625000;0.166670;,
  0.375000;0.000000;,
  0.750000;0.166670;,
  0.437500;0.000000;,
  0.875000;0.166670;,
  0.500000;0.000000;,
  1.000000;0.166670;,
  0.875000;0.415250;,
  0.875000;0.300330;,
  1.000000;0.300330;,
  1.000000;0.415250;,
  0.750000;0.415250;,
  0.750000;0.300330;,
  0.000000;0.415250;,
  0.000000;0.300330;,
  0.125000;0.300330;,
  0.125000;0.415250;,
  0.625000;0.415250;,
  0.625000;0.300330;,
  0.250000;0.300330;,
  0.250000;0.415250;,
  0.500000;0.415250;,
  0.500000;0.300330;,
  0.375000;0.300330;,
  0.375000;0.415250;,
  0.875000;0.536350;,
  0.875000;0.450240;,
  1.000000;0.450240;,
  1.000000;0.536350;,
  0.750000;0.536350;,
  0.750000;0.450240;,
  0.000000;0.536350;,
  0.000000;0.450240;,
  0.125000;0.450240;,
  0.125000;0.536350;,
  0.625000;0.536350;,
  0.625000;0.450240;,
  0.250000;0.450240;,
  0.250000;0.536350;,
  0.500000;0.536350;,
  0.500000;0.450240;,
  0.375000;0.450240;,
  0.375000;0.536350;,
  0.625000;0.568520;,
  0.750000;0.568520;,
  0.500000;0.568520;,
  0.875000;0.568520;,
  0.375000;0.568520;,
  1.000000;0.568520;,
  0.250000;0.568520;,
  0.000000;0.568520;,
  0.125000;0.568520;,
  0.625000;0.189760;,
  0.750000;0.189760;,
  0.750000;0.275200;,
  0.625000;0.275200;,
  0.500000;0.275200;,
  0.500000;0.189760;,
  0.875000;0.189760;,
  0.875000;0.275200;,
  0.375000;0.275200;,
  0.375000;0.189760;,
  1.000000;0.189760;,
  1.000000;0.275200;,
  0.250000;0.275200;,
  0.250000;0.189760;,
  0.000000;0.189760;,
  0.125000;0.189760;,
  0.125000;0.275200;,
  0.000000;0.275200;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.275200;,
  0.875000;0.275200;,
  0.875000;0.300330;,
  1.000000;0.300330;,
  0.750000;0.300330;,
  0.750000;0.275200;,
  0.125000;0.275200;,
  0.000000;0.275200;,
  0.000000;0.300330;,
  0.125000;0.300330;,
  0.625000;0.300330;,
  0.625000;0.275200;,
  0.250000;0.275200;,
  0.250000;0.300330;,
  0.500000;0.300330;,
  0.500000;0.275200;,
  0.375000;0.275200;,
  0.375000;0.300330;,
  1.000000;0.415250;,
  0.875000;0.415250;,
  0.875000;0.450240;,
  1.000000;0.450240;,
  0.750000;0.450240;,
  0.750000;0.415250;,
  0.125000;0.415250;,
  0.000000;0.415250;,
  0.000000;0.450240;,
  0.125000;0.450240;,
  0.625000;0.450240;,
  0.625000;0.415250;,
  0.250000;0.415250;,
  0.250000;0.450240;,
  0.500000;0.450240;,
  0.500000;0.415250;,
  0.375000;0.415250;,
  0.375000;0.450240;,
  0.750000;0.536350;,
  0.625000;0.536350;,
  0.625000;0.568520;,
  0.750000;0.568520;,
  0.500000;0.568520;,
  0.500000;0.536350;,
  0.875000;0.536350;,
  0.875000;0.568520;,
  0.375000;0.568520;,
  0.375000;0.536350;,
  1.000000;0.536350;,
  1.000000;0.568520;,
  0.250000;0.568520;,
  0.250000;0.536350;,
  0.125000;0.536350;,
  0.000000;0.536350;,
  0.000000;0.568520;,
  0.125000;0.568520;,
  0.750000;0.166670;,
  0.625000;0.166670;,
  0.625000;0.189760;,
  0.750000;0.189760;,
  0.500000;0.189760;,
  0.500000;0.166670;,
  0.875000;0.166670;,
  0.875000;0.189760;,
  0.375000;0.189760;,
  0.375000;0.166670;,
  1.000000;0.166670;,
  1.000000;0.189760;,
  0.250000;0.189760;,
  0.250000;0.166670;,
  0.125000;0.166670;,
  0.000000;0.166670;,
  0.000000;0.189760;,
  0.125000;0.189760;;
 }
}