package springhystrix.hystrix;

import com.netflix.hystrix.HystrixCommand;
import com.netflix.hystrix.HystrixCommandGroupKey;
import com.netflix.hystrix.HystrixCommandProperties;
import com.netflix.hystrix.HystrixThreadPoolProperties;
import com.netflix.hystrix.strategy.concurrency.HystrixRequestContext;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.Future;

public class MyHystrixCommand extends HystrixCommand<String> {



	private final String name;

	public MyHystrixCommand(String name){
		/**
		 * 系统默认采用线程隔离策略
		 * 线程隔离策略配置  hystrix.threadpool.default.coreSize 固定线程池大小
		 */
//		super(HystrixCommand.Setter.withGroupKey(HystrixCommandGroupKey.Factory.asKey("MyGroup"))
//				.andCommandPropertiesDefaults(HystrixCommandProperties.Setter()
//						.withExecutionIsolationStrategy(HystrixCommandProperties.ExecutionIsolationStrategy.THREAD))
//				.andThreadPoolPropertiesDefaults(HystrixThreadPoolProperties.Setter().withCoreSize(10)
//						.withMaxQueueSize(100).withMaximumSize(100)));

/**
 * 信号量策略配置方法 隔离
 */
		super(HystrixCommand.Setter.withGroupKey(HystrixCommandGroupKey.Factory.asKey("MyGroup")));
//				.andCommandPropertiesDefaults(HystrixCommandProperties.Setter()
//						.withExecutionIsolationStrategy(HystrixCommandProperties.ExecutionIsolationStrategy.SEMAPHORE
//						)))

		this.name = name;

	}
	@Override
	protected String run() throws Exception {

//		try {
//			Thread.sleep(1000 * 10);
//		} catch (InterruptedException e) {
//			e.printStackTrace();
//		}

		//System.err.println("get data");
		return this.name + ":" + Thread.currentThread().getName();
	}

	//回退支持 服务降级

//	@Override
//	protected String getFallback() {
//		return "失败了 ";
//	}

//	@Override
//	protected String getCacheKey() {
//		return String.valueOf(this.name);
//	}

	public static void main(String[] args) throws InterruptedException, ExecutionException {


		//同步调用
//		String result = new MyHystrixCommand("zhangsan").execute();
//		System.out.println(result);
		//异步调用
//		Future<String> future = new MyHystrixCommand("zhangsan").queue();
//		System.out.println(future.get());

		/**
		 * 缓存问题
		 *
		 */


//		HystrixRequestContext context = HystrixRequestContext.initializeContext();
////		String result = new MyHystrixCommand("zhangsan").execute();
////		System.out.println(result);
////		Future<String> future = new MyHystrixCommand("zhangsan").queue();
////		System.out.println(future.get());
////		//关闭上下文
////		context.shutdown();


//		HystrixRequestContext context = HystrixRequestContext.initializeContext();
//		String result = new ClearCacheHystrixCommand("zhangsan").execute();
//		System.out.println(result);
//		ClearCacheHystrixCommand.flushCache("zhangsan");
//		Future<String> future = new ClearCacheHystrixCommand("zhangsan").queue();
//		System.out.println(future.get());
//		//关闭上下文
//		context.shutdown();

		HystrixRequestContext context = HystrixRequestContext.initializeContext();

		Future<String> f1 = new MyHystrixCollapser("zhangsan").queue();
		Future<String> f2 = new MyHystrixCollapser("zhangsan333").queue();

		System.out.println(f1.get()+"*******"+f2.get());
		context.shutdown();

	}
}
