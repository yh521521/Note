package springhystrix.hystrix;

import com.netflix.hystrix.HystrixCommand;
import com.netflix.hystrix.HystrixCommandGroupKey;
import com.netflix.hystrix.strategy.concurrency.HystrixRequestContext;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

public class Main extends HystrixCommand {
	private final String name;
	public Main(String name) {
		super(HystrixCommandGroupKey.Factory.asKey("MyGroup"));
		this.name = name;
	}
	@Override
	protected String run() {
		return this.name + ":" + Thread.currentThread().getName();
	}

	public static void main(String[] args) throws InterruptedException, ExecutionException {
		HystrixRequestContext context = HystrixRequestContext.initializeContext();

		Future<String> f1 = new MyHystrixCollapser("zhangsan").queue();
		Future<String> f2 = new MyHystrixCollapser("zhangsan333").queue();

		System.out.println(f1.get()+"*******"+f2.get());
		context.shutdown();
	}
}
