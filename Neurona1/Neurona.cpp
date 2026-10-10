#include "pch.h"
#include "Neurona.h"

float Neurona::eval(float x, float y)
{
	float s = W[0] * x + W[1] * y + W[2];
	return 1 / (1 + exp(-s));
}

float Neurona::Train(float x, float y, float de)
{
	float f = eval(x, y);
	float dwx = lr * (de - f) * f * (1 - f) * x;
	float dwy = lr * (de - f) * f * (1 - f) * y;
	float dw = lr * (de - f) * f * (1 - f);

	W[0] += dwx;
	W[1] += dwy;
	W[2] += dw;

	return de - f;	
}

void Neurona::DrawPerfect(CPaintDC& dc, CRect rect) {


	float kx = 20.0 / (float)rect.Width();
	float ky = 20.0 / (float)rect.Height();

	for (int j = 0; j < rect.Height(); j++) {

		for (size_t i = 0; i < rect.Width(); i++)
		{

			float x = ((float) i - rect.Width() / 2) * kx;
			float y = -((float) j - rect.Height() / 2) * ky;
		
			float f = eval(x, y);
			dc.SetPixel(i, j, RGB(f*255, 0, 0) );
		}
	}
}


void Neurona::Draw(CPaintDC& dc, CRect rect) {

	int Cx = rect.Width() / 2;
	int Cy = rect.Height() / 2;

	float x1 = -10;
	float y1 = ( - x1 * W[0] - W[2])/W[1];

	float x2 = 10;
	float y2 = (-x2 * W[0] - W[2]) / W[1];

	float Kx = rect.Width() / 20;
	float Ky = rect.Height() / 20;

	float xf1 = Cx + x1 * Kx;
	float yf1 = Cy - y1 * Ky;

	float xf2 = Cx + x2 * Kx;
	float yf2 = Cy - y2 * Ky;

	dc.MoveTo(xf1, yf1);
	dc.LineTo(xf2, yf2);


}