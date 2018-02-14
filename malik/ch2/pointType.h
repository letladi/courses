class pointType
{
public:
    void print() const;
    void setCoordinate(double, double);
    void getCoordinates(double &xToGet, double &yToGet) const;
    double getX() const;
    double getY() const;
    void setX(double);
    void setY(double);
    pointType();
    pointType(double, double);
private:
    double x;
    double y;
};