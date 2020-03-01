package cloudribbon.ribbon;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
public class controller {

	@Autowired
	private UserRemoteClient userRemoteClient;

	@RequestMapping("/callHello")
	public String callHello() {
		//return restTemplate.getForObject("http://localhost:8083/house/hello",String.class);
		//String result = restTemplate.getForObject("http://eureka-client-user-service/user/hello",String.class);
		String result = userRemoteClient.hello();
		System.out.println("调用结果：" + result);
		return result;
	}
}
