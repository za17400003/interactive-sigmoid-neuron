#pragma once
class Neurona
{
	float W[3];
	float lr = 0.1;

public:
	float eval(float x, float y);
	void Draw(CPaintDC& dc, CRect rect);
	void DrawPerfect(CPaintDC& dc, CRect rect);
	float Train(float x, float y, float de);
};

