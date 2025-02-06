class Cuboid {
private:
    double l,w,h;
    POINT tl, br;
	double area = 0.0f, vol = 0.0f;
	Dim dim;
	POINT vertices[8];
	int order=0, max=0;
public:
    Cuboid(){};
    void update(const POINT pt1, const POINT pb1);
	Cuboid(POINT tl, POINT br);
	double getSurfaceArea();
	double getVol();
	void showVertices();
	int getOrder();
	int getMax();
};