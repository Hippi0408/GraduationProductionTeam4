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
 92;
 23.22950;158.60492;-50.00002;,
 23.22950;146.38361;-23.23002;,
 -13.17955;118.93971;-23.23002;,
 -13.17955;131.16101;-50.00002;,
 23.22950;124.13425;23.22998;,
 11.88425;96.69036;23.22998;,
 23.22950;109.10696;49.99998;,
 0.58425;88.17906;49.99998;,
 -50.00050;109.10696;49.99998;,
 -50.00050;124.13425;23.22998;,
 11.88425;96.69036;23.22998;,
 0.58425;88.17906;49.99998;,
 -50.00050;146.38361;-23.23002;,
 -13.17955;118.93971;-23.23002;,
 -50.00050;158.60492;-50.00002;,
 -13.17955;131.16101;-50.00002;,
 23.22950;124.13425;23.22998;,
 -50.00050;124.13425;23.22998;,
 23.22950;146.38361;-23.23002;,
 -50.00050;146.38361;-23.23002;,
 23.22950;158.60492;-50.00002;,
 -50.00050;158.60492;-50.00002;,
 0.58425;88.17906;49.99998;,
 23.22950;109.10696;49.99998;,
 -50.00050;109.10696;49.99998;,
 -13.17955;131.16101;-50.00002;,
 -50.00050;158.60492;-50.00002;,
 23.22950;158.60492;-50.00002;,
 -23.23050;109.10095;49.99998;,
 23.22950;109.10095;49.99998;,
 23.22950;195.76145;49.99998;,
 -23.23050;183.73490;49.99998;,
 49.99950;109.10095;49.99998;,
 49.99950;195.76145;49.99998;,
 49.99950;109.10095;49.99998;,
 49.99950;124.13425;23.22998;,
 49.99950;195.76150;23.22998;,
 49.99950;195.76145;49.99998;,
 49.99950;146.38361;-23.23002;,
 49.99950;212.56055;-23.23002;,
 49.99950;158.59890;-50.00002;,
 49.99950;212.56060;-50.00002;,
 49.99950;158.59890;-50.00002;,
 23.22950;158.59890;-50.00002;,
 23.22950;212.56060;-50.00002;,
 49.99950;212.56060;-50.00002;,
 -23.23050;158.59890;-50.00002;,
 -23.23050;200.53401;-50.00002;,
 -50.00050;158.59890;-50.00002;,
 -50.00050;194.52051;-50.00002;,
 -50.00050;158.59890;-50.00002;,
 -50.00050;146.38361;-23.23002;,
 -50.00050;194.52051;-23.23002;,
 -50.00050;194.52051;-50.00002;,
 -50.00050;124.13425;23.22998;,
 -50.00050;177.72151;23.22998;,
 -50.00050;158.59890;-50.00002;,
 -23.23050;158.59890;-50.00002;,
 -23.23050;146.38361;-23.23002;,
 -50.00050;146.38361;-23.23002;,
 23.22950;158.59890;-50.00002;,
 23.22950;146.38361;-23.23002;,
 49.99950;158.59890;-50.00002;,
 49.99950;146.38361;-23.23002;,
 -23.23050;124.13425;23.22998;,
 -50.00050;124.13425;23.22998;,
 23.22950;124.13425;23.22998;,
 49.99950;124.13425;23.22998;,
 -23.23050;109.10095;49.99998;,
 -50.00050;109.10095;49.99998;,
 23.22950;109.10095;49.99998;,
 49.99950;109.10095;49.99998;,
 -50.00050;177.72151;49.99998;,
 -23.23050;183.73490;49.99998;,
 -23.23050;183.73498;23.22998;,
 -50.00050;177.72151;23.22998;,
 23.22950;195.76145;49.99998;,
 23.22950;195.76150;23.22998;,
 49.99950;195.76145;49.99998;,
 49.99950;195.76150;23.22998;,
 -23.23050;200.53396;-23.23002;,
 -50.00050;194.52051;-23.23002;,
 23.22950;212.56055;-23.23002;,
 49.99950;212.56055;-23.23002;,
 -23.23050;200.53401;-50.00002;,
 -50.00050;194.52051;-50.00002;,
 23.22950;212.56060;-50.00002;,
 49.99950;212.56060;-50.00002;,
 -50.00050;177.72151;49.99998;,
 -50.00050;177.72151;49.99998;,
 -50.00050;109.10095;49.99998;,
 -50.00050;109.10095;49.99998;;
 
 43;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;8,9,10,11;,
 4;9,12,13,10;,
 4;12,14,15,13;,
 4;8,6,16,17;,
 4;17,16,18,19;,
 4;19,18,20,21;,
 3;22,23,24;,
 3;25,26,27;,
 4;28,29,30,31;,
 4;29,32,33,30;,
 4;34,35,36,37;,
 4;35,38,39,36;,
 4;38,40,41,39;,
 4;42,43,44,45;,
 4;43,46,47,44;,
 4;46,48,49,47;,
 4;50,51,52,53;,
 4;51,54,55,52;,
 4;56,57,58,59;,
 4;57,60,61,58;,
 4;60,62,63,61;,
 4;59,58,64,65;,
 4;58,61,66,64;,
 4;61,63,67,66;,
 4;65,64,68,69;,
 4;64,66,70,68;,
 4;66,67,71,70;,
 4;72,73,74,75;,
 4;73,76,77,74;,
 4;76,78,79,77;,
 4;75,74,80,81;,
 4;74,77,82,80;,
 4;77,79,83,82;,
 4;81,80,84,85;,
 4;80,82,86,84;,
 4;82,83,87,86;,
 3;88,28,31;,
 3;89,55,54;,
 3;28,88,90;,
 3;54,91,89;;
 
 MeshMaterialList {
  4;
  43;
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  2,
  0,
  0,
  0,
  0,
  1,
  1,
  1,
  0,
  0,
  0,
  1,
  1,
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
  0,
  1,
  0,
  1;;
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill002.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\bill002.jpg";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "texture\\Concrete.png";
   }
  }
 }
 MeshNormals {
  38;
  -0.561188;-0.752936;-0.343738;,
  0.565515;-0.750252;-0.342513;,
  0.631702;-0.655883;-0.413244;,
  0.768324;-0.573137;-0.284944;,
  0.816550;-0.571570;-0.080949;,
  -0.353818;-0.825365;-0.439983;,
  -0.419488;-0.830649;-0.366131;,
  -0.522102;-0.791859;-0.316812;,
  0.000000;-0.871921;-0.489647;,
  -0.219171;0.975686;0.000001;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;-0.905876;-0.423543;,
  0.000000;-0.905876;-0.423542;,
  0.000000;-0.887386;-0.461027;,
  -0.231573;0.958169;0.168187;,
  -0.124551;0.977293;0.171419;,
  -0.231573;0.958169;0.168186;,
  -0.124551;0.977294;0.171419;,
  0.000000;0.872004;0.489498;,
  0.000000;0.887425;0.460951;,
  0.000000;0.905837;0.423627;,
  0.000000;0.909685;0.415299;,
  0.000000;-0.909762;-0.415129;,
  0.000000;-0.909762;-0.415130;,
  0.000000;-0.871921;-0.489647;,
  -0.234915;0.972016;0.000002;,
  -0.216028;0.961691;0.168767;,
  -0.126311;0.991991;0.000002;,
  0.000000;1.000000;0.000002;,
  0.000000;0.984990;0.172609;,
  -0.216029;0.961691;0.168767;,
  -0.234917;0.972016;0.000001;,
  -0.219173;0.975686;0.000001;,
  -0.126311;0.991991;0.000002;,
  0.000000;1.000000;0.000002;;
  43;
  4;1,2,2,1;,
  4;2,3,3,2;,
  4;3,4,4,3;,
  4;5,6,6,5;,
  4;6,7,7,6;,
  4;7,0,0,7;,
  4;21,21,22,22;,
  4;22,22,23,23;,
  4;23,23,24,24;,
  3;10,10,10;,
  3;12,12,12;,
  4;10,10,10,10;,
  4;10,10,10,10;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;12,12,12,12;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;13,13,13,13;,
  4;25,26,14,15;,
  4;26,26,15,14;,
  4;26,25,15,15;,
  4;15,14,16,16;,
  4;14,15,16,16;,
  4;15,15,16,16;,
  4;16,16,27,8;,
  4;16,16,27,27;,
  4;16,16,8,27;,
  4;9,28,17,29;,
  4;28,30,18,17;,
  4;30,31,32,18;,
  4;29,17,19,33;,
  4;17,18,20,19;,
  4;18,32,32,20;,
  4;33,19,34,35;,
  4;19,20,36,34;,
  4;20,32,37,36;,
  3;10,10,10;,
  3;13,13,13;,
  3;10,10,10;,
  3;13,13,13;;
 }
 MeshTextureCoords {
  92;
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;0.000000;,
  0.666670;1.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  1.000000;0.333330;,
  0.000000;0.333330;,
  1.000000;0.666670;,
  0.000000;0.666670;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.503723;0.152674;,
  0.648039;0.033198;,
  0.181353;0.033198;,
  0.416008;-0.092707;,
  0.181353;-0.249382;,
  0.648039;-0.249382;,
  0.351955;0.033232;,
  0.648039;0.033232;,
  0.648039;-0.461506;,
  0.351955;-0.392847;,
  0.818641;0.033232;,
  0.818641;-0.461506;,
  0.818634;0.033221;,
  0.648037;-0.052605;,
  0.648037;-0.461529;,
  0.818634;-0.461529;,
  0.351963;-0.179628;,
  0.351963;-0.557436;,
  0.181366;-0.249366;,
  0.181366;-0.557437;,
  0.818641;-0.249348;,
  0.648039;-0.249348;,
  0.648039;-0.557411;,
  0.818641;-0.557411;,
  0.351955;-0.249348;,
  0.351955;-0.488752;,
  0.181353;-0.249348;,
  0.181353;-0.454422;,
  0.181366;-0.249366;,
  0.351963;-0.179628;,
  0.351963;-0.454445;,
  0.181366;-0.454445;,
  0.648037;-0.052605;,
  0.648037;-0.358538;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.000000;0.000000;,
  0.333330;0.000000;,
  0.333330;0.333330;,
  0.000000;0.333330;,
  0.666670;0.000000;,
  0.666670;0.333330;,
  1.000000;0.000000;,
  1.000000;0.333330;,
  0.333330;0.666670;,
  0.000000;0.666670;,
  0.666670;0.666670;,
  1.000000;0.666670;,
  0.333330;1.000000;,
  0.000000;1.000000;,
  0.666670;1.000000;,
  1.000000;1.000000;,
  0.181353;-0.358517;,
  0.818634;-0.358538;,
  0.181353;0.033232;,
  0.818634;0.033221;;
 }
}
