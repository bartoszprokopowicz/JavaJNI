public class JNI {
    public double[] a;
    public double[] b;
    public double c;

    public native double multi01(double[] a, double[] b);
    // zakładamy, że po stronie kodu natywnego wyliczony zostanie iloczyn skalarny dwóch wektorów
    public native double multi02(double[] a);
    // zakładamy, że drugi atrybut będzie pobrany z obiektu przekazanego do metody natywnej
    public native void multi03();
    // zakładamy, że po stronie natywnej utworzone zostanie okienko na atrybuty,
    // a po ich wczytaniu i przepisaniu do a,b obliczony zostanie wynik.
    // Wynik powinna wyliczać metoda Javy multi04
    // (korzystająca z parametrów a,b i wpisująca wynik do c).

    public void multi04(){
        // mnoży a i b, wynik wpisuje do c

        double sum = 0;
        int lengthA = a.length;
        int lengthB = b.length;

        if (lengthA > lengthB)
        {
            for (int i = 0; i < lengthB; i++)
            {
                sum += a[i] * b[i];
            }
        }
        else
        {
            for (int i = 0; i < lengthA; i++)
            {
                sum += a[i] * b[i];
            }
        }
        c = sum;
    }
    static{
        System.loadLibrary("ScalarLib");
    }

}
