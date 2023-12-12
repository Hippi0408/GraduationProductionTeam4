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

  Frame LowerLeg_R {


   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }

   Mesh LowerLeg_R_PM2 {
    67;
    0.955791;-4.771340;2.835363;,
    0.673758;-13.579474;0.107658;,
    1.787742;-5.077682;0.449262;,
    -1.434594;-4.770395;2.862288;,
    0.230637;-13.112141;1.439361;,
    0.955791;-4.771340;2.835363;,
    -2.448930;-4.917984;0.790983;,
    -0.706722;-13.111454;1.423233;,
    -1.434594;-4.770395;2.862288;,
    0.673758;-13.579474;0.107658;,
    0.180213;-14.154086;-1.291800;,
    0.948414;-5.221454;-1.865658;,
    -0.737733;-14.152085;-1.291800;,
    -1.200120;-13.539898;0.099495;,
    0.948414;-5.221454;-1.865658;,
    -0.737733;-14.152085;-1.291800;,
    -1.164270;-5.218694;-1.865658;,
    0.843627;-0.660465;1.740708;,
    1.505349;-0.274641;0.044028;,
    -0.933051;-0.660465;1.740708;,
    0.843627;-0.660465;1.740708;,
    -1.589424;-0.274641;0.100344;,
    -0.933051;-0.660465;1.740708;,
    -0.805014;0.253590;-1.958628;,
    1.013589;0.253590;-1.958628;,
    -0.805014;0.253590;-1.958628;,
    1.505349;-0.274641;0.044028;,
    1.013589;0.253590;-1.958628;,
    -1.164270;-5.218694;-1.865658;,
    1.787742;-5.077682;0.449262;,
    0.180213;-14.154086;-1.291800;,
    0.230637;-13.112141;1.439361;,
    -0.706722;-13.111454;1.423233;,
    -0.659703;-0.857556;-1.621806;,
    -0.023919;-2.157618;0.006258;,
    0.838632;-0.857556;-1.621806;,
    -0.765189;-1.610640;1.426758;,
    -1.406637;-1.292766;0.074565;,
    1.243788;-1.292766;0.028167;,
    0.698601;-1.610640;1.425336;,
    -0.933051;-0.660465;1.740708;,
    -1.589424;-0.274641;0.100344;,
    0.843627;-0.660465;1.740708;,
    -0.933051;-0.660465;1.740708;,
    0.843627;-0.660465;1.740708;,
    1.505349;-0.274641;0.044028;,
    1.013589;0.253590;-1.958628;,
    -0.805014;0.253590;-1.958628;,
    1.013589;0.253590;-1.958628;,
    -0.805014;0.253590;-1.958628;,
    -0.637833;-12.851114;1.177530;,
    -0.293127;-12.609452;-0.128481;,
    0.118557;-12.851668;1.190544;,
    -0.662859;-13.398161;-1.013331;,
    -1.034487;-13.060586;0.005079;,
    0.477618;-13.092521;0.011667;,
    0.077868;-13.399775;-1.013331;,
    -1.200120;-13.539898;0.099495;,
    -0.737733;-14.152085;-1.291800;,
    -0.737733;-14.152085;-1.291800;,
    0.180213;-14.154086;-1.291800;,
    0.673758;-13.579474;0.107658;,
    0.180213;-14.154086;-1.291800;,
    0.230637;-13.112141;1.439361;,
    -0.706722;-13.111454;1.423233;,
    0.230637;-13.112141;1.439361;,
    -0.706722;-13.111454;1.423233;;
    60;
    3;0,1,2;,
    3;3,4,5;,
    3;6,7,8;,
    3;9,10,11;,
    3;12,13,6;,
    3;14,15,16;,
    3;17,2,18;,
    3;19,5,20;,
    3;21,8,22;,
    3;23,6,21;,
    3;24,16,25;,
    3;26,11,27;,
    3;21,6,8;,
    3;19,3,5;,
    3;17,0,2;,
    3;23,28,6;,
    3;24,14,16;,
    3;26,29,11;,
    3;28,12,6;,
    3;14,30,15;,
    3;29,9,11;,
    3;0,31,1;,
    3;3,32,4;,
    3;6,13,7;,
    3;33,34,35;,
    3;36,34,37;,
    3;37,34,33;,
    3;35,34,38;,
    3;38,34,39;,
    3;39,34,36;,
    3;40,37,41;,
    3;36,37,40;,
    3;42,36,43;,
    3;39,36,42;,
    3;44,38,39;,
    3;45,38,44;,
    3;35,45,46;,
    3;38,45,35;,
    3;47,35,48;,
    3;33,35,47;,
    3;41,33,49;,
    3;37,33,41;,
    3;50,51,52;,
    3;53,51,54;,
    3;54,51,50;,
    3;52,51,55;,
    3;55,51,56;,
    3;56,51,53;,
    3;53,57,58;,
    3;54,57,53;,
    3;56,59,60;,
    3;53,59,56;,
    3;61,56,62;,
    3;55,56,61;,
    3;52,61,63;,
    3;55,61,52;,
    3;64,52,65;,
    3;50,52,64;,
    3;57,50,66;,
    3;54,50,57;;


    MeshNormals {
     67;
     0.938774;-0.055738;0.339995;,
     0.991504;-0.128690;0.018938;,
     0.997025;-0.004893;0.076919;,
     0.001682;-0.025682;0.999669;,
     -0.003017;-0.168735;0.985657;,
     0.007491;0.120228;0.992718;,
     -0.999330;-0.016068;-0.032875;,
     -0.895016;-0.158128;0.417064;,
     -0.898101;0.098418;0.428635;,
     0.991504;-0.128690;0.018938;,
     0.950524;-0.100626;-0.293903;,
     0.951500;-0.049947;-0.303567;,
     -0.932580;-0.094226;-0.348447;,
     -0.986775;-0.148193;0.065680;,
     -0.000082;-0.048407;-0.998828;,
     -0.000112;-0.064104;-0.997943;,
     -0.000035;-0.032699;-0.999465;,
     0.932729;0.097895;0.347036;,
     0.996793;0.034099;-0.072391;,
     0.005487;0.259666;0.965683;,
     -0.000000;0.257316;0.966327;,
     -0.963137;0.202646;0.176923;,
     -0.886990;0.219164;0.406468;,
     -0.919411;0.088515;-0.383208;,
     -0.000011;-0.016982;-0.999856;,
     -0.000000;-0.016987;-0.999856;,
     0.996793;0.034099;-0.072391;,
     0.970066;-0.015663;-0.242335;,
     -0.900650;-0.009567;-0.434440;,
     0.997025;-0.004893;0.076919;,
     -0.000140;-0.064099;-0.997944;,
     0.923750;-0.139979;0.356498;,
     -0.017074;-0.171437;0.985047;,
     0.180459;0.665529;0.724228;,
     -0.017318;0.951320;0.307717;,
     -0.147689;0.590168;0.793656;,
     0.542840;0.786684;-0.294029;,
     0.860383;0.509069;0.024278;,
     -0.857757;0.514044;-0.003387;,
     -0.573926;0.773473;-0.268976;,
     0.911172;0.225763;-0.344669;,
     0.963614;0.199726;0.177647;,
     -0.000461;0.314434;-0.949279;,
     0.000000;0.313731;-0.949512;,
     -0.921373;0.241578;-0.304487;,
     -0.964488;0.246295;0.095404;,
     -0.928120;0.233927;0.289605;,
     -0.000000;0.290095;0.956998;,
     -0.000000;0.290095;0.956998;,
     0.886194;0.236637;0.398324;,
     0.193558;-0.920855;-0.338468;,
     -0.005014;-0.964761;0.263081;,
     -0.139486;-0.883588;-0.447008;,
     0.533130;-0.531332;0.658376;,
     0.782895;-0.601783;0.157899;,
     -0.771121;-0.610408;0.181037;,
     -0.437656;-0.521231;0.732649;,
     0.940048;-0.327413;0.095449;,
     0.886684;-0.235114;0.398136;,
     -0.000755;-0.346414;0.938081;,
     -0.000755;-0.346413;0.938082;,
     -0.917404;-0.373242;0.138063;,
     -0.867145;-0.271742;0.417391;,
     -0.866301;-0.485405;-0.117917;,
     0.011980;-0.687993;-0.725618;,
     0.011980;-0.687993;-0.725619;,
     0.886904;-0.418760;-0.195040;;
     60;
     3;0,1,2;,
     3;3,4,5;,
     3;6,7,8;,
     3;9,10,11;,
     3;12,13,6;,
     3;14,15,16;,
     3;17,2,18;,
     3;19,5,20;,
     3;21,8,22;,
     3;23,6,21;,
     3;24,16,25;,
     3;26,11,27;,
     3;21,6,8;,
     3;19,3,5;,
     3;17,0,2;,
     3;23,28,6;,
     3;24,14,16;,
     3;26,29,11;,
     3;28,12,6;,
     3;14,30,15;,
     3;29,9,11;,
     3;0,31,1;,
     3;3,32,4;,
     3;6,13,7;,
     3;33,34,35;,
     3;36,34,37;,
     3;37,34,33;,
     3;35,34,38;,
     3;38,34,39;,
     3;39,34,36;,
     3;40,37,41;,
     3;36,37,40;,
     3;42,36,43;,
     3;39,36,42;,
     3;44,38,39;,
     3;45,38,44;,
     3;35,45,46;,
     3;38,45,35;,
     3;47,35,48;,
     3;33,35,47;,
     3;41,33,49;,
     3;37,33,41;,
     3;50,51,52;,
     3;53,51,54;,
     3;54,51,50;,
     3;52,51,55;,
     3;55,51,56;,
     3;56,51,53;,
     3;53,57,58;,
     3;54,57,53;,
     3;56,59,60;,
     3;53,59,56;,
     3;61,56,62;,
     3;55,56,61;,
     3;52,61,63;,
     3;55,61,52;,
     3;64,52,65;,
     3;50,52,64;,
     3;57,50,66;,
     3;54,50,57;;
    }

    MeshTextureCoords {
     67;
     0.535114;0.860291;,
     0.566771;0.979865;,
     0.566771;0.864553;,
     0.491096;0.860279;,
     0.535114;0.978939;,
     0.535114;0.860291;,
     0.457831;0.862128;,
     0.491096;0.978930;,
     0.491096;0.860279;,
     0.354033;0.982246;,
     0.383864;0.980298;,
     0.383864;0.865929;,
     0.419553;0.980273;,
     0.457831;0.979368;,
     0.383864;0.865929;,
     0.419553;0.980273;,
     0.419553;0.865894;,
     0.535114;0.798409;,
     0.566771;0.802680;,
     0.491096;0.797171;,
     0.535114;0.798409;,
     0.457831;0.798256;,
     0.491096;0.797171;,
     0.419553;0.805006;,
     0.383864;0.805006;,
     0.419553;0.805006;,
     0.354033;0.806210;,
     0.383864;0.805006;,
     0.419553;0.865894;,
     0.354033;0.870131;,
     0.383864;0.980298;,
     0.535114;0.978939;,
     0.491096;0.978930;,
     0.702293;0.980893;,
     0.692817;0.957093;,
     0.679961;0.980893;,
     0.703865;0.936328;,
     0.713425;0.956095;,
     0.673922;0.956773;,
     0.682048;0.936349;,
     0.709955;0.924142;,
     0.722504;0.954900;,
     0.675989;0.924142;,
     0.709955;0.924142;,
     0.675989;0.924142;,
     0.663338;0.955956;,
     0.672739;0.993507;,
     0.707507;0.993507;,
     0.672739;0.993507;,
     0.707507;0.993507;,
     0.764784;0.936557;,
     0.756628;0.963971;,
     0.746887;0.936283;,
     0.765377;0.982545;,
     0.774170;0.961167;,
     0.738391;0.961029;,
     0.747850;0.982545;,
     0.783485;0.959129;,
     0.769837;0.995559;,
     0.769837;0.995559;,
     0.742743;0.995559;,
     0.728175;0.958915;,
     0.742743;0.995559;,
     0.741254;0.924045;,
     0.768922;0.924468;,
     0.741254;0.924045;,
     0.768922;0.924468;;
    }

    MeshMaterialList {
     1;
     60;
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
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
     67;
     67;
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
     66;
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