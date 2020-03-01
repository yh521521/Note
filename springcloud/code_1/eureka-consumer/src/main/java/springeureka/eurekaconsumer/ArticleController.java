package springeureka.eurekaconsumer;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cloud.client.ServiceInstance;
import org.springframework.cloud.client.loadbalancer.LoadBalancerClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@RestController
public class ArticleController {
	@Autowired
	private RestTemplate restTemplate;
	@Autowired
	private LoadBalancerClient loadBalancer;

	//普通的rest风格访问
	@RequestMapping ("/article/callHello")
	public String callHello() {
		return restTemplate.getForObject("http://localhost:8081/user/hello", String.class);
	}
	//eureka  整合ribbon
	@GetMapping("/article/callHello2")
	public String callHello2() {
		return restTemplate.getForObject("http://eureka-client-user-service/user/hello", String.class);
	}
	//ribbon API 使用
	@RequestMapping ("/choose")//spring.application.name=eureka-client-article-service
	public Object  chooseUrl() {
		ServiceInstance instance = loadBalancer.choose("eureka-client-user-service");
		return instance;
	}

	@RequestMapping("/test")
	public String   findById() {
		ServiceInstance serviceInstance = this.loadBalancer.choose("eureka-client-user-service");
		System.out.println("===" + ":" + serviceInstance.getServiceId() + ":" + serviceInstance.getHost() + ":"
				+ serviceInstance.getPort());// 打印当前调用服务的信息

		return  restTemplate.getForObject("http://localhost:8081/user/hello", String.class);
	}
}
