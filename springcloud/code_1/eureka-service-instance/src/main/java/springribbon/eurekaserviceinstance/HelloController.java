package springribbon.eurekaserviceinstance;

import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class HelloController {
	@RequestMapping("/user/hello")
	public String hello() {
		return "hello  eureka service2";
	}
}
