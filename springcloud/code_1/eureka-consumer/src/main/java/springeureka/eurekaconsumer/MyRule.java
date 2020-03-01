package springeureka.eurekaconsumer;

import com.netflix.loadbalancer.ILoadBalancer;
import com.netflix.loadbalancer.IRule;
import com.netflix.loadbalancer.Server;
import org.springframework.beans.factory.annotation.Autowired;

import java.util.List;

/**
 * 自定义负载策略
 */
public class MyRule implements IRule {


	@Autowired
	private ILoadBalancer lb;
	@Override
	public Server choose(Object key) {
		List<Server> servers = lb.getAllServers();

		for (Server server : servers) {
			System.out.println(server.getHostPort());
		}
		return servers.get(0);
	}

	@Override
	public void setLoadBalancer(ILoadBalancer lb) {

		this.lb = lb;
	}

	@Override
	public ILoadBalancer getLoadBalancer() {
		return lb;
	}
}
