public class ConcreteBuilderB extends Builder{
    private Product product = new Product();

    @Override
    public void buildPartA(){
        product.add("ConcreteBuilderB add buildPart A");
    }

    @Override
    public void buildPartB() {
        product.add("ConcreteBuilderB add bulidPart B");
    }

    @Override
    public Product getResult(){
        return product;
    }
}
