xof 0303txt 0032
template AnimTicksPerSecond {
 <9e415a43-7ba6-4a73-8743-b73d47e88476>
 DWORD AnimTicksPerSecond;
}

template Frame {
 <3d82ab46-62da-11cf-ab39-0020af71e433>
 [...]
}

template Matrix4x4 {
 <f6f23f45-7686-11cf-8f52-0040333594a3>
 array FLOAT matrix[16];
}

template FrameTransformMatrix {
 <f6f23f41-7686-11cf-8f52-0040333594a3>
 Matrix4x4 frameMatrix;
}

template Vector {
 <3d82ab5e-62da-11cf-ab39-0020af71e433>
 FLOAT x;
 FLOAT y;
 FLOAT z;
}

template MeshFace {
 <3d82ab5f-62da-11cf-ab39-0020af71e433>
 DWORD nFaceVertexIndices;
 array DWORD faceVertexIndices[nFaceVertexIndices];
}

template Mesh {
 <3d82ab44-62da-11cf-ab39-0020af71e433>
 DWORD nVertices;
 array Vector vertices[nVertices];
 DWORD nFaces;
 array MeshFace faces[nFaces];
 [...]
}


template MeshNormals {
 <f6f23f43-7686-11cf-8f52-0040333594a3>
 DWORD nNormals;
 array Vector normals[nNormals];
 DWORD nFaceNormals;
 array MeshFace faceNormals[nFaceNormals];
}

template Coords2d {
 <f6f23f44-7686-11cf-8f52-0040333594a3>
 FLOAT u;
 FLOAT v;
}

template MeshTextureCoords {
 <f6f23f40-7686-11cf-8f52-0040333594a3>
 DWORD nTextureCoords;
 array Coords2d textureCoords[nTextureCoords];
}

template ColorRGBA {
 <35ff44e0-6c7c-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
 FLOAT alpha;
}

template IndexedColor {
 <1630b820-7842-11cf-8f52-0040333594a3>
 DWORD index;
 ColorRGBA indexColor;
}

template MeshVertexColors {
 <1630b821-7842-11cf-8f52-0040333594a3>
 DWORD nVertexColors;
 array IndexedColor vertexColors[nVertexColors];
}

template ColorRGB {
 <d3e16e81-7835-11cf-8f52-0040333594a3>
 FLOAT red;
 FLOAT green;
 FLOAT blue;
}

template Material {
 <3d82ab4d-62da-11cf-ab39-0020af71e433>
 ColorRGBA faceColor;
 FLOAT power;
 ColorRGB specularColor;
 ColorRGB emissiveColor;
 [...]
}


template MeshMaterialList {
 <f6f23f42-7686-11cf-8f52-0040333594a3>
 DWORD nMaterials;
 DWORD nFaceIndexes;
 array DWORD faceIndexes[nFaceIndexes];
 [Material <3d82ab4d-62da-11cf-ab39-0020af71e433>]
}

template VertexDuplicationIndices {
 <b8d65549-d7c9-4995-89cf-53a9a8b031e3>
 DWORD nIndices;
 DWORD nOriginalVertices;
 array DWORD indices[nIndices];
}

template XSkinMeshHeader {
 <3cf169ce-ff7c-44ab-93c0-f78f62d172e2>
 WORD nMaxSkinWeightsPerVertex;
 WORD nMaxSkinWeightsPerFace;
 WORD nBones;
}

template SkinWeights {
 <6f0d123b-bad2-4167-a0d0-80224f25fabb>
 STRING transformNodeName;
 DWORD nWeights;
 array DWORD vertexIndices[nWeights];
 array FLOAT weights[nWeights];
 Matrix4x4 matrixOffset;
}

template RDB2ExtInfo1 {
 <10b97487-12b6-41f9-896f-af119248bd3c>
 DWORD StringNum;
 array STRING InfoString[StringNum];
}

template TextureFilename {
 <a42790e1-7810-11cf-8f52-0040333594a3>
 STRING filename;
}


template Animation {
 <3d82ab4f-62da-11cf-ab39-0020af71e433>
 [...]
}

template AnimationSet {
 <3d82ab50-62da-11cf-ab39-0020af71e433>
 [Animation <3d82ab4f-62da-11cf-ab39-0020af71e433>]
}

template FloatKeys {
 <10dd46a9-775b-11cf-8f52-0040333594a3>
 DWORD nValues;
 array FLOAT values[nValues];
}

template TimedFloatKeys {
 <f406b180-7b3b-11cf-8f52-0040333594a3>
 DWORD time;
 FloatKeys tfkeys;
}

template AnimationKey {
 <10dd46a8-775b-11cf-8f52-0040333594a3>
 DWORD keyType;
 DWORD nKeys;
 array TimedFloatKeys keys[nKeys];
}

template RDB2TimedDSKeys {
 <2f286f31-2b2c-4bbc-b75e-1623aaa4861e>
 DWORD StringNum;
 array STRING KeyString[StringNum];
}

template RDB2DSAnime {
 <cf1812c0-060d-498f-8a23-4aca594ac560>
 STRING AnimName;
 DWORD nKeys;
 array RDB2TimedDSKeys keys[nKeys];
}


AnimTicksPerSecond {
 60;
}

Frame ReplacedName0 {


 FrameTransformMatrix {
  1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
 }

 Frame ReplacedName1 {


  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

  Frame Hip {


   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }

   Mesh Hip_PM2 {
    180;
    2.425524;-1.153944;-4.601253;,
    3.465170;1.460559;-3.319947;,
    3.724077;0.370629;-3.313794;,
    3.999948;2.445312;1.536711;,
    2.564337;2.513448;3.091776;,
    3.006801;0.703815;3.362481;,
    4.785963;1.077819;-0.922635;,
    4.339122;1.261101;1.645779;,
    4.446779;2.061303;-0.985506;,
    1.286880;-1.140690;-5.028893;,
    1.397679;0.866745;-4.613529;,
    1.061898;-2.882433;-4.725488;,
    1.580142;-2.812056;-4.587749;,
    0.877227;-4.339145;-3.686319;,
    0.880818;-4.237679;2.283546;,
    0.000000;-5.139014;0.329160;,
    0.791745;-4.815764;0.327465;,
    0.000000;2.473935;4.030532;,
    1.281162;0.794358;4.216079;,
    1.314339;2.470413;3.723294;,
    0.000000;0.780363;4.521452;,
    1.214703;-1.269945;4.323653;,
    1.201431;-3.110250;3.850311;,
    0.000000;-4.508750;2.416284;,
    0.000000;-1.265298;4.570307;,
    0.000000;-3.194454;4.122020;,
    2.125797;1.946877;-2.418882;,
    1.422687;2.450244;-4.267955;,
    1.089801;1.701846;-3.148053;,
    3.042384;2.720367;-3.125478;,
    0.000000;1.469949;-3.512937;,
    0.000000;2.321028;-4.645068;,
    3.860250;3.134904;-0.899838;,
    2.418092;2.571642;0.769584;,
    3.501693;3.462273;1.409841;,
    2.817684;2.350362;-0.919818;,
    1.706976;3.623448;2.805540;,
    0.000000;2.472576;2.149371;,
    0.000000;3.695073;3.347991;,
    1.267074;2.532980;1.708881;,
    0.000000;1.371855;-0.951774;,
    1.208484;1.775265;-0.129444;,
    1.397337;1.693104;-0.957183;,
    0.662289;1.482372;-2.222040;,
    0.000000;1.376937;-2.397111;,
    1.383711;0.070383;1.048122;,
    2.867046;1.006347;1.154364;,
    2.097330;0.479742;2.301894;,
    1.692798;0.420807;0.442296;,
    2.514096;0.331743;-2.602068;,
    1.306569;-0.539694;-1.781586;,
    1.756617;-0.805788;-3.424386;,
    1.654161;0.119472;-1.503051;,
    1.006050;-1.229142;-1.740453;,
    0.651555;-3.345684;-2.016408;,
    1.120959;-2.289048;-3.267603;,
    0.803241;-1.705020;-1.088781;,
    3.051342;0.939441;-0.706506;,
    1.890159;0.494961;-0.534516;,
    0.585306;-3.432312;0.044847;,
    0.835539;-1.386621;0.876936;,
    0.930072;-2.576859;1.969572;,
    0.683745;-1.768434;-0.139698;,
    1.033959;-0.585975;1.186569;,
    1.285734;-1.067397;2.697381;,
    0.791745;-4.815764;0.327465;,
    0.000000;-5.286201;-1.924161;,
    0.700869;-4.984721;-1.870350;,
    0.000000;3.695073;3.347991;,
    1.706976;3.623448;2.805540;,
    3.501693;3.462273;1.409841;,
    3.860250;3.134904;-0.899838;,
    3.042384;2.720367;-3.125478;,
    1.422687;2.450244;-4.267955;,
    0.000000;0.652026;-5.059025;,
    0.000000;2.321028;-4.645068;,
    1.742778;-1.293231;4.076217;,
    0.000000;-1.142739;-5.155211;,
    0.000000;-4.629312;-3.740466;,
    0.877227;-4.339145;-3.686319;,
    1.580142;-2.812056;-4.587749;,
    0.700869;-4.984721;-1.870350;,
    0.791745;-4.815764;0.327465;,
    0.880818;-4.237679;2.283546;,
    1.201431;-3.110250;3.850311;,
    1.742778;-1.293231;4.076217;,
    3.006801;0.703815;3.362481;,
    4.339122;1.261101;1.645779;,
    4.785963;1.077819;-0.922635;,
    3.724077;0.370629;-3.313794;,
    2.425524;-1.153944;-4.601253;,
    1.096320;-0.430497;-0.345399;,
    0.633537;1.863744;0.614994;,
    1.179054;1.634007;-1.769646;,
    0.000000;1.829073;0.889557;,
    -1.397679;0.866745;-4.613529;,
    -2.425524;-1.153944;-4.601253;,
    -3.465170;1.460559;-3.319947;,
    -3.999948;2.445312;1.536711;,
    -4.339122;1.261101;1.645779;,
    -3.006801;0.703815;3.362481;,
    -4.446779;2.061303;-0.985506;,
    -4.785963;1.077819;-0.922635;,
    -3.724077;0.370629;-3.313794;,
    -1.286880;-1.140690;-5.028893;,
    -1.580142;-2.812056;-4.587749;,
    -1.061898;-2.882433;-4.725488;,
    -0.877227;-4.339145;-3.686319;,
    -0.880818;-4.237679;2.283546;,
    -0.791745;-4.815764;0.327465;,
    -1.281162;0.794358;4.216079;,
    -1.314339;2.470413;3.723294;,
    -1.214703;-1.269945;4.323653;,
    -1.201431;-3.110250;3.850311;,
    -1.422687;2.450244;-4.267955;,
    -2.125797;1.946877;-2.418882;,
    -1.089801;1.701846;-3.148053;,
    -3.042384;2.720367;-3.125478;,
    0.000000;1.469949;-3.512937;,
    0.000000;2.321028;-4.645068;,
    -2.418092;2.571642;0.769584;,
    -3.860250;3.134904;-0.899838;,
    -3.501693;3.462273;1.409841;,
    -2.817684;2.350362;-0.919818;,
    -1.706976;3.623448;2.805540;,
    0.000000;2.472576;2.149371;,
    -1.267074;2.532980;1.708881;,
    0.000000;3.695073;3.347991;,
    -1.208484;1.775265;-0.129444;,
    0.000000;1.371855;-0.951774;,
    -1.397337;1.693104;-0.957183;,
    -0.662289;1.482372;-2.222040;,
    0.000000;1.376937;-2.397111;,
    -2.867046;1.006347;1.154364;,
    -1.383711;0.070383;1.048122;,
    -2.097330;0.479742;2.301894;,
    -1.692798;0.420807;0.442296;,
    -2.514096;0.331743;-2.602068;,
    -1.306569;-0.539694;-1.781586;,
    -1.654161;0.119472;-1.503051;,
    -1.756617;-0.805788;-3.424386;,
    -0.651555;-3.345684;-2.016408;,
    -1.006050;-1.229142;-1.740453;,
    -1.120959;-2.289048;-3.267603;,
    -0.803241;-1.705020;-1.088781;,
    -3.051342;0.939441;-0.706506;,
    -1.890159;0.494961;-0.534516;,
    -0.585306;-3.432312;0.044847;,
    -0.835539;-1.386621;0.876936;,
    -0.683745;-1.768434;-0.139698;,
    -0.930072;-2.576859;1.969572;,
    -1.033959;-0.585975;1.186569;,
    -1.285734;-1.067397;2.697381;,
    -0.791745;-4.815764;0.327465;,
    -0.700869;-4.984721;-1.870350;,
    -1.706976;3.623448;2.805540;,
    -2.564337;2.513448;3.091776;,
    -3.501693;3.462273;1.409841;,
    -3.860250;3.134904;-0.899838;,
    -3.042384;2.720367;-3.125478;,
    -1.422687;2.450244;-4.267955;,
    -1.742778;-1.293231;4.076217;,
    -0.877227;-4.339145;-3.686319;,
    -1.580142;-2.812056;-4.587749;,
    -0.700869;-4.984721;-1.870350;,
    -0.791745;-4.815764;0.327465;,
    -0.880818;-4.237679;2.283546;,
    -1.201431;-3.110250;3.850311;,
    -1.742778;-1.293231;4.076217;,
    -3.006801;0.703815;3.362481;,
    -4.339122;1.261101;1.645779;,
    -4.785963;1.077819;-0.922635;,
    -3.724077;0.370629;-3.313794;,
    -2.425524;-1.153944;-4.601253;,
    -1.096320;-0.430497;-0.345399;,
    -0.633537;1.863744;0.614994;,
    -1.179054;1.634007;-1.769646;,
    0.000000;1.829073;0.889557;,
    0.000000;-2.908320;-4.831479;,
    0.000000;-5.139014;0.329160;;
    264;
    3;0,1,2;,
    3;3,4,5;,
    3;6,3,7;,
    3;1,8,6;,
    3;0,9,10;,
    3;11,12,13;,
    3;14,15,16;,
    3;17,18,19;,
    3;9,0,12;,
    3;20,21,18;,
    3;22,23,14;,
    3;24,25,21;,
    3;26,27,28;,
    3;29,27,26;,
    3;27,30,28;,
    3;31,30,27;,
    3;32,33,34;,
    3;35,33,32;,
    3;36,37,38;,
    3;39,37,36;,
    3;40,41,42;,
    3;40,43,44;,
    3;45,46,47;,
    3;48,46,45;,
    3;49,50,51;,
    3;52,50,49;,
    3;53,54,55;,
    3;56,54,53;,
    3;57,52,49;,
    3;58,52,57;,
    3;48,57,46;,
    3;58,57,48;,
    3;59,60,61;,
    3;62,60,59;,
    3;51,53,55;,
    3;50,53,51;,
    3;63,47,64;,
    3;45,47,63;,
    3;59,56,62;,
    3;54,56,59;,
    3;65,66,67;,
    3;68,19,69;,
    3;69,4,70;,
    3;70,3,71;,
    3;71,8,72;,
    3;72,1,73;,
    3;73,74,75;,
    3;69,19,4;,
    3;19,18,4;,
    3;5,18,76;,
    3;76,21,22;,
    3;9,74,10;,
    3;77,9,11;,
    3;78,11,13;,
    3;79,55,54;,
    3;80,55,79;,
    3;59,81,54;,
    3;82,81,59;,
    3;83,59,61;,
    3;82,59,83;,
    3;83,61,84;,
    3;85,47,86;,
    3;64,47,85;,
    3;86,46,87;,
    3;47,46,86;,
    3;87,57,88;,
    3;46,57,87;,
    3;89,57,49;,
    3;88,57,89;,
    3;89,51,90;,
    3;49,51,89;,
    3;90,55,80;,
    3;51,55,90;,
    3;64,84,61;,
    3;85,84,64;,
    3;64,60,63;,
    3;61,60,64;,
    3;54,81,79;,
    3;91,56,53;,
    3;91,53,50;,
    3;91,50,52;,
    3;91,52,58;,
    3;91,58,48;,
    3;91,48,45;,
    3;91,45,63;,
    3;63,60,91;,
    3;91,60,62;,
    3;62,56,91;,
    3;36,33,39;,
    3;34,33,36;,
    3;40,92,41;,
    3;29,35,32;,
    3;26,35,29;,
    3;40,42,93;,
    3;40,93,43;,
    3;40,94,92;,
    3;28,44,43;,
    3;30,44,28;,
    3;28,93,26;,
    3;43,93,28;,
    3;26,42,35;,
    3;93,42,26;,
    3;35,41,33;,
    3;42,41,35;,
    3;33,92,39;,
    3;41,92,33;,
    3;39,94,37;,
    3;92,94,39;,
    3;13,66,78;,
    3;95,96,97;,
    3;98,99,100;,
    3;101,102,98;,
    3;97,103,102;,
    3;104,96,95;,
    3;105,106,107;,
    3;15,108,109;,
    3;110,17,111;,
    3;104,106,105;,
    3;112,20,110;,
    3;23,113,108;,
    3;24,112,25;,
    3;114,115,116;,
    3;117,115,114;,
    3;118,114,116;,
    3;119,114,118;,
    3;120,121,122;,
    3;123,121,120;,
    3;124,125,126;,
    3;127,125,124;,
    3;128,129,130;,
    3;131,129,132;,
    3;133,134,135;,
    3;136,134,133;,
    3;137,138,139;,
    3;140,138,137;,
    3;141,142,143;,
    3;144,142,141;,
    3;145,139,146;,
    3;137,139,145;,
    3;145,136,133;,
    3;146,136,145;,
    3;147,148,149;,
    3;150,148,147;,
    3;140,142,138;,
    3;143,142,140;,
    3;135,151,152;,
    3;134,151,135;,
    3;144,147,149;,
    3;141,147,144;,
    3;66,153,154;,
    3;111,68,155;,
    3;156,157,98;,
    3;98,158,101;,
    3;101,159,97;,
    3;159,160,97;,
    3;74,160,75;,
    3;111,155,156;,
    3;110,156,100;,
    3;112,110,161;,
    3;112,161,113;,
    3;77,104,74;,
    3;104,77,106;,
    3;106,78,107;,
    3;162,143,163;,
    3;141,143,162;,
    3;147,164,165;,
    3;141,164,147;,
    3;166,147,165;,
    3;150,147,166;,
    3;150,166,167;,
    3;135,168,169;,
    3;152,168,135;,
    3;133,169,170;,
    3;135,169,133;,
    3;145,170,171;,
    3;133,170,145;,
    3;172,145,171;,
    3;137,145,172;,
    3;140,172,173;,
    3;137,172,140;,
    3;143,173,163;,
    3;140,173,143;,
    3;152,167,168;,
    3;150,167,152;,
    3;148,152,151;,
    3;150,152,148;,
    3;164,141,162;,
    3;144,174,142;,
    3;142,174,138;,
    3;138,174,139;,
    3;139,174,146;,
    3;146,174,136;,
    3;136,174,134;,
    3;134,174,151;,
    3;148,151,174;,
    3;148,174,149;,
    3;144,149,174;,
    3;120,124,126;,
    3;122,124,120;,
    3;175,129,128;,
    3;123,117,121;,
    3;115,117,123;,
    3;130,129,176;,
    3;176,129,131;,
    3;177,129,175;,
    3;116,132,118;,
    3;131,132,116;,
    3;176,116,115;,
    3;131,116,176;,
    3;130,115,123;,
    3;176,115,130;,
    3;128,123,120;,
    3;130,123,128;,
    3;175,120,126;,
    3;128,120,175;,
    3;126,177,175;,
    3;125,177,126;,
    3;66,107,78;,
    3;10,1,0;,
    3;97,96,103;,
    3;77,74,9;,
    3;95,160,74;,
    3;10,74,73;,
    3;97,160,95;,
    3;73,1,10;,
    3;72,8,1;,
    3;158,159,101;,
    3;101,97,102;,
    3;2,1,6;,
    3;71,3,8;,
    3;157,158,98;,
    3;17,19,68;,
    3;17,68,111;,
    3;155,157,156;,
    3;70,4,3;,
    3;18,21,76;,
    3;110,100,161;,
    3;21,25,22;,
    3;25,112,113;,
    3;24,21,20;,
    3;24,20,112;,
    3;20,18,17;,
    3;20,17,110;,
    3;111,156,110;,
    3;4,18,5;,
    3;7,3,5;,
    3;156,98,100;,
    3;98,102,99;,
    3;8,3,6;,
    3;104,95,74;,
    3;96,104,105;,
    3;11,9,12;,
    3;77,178,106;,
    3;178,77,11;,
    3;178,11,78;,
    3;178,78,106;,
    3;154,107,66;,
    3;67,66,13;,
    3;179,153,66;,
    3;179,66,65;,
    3;25,113,23;,
    3;25,23,22;,
    3;23,108,15;,
    3;23,15,14;;


    MeshNormals {
     180;
     0.451412;0.092261;-0.887533;,
     0.687322;0.247295;-0.682959;,
     0.757585;0.176412;-0.628445;,
     0.861722;0.370603;0.346537;,
     0.541786;0.380566;0.749425;,
     0.591669;0.207294;0.779074;,
     0.944951;0.284537;-0.161577;,
     0.866257;0.285846;0.409745;,
     0.893892;0.391579;-0.218225;,
     0.244231;-0.027215;-0.969335;,
     0.370413;0.193990;-0.908384;,
     0.187385;-0.386591;-0.903014;,
     0.307209;-0.327747;-0.893423;,
     0.322450;-0.765308;-0.557073;,
     0.339257;-0.874573;0.346449;,
     0.000000;-0.977948;0.208851;,
     0.379935;-0.916993;0.121546;,
     0.000000;0.350306;0.936635;,
     0.348827;0.165120;0.922527;,
     0.304989;0.411266;0.858977;,
     0.000000;0.116281;0.993216;,
     0.284596;-0.100855;0.953328;,
     0.305101;-0.545444;0.780643;,
     -0.000000;-0.873825;0.486240;,
     0.000000;-0.102119;0.994772;,
     -0.000000;-0.445850;0.895107;,
     -0.423511;0.893613;0.148643;,
     -0.359123;0.813752;0.456989;,
     -0.310378;0.928353;0.204517;,
     -0.548058;0.817477;0.177101;,
     -0.000000;0.916834;0.399269;,
     0.000000;0.799328;0.600895;,
     -0.582568;0.803327;-0.123614;,
     -0.432095;0.831290;-0.349643;,
     -0.450787;0.813152;-0.368205;,
     -0.513996;0.852832;-0.092122;,
     -0.312309;0.736425;-0.600117;,
     0.000000;0.790922;-0.611917;,
     0.000000;0.700099;-0.714046;,
     -0.293526;0.827191;-0.479163;,
     0.000000;0.993377;-0.114897;,
     -0.308499;0.923470;-0.228106;,
     -0.318118;0.945001;-0.075987;,
     -0.233899;0.971333;0.042474;,
     0.000000;0.997040;0.076890;,
     0.735279;-0.670128;-0.101453;,
     0.380790;-0.922126;-0.068432;,
     0.696110;-0.664443;-0.271931;,
     0.590589;-0.806945;0.006612;,
     0.496402;-0.785824;0.368870;,
     0.816634;-0.506329;0.277021;,
     0.710605;-0.547699;0.441663;,
     0.648633;-0.726882;0.225649;,
     0.933295;-0.293136;0.207440;,
     0.987113;-0.095117;0.128691;,
     0.896631;-0.265321;0.354483;,
     0.978359;-0.179247;0.103366;,
     0.266762;-0.953237;0.142043;,
     0.586251;-0.802671;0.109673;,
     0.998873;-0.005221;-0.047184;,
     0.979661;-0.160687;-0.120187;,
     0.981122;-0.088480;-0.171965;,
     0.984260;-0.175771;0.018322;,
     0.908747;-0.383499;-0.164645;,
     0.920809;-0.281490;-0.269953;,
     0.379935;-0.916993;0.121546;,
     0.000000;-0.991255;-0.131957;,
     0.399875;-0.909862;-0.110682;,
     0.000000;0.524693;0.851292;,
     0.399903;0.540635;0.740129;,
     0.736302;0.499414;0.456557;,
     0.877515;0.473525;-0.075770;,
     0.737407;0.381599;-0.557326;,
     0.378996;0.230561;-0.896216;,
     0.000000;0.172346;-0.985036;,
     0.000000;0.240733;-0.970591;,
     0.428280;-0.053342;0.902070;,
     0.000000;-0.104161;-0.994560;,
     0.000000;-0.719580;-0.694410;,
     0.964164;-0.103632;0.244232;,
     0.858722;-0.298125;0.416796;,
     0.997052;0.070192;0.030976;,
     0.988715;0.133750;-0.067487;,
     0.991267;0.004437;-0.131794;,
     0.962883;-0.144535;-0.227959;,
     0.806431;-0.448020;-0.385938;,
     0.447281;-0.855720;-0.260160;,
     0.154210;-0.988034;-0.002944;,
     0.098598;-0.981724;0.162778;,
     0.283069;-0.869292;0.405220;,
     0.702757;-0.504567;0.501543;,
     0.893685;-0.442713;0.073029;,
     -0.236882;0.917441;-0.319671;,
     -0.277207;0.960636;0.018274;,
     -0.000000;0.927577;-0.373632;,
     -0.370413;0.193990;-0.908384;,
     -0.451412;0.092261;-0.887533;,
     -0.687322;0.247295;-0.682959;,
     -0.861722;0.370603;0.346537;,
     -0.866257;0.285846;0.409745;,
     -0.591669;0.207294;0.779074;,
     -0.893892;0.391579;-0.218226;,
     -0.944951;0.284537;-0.161577;,
     -0.757585;0.176412;-0.628446;,
     -0.244231;-0.027215;-0.969335;,
     -0.307209;-0.327747;-0.893423;,
     -0.187385;-0.386591;-0.903014;,
     -0.322449;-0.765308;-0.557073;,
     -0.339257;-0.874573;0.346449;,
     -0.379935;-0.916993;0.121546;,
     -0.348827;0.165120;0.922527;,
     -0.304989;0.411266;0.858977;,
     -0.284596;-0.100855;0.953328;,
     -0.305101;-0.545444;0.780643;,
     0.359123;0.813752;0.456989;,
     0.423511;0.893613;0.148643;,
     0.310378;0.928353;0.204517;,
     0.548058;0.817477;0.177101;,
     -0.000000;0.916834;0.399269;,
     0.000000;0.799328;0.600895;,
     0.432095;0.831290;-0.349643;,
     0.582568;0.803327;-0.123614;,
     0.450787;0.813152;-0.368205;,
     0.513996;0.852832;-0.092122;,
     0.312309;0.736426;-0.600117;,
     0.000000;0.790922;-0.611917;,
     0.293526;0.827191;-0.479163;,
     0.000000;0.700099;-0.714046;,
     0.308499;0.923470;-0.228106;,
     0.000000;0.993377;-0.114897;,
     0.318118;0.945001;-0.075987;,
     0.233899;0.971333;0.042474;,
     0.000000;0.997040;0.076890;,
     -0.380790;-0.922126;-0.068432;,
     -0.735279;-0.670128;-0.101453;,
     -0.696110;-0.664443;-0.271931;,
     -0.590589;-0.806945;0.006612;,
     -0.496402;-0.785824;0.368870;,
     -0.816634;-0.506329;0.277021;,
     -0.648634;-0.726882;0.225649;,
     -0.710605;-0.547699;0.441663;,
     -0.987113;-0.095117;0.128691;,
     -0.933295;-0.293136;0.207440;,
     -0.896631;-0.265321;0.354483;,
     -0.978359;-0.179247;0.103366;,
     -0.266762;-0.953237;0.142043;,
     -0.586251;-0.802671;0.109673;,
     -0.998873;-0.005221;-0.047184;,
     -0.979661;-0.160687;-0.120187;,
     -0.984260;-0.175771;0.018322;,
     -0.981121;-0.088480;-0.171965;,
     -0.908747;-0.383499;-0.164645;,
     -0.920809;-0.281490;-0.269953;,
     -0.379935;-0.916993;0.121546;,
     -0.399875;-0.909862;-0.110682;,
     -0.399903;0.540635;0.740129;,
     -0.541786;0.380566;0.749425;,
     -0.736302;0.499414;0.456557;,
     -0.877515;0.473525;-0.075770;,
     -0.737407;0.381599;-0.557326;,
     -0.378996;0.230561;-0.896216;,
     -0.428280;-0.053342;0.902070;,
     -0.964164;-0.103632;0.244232;,
     -0.858722;-0.298125;0.416796;,
     -0.997052;0.070192;0.030976;,
     -0.988715;0.133750;-0.067487;,
     -0.991267;0.004437;-0.131794;,
     -0.962883;-0.144535;-0.227959;,
     -0.806431;-0.448020;-0.385938;,
     -0.447281;-0.855720;-0.260160;,
     -0.154210;-0.988034;-0.002944;,
     -0.098598;-0.981724;0.162778;,
     -0.283069;-0.869292;0.405220;,
     -0.702757;-0.504567;0.501543;,
     -0.893685;-0.442713;0.073029;,
     0.236882;0.917441;-0.319671;,
     0.277207;0.960636;0.018274;,
     0.000000;0.927577;-0.373632;,
     0.000000;-0.364620;-0.931156;,
     0.000000;-0.977948;0.208851;;
     264;
     3;0,1,2;,
     3;3,4,5;,
     3;6,3,7;,
     3;1,8,6;,
     3;0,9,10;,
     3;11,12,13;,
     3;14,15,16;,
     3;17,18,19;,
     3;9,0,12;,
     3;20,21,18;,
     3;22,23,14;,
     3;24,25,21;,
     3;26,27,28;,
     3;29,27,26;,
     3;27,30,28;,
     3;31,30,27;,
     3;32,33,34;,
     3;35,33,32;,
     3;36,37,38;,
     3;39,37,36;,
     3;40,41,42;,
     3;40,43,44;,
     3;45,46,47;,
     3;48,46,45;,
     3;49,50,51;,
     3;52,50,49;,
     3;53,54,55;,
     3;56,54,53;,
     3;57,52,49;,
     3;58,52,57;,
     3;48,57,46;,
     3;58,57,48;,
     3;59,60,61;,
     3;62,60,59;,
     3;51,53,55;,
     3;50,53,51;,
     3;63,47,64;,
     3;45,47,63;,
     3;59,56,62;,
     3;54,56,59;,
     3;65,66,67;,
     3;68,19,69;,
     3;69,4,70;,
     3;70,3,71;,
     3;71,8,72;,
     3;72,1,73;,
     3;73,74,75;,
     3;69,19,4;,
     3;19,18,4;,
     3;5,18,76;,
     3;76,21,22;,
     3;9,74,10;,
     3;77,9,11;,
     3;78,11,13;,
     3;79,55,54;,
     3;80,55,79;,
     3;59,81,54;,
     3;82,81,59;,
     3;83,59,61;,
     3;82,59,83;,
     3;83,61,84;,
     3;85,47,86;,
     3;64,47,85;,
     3;86,46,87;,
     3;47,46,86;,
     3;87,57,88;,
     3;46,57,87;,
     3;89,57,49;,
     3;88,57,89;,
     3;89,51,90;,
     3;49,51,89;,
     3;90,55,80;,
     3;51,55,90;,
     3;64,84,61;,
     3;85,84,64;,
     3;64,60,63;,
     3;61,60,64;,
     3;54,81,79;,
     3;91,56,53;,
     3;91,53,50;,
     3;91,50,52;,
     3;91,52,58;,
     3;91,58,48;,
     3;91,48,45;,
     3;91,45,63;,
     3;63,60,91;,
     3;91,60,62;,
     3;62,56,91;,
     3;36,33,39;,
     3;34,33,36;,
     3;40,92,41;,
     3;29,35,32;,
     3;26,35,29;,
     3;40,42,93;,
     3;40,93,43;,
     3;40,94,92;,
     3;28,44,43;,
     3;30,44,28;,
     3;28,93,26;,
     3;43,93,28;,
     3;26,42,35;,
     3;93,42,26;,
     3;35,41,33;,
     3;42,41,35;,
     3;33,92,39;,
     3;41,92,33;,
     3;39,94,37;,
     3;92,94,39;,
     3;13,66,78;,
     3;95,96,97;,
     3;98,99,100;,
     3;101,102,98;,
     3;97,103,102;,
     3;104,96,95;,
     3;105,106,107;,
     3;15,108,109;,
     3;110,17,111;,
     3;104,106,105;,
     3;112,20,110;,
     3;23,113,108;,
     3;24,112,25;,
     3;114,115,116;,
     3;117,115,114;,
     3;118,114,116;,
     3;119,114,118;,
     3;120,121,122;,
     3;123,121,120;,
     3;124,125,126;,
     3;127,125,124;,
     3;128,129,130;,
     3;131,129,132;,
     3;133,134,135;,
     3;136,134,133;,
     3;137,138,139;,
     3;140,138,137;,
     3;141,142,143;,
     3;144,142,141;,
     3;145,139,146;,
     3;137,139,145;,
     3;145,136,133;,
     3;146,136,145;,
     3;147,148,149;,
     3;150,148,147;,
     3;140,142,138;,
     3;143,142,140;,
     3;135,151,152;,
     3;134,151,135;,
     3;144,147,149;,
     3;141,147,144;,
     3;66,153,154;,
     3;111,68,155;,
     3;156,157,98;,
     3;98,158,101;,
     3;101,159,97;,
     3;159,160,97;,
     3;74,160,75;,
     3;111,155,156;,
     3;110,156,100;,
     3;112,110,161;,
     3;112,161,113;,
     3;77,104,74;,
     3;104,77,106;,
     3;106,78,107;,
     3;162,143,163;,
     3;141,143,162;,
     3;147,164,165;,
     3;141,164,147;,
     3;166,147,165;,
     3;150,147,166;,
     3;150,166,167;,
     3;135,168,169;,
     3;152,168,135;,
     3;133,169,170;,
     3;135,169,133;,
     3;145,170,171;,
     3;133,170,145;,
     3;172,145,171;,
     3;137,145,172;,
     3;140,172,173;,
     3;137,172,140;,
     3;143,173,163;,
     3;140,173,143;,
     3;152,167,168;,
     3;150,167,152;,
     3;148,152,151;,
     3;150,152,148;,
     3;164,141,162;,
     3;144,174,142;,
     3;142,174,138;,
     3;138,174,139;,
     3;139,174,146;,
     3;146,174,136;,
     3;136,174,134;,
     3;134,174,151;,
     3;148,151,174;,
     3;148,174,149;,
     3;144,149,174;,
     3;120,124,126;,
     3;122,124,120;,
     3;175,129,128;,
     3;123,117,121;,
     3;115,117,123;,
     3;130,129,176;,
     3;176,129,131;,
     3;177,129,175;,
     3;116,132,118;,
     3;131,132,116;,
     3;176,116,115;,
     3;131,116,176;,
     3;130,115,123;,
     3;176,115,130;,
     3;128,123,120;,
     3;130,123,128;,
     3;175,120,126;,
     3;128,120,175;,
     3;126,177,175;,
     3;125,177,126;,
     3;66,107,78;,
     3;10,1,0;,
     3;97,96,103;,
     3;77,74,9;,
     3;95,160,74;,
     3;10,74,73;,
     3;97,160,95;,
     3;73,1,10;,
     3;72,8,1;,
     3;158,159,101;,
     3;101,97,102;,
     3;2,1,6;,
     3;71,3,8;,
     3;157,158,98;,
     3;17,19,68;,
     3;17,68,111;,
     3;155,157,156;,
     3;70,4,3;,
     3;18,21,76;,
     3;110,100,161;,
     3;21,25,22;,
     3;25,112,113;,
     3;24,21,20;,
     3;24,20,112;,
     3;20,18,17;,
     3;20,17,110;,
     3;111,156,110;,
     3;4,18,5;,
     3;7,3,5;,
     3;156,98,100;,
     3;98,102,99;,
     3;8,3,6;,
     3;104,95,74;,
     3;96,104,105;,
     3;11,9,12;,
     3;77,178,106;,
     3;178,77,11;,
     3;178,11,78;,
     3;178,78,106;,
     3;154,107,66;,
     3;67,66,13;,
     3;179,153,66;,
     3;179,66,65;,
     3;25,113,23;,
     3;25,23,22;,
     3;23,108,15;,
     3;23,15,14;;
    }

    MeshTextureCoords {
     180;
     0.572382;0.420280;,
     0.601834;0.344408;,
     0.608094;0.375025;,
     0.766261;0.302522;,
     0.847816;0.300250;,
     0.847936;0.354027;,
     0.679033;0.349516;,
     0.767394;0.343159;,
     0.673500;0.320273;,
     0.537316;0.419256;,
     0.545088;0.359017;,
     0.538668;0.466462;,
     0.560869;0.466392;,
     0.567535;0.513375;,
     0.922727;0.471814;,
     0.941811;0.505138;,
     0.914397;0.497934;,
     0.931033;0.296510;,
     0.908024;0.341432;,
     0.886871;0.296526;,
     0.946698;0.334332;,
     0.916416;0.393194;,
     0.924091;0.437447;,
     0.950551;0.474703;,
     0.955548;0.391495;,
     0.954100;0.436661;,
     0.959053;0.280208;,
     0.968981;0.306317;,
     0.973682;0.290504;,
     0.946111;0.290185;,
     0.989069;0.295656;,
     0.989069;0.311642;,
     0.934563;0.258760;,
     0.954926;0.235188;,
     0.939626;0.226147;,
     0.949284;0.259042;,
     0.964967;0.206440;,
     0.989069;0.215705;,
     0.989069;0.198781;,
     0.971179;0.221925;,
     0.989069;0.259493;,
     0.972006;0.247882;,
     0.969339;0.259569;,
     0.979718;0.277429;,
     0.989069;0.279901;,
     0.696062;0.642479;,
     0.697807;0.627106;,
     0.716655;0.635756;,
     0.686111;0.636724;,
     0.636109;0.638186;,
     0.649585;0.652499;,
     0.622603;0.656870;,
     0.654160;0.641673;,
     0.650261;0.663823;,
     0.645728;0.698587;,
     0.625178;0.681232;,
     0.660964;0.671639;,
     0.667527;0.627069;,
     0.670068;0.635506;,
     0.679583;0.700010;,
     0.693250;0.666410;,
     0.711196;0.685959;,
     0.676552;0.672681;,
     0.698336;0.653260;,
     0.723150;0.661167;,
     0.608891;0.553492;,
     0.564925;0.567035;,
     0.585013;0.541644;,
     0.914713;0.262724;,
     0.859462;0.265312;,
     0.765781;0.271978;,
     0.667966;0.291030;,
     0.597640;0.314855;,
     0.548788;0.330186;,
     0.491713;0.364167;,
     0.491990;0.335774;,
     0.902595;0.394401;,
     0.492469;0.419144;,
     0.526701;0.521644;,
     0.618300;0.714904;,
     0.603495;0.689822;,
     0.648127;0.725507;,
     0.684225;0.722733;,
     0.716353;0.713238;,
     0.742087;0.694720;,
     0.745797;0.664876;,
     0.734074;0.632075;,
     0.705576;0.620804;,
     0.664601;0.620067;,
     0.624722;0.634825;,
     0.603273;0.662588;,
     0.673174;0.650706;,
     0.980124;0.237370;,
     0.972421;0.271041;,
     0.989069;0.233494;,
     0.545088;0.359017;,
     0.572382;0.420280;,
     0.601834;0.344408;,
     0.766261;0.302522;,
     0.767394;0.343159;,
     0.847936;0.354027;,
     0.673500;0.320273;,
     0.679033;0.349516;,
     0.608094;0.375025;,
     0.537316;0.419256;,
     0.560869;0.466392;,
     0.538668;0.466462;,
     0.567535;0.513375;,
     0.922727;0.471814;,
     0.914397;0.497934;,
     0.908024;0.341432;,
     0.886871;0.296526;,
     0.916416;0.393194;,
     0.924091;0.437447;,
     0.968973;0.306317;,
     0.959045;0.280208;,
     0.973673;0.290504;,
     0.946103;0.290185;,
     0.989061;0.295656;,
     0.989061;0.311642;,
     0.954917;0.235188;,
     0.934554;0.258760;,
     0.939617;0.226147;,
     0.949275;0.259042;,
     0.964958;0.206440;,
     0.989061;0.215705;,
     0.971170;0.221925;,
     0.989061;0.198781;,
     0.971997;0.247882;,
     0.989061;0.259493;,
     0.969330;0.259569;,
     0.979709;0.277429;,
     0.989061;0.279901;,
     0.697807;0.627106;,
     0.696062;0.642479;,
     0.716655;0.635756;,
     0.686111;0.636724;,
     0.636109;0.638186;,
     0.649585;0.652499;,
     0.654160;0.641673;,
     0.622603;0.656870;,
     0.645728;0.698587;,
     0.650261;0.663823;,
     0.625178;0.681232;,
     0.660964;0.671639;,
     0.667527;0.627069;,
     0.670068;0.635506;,
     0.679583;0.700010;,
     0.693250;0.666410;,
     0.676552;0.672681;,
     0.711196;0.685959;,
     0.698336;0.653260;,
     0.723150;0.661167;,
     0.608891;0.553492;,
     0.585013;0.541644;,
     0.859462;0.265312;,
     0.847816;0.300250;,
     0.765781;0.271978;,
     0.667966;0.291030;,
     0.597640;0.314855;,
     0.548788;0.330186;,
     0.902595;0.394401;,
     0.618300;0.714904;,
     0.603495;0.689822;,
     0.648127;0.725507;,
     0.684225;0.722733;,
     0.716353;0.713238;,
     0.742087;0.694720;,
     0.745797;0.664876;,
     0.734074;0.632075;,
     0.705576;0.620804;,
     0.664601;0.620067;,
     0.624722;0.634825;,
     0.603273;0.662588;,
     0.673174;0.650706;,
     0.980115;0.237370;,
     0.972412;0.271041;,
     0.989061;0.233494;,
     0.496648;0.466598;,
     0.607186;0.593552;;
    }

    MeshMaterialList {
     1;
     264;
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0;
     Material {
      0.800000;0.800000;0.800000;1.000000;;
      5.000000;
      0.000000;0.000000;0.000000;;
      0.000000;0.000000;0.000000;;
      TextureFilename {
       "data\\TEXTURE\\OBJModel_tex.tga";
      }
     }

    }

    VertexDuplicationIndices {
     180;
     180;
     0,
     1,
     2,
     3,
     4,
     5,
     6,
     7,
     8,
     9,
     10,
     11,
     12,
     13,
     14,
     15,
     16,
     17,
     18,
     19,
     20,
     21,
     22,
     23,
     24,
     25,
     26,
     27,
     28,
     29,
     30,
     31,
     32,
     33,
     34,
     35,
     36,
     37,
     38,
     39,
     40,
     41,
     42,
     43,
     44,
     45,
     46,
     47,
     48,
     49,
     50,
     51,
     52,
     53,
     54,
     55,
     56,
     57,
     58,
     59,
     60,
     61,
     62,
     63,
     64,
     65,
     66,
     67,
     68,
     69,
     70,
     71,
     72,
     73,
     74,
     75,
     76,
     77,
     78,
     79,
     80,
     81,
     82,
     83,
     84,
     85,
     86,
     87,
     88,
     89,
     90,
     91,
     92,
     93,
     94,
     95,
     96,
     97,
     98,
     99,
     100,
     101,
     102,
     103,
     104,
     105,
     106,
     107,
     108,
     109,
     110,
     111,
     112,
     113,
     114,
     115,
     116,
     117,
     118,
     119,
     120,
     121,
     122,
     123,
     124,
     125,
     126,
     127,
     128,
     129,
     130,
     131,
     132,
     133,
     134,
     135,
     136,
     137,
     138,
     139,
     140,
     141,
     142,
     143,
     144,
     145,
     146,
     147,
     148,
     149,
     150,
     151,
     152,
     153,
     154,
     155,
     156,
     157,
     158,
     159,
     160,
     161,
     162,
     163,
     164,
     165,
     166,
     167,
     168,
     169,
     170,
     171,
     172,
     173,
     174,
     175,
     176,
     177,
     178,
     179;
    }

    XSkinMeshHeader {
     1;
     0;
     1;
    }

    SkinWeights {
     "ReplacedName0";
     0;
     ;
     ;
     1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
    }

    RDB2ExtInfo1 {
     8;
     "dispswitchno=0",
     "transparent=0",
     "uanime=0.000000",
     "vanime=0.000000",
     "exttexnum=0",
     "exttexmode=0",
     "exttexrep=2",
     "exttexstep=1";
    }
   }

  }
 }
 Frame ReplacedName2 {


  FrameTransformMatrix {
   1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
  }

 }
}
