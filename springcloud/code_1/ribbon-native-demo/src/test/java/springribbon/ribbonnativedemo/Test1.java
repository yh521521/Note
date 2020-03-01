package springribbon.ribbonnativedemo;//package springribbon.eurekaserviceinstance;

import com.netflix.loadbalancer.ILoadBalancer;
import com.netflix.loadbalancer.LoadBalancerBuilder;
import com.netflix.loadbalancer.Server;
import com.netflix.loadbalancer.reactive.LoadBalancerCommand;
import com.netflix.loadbalancer.reactive.ServerOperation;
import org.assertj.core.util.Lists;


import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import rx.Observable;

import java.io.InputStream;
import java.net.HttpURLConnection;
import java.net.URL;
import java.util.List;

@SpringBootTest
class Test1 {

	@Test
	void contextLoads() {


		// 服务列表
		List<Server> serverList = Lists.newArrayList(new Server("localhost", 8081), new Server("localhost", 8084));
		// 构建负载实例
		ILoadBalancer loadBalancer = LoadBalancerBuilder.newBuilder().buildFixedServerListLoadBalancer(serverList);
// 调用 5 次来测试效果
		for(int i = 0; i <5; i++) {
			String result = LoadBalancerCommand.<String>builder().withLoadBalancer(loadBalancer).build()
					.submit(new ServerOperation<String>() {
						public Observable<String> call(Server server) {
							try {
								String addr = "http://" + server.getHost() + ":" + server.getPort() + "/user/hello";
								System.out.println(" 调用地址：" + addr);
								URL url = new URL(addr);
								HttpURLConnection conn = (HttpURLConnection) url.openConnection();
								conn.setRequestMethod("GET");
								conn.connect();
								InputStream in = conn.getInputStream();
								byte[] data = new byte[in.available()];
								in.read(data);
								return Observable.just(new String(data));
							} catch (Exception e) {
								return Observable.error(e);
							}
						}
					}).toBlocking().first();
			System.out.println(" 调用结果：" + result);
		}
	}
	}


