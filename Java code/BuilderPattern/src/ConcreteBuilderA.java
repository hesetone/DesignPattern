public class ConcreteBuilderA extends Builder{
    private Product product = new Product();

    @Override
    public void buildPartA(){
        product.add("ConcreteBuilderA add buildPart A");
    }

    @Override
    public void buildPartB() {
        product.add("ConcreteBuilderA add bulidPart B");
    }

    @Override
    public Product getResult(){
        return product;
    }
}
