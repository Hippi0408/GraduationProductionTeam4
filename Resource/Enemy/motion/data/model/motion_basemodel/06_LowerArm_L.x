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

  Frame LowerArm_L {


   FrameTransformMatrix {
    1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000,0.000000,0.000000,0.000000,0.000000,1.000000;;
   }

   Mesh LowerArm_L_PM2 {
    118;
    1.827390;-1.375041;-1.048623;,
    1.356831;-1.330155;1.002291;,
    0.786093;-1.329084;-0.962499;,
    -0.173697;1.226271;0.930561;,
    -0.587247;0.016326;1.701519;,
    1.212525;0.007386;1.807605;,
    1.353756;1.389465;1.026270;,
    0.790596;1.222374;-0.890079;,
    -0.173697;1.226271;0.930561;,
    1.865616;1.344414;-0.989286;,
    0.992925;-0.030111;-1.358556;,
    0.790596;1.222374;-0.890079;,
    3.732753;-1.268862;-1.065936;,
    3.565001;-1.251654;1.003230;,
    1.353756;1.389465;1.026270;,
    3.561255;1.282680;0.975147;,
    3.743520;1.282680;-1.057788;,
    1.865616;1.344414;-0.989286;,
    3.738137;-0.041079;-1.712409;,
    2.066052;-0.039051;-1.663548;,
    3.743520;1.282680;-1.057788;,
    0.786093;-1.329084;-0.962499;,
    3.732753;-1.268862;-1.065936;,
    1.827390;-1.375041;-1.048623;,
    1.212525;0.007386;1.807605;,
    -0.161148;-1.195635;0.892422;,
    8.110856;0.015141;0.960126;,
    3.563130;0.015516;1.648845;,
    3.563130;0.015516;1.648845;,
    8.110856;0.015141;0.960126;,
    8.109257;0.848112;0.616080;,
    8.120748;0.848112;-0.480720;,
    3.561255;1.282680;0.975147;,
    8.120748;0.848112;-0.480720;,
    8.116145;0.012585;-0.837219;,
    8.111543;-0.611226;-0.441651;,
    8.112461;-0.613728;0.634128;,
    -0.587247;0.016326;1.701519;,
    8.112461;-0.613728;0.634128;,
    8.109257;0.848112;0.616080;,
    1.270707;0.018837;0.277560;,
    0.444708;0.976698;0.892389;,
    1.194135;0.973665;-0.522567;,
    0.454461;-0.905553;0.862749;,
    0.123309;0.036354;1.633653;,
    1.351374;-0.007616;-0.886656;,
    1.190634;-1.009269;-0.578850;,
    -0.161148;-1.195635;0.892422;,
    -0.587247;0.016326;1.701519;,
    0.786093;-1.329084;-0.962499;,
    0.992925;-0.030111;-1.358556;,
    0.786093;-1.329084;-0.962499;,
    0.790596;1.222374;-0.890079;,
    0.790596;1.222374;-0.890079;,
    -0.173697;1.226271;0.930561;,
    -0.587247;0.016326;1.701519;,
    1.014963;0.002559;0.693372;,
    0.585990;-0.949575;0.603906;,
    1.014963;-0.547125;0.359148;,
    0.585990;0.002502;1.182801;,
    1.014963;-0.547056;-0.309423;,
    0.585990;-0.949452;-0.554094;,
    1.014963;0.002694;-0.643770;,
    0.616278;0.002748;-1.133196;,
    0.585990;0.954828;-0.554301;,
    1.014963;0.552378;-0.309546;,
    1.014963;0.552309;0.359025;,
    0.585990;0.954702;0.603696;,
    1.014963;0.002559;0.693372;,
    0.585990;0.002502;1.182801;,
    0.000000;-1.096878;0.693492;,
    0.000000;0.002475;1.361943;,
    0.000000;-1.096737;-0.643647;,
    0.000000;0.002766;-1.312341;,
    0.000000;0.002766;-1.312341;,
    0.000000;1.102131;-0.643890;,
    0.000000;1.101990;0.693252;,
    0.000000;0.002475;1.361943;,
    -0.585990;0.002502;1.182801;,
    -0.585990;-0.949575;0.603906;,
    -0.585990;-0.949452;-0.554094;,
    -0.585990;0.002748;-1.133196;,
    -0.585990;0.002748;-1.133196;,
    -0.585990;0.954828;-0.554301;,
    -0.585990;0.954702;0.603696;,
    -0.585990;0.002502;1.182801;,
    -1.014963;0.002559;0.693372;,
    -1.014963;-0.547125;0.359148;,
    -1.014963;-0.547056;-0.309423;,
    -1.014963;0.002694;-0.643770;,
    -1.014963;0.552378;-0.309546;,
    -1.014963;0.552309;0.359025;,
    -1.014963;0.002559;0.693372;,
    1.171977;0.002625;0.024801;,
    1.171977;0.002625;0.024801;,
    1.171977;0.002625;0.024801;,
    1.171977;0.002625;0.024801;,
    1.171977;0.002625;0.024801;,
    1.171977;0.002625;0.024801;,
    -1.171980;0.002625;0.024801;,
    -1.171980;0.002625;0.024801;,
    -1.171980;0.002625;0.024801;,
    -1.171980;0.002625;0.024801;,
    -1.171980;0.002625;0.024801;,
    -1.171980;0.002625;0.024801;,
    7.658585;0.060054;0.028794;,
    7.903058;0.678552;0.482307;,
    7.904318;0.021957;0.753504;,
    7.905584;-0.473748;0.496536;,
    7.908488;0.019947;-0.663258;,
    7.912115;0.678552;-0.382248;,
    7.904860;-0.471777;-0.351450;,
    8.111543;-0.611226;-0.441651;,
    8.116145;0.012585;-0.837219;,
    8.112461;-0.613728;0.634128;,
    8.110856;0.015141;0.960126;,
    8.109257;0.848112;0.616080;,
    8.120748;0.848112;-0.480720;;
    132;
    3;0,1,2;,
    3;3,4,5;,
    3;6,7,8;,
    3;9,10,11;,
    3;1,12,13;,
    3;14,5,15;,
    3;16,17,6;,
    3;18,19,20;,
    3;21,10,19;,
    3;22,23,18;,
    3;13,24,1;,
    3;1,24,25;,
    3;26,27,13;,
    3;28,29,15;,
    3;30,31,32;,
    3;33,18,20;,
    3;22,34,35;,
    3;35,36,22;,
    3;24,37,25;,
    3;1,25,2;,
    3;36,13,22;,
    3;23,19,18;,
    3;0,22,1;,
    3;23,21,19;,
    3;19,10,9;,
    3;17,7,6;,
    3;32,16,6;,
    3;20,19,9;,
    3;15,5,28;,
    3;14,3,5;,
    3;27,24,13;,
    3;38,26,13;,
    3;15,29,39;,
    3;31,16,32;,
    3;34,18,33;,
    3;18,34,22;,
    3;40,41,42;,
    3;40,43,44;,
    3;45,46,40;,
    3;46,43,40;,
    3;40,44,41;,
    3;40,42,45;,
    3;44,47,48;,
    3;43,47,44;,
    3;49,43,46;,
    3;47,43,49;,
    3;50,46,45;,
    3;51,46,50;,
    3;50,42,52;,
    3;45,42,50;,
    3;53,41,54;,
    3;42,41,53;,
    3;54,44,55;,
    3;41,44,54;,
    3;56,57,58;,
    3;59,57,56;,
    3;57,60,58;,
    3;61,60,57;,
    3;61,62,60;,
    3;63,62,61;,
    3;62,64,65;,
    3;63,64,62;,
    3;64,66,65;,
    3;67,66,64;,
    3;67,68,66;,
    3;69,68,67;,
    3;59,70,57;,
    3;71,70,59;,
    3;70,61,57;,
    3;72,61,70;,
    3;61,73,63;,
    3;72,73,61;,
    3;74,64,63;,
    3;75,64,74;,
    3;75,67,64;,
    3;76,67,75;,
    3;76,69,67;,
    3;77,69,76;,
    3;78,70,71;,
    3;79,70,78;,
    3;79,72,70;,
    3;80,72,79;,
    3;72,81,73;,
    3;80,81,72;,
    3;82,75,74;,
    3;83,75,82;,
    3;83,76,75;,
    3;84,76,83;,
    3;76,85,77;,
    3;84,85,76;,
    3;86,79,78;,
    3;87,79,86;,
    3;87,80,79;,
    3;88,80,87;,
    3;80,89,81;,
    3;88,89,80;,
    3;89,83,81;,
    3;90,83,89;,
    3;90,84,83;,
    3;91,84,90;,
    3;84,92,85;,
    3;91,92,84;,
    3;93,56,58;,
    3;94,58,60;,
    3;95,60,62;,
    3;96,62,65;,
    3;97,65,66;,
    3;98,66,68;,
    3;99,87,86;,
    3;100,88,87;,
    3;101,89,88;,
    3;102,90,89;,
    3;103,91,90;,
    3;104,92,91;,
    3;105,106,107;,
    3;105,107,108;,
    3;109,110,105;,
    3;105,111,109;,
    3;110,106,105;,
    3;105,108,111;,
    3;112,109,111;,
    3;113,109,112;,
    3;112,108,114;,
    3;111,108,112;,
    3;114,107,115;,
    3;108,107,114;,
    3;115,106,116;,
    3;107,106,115;,
    3;117,106,110;,
    3;116,106,117;,
    3;113,110,109;,
    3;117,110,113;;


    MeshNormals {
     118;
     0.006419;-0.999707;0.023352;,
     -0.024599;-0.941932;0.334900;,
     -0.066611;-0.997602;0.018806;,
     -0.076867;0.523259;0.848700;,
     -0.046505;0.548043;0.835156;,
     -0.013009;0.502086;0.864720;,
     -0.034910;0.998950;-0.029647;,
     -0.109978;0.992454;-0.054215;,
     -0.102569;0.993123;-0.056451;,
     -0.130869;0.389189;-0.911814;,
     -0.222870;0.168547;-0.960167;,
     -0.123826;0.330027;-0.935815;,
     0.125515;-0.978098;-0.166045;,
     0.072798;-0.939940;0.333485;,
     -0.031738;0.494341;0.868688;,
     0.085920;0.451295;0.888229;,
     0.059493;0.998229;-0.000343;,
     -0.042649;0.998540;-0.033150;,
     0.089542;-0.013597;-0.995890;,
     -0.123995;0.039386;-0.991501;,
     0.038788;0.440346;-0.896990;,
     -0.181394;-0.324508;-0.928327;,
     0.132013;-0.485579;-0.864168;,
     -0.034135;-0.428098;-0.903087;,
     -0.004647;-0.346421;0.938068;,
     -0.092254;-0.772573;0.628189;,
     0.142033;-0.016792;0.989719;,
     0.108674;0.008843;0.994038;,
     0.108674;0.008843;0.994038;,
     0.142033;-0.016792;0.989719;,
     0.095196;0.995458;0.000997;,
     0.096422;0.995328;0.004876;,
     0.080441;0.996748;0.004699;,
     0.168273;0.411429;-0.895774;,
     0.202668;-0.219778;-0.954266;,
     0.196315;-0.859994;-0.471032;,
     0.144668;-0.989443;0.008597;,
     -0.051279;-0.566911;0.822181;,
     0.135337;-0.455719;0.879775;,
     0.108810;0.379665;0.918703;,
     -0.913570;0.004017;-0.406661;,
     -0.564580;-0.661442;-0.493704;,
     -0.802469;-0.539743;-0.254403;,
     -0.573678;0.634810;-0.517600;,
     -0.497521;0.127457;-0.858037;,
     -0.960358;-0.009395;0.278612;,
     -0.877010;0.473406;0.082097;,
     -0.285392;0.682483;-0.672880;,
     -0.095441;0.529271;-0.843067;,
     -0.420480;0.864020;-0.276885;,
     -0.795579;-0.020790;0.605494;,
     -0.769905;0.295110;0.565824;,
     -0.739010;-0.337473;0.583074;,
     -0.377328;-0.904684;-0.197912;,
     -0.254867;-0.703999;-0.662893;,
     -0.066689;-0.519861;-0.851644;,
     0.852048;0.000045;0.523463;,
     0.612529;-0.690310;0.385071;,
     0.886116;-0.405454;0.224511;,
     0.529364;-0.279838;0.800915;,
     0.857549;-0.481840;-0.180111;,
     0.504669;-0.726191;-0.466858;,
     0.858301;-0.000044;-0.513146;,
     0.631089;-0.192129;-0.751540;,
     0.570553;0.679212;-0.461671;,
     0.886116;0.405454;-0.224512;,
     0.857549;0.481840;0.180111;,
     0.537892;0.746815;0.391074;,
     0.852048;0.000045;0.523463;,
     0.529338;0.279944;0.800895;,
     0.094220;-0.763407;0.639008;,
     0.000000;-0.519538;0.854447;,
     0.002542;-0.971863;-0.235535;,
     0.082342;-0.519769;-0.850329;,
     0.082359;0.519680;-0.850382;,
     0.055204;0.810564;-0.583042;,
     0.061444;0.919455;0.388365;,
     0.000000;0.519619;0.854398;,
     -0.413386;-0.473066;0.778023;,
     -0.537962;-0.746808;0.390992;,
     -0.612462;-0.690329;-0.385146;,
     -0.413327;-0.473159;-0.777998;,
     -0.413385;0.473064;-0.778025;,
     -0.537962;0.746807;-0.390992;,
     -0.612462;0.690328;0.385145;,
     -0.413326;0.473158;0.777999;,
     -0.852047;0.000045;0.523465;,
     -0.857579;-0.481817;0.180028;,
     -0.886082;-0.405492;-0.224576;,
     -0.852047;-0.000045;-0.523466;,
     -0.857579;0.481818;-0.180028;,
     -0.886082;0.405492;0.224576;,
     -0.852047;0.000045;0.523465;,
     1.000000;-0.000000;0.000000;,
     1.000000;-0.000000;0.000000;,
     1.000000;-0.000000;0.000000;,
     1.000000;-0.000000;0.000000;,
     1.000000;-0.000000;0.000000;,
     1.000000;-0.000000;0.000000;,
     -1.000000;-0.000000;0.000000;,
     -1.000000;-0.000000;0.000000;,
     -1.000000;-0.000000;0.000000;,
     -1.000000;-0.000000;0.000000;,
     -1.000000;-0.000000;0.000000;,
     -1.000000;-0.000000;0.000000;,
     0.999727;0.022104;0.007634;,
     0.821918;-0.480333;-0.306155;,
     0.824379;0.092364;-0.558452;,
     0.796640;0.566271;-0.211428;,
     0.788825;0.128067;0.601127;,
     0.811597;-0.424639;0.401239;,
     0.813632;0.512041;0.275350;,
     0.625309;0.685175;0.373529;,
     0.639003;-0.072011;0.765826;,
     0.687591;0.548239;-0.476080;,
     0.703930;-0.076283;-0.706161;,
     0.721631;-0.582815;-0.373598;,
     0.680969;-0.679928;0.271991;;
     132;
     3;0,1,2;,
     3;3,4,5;,
     3;6,7,8;,
     3;9,10,11;,
     3;1,12,13;,
     3;14,5,15;,
     3;16,17,6;,
     3;18,19,20;,
     3;21,10,19;,
     3;22,23,18;,
     3;13,24,1;,
     3;1,24,25;,
     3;26,27,13;,
     3;28,29,15;,
     3;30,31,32;,
     3;33,18,20;,
     3;22,34,35;,
     3;35,36,22;,
     3;24,37,25;,
     3;1,25,2;,
     3;36,13,22;,
     3;23,19,18;,
     3;0,22,1;,
     3;23,21,19;,
     3;19,10,9;,
     3;17,7,6;,
     3;32,16,6;,
     3;20,19,9;,
     3;15,5,28;,
     3;14,3,5;,
     3;27,24,13;,
     3;38,26,13;,
     3;15,29,39;,
     3;31,16,32;,
     3;34,18,33;,
     3;18,34,22;,
     3;40,41,42;,
     3;40,43,44;,
     3;45,46,40;,
     3;46,43,40;,
     3;40,44,41;,
     3;40,42,45;,
     3;44,47,48;,
     3;43,47,44;,
     3;49,43,46;,
     3;47,43,49;,
     3;50,46,45;,
     3;51,46,50;,
     3;50,42,52;,
     3;45,42,50;,
     3;53,41,54;,
     3;42,41,53;,
     3;54,44,55;,
     3;41,44,54;,
     3;56,57,58;,
     3;59,57,56;,
     3;57,60,58;,
     3;61,60,57;,
     3;61,62,60;,
     3;63,62,61;,
     3;62,64,65;,
     3;63,64,62;,
     3;64,66,65;,
     3;67,66,64;,
     3;67,68,66;,
     3;69,68,67;,
     3;59,70,57;,
     3;71,70,59;,
     3;70,61,57;,
     3;72,61,70;,
     3;61,73,63;,
     3;72,73,61;,
     3;74,64,63;,
     3;75,64,74;,
     3;75,67,64;,
     3;76,67,75;,
     3;76,69,67;,
     3;77,69,76;,
     3;78,70,71;,
     3;79,70,78;,
     3;79,72,70;,
     3;80,72,79;,
     3;72,81,73;,
     3;80,81,72;,
     3;82,75,74;,
     3;83,75,82;,
     3;83,76,75;,
     3;84,76,83;,
     3;76,85,77;,
     3;84,85,76;,
     3;86,79,78;,
     3;87,79,86;,
     3;87,80,79;,
     3;88,80,87;,
     3;80,89,81;,
     3;88,89,80;,
     3;89,83,81;,
     3;90,83,89;,
     3;90,84,83;,
     3;91,84,90;,
     3;84,92,85;,
     3;91,92,84;,
     3;93,56,58;,
     3;94,58,60;,
     3;95,60,62;,
     3;96,62,65;,
     3;97,65,66;,
     3;98,66,68;,
     3;99,87,86;,
     3;100,88,87;,
     3;101,89,88;,
     3;102,90,89;,
     3;103,91,90;,
     3;104,92,91;,
     3;105,106,107;,
     3;105,107,108;,
     3;109,110,105;,
     3;105,111,109;,
     3;110,106,105;,
     3;105,108,111;,
     3;112,109,111;,
     3;113,109,112;,
     3;112,108,114;,
     3;111,108,112;,
     3;114,107,115;,
     3;108,107,114;,
     3;115,106,116;,
     3;107,106,115;,
     3;117,106,110;,
     3;116,106,117;,
     3;113,110,109;,
     3;117,110,113;;
    }

    MeshTextureCoords {
     118;
     0.141883;0.734519;,
     0.181485;0.737470;,
     0.141883;0.754231;,
     0.045871;0.760036;,
     0.018264;0.758781;,
     0.018264;0.737825;,
     0.045871;0.737858;,
     0.081442;0.756826;,
     0.045871;0.760036;,
     0.081442;0.734648;,
     0.113478;0.755528;,
     0.081442;0.756826;,
     0.141883;0.668780;,
     0.181485;0.672376;,
     0.045871;0.737858;,
     0.045871;0.672707;,
     0.081442;0.668795;,
     0.081442;0.734648;,
     0.113478;0.668788;,
     0.113478;0.734583;,
     0.081442;0.668795;,
     0.141883;0.754231;,
     0.141883;0.668780;,
     0.141883;0.734519;,
     0.212957;0.737503;,
     0.181485;0.757182;,
     0.212957;0.562579;,
     0.212957;0.672416;,
     0.018264;0.672667;,
     0.018264;0.562708;,
     0.045871;0.562742;,
     0.081442;0.562495;,
     0.045871;0.672707;,
     0.081442;0.562495;,
     0.113478;0.562530;,
     0.141883;0.562565;,
     0.181485;0.562545;,
     0.212957;0.758435;,
     0.181485;0.562545;,
     0.045871;0.562742;,
     0.686928;0.883360;,
     0.697798;0.865849;,
     0.672781;0.865905;,
     0.697274;0.900259;,
     0.710905;0.883040;,
     0.666343;0.883700;,
     0.671785;0.902155;,
     0.701775;0.910044;,
     0.722514;0.883047;,
     0.662656;0.912954;,
     0.654303;0.884630;,
     0.662656;0.912954;,
     0.664183;0.857319;,
     0.664183;0.857319;,
     0.702579;0.857234;,
     0.722514;0.883047;,
     0.232734;0.972783;,
     0.249515;0.956002;,
     0.249515;0.972783;,
     0.232734;0.956002;,
     0.266296;0.972783;,
     0.266296;0.956002;,
     0.283077;0.972783;,
     0.283077;0.956002;,
     0.299858;0.956002;,
     0.299858;0.972783;,
     0.316639;0.972783;,
     0.316639;0.956002;,
     0.333420;0.972783;,
     0.333420;0.956002;,
     0.249515;0.939221;,
     0.232734;0.939221;,
     0.266296;0.939221;,
     0.283077;0.939221;,
     0.283077;0.939221;,
     0.299858;0.939221;,
     0.316639;0.939221;,
     0.333420;0.939221;,
     0.232734;0.922440;,
     0.249515;0.922440;,
     0.266296;0.922440;,
     0.283077;0.922440;,
     0.283077;0.922440;,
     0.299858;0.922440;,
     0.316639;0.922440;,
     0.333420;0.922440;,
     0.232734;0.905659;,
     0.249515;0.905659;,
     0.266296;0.905659;,
     0.283077;0.905659;,
     0.299858;0.905659;,
     0.316639;0.905659;,
     0.333420;0.905659;,
     0.241125;0.989564;,
     0.257906;0.989564;,
     0.274687;0.989564;,
     0.291468;0.989564;,
     0.308249;0.989564;,
     0.325030;0.989564;,
     0.241125;0.888878;,
     0.257906;0.888878;,
     0.274687;0.888878;,
     0.291468;0.888878;,
     0.308249;0.888878;,
     0.325030;0.888878;,
     0.761486;0.884012;,
     0.773848;0.867477;,
     0.781240;0.885031;,
     0.774235;0.898283;,
     0.742621;0.885085;,
     0.750281;0.867477;,
     0.751121;0.898231;,
     0.743892;0.908818;,
     0.729232;0.886145;,
     0.783759;0.908909;,
     0.795840;0.886052;,
     0.783090;0.855776;,
     0.742444;0.855776;;
    }

    MeshMaterialList {
     1;
     132;
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
     0,
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
     118;
     118;
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
     117;
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
