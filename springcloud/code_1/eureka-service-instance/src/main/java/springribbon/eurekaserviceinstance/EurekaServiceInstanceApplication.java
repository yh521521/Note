package springribbon.eurekaserviceinstance;

import org.springframework.boot.SpringApplication;
import org.springframework.boot.autoconfigure.SpringBootApplication;
import org.springframework.cloud.client.discovery.EnableDiscoveryClient;

//当前服务是一个   服务提供者
@EnableDiscoveryClient
@SpringBootApplication
public class EurekaServiceInstanceApplication {

	public static void main(String[] args) {
		SpringApplication.run(EurekaServiceInstanceApplication.class, args);
	}

}
