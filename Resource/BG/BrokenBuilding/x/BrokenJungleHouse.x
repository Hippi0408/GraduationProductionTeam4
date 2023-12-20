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
 295;
 0.00000;23.58570;-14.00000;,
 0.00000;21.58570;-14.00000;,
 -12.00000;10.58570;-14.00000;,
 -14.00000;10.58570;-14.00000;,
 0.00000;21.58570;14.00000;,
 -12.00000;10.58570;14.00000;,
 0.00000;23.58570;14.00000;,
 -14.00000;10.58570;14.00000;,
 0.00000;23.58570;-14.00000;,
 14.00000;10.58570;-14.00000;,
 12.00000;10.58570;-14.00000;,
 0.00000;21.58570;-14.00000;,
 12.00000;10.58570;14.00000;,
 0.00000;21.58570;14.00000;,
 14.00000;10.58570;14.00000;,
 0.00000;23.58570;14.00000;,
 7.99454;14.65030;-12.00000;,
 7.99454;14.65030;-12.00000;,
 11.70444;10.94552;-12.00000;,
 0.80930;10.94552;-12.00000;,
 7.99454;14.65030;-12.00000;,
 7.99454;14.65030;12.00000;,
 11.70444;10.94552;12.00000;,
 11.70444;10.94552;-12.00000;,
 7.99454;14.65030;12.00000;,
 7.99454;14.65030;12.00000;,
 0.55738;10.94552;12.00000;,
 11.70444;10.94552;12.00000;,
 7.99454;14.65030;12.00000;,
 7.99454;14.65030;-12.00000;,
 0.80930;10.94552;-12.00000;,
 0.55738;10.94552;12.00000;,
 7.99454;14.65030;12.00000;,
 7.99454;14.65030;12.00000;,
 7.99454;14.65030;-12.00000;,
 7.99454;14.65030;-12.00000;,
 0.80930;10.94552;-12.00000;,
 11.70444;10.94552;-12.00000;,
 11.70444;10.94552;12.00000;,
 0.55738;10.94552;12.00000;,
 0.80930;11.46544;-12.00000;,
 11.70444;11.46544;-12.00000;,
 11.70444;4.05336;-12.00000;,
 0.80930;4.05336;-12.00000;,
 11.70444;11.46544;-12.00000;,
 11.70444;11.46544;12.00000;,
 11.70444;4.05336;12.00000;,
 11.70444;4.05336;-12.00000;,
 11.70444;11.46544;12.00000;,
 0.55738;11.46544;12.00000;,
 0.55738;4.05336;12.00000;,
 11.70444;4.05336;12.00000;,
 0.55738;11.46544;12.00000;,
 0.80930;11.46544;-12.00000;,
 0.80930;4.05336;-12.00000;,
 0.55738;4.05336;12.00000;,
 0.55738;11.46544;12.00000;,
 11.70444;11.46544;12.00000;,
 11.70444;11.46544;-12.00000;,
 0.80930;11.46544;-12.00000;,
 0.80930;4.05336;-12.00000;,
 11.70444;4.05336;-12.00000;,
 11.70444;4.05336;12.00000;,
 0.55738;4.05336;12.00000;,
 1.89476;10.57830;-12.08992;,
 6.66470;10.57830;-12.08992;,
 6.66470;3.82612;-12.08992;,
 1.89476;3.82612;-12.08992;,
 6.66470;10.57830;-12.08992;,
 6.66470;10.57830;-8.08992;,
 6.66470;3.82612;-8.08992;,
 6.66470;3.82612;-12.08992;,
 6.66470;10.57830;-8.08992;,
 1.89476;10.57830;-8.08992;,
 1.89476;3.82612;-8.08992;,
 6.66470;3.82612;-8.08992;,
 1.89476;10.57830;-8.08992;,
 1.89476;10.57830;-12.08992;,
 1.89476;3.82612;-12.08992;,
 1.89476;3.82612;-8.08992;,
 6.66470;10.57830;-12.08992;,
 1.89476;10.57830;-12.08992;,
 1.89476;3.82612;-12.08992;,
 6.66470;3.82612;-12.08992;,
 -11.31430;4.51216;-11.30736;,
 -9.36356;4.51216;-11.30736;,
 -9.36356;0.09258;-11.30736;,
 -11.31430;0.09258;-11.30736;,
 -9.36356;4.51216;-11.30736;,
 -9.36356;4.51216;-9.42356;,
 -9.36356;0.09258;-9.42356;,
 -9.36356;0.09258;-11.30736;,
 -9.36356;4.51216;-9.42356;,
 -11.31430;4.51216;-9.42356;,
 -11.31430;0.09258;-9.42356;,
 -9.36356;0.09258;-9.42356;,
 -11.31430;4.51216;-9.42356;,
 -11.31430;4.51216;-11.30736;,
 -11.31430;0.09258;-11.30736;,
 -11.31430;0.09258;-9.42356;,
 -9.36356;4.51216;-11.30736;,
 -11.31430;4.51216;-11.30736;,
 -11.31430;0.09258;-11.30736;,
 -9.36356;0.09258;-11.30736;,
 11.31430;4.51216;-11.30736;,
 11.31430;0.09258;-11.30736;,
 9.36356;0.09258;-11.30736;,
 9.36356;4.51216;-11.30736;,
 9.36356;4.51216;-11.30736;,
 9.36356;0.09258;-11.30736;,
 9.36356;0.09258;-9.42356;,
 9.36356;4.51216;-9.42356;,
 9.36356;4.51216;-9.42356;,
 9.36356;0.09258;-9.42356;,
 11.31430;0.09258;-9.42356;,
 11.31430;4.51216;-9.42356;,
 11.31430;4.51216;-9.42356;,
 11.31430;0.09258;-9.42356;,
 11.31430;0.09258;-11.30736;,
 11.31430;4.51216;-11.30736;,
 11.31430;4.51216;-11.30736;,
 9.36356;4.51216;-11.30736;,
 11.31430;0.09258;-11.30736;,
 9.36356;0.09258;-11.30736;,
 -11.31430;4.51216;9.26874;,
 -9.36356;4.51216;9.26874;,
 -9.36356;0.09258;9.26874;,
 -11.31430;0.09258;9.26874;,
 -9.36356;4.51216;9.26874;,
 -9.36356;4.51216;11.15254;,
 -9.36356;0.09258;11.15254;,
 -9.36356;0.09258;9.26874;,
 -9.36356;4.51216;11.15254;,
 -11.31430;4.51216;11.15254;,
 -11.31430;0.09258;11.15254;,
 -9.36356;0.09258;11.15254;,
 -11.31430;4.51216;11.15254;,
 -11.31430;4.51216;9.26874;,
 -11.31430;0.09258;9.26874;,
 -11.31430;0.09258;11.15254;,
 -9.36356;4.51216;9.26874;,
 -11.31430;4.51216;9.26874;,
 -11.31430;0.09258;9.26874;,
 -9.36356;0.09258;9.26874;,
 11.31430;4.51216;9.26874;,
 11.31430;0.09258;9.26874;,
 9.36356;0.09258;9.26874;,
 9.36356;4.51216;9.26874;,
 9.36356;4.51216;9.26874;,
 9.36356;0.09258;9.26874;,
 9.36356;0.09258;11.15254;,
 9.36356;4.51216;11.15254;,
 9.36356;4.51216;11.15254;,
 9.36356;0.09258;11.15254;,
 11.31430;0.09258;11.15254;,
 11.31430;4.51216;11.15254;,
 11.31430;4.51216;11.15254;,
 11.31430;0.09258;11.15254;,
 11.31430;0.09258;9.26874;,
 11.31430;4.51216;9.26874;,
 11.31430;4.51216;9.26874;,
 9.36356;4.51216;9.26874;,
 11.31430;0.09258;9.26874;,
 9.36356;0.09258;9.26874;,
 -12.16738;4.68954;-14.60930;,
 12.16738;4.68954;-14.60930;,
 12.16738;3.77106;-14.60930;,
 -12.16738;3.77106;-14.60930;,
 12.16738;4.68954;-14.60930;,
 12.16738;4.68954;12.54760;,
 12.16738;3.77106;12.54760;,
 12.16738;3.77106;-14.60930;,
 12.16738;4.68954;12.54760;,
 -12.16738;4.68954;12.54760;,
 -12.16738;3.77106;12.54760;,
 12.16738;3.77106;12.54760;,
 -12.16738;4.68954;12.54760;,
 -12.16738;4.68954;-14.60930;,
 -12.16738;3.77106;-14.60930;,
 -12.16738;3.77106;12.54760;,
 12.16738;4.68954;-14.60930;,
 -12.16738;4.68954;-14.60930;,
 -12.16738;3.77106;-14.60930;,
 12.16738;3.77106;-14.60930;,
 1.89708;4.72148;-14.62214;,
 6.66056;4.72148;-14.62214;,
 6.66056;-0.06212;-18.76252;,
 1.89708;-0.06212;-18.76252;,
 6.66056;4.72148;-14.62214;,
 6.66056;4.07254;-13.85176;,
 6.66056;-0.12132;-17.49088;,
 6.66056;-0.06212;-18.76252;,
 6.66056;4.07254;-13.85176;,
 1.89708;4.07254;-13.85176;,
 1.89708;-0.12132;-17.49088;,
 6.66056;-0.12132;-17.49088;,
 1.89708;4.07254;-13.85176;,
 1.89708;4.72148;-14.62214;,
 1.89708;-0.06212;-18.76252;,
 1.89708;-0.12132;-17.49088;,
 6.66056;4.72148;-14.62214;,
 1.89708;4.72148;-14.62214;,
 1.89708;-0.06212;-18.76252;,
 6.66056;-0.06212;-18.76252;,
 0.00000;22.00496;-12.00000;,
 0.00000;22.00496;-12.00000;,
 0.80930;10.94552;-12.00000;,
 -11.70444;10.94552;-12.00000;,
 0.00000;22.00496;-12.00000;,
 0.00000;22.00496;12.00000;,
 0.55738;10.94552;12.00000;,
 0.80930;10.94552;-12.00000;,
 0.00000;22.00496;12.00000;,
 0.00000;22.00496;12.00000;,
 -11.70444;10.94552;12.00000;,
 0.55738;10.94552;12.00000;,
 0.00000;22.00496;12.00000;,
 0.00000;22.00496;-12.00000;,
 -11.70444;10.94552;-12.00000;,
 -11.70444;10.94552;12.00000;,
 0.00000;22.00496;12.00000;,
 0.00000;22.00496;12.00000;,
 0.00000;22.00496;-12.00000;,
 0.00000;22.00496;-12.00000;,
 -11.70444;10.94552;-12.00000;,
 0.80930;10.94552;-12.00000;,
 0.55738;10.94552;12.00000;,
 -11.70444;10.94552;12.00000;,
 -11.70444;11.46544;-12.00000;,
 0.80930;11.46544;-12.00000;,
 0.80930;4.05336;-12.00000;,
 -11.70444;4.05336;-12.00000;,
 0.80930;11.46544;-12.00000;,
 0.55738;11.46544;12.00000;,
 0.55738;4.05336;12.00000;,
 0.80930;4.05336;-12.00000;,
 0.55738;11.46544;12.00000;,
 -11.70444;11.46544;12.00000;,
 -11.70444;4.05336;12.00000;,
 0.55738;4.05336;12.00000;,
 -11.70444;11.46544;12.00000;,
 -11.70444;11.46544;-12.00000;,
 -11.70444;4.05336;-12.00000;,
 -11.70444;4.05336;12.00000;,
 -11.70444;11.46544;12.00000;,
 0.55738;11.46544;12.00000;,
 0.80930;11.46544;-12.00000;,
 -11.70444;11.46544;-12.00000;,
 -11.70444;4.05336;-12.00000;,
 0.80930;4.05336;-12.00000;,
 0.55738;4.05336;12.00000;,
 -11.70444;4.05336;12.00000;,
 0.00000;22.00496;-12.00000;,
 4.37784;19.14508;-12.00000;,
 7.99454;14.65030;-12.00000;,
 0.35240;14.63856;-12.00000;,
 4.37784;19.14508;-12.00000;,
 7.99454;14.65030;12.00000;,
 4.56954;14.63856;12.00000;,
 7.99454;14.65030;-12.00000;,
 7.99454;14.65030;12.00000;,
 0.00000;22.00496;12.00000;,
 0.35240;14.63856;12.00000;,
 4.56954;14.63856;12.00000;,
 0.00000;22.00496;12.00000;,
 0.00000;22.00496;-12.00000;,
 0.35240;14.63856;-12.00000;,
 0.35240;14.63856;12.00000;,
 0.00000;22.00496;12.00000;,
 7.99454;14.65030;12.00000;,
 4.37784;19.14508;-12.00000;,
 0.00000;22.00496;-12.00000;,
 0.35240;14.63856;-12.00000;,
 7.99454;14.65030;-12.00000;,
 4.56954;14.63856;12.00000;,
 0.35240;14.63856;12.00000;,
 4.56954;14.85042;12.00000;,
 0.35240;14.85042;12.00000;,
 0.55738;10.94552;12.00000;,
 0.35240;14.85042;12.00000;,
 0.35240;14.85042;-12.00000;,
 0.80930;10.94552;-12.00000;,
 0.55738;10.94552;12.00000;,
 0.35240;14.85042;12.00000;,
 4.56954;14.85042;12.00000;,
 7.99454;14.65030;-12.00000;,
 0.35240;14.85042;-12.00000;,
 0.80930;10.94552;-12.00000;,
 7.99454;14.65030;12.00000;,
 0.55738;10.94552;12.00000;,
 0.80930;10.94552;-12.00000;,
 0.35240;14.85042;-12.00000;,
 7.99454;14.65030;-12.00000;,
 4.56954;14.85042;12.00000;,
 7.99454;14.65030;12.00000;;
 
 90;
 4;0,1,2,3;,
 4;1,4,5,2;,
 4;4,6,7,5;,
 4;6,0,3,7;,
 4;6,4,1,0;,
 4;3,2,5,7;,
 4;8,9,10,11;,
 4;11,10,12,13;,
 4;13,12,14,15;,
 4;15,14,9,8;,
 4;15,8,11,13;,
 4;9,14,12,10;,
 4;16,17,18,19;,
 4;20,21,22,23;,
 4;24,25,26,27;,
 4;28,29,30,31;,
 4;32,33,34,35;,
 4;36,37,38,39;,
 4;40,41,42,43;,
 4;44,45,46,47;,
 4;48,49,50,51;,
 4;52,53,54,55;,
 4;56,57,58,59;,
 4;60,61,62,63;,
 4;64,65,66,67;,
 4;68,69,70,71;,
 4;72,73,74,75;,
 4;76,77,78,79;,
 4;76,69,80,81;,
 4;82,83,70,79;,
 4;84,85,86,87;,
 4;88,89,90,91;,
 4;92,93,94,95;,
 4;96,97,98,99;,
 4;96,89,100,101;,
 4;102,103,90,99;,
 4;104,105,106,107;,
 4;108,109,110,111;,
 4;112,113,114,115;,
 4;116,117,118,119;,
 4;116,120,121,111;,
 4;122,117,110,123;,
 4;124,125,126,127;,
 4;128,129,130,131;,
 4;132,133,134,135;,
 4;136,137,138,139;,
 4;136,129,140,141;,
 4;142,143,130,139;,
 4;144,145,146,147;,
 4;148,149,150,151;,
 4;152,153,154,155;,
 4;156,157,158,159;,
 4;156,160,161,151;,
 4;162,157,150,163;,
 4;164,165,166,167;,
 4;168,169,170,171;,
 4;172,173,174,175;,
 4;176,177,178,179;,
 4;176,169,180,181;,
 4;182,183,170,179;,
 4;184,185,186,187;,
 4;188,189,190,191;,
 4;192,193,194,195;,
 4;196,197,198,199;,
 4;196,189,200,201;,
 4;202,203,190,199;,
 4;204,205,206,207;,
 4;208,209,210,211;,
 4;212,213,214,215;,
 4;216,217,218,219;,
 4;220,221,222,223;,
 4;224,225,226,227;,
 4;228,229,230,231;,
 4;232,233,234,235;,
 4;236,237,238,239;,
 4;240,241,242,243;,
 4;244,245,246,247;,
 4;248,249,250,251;,
 4;252,253,254,255;,
 4;256,257,258,259;,
 4;260,261,262,263;,
 4;264,265,266,267;,
 4;268,269,270,271;,
 4;272,273,274,275;,
 4;276,277,278,260;,
 4;279,280,281,282;,
 4;283,284,285,286;,
 4;287,273,288,289;,
 3;254,290,291;,
 3;292,293,294;;
 
 MeshMaterialList {
  6;
  90;
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
  1,
  0,
  1,
  0,
  5,
  5,
  1,
  3,
  1,
  3,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  0,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  4,
  1,
  0,
  1,
  0,
  5,
  5,
  1,
  3,
  1,
  3,
  0,
  0,
  1,
  0,
  1,
  0,
  0,
  5,
  1,
  3,
  0,
  0,
  1,
  0;;
  Material {
   0.000000;0.000000;0.000000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.624000;0.540000;0.385600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.476800;0.417600;0.313600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
   TextureFilename {
    "Data\\texture\\building\\Palm.png";
   }
  }
  Material {
   0.624000;0.545600;0.392000;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   0.476800;0.417600;0.313600;1.000000;;
   5.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
  Material {
   1.000000;1.000000;1.000000;1.000000;;
   0.000000;
   0.000000;0.000000;0.000000;;
   0.000000;0.000000;0.000000;;
  }
 }
 MeshNormals {
  73;
  0.000000;0.000000;-1.000000;,
  0.915348;-0.402663;-0.000000;,
  0.362523;-0.931975;-0.000000;,
  0.000000;0.000000;1.000000;,
  -0.362523;-0.931975;0.000000;,
  -0.916638;0.399718;0.000000;,
  -0.680451;0.732794;0.000000;,
  0.916638;0.399718;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.915348;-0.402663;0.000000;,
  0.680451;0.732794;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.706618;0.707595;0.000000;,
  0.000000;0.000000;1.000000;,
  1.000000;0.000000;0.000000;,
  -0.452091;0.891969;-0.002340;,
  0.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -0.999945;0.000000;-0.010496;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.000000;-1.000000;,
  1.000000;0.000000;0.000000;,
  0.000000;0.000000;1.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  0.000000;0.654442;-0.756112;,
  1.000000;0.000000;0.000000;,
  0.000000;-0.655387;0.755293;,
  0.000000;-0.919185;0.393826;,
  -1.000000;0.000000;0.000000;,
  0.000000;0.764814;0.644251;,
  0.000000;-0.998918;-0.046504;,
  0.000000;0.000000;-1.000000;,
  0.998083;0.061661;0.005234;,
  0.000000;0.000000;1.000000;,
  0.999945;0.000000;0.010496;,
  -0.686796;0.726850;0.000000;,
  0.000000;0.000000;0.000000;,
  0.000000;-1.000000;-0.000000;,
  -1.000000;0.000000;0.000000;,
  0.000000;1.000000;0.000000;,
  0.000000;0.000000;-1.000000;,
  0.902653;-0.430368;-0.000000;,
  0.000000;0.000000;1.000000;,
  -0.996422;-0.084359;-0.005215;,
  0.715614;-0.698495;0.001236;,
  -0.998858;-0.047784;0.000000;,
  0.613944;0.789145;0.017954;,
  0.352018;0.935946;0.009401;,
  0.000768;-1.000000;-0.000135;,
  0.013090;0.999912;-0.002300;,
  0.035719;0.999361;-0.001150;,
  0.452091;-0.891969;0.002340;,
  0.000000;0.000000;-1.000000;;
  90;
  4;0,0,0,0;,
  4;1,1,2,2;,
  4;3,3,3,3;,
  4;5,5,6,6;,
  4;7,1,1,7;,
  4;8,2,2,8;,
  4;0,0,0,0;,
  4;9,4,4,9;,
  4;3,3,3,3;,
  4;7,10,10,7;,
  4;5,5,9,9;,
  4;8,8,4,4;,
  4;11,11,11,11;,
  4;12,12,12,12;,
  4;13,13,13,13;,
  4;15,15,15,15;,
  4;16,16,16,16;,
  4;17,17,17,17;,
  4;11,11,11,11;,
  4;14,14,14,14;,
  4;13,13,13,13;,
  4;18,18,18,18;,
  4;19,19,19,19;,
  4;17,17,17,17;,
  4;20,20,20,20;,
  4;21,21,21,21;,
  4;22,22,22,22;,
  4;23,23,23,23;,
  4;24,24,24,24;,
  4;25,25,25,25;,
  4;26,26,26,26;,
  4;27,27,27,27;,
  4;28,28,28,28;,
  4;29,29,29,29;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;26,26,26,26;,
  4;29,29,29,29;,
  4;28,28,28,28;,
  4;27,27,27,27;,
  4;30,30,30,30;,
  4;31,31,31,31;,
  4;32,32,32,32;,
  4;33,33,33,33;,
  4;34,34,34,34;,
  4;35,35,35,35;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;32,32,32,32;,
  4;35,35,35,35;,
  4;34,34,34,34;,
  4;33,33,33,33;,
  4;36,36,36,36;,
  4;37,37,37,37;,
  4;38,38,38,38;,
  4;39,39,39,39;,
  4;40,40,40,40;,
  4;41,41,41,41;,
  4;42,42,42,42;,
  4;43,43,43,43;,
  4;44,44,44,44;,
  4;45,45,45,45;,
  4;46,46,47,47;,
  4;48,48,48,48;,
  4;49,49,49,49;,
  4;50,50,47,47;,
  4;51,51,51,51;,
  4;52,52,52,52;,
  4;53,53,53,53;,
  4;55,55,55,55;,
  4;56,56,56,56;,
  4;57,57,57,57;,
  4;51,51,51,51;,
  4;54,54,54,54;,
  4;53,53,53,53;,
  4;58,58,58,58;,
  4;59,59,59,59;,
  4;57,57,57,57;,
  4;60,60,60,60;,
  4;61,64,61,64;,
  4;62,62,62,62;,
  4;65,65,65,65;,
  4;66,67,66,66;,
  4;68,68,68,68;,
  4;62,62,62,62;,
  4;63,63,63,63;,
  4;69,70,70,69;,
  4;71,64,64,71;,
  3;60,72,72;,
  3;70,70,67;;
 }
 MeshTextureCoords {
  295;
  0.000000;2.161200;,
  0.000000;2.337970;,
  0.000000;4.370910;,
  0.000000;4.547680;,
  1.000000;2.337970;,
  1.000000;4.370910;,
  1.000000;2.161200;,
  1.000000;4.547680;,
  0.000000;-1.161200;,
  0.000000;-3.547680;,
  0.000000;-3.370910;,
  0.000000;-1.337970;,
  1.000000;-3.370910;,
  1.000000;-1.337970;,
  1.000000;-3.547680;,
  1.000000;-1.161200;,
  2.145360;2.297286;,
  2.145360;2.297286;,
  1.566488;2.788481;,
  1.566488;1.345951;,
  0.433450;0.551020;,
  0.433450;0.795920;,
  0.364330;0.795920;,
  0.364330;0.551020;,
  2.145360;2.297286;,
  2.145360;2.297286;,
  1.566488;1.312597;,
  1.566488;2.788481;,
  0.433450;0.795920;,
  0.433450;0.551020;,
  0.364330;0.551020;,
  0.364330;0.795920;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.647725;1.345951;,
  1.647725;2.788481;,
  0.489587;2.788481;,
  0.489587;1.345951;,
  1.647725;0.246032;,
  1.647725;3.420635;,
  0.489587;3.420635;,
  0.489587;0.246032;,
  1.647725;2.788481;,
  1.647725;1.312597;,
  0.489587;1.312597;,
  0.489587;2.788481;,
  1.647725;3.420635;,
  1.647725;0.246032;,
  0.489587;0.246032;,
  0.489587;3.420635;,
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
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
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
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
  1.000000;0.000000;,
  0.000000;1.000000;,
  1.000000;1.000000;,
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
  3.294525;1.238799;,
  3.294525;1.238799;,
  1.566488;1.345951;,
  1.566488;-0.310883;,
  0.433450;0.551020;,
  0.433450;0.795920;,
  0.364330;0.795920;,
  0.364330;0.551020;,
  3.294525;1.238799;,
  3.294525;1.238799;,
  1.566488;-0.310883;,
  1.566488;1.312597;,
  0.433450;0.795920;,
  0.433450;0.551020;,
  0.364330;0.551020;,
  0.364330;0.795920;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.647725;-0.310883;,
  1.647725;1.345951;,
  0.489587;1.345951;,
  0.489587;-0.310883;,
  1.647725;0.246032;,
  1.647725;3.420635;,
  0.489587;3.420635;,
  0.489587;0.246032;,
  1.647725;1.312597;,
  1.647725;-0.310883;,
  0.489587;-0.310883;,
  0.489587;1.312597;,
  1.647725;3.420635;,
  1.647725;0.246032;,
  0.489587;0.246032;,
  0.489587;3.420635;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  3.294525;1.238799;,
  2.847669;1.818430;,
  2.145360;2.297286;,
  2.143525;1.285457;,
  0.433450;0.551020;,
  0.433450;0.795920;,
  0.364330;0.795920;,
  0.364330;0.551020;,
  2.145360;2.297286;,
  3.294525;1.238799;,
  2.143525;1.285457;,
  2.143525;1.843812;,
  0.433450;0.795920;,
  0.433450;0.551020;,
  0.364330;0.551020;,
  0.364330;0.795920;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  2.176628;1.843812;,
  2.176628;1.285457;,
  1.566488;1.312597;,
  2.176628;3.420635;,
  2.176628;0.246032;,
  1.566488;0.246032;,
  1.566488;3.420635;,
  0.000000;0.000000;,
  1.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  0.000000;0.000000;,
  1.000000;1.000000;,
  0.000000;1.000000;,
  1.566488;1.345951;,
  2.176628;1.285457;,
  2.145360;0.246030;,
  2.176630;3.420630;,
  2.145360;3.420630;;
 }
}