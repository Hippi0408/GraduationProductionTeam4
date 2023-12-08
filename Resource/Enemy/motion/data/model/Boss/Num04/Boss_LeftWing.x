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
 120;
 36.57732;40.49491;8.55582;,
 1.22043;5.78470;0.28232;,
 -0.15082;2.61371;0.28232;,
 32.59832;27.61552;8.55582;,
 1.22043;5.78470;0.28232;,
 1.22043;5.78470;-0.28018;,
 -0.15082;2.61371;-0.28018;,
 -0.15082;2.61371;0.28232;,
 1.22043;5.78470;-0.28018;,
 36.57732;40.49491;7.99332;,
 32.59832;27.61552;7.99332;,
 -0.15082;2.61371;-0.28018;,
 36.57732;40.49491;7.99332;,
 36.57732;40.49491;8.55582;,
 32.59832;27.61552;8.55582;,
 32.59832;27.61552;7.99332;,
 1.22043;5.78470;0.28232;,
 36.57732;40.49491;8.55582;,
 32.59832;27.61552;8.55582;,
 -0.15082;2.61371;0.28232;,
 44.48251;37.92469;8.55582;,
 1.52037;4.95455;0.28232;,
 -0.27669;0.70013;0.28232;,
 37.10332;23.41349;8.55582;,
 1.52037;4.95455;0.28232;,
 1.52037;4.95455;-0.28018;,
 -0.27669;0.70013;-0.28018;,
 -0.27669;0.70013;0.28232;,
 1.52037;4.95455;-0.28018;,
 44.48251;37.92469;7.99332;,
 37.10332;23.41349;7.99332;,
 -0.27669;0.70013;-0.28018;,
 44.48251;37.92469;7.99332;,
 44.48251;37.92469;8.55582;,
 37.10332;23.41349;8.55582;,
 37.10332;23.41349;7.99332;,
 1.52037;4.95455;0.28232;,
 44.48251;37.92469;8.55582;,
 37.10332;23.41349;8.55582;,
 -0.27669;0.70013;0.28232;,
 47.69211;29.76006;8.55582;,
 2.12589;3.69786;0.28232;,
 -0.24581;-0.26512;0.28232;,
 40.26017;16.24310;8.55582;,
 2.12589;3.69786;0.28232;,
 2.12589;3.69786;-0.28018;,
 -0.24581;-0.26512;-0.28018;,
 -0.24581;-0.26512;0.28232;,
 2.12589;3.69786;-0.28018;,
 47.69211;29.76006;7.99332;,
 40.26017;16.24310;7.99332;,
 -0.24581;-0.26512;-0.28018;,
 47.69211;29.76006;7.99332;,
 47.69211;29.76006;8.55582;,
 40.26017;16.24310;8.55582;,
 40.26017;16.24310;7.99332;,
 2.12589;3.69786;0.28232;,
 47.69211;29.76006;8.55582;,
 40.26017;16.24310;8.55582;,
 -0.24581;-0.26512;0.28232;,
 51.92902;22.23727;8.55582;,
 3.33282;2.32422;0.28232;,
 0.52780;-1.34473;0.28232;,
 43.13910;9.72306;8.55582;,
 3.33282;2.32422;0.28232;,
 3.33282;2.32422;-0.28018;,
 0.52780;-1.34473;-0.28018;,
 0.52780;-1.34473;0.28232;,
 3.33282;2.32422;-0.28018;,
 51.92902;22.23727;7.99332;,
 43.13910;9.72306;7.99332;,
 0.52780;-1.34473;-0.28018;,
 51.92902;22.23727;7.99332;,
 51.92902;22.23727;8.55582;,
 43.13910;9.72306;8.55582;,
 43.13910;9.72306;7.99332;,
 3.33282;2.32422;0.28232;,
 51.92902;22.23727;8.55582;,
 43.13910;9.72306;8.55582;,
 0.52780;-1.34473;0.28232;,
 56.66146;14.60006;8.55582;,
 5.23785;0.50755;0.28232;,
 0.09818;-2.76382;0.28232;,
 46.44604;1.72066;8.55582;,
 5.23785;0.50755;0.28232;,
 3.35811;0.50755;-0.28018;,
 0.09818;-2.76382;-0.28018;,
 0.09818;-2.76382;0.28232;,
 3.35811;0.50755;-0.28018;,
 56.66146;14.60006;7.99332;,
 46.44604;1.72066;7.99332;,
 0.09818;-2.76382;-0.28018;,
 56.66146;14.60006;7.99332;,
 56.66146;14.60006;8.55582;,
 46.44604;1.72066;8.55582;,
 46.44604;1.72066;7.99332;,
 5.23785;0.50755;0.28232;,
 56.66146;14.60006;8.55582;,
 46.44604;1.72066;8.55582;,
 0.09818;-2.76382;0.28232;,
 53.90614;2.85140;8.55582;,
 2.49924;-1.76631;0.28232;,
 -1.13513;-4.61604;0.28232;,
 42.51743;-8.49389;8.55582;,
 2.49924;-1.76631;0.28232;,
 2.49924;-1.76631;-0.28018;,
 -1.13513;-4.61604;-0.28018;,
 -1.13513;-4.61604;0.28232;,
 2.49924;-1.76631;-0.28018;,
 53.90614;2.85140;7.99332;,
 42.51743;-8.49389;7.99332;,
 -1.13513;-4.61604;-0.28018;,
 53.90614;2.85140;7.99332;,
 53.90614;2.85140;8.55582;,
 42.51743;-8.49389;8.55582;,
 42.51743;-8.49389;7.99332;,
 2.49924;-1.76631;0.28232;,
 53.90614;2.85140;8.55582;,
 42.51743;-8.49389;8.55582;,
 -1.13513;-4.61604;0.28232;;
 
 36;
 4;0,1,2,3;,
 4;4,5,6,7;,
 4;8,9,10,11;,
 4;12,13,14,15;,
 4;12,5,16,17;,
 4;18,19,6,15;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;32,25,36,37;,
 4;38,39,26,35;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;52,45,56,57;,
 4;58,59,46,55;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;72,65,76,77;,
 4;78,79,66,75;,
 4;80,81,82,83;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;92,85,96,97;,
 4;98,99,86,95;,
 4;100,101,102,103;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;112,105,116,117;,
 4;118,119,106,115;;
 
 MeshMaterialList {
  6;
  36;
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5,
  5;;
  Material {
   0.656000;0.656000;0.656000;1.000000;;
   5.000000;
   0.840000;0.840000;0.840000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.344800;0.344800;0.344800;1.000000;;
   5.000000;
   0.550000;0.550000;0.550000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.737600;0.737600;0.737600;1.000000;;
   5.000000;
   0.750000;0.750000;0.750000;;
   0.378020;0.378020;0.378020;;
  }
  Material {
   0.344800;0.344800;0.344800;1.000000;;
   5.000000;
   0.800000;0.800000;0.800000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.019200;0.000000;1.000000;;
   5.000000;
   0.630000;0.630000;0.630000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.800000;0.800000;0.800000;1.000000;;
   5.000000;
   0.910000;0.910000;0.910000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  51;
  -0.333023;0.124436;0.934672;,
  -0.824550;0.565789;0.000000;,
  -0.917856;0.396913;0.000000;,
  0.333023;-0.124436;-0.934672;,
  -0.290556;0.135551;0.947208;,
  -0.791247;0.611497;0.000000;,
  -0.921192;0.389109;0.000000;,
  0.290556;-0.135551;-0.947208;,
  -0.255614;0.146809;0.955567;,
  -0.700093;0.714052;0.000000;,
  -0.858074;0.513527;0.000000;,
  0.255614;-0.146809;-0.955567;,
  -0.230607;0.169177;0.958227;,
  -0.607952;0.793974;0.000000;,
  -0.794425;0.607362;0.000000;,
  0.230607;-0.169177;-0.958227;,
  -0.267796;0.568954;0.777545;,
  -0.198006;0.233513;0.951980;,
  -0.379135;0.609086;0.696614;,
  -0.407891;0.472599;0.781201;,
  -0.436819;0.744590;0.504752;,
  -0.564595;0.650068;0.508571;,
  0.190437;-0.170398;-0.966798;,
  -0.167879;0.190804;0.967166;,
  -0.368393;0.929670;0.000000;,
  -0.617039;0.786933;0.000000;,
  0.167879;-0.190804;-0.967166;,
  0.955442;-0.295178;-0.000000;,
  0.820108;-0.572209;-0.000000;,
  -0.700551;0.713603;0.000000;,
  0.606812;-0.794845;-0.000000;,
  0.891370;-0.453277;-0.000000;,
  0.733316;-0.679888;-0.000000;,
  -0.608809;0.793317;0.000000;,
  0.519285;-0.854601;-0.000000;,
  0.876281;-0.481800;-0.000000;,
  0.665037;-0.746810;-0.000000;,
  -0.496489;0.868043;0.000000;,
  0.377410;-0.926046;-0.000000;,
  0.818310;-0.574777;-0.000000;,
  0.569826;-0.821766;-0.000000;,
  -0.379168;0.925328;0.000000;,
  0.251397;-0.967884;-0.000000;,
  0.783476;-0.621422;-0.000000;,
  0.477975;-0.878373;-0.000000;,
  -0.298001;0.820293;0.488175;,
  0.096307;-0.995352;-0.000000;,
  0.705755;-0.708456;-0.000000;,
  0.340495;-0.940246;-0.000000;,
  -0.089466;0.995990;0.000000;,
  -0.088486;-0.996077;0.000000;;
  36;
  4;0,0,0,0;,
  4;1,1,2,2;,
  4;3,3,3,3;,
  4;27,27,28,28;,
  4;29,1,1,29;,
  4;28,30,30,28;,
  4;4,4,4,4;,
  4;5,5,6,6;,
  4;7,7,7,7;,
  4;31,31,32,32;,
  4;33,5,5,33;,
  4;32,34,34,32;,
  4;8,8,8,8;,
  4;9,9,10,10;,
  4;11,11,11,11;,
  4;35,35,36,36;,
  4;37,9,9,37;,
  4;36,38,38,36;,
  4;12,12,12,12;,
  4;13,13,14,14;,
  4;15,15,15,15;,
  4;39,39,40,40;,
  4;41,13,13,41;,
  4;40,42,42,40;,
  4;16,18,19,17;,
  4;18,20,21,19;,
  4;22,22,22,22;,
  4;43,43,44,44;,
  4;45,20,18,16;,
  4;44,46,46,44;,
  4;23,23,23,23;,
  4;24,24,25,25;,
  4;26,26,26,26;,
  4;47,47,48,48;,
  4;49,24,24,49;,
  4;48,50,50,48;;
 }
 MeshTextureCoords {
  120;
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;;
 }
}
