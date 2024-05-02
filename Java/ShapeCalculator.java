package Other;

import java.util.*;

abstract class Shape {
    protected float input;
    protected float area;

    Shape(float a) {
        this.input = a;
    }
    abstract public float calculateArea();
}

class Square extends Shape {

    Square(float a) {
        super(a);
    }

    public float calculateArea() {
        return this.input * this.input;
    }
}

class Circle extends Shape {

    Circle(float a) {
        super(a);
    }

    public float calculateArea() {
        return (float) 3.14 * this.input * this.input;
    }
}

public class ShapeCalculator {
    public static void main(String[] args) {
        Circle c = new Circle();
        Square r = new Square();
        System.out.println("Select an option:");
        System.out.println("1. Area of Circle");
        System.out.println("2. Area of Square");
        System.out.println("3. Exit");
    }
}
