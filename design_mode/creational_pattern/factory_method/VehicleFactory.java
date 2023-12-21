package design_mode.creational_pattern.factory_method;

public class VehicleFactory {

    public Vehicle create(int type) {
        Vehicle vehicle;
        switch (type) {
            case 1:
                vehicle = new Porsche();
                break;
            case 2:
                vehicle = new Volkswagen();
                break;
            default:
                vehicle = null;
                break;
        }
        return vehicle;
    }

    public static void main(String[] args) {
        VehicleFactory factory = new VehicleFactory();
        Vehicle vehicle1 = factory.create(1);
        Vehicle vehicle2 = factory.create(2);
        System.out.println(vehicle1.brand());
        System.out.println(vehicle2.brand());
    }

}
