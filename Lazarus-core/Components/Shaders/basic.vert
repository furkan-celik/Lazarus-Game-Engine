#version 330 core

layout (location = 0) in vec4 position;
layout (location = 1) in vec4 color;

uniform mat4 prMatrix;
uniform mat4 vwMatrix = mat4(1.0);
uniform mat4 mlMatrix = mat4(1.0);

out DATA {
	vec4 pos, color;
} vs_out;

void main(){
	gl_Position = prMatrix * vwMatrix * mlMatrix * position;
	vs_out.pos = mlMatrix * position;
	vs_out.color = color;
}