import java.util.HashSet;

public class NanSet {
    public static void main(String[] args) {
        double x = Double.NaN;
        double y = x + 1;
        var s = new HashSet<Double>();

        s.add(x);
        s.add(x);
        s.add(y);

        System.out.println("size           : " + s.size());
        System.out.println("has x          : " + s.contains(x));
        System.out.println("has stored y   : " + s.contains(y));
        System.out.println("has fresh x + 1: " + s.contains(x + 1));
    }
}
