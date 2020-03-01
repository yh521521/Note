package springhystrix.hystrix;

import com.netflix.hystrix.HystrixCommand;
import com.netflix.hystrix.HystrixCommandGroupKey;
import com.netflix.hystrix.HystrixCommandKey;
import com.netflix.hystrix.HystrixRequestCache;
import com.netflix.hystrix.strategy.concurrency.HystrixConcurrencyStrategyDefault;

/**
 * 清除缓存
 */
public class ClearCacheHystrixCommand extends HystrixCommand<String> {

	private final String name;
	private static final HystrixCommandKey GETTER_KEY =
			HystrixCommandKey.Factory.asKey("MyKey");

	public ClearCacheHystrixCommand(String name) {
		super(HystrixCommand.Setter.withGroupKey(HystrixCommandGroupKey.Factory.asKey("MyGroup")).andCommandKey(GETTER_KEY));
		this.name = name;
	}

	/**
	 * 清除缓存
	 * @param name
	 */
	public static void flushCache(String name){
		//HystrixRequestCache 来执行清除缓存操作
		HystrixRequestCache.getInstance
				(GETTER_KEY, HystrixConcurrencyStrategyDefault.getInstance())
				.clear(name);
	}
	@Override
	protected  String getCacheKey(){
		return String.valueOf(this.name);
	}
	@Override
	protected String run() throws Exception {
		System.err.println("get data");
		return this.name+":"+Thread.currentThread().getName();
	}

	@Override
	protected String  getFallback(){
		return "失败了";
	}
}
