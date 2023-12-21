package design_mode.creational_pattern.singleton;

public class LazyInitializedSingleton {

    private static LazyInitializedSingleton INSTANCE;

    private LazyInitializedSingleton() {
    }

    public static LazyInitializedSingleton getInstance() {
        if (INSTANCE == null) {
            INSTANCE = new LazyInitializedSingleton();
        }
        return INSTANCE;
    }
}
