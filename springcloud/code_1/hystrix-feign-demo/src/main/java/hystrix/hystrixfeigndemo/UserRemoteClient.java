package hystrix.hystrixfeigndemo;


import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@FeignClient(value = "eureka-client-user-service")
@RestController
@RequestMapping("/test")
public interface UserRemoteClient {

	@RequestMapping("/user/hello")
	String  hello();

}
