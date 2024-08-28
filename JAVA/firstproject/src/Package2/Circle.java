package Package2;

import java.util.Scanner;

class CircleClass{
    private float radius;

    //default constructor
    CircleClass(){
        System.out.println("There is no radius passed");
    }

    //set radius
    CircleClass(float r){
        this.radius = r;
    }

    //get radius
    protected float getRadius(){
        return radius;
    }

    //get area of circle
    public float getCircleArea(){
        float area = (float) (Math.PI * Math.pow(getRadius(), 2));
        return area;
    }

    //print area of circle
    public void printArea(){
        System.out.println("Area of Circle is "+ getCircleArea());
    }
}

class Cylinder extends CircleClass{
    private float height;

    //default constructor
    Cylinder(){
        System.out.println("No value of the cylinder is passed");
    }

    //set radius and height
    Cylinder(float r, float h){
        super(r);
        this.height = h;
    }

    //get height
    public float getHeight(){
        return height;
    }

    //get cylinder area
    public float getCylinderArea(){
        float area = getCircleArea()*height;
        return area;
    }

    //print cylinder area
    @Override
    public void printArea(){
        System.out.println("Cylinder Area = "+ getCylinderArea());
    }
}

public class Circle {
    public static void main(String[] args) {
        CircleClass obj = new Cylinder(4, 6);
        Cylinder obj1 = new Cylinder(4, 6);
        CircleClass obj2 = new CircleClass(4);

        obj.printArea();
        obj1.printArea();
        obj2.printArea();
    }
}
