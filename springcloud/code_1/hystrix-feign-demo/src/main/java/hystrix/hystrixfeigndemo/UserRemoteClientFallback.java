package hystrix.hystrixfeigndemo;


import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Component;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;
import org.springframework.web.client.RestTemplate;

@Component
@RestController
public class UserRemoteClientFallback implements UserRemoteClient {

	@Autowired
	private RestTemplate restTemplate;
	@Override
	public String hello() {
		return "fail";


	}
		@RequestMapping("/callHello")
		public String callHello(){
			String result = restTemplate.getForObject("http://localhost:8081/user/hello", String.class);
			return result;
}
}
