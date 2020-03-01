package cloudribbon.ribbon;

import feign.Logger;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;



@Configuration
public class FeignConfiguration {

	/**
	 * 日志级别
	 */


	@Bean
	Logger.Level feignLoggerLevel(){
		return Logger.Level.FULL;
	}

}
