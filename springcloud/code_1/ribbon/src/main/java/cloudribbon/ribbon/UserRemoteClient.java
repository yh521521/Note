package cloudribbon.ribbon;

import org.springframework.cloud.openfeign.FeignClient;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;

@FeignClient(value = "eureka-client-user-service",configuration = FeignConfiguration.class)
@RestController
public interface UserRemoteClient {
	@GetMapping("/user/hello")
	String  hello();
}

