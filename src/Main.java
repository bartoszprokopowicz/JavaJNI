public class Main {
    public static void main(String[] args) {
        JNI xxx = new JNI();
        double a[] = {1.0,2.0,3.0,4.0};
        double b[] = {1.0,2.0,3.0};

        System.out.println(xxx.multi01(a,b));

        xxx.b = b;
        System.out.println(xxx.multi02(a));

        xxx.a = a;
        xxx.b = b;
        xxx.multi03();
        System.out.println(xxx.c);

        xxx.a = a;
        xxx.b = b;
        xxx.multi04();
        System.out.println(xxx.c);

    }
}
