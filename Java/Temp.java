package Other;

// import java.util.*;

class A {
    private int var1;
    protected int var2;
    public int var3;
}

class B extends A {

}

public class Temp {
    public static void main(String[] args) {
        A a = new A();
        a.var2 = 3;
    }
}
