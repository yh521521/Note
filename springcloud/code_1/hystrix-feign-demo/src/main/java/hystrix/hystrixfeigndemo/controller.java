//package hystrix.hystrixfeigndemo;
//
//import com.netflix.hystrix.contrib.javanica.annotation.HystrixCommand;
//import com.netflix.hystrix.contrib.javanica.annotation.HystrixProperty;
//import org.springframework.beans.factory.annotation.Autowired;
//import org.springframework.web.bind.annotation.RequestMapping;
//import org.springframework.web.bind.annotation.RestController;
//import org.springframework.web.client.RestTemplate;
//
//@RestController
//public class controller {
//
//	@Autowired
//	private RestTemplate restTemplate;
//
//	@RequestMapping("/callHello")
//	@HystrixCommand(fallbackMethod = "defaultCallHello",
//			commandProperties  = {@HystrixProperty(name = "execution.isolation.strategy",value = "THREAD")})
//
//	public String callHello(){
//		String result = restTemplate.getForObject("http://localhost:8081/user/hello", String.class);
//		return result;
//	}
//	public String defaultCallHello() {
//		return "fail";
//	}
//
//
//}
