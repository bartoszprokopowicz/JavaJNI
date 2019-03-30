public class Main {
    public static void main(String[] args) {
        JNI xxx = new JNI();
        Double[] a = {1.0, 2.0, 3.0, 4.0};
        Double[] b = {1.0, 2.0, 3.0};

        System.out.println(xxx.multi01(a,b));

        xxx = new JNI();
        xxx.b = b;
        System.out.println(xxx.multi02(a));

        xxx = new JNI();
        xxx.multi03();
        System.out.println(xxx.c);
    }
}
