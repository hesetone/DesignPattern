public abstract class Flyweight {
    public void operation(int exrinsicstate){
        System.out.println(this.getClass().toString() + " : " + exrinsicstate);
    }
}
