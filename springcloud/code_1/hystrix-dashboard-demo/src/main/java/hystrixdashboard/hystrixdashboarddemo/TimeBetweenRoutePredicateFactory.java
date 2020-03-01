package hystrixdashboard.hystrixdashboarddemo;

import org.springframework.cloud.gateway.handler.predicate.AbstractRoutePredicateFactory;
import org.springframework.web.server.ServerWebExchange;

import java.time.LocalTime;
import java.util.function.Predicate;

public class TimeBetweenRoutePredicateFactory  extends AbstractRoutePredicateFactory<TimeBetweenConfig> {

	public TimeBetweenRoutePredicateFactory(){
		super(TimeBetweenConfig.class);
	}

	/**
	 * 实现谓语动词的方法
	 * @param config
	 * @return
	 */
	@Override
	public Predicate<ServerWebExchange> apply(TimeBetweenConfig config) {
		LocalTime start = config.getStart();
		LocalTime end = config.getEnd();
		return serverWebExchange -> {
			LocalTime now = LocalTime.now();

			return now.isAfter(start)&& now.isBefore(end);
		};


	}
}
