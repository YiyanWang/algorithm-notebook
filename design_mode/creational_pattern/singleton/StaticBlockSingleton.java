package design_mode.creational_pattern.singleton;

public class StaticBlockSingleton {

    private static StaticBlockSingleton INSTANCE;

    private StaticBlockSingleton() {
    }

    // static block initialization for exception handling
    static {
        try {
            INSTANCE = new StaticBlockSingleton();
        } catch (Exception e) {
            throw new RuntimeException("Exception occurred in creating singleton instance");
        }
    }

    public static StaticBlockSingleton getInstance() {
        return INSTANCE;
    }

}