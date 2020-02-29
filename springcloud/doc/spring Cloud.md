

# spring Cloud

## 2020/2/23

### 微服务是什莫,他的优点是什莫

> 微服务”一词来源于 Martin Fowler 的《Microservices》一文。微服务是一种架构风格，即将单体应用划分为小型的服务单元，微服务之间使用 HTTP 的 API 进行资源访问与操作。

### 微服务架构的优势

#### 1）服务的独立部署

每个服务都是一个独立的项目，可以独立部署，不依赖于其他服务，耦合性低。

#### 2）服务的快速启动

拆分之后服务启动的速度必然要比拆分之前快很多，因为依赖的库少了，代码量也少了。

#### 3）更加适合敏捷开发

敏捷开发以用户的需求进化为核心，采用迭代、循序渐进的方法进行。服务拆分可以快速发布新版本，修改哪个服务只需要发布对应的服务即可，不用整体重新发布。

#### 4）职责专一，由专门的团队负责专门的服务

业务发展迅速时，研发人员也会越来越多，每个团队可以负责对应的业务线，服务的拆分有利于团队之间的分工。

#### 5）服务可以动态按需扩容

当某个服务的访问量较大时，我们只需要将这个服务扩容即可。

#### 6）代码的复用

每个服务都提供 REST API，所有的基础服务都必须抽出来，很多的底层实现都可以以接口方式提供。

### 微服务架构的劣势

#### 1）分布式部署，调用的复杂性高

单体应用的时候，所有模块之前的调用都是在本地进行的，在微服务中，每个模块都是独立部署的，通过 HTTP 来进行通信，这当中会产生很多问题，比如网络问题、容错问题、调用关系等。

#### 2）独立的数据库，分布式事务的挑战

每个微服务都有自己的数据库，这就是所谓的去中心化的数据管理。这种模式的优点在于不同的服务，可以选择适合自身业务的数据，比如订单服务可以用 

MySQL

、评论服务可以用 Mongodb、商品搜索服务可以用 Elasticsearch。

缺点就是事务的问题了，目前最理想的解决方案就是柔性事务中的最终一致性，后面的章节会给大家做具体介绍。

#### 3）测试的难度提升

服务和服务之间通过接口来交互，当接口有改变的时候，对所有的调用方都是有影响的，这时自动化测试就显得非常重要了，如果要靠人工一个个接口去测试，那工作量就太大了。这里要强调一点，就是 API 文档的管理尤为重要。

#### 4）运维难度的提升

在采用传统的单体应用时，我们可能只需要关注一个 Tomcat 的集群、一个 MySQL 的集群就可以了，但这在微服务架构下是行不通的。当业务增加时，服务也将越来越多，服务的部署、监控将变得非常复杂，这个时候对于运维的要求就高了。

### spring cloud 是什莫 

Spring Cloud 是一系列框架的有序集合。它利用 Spring Boot 的开发便利性，巧妙地简化了分布式系统基础设施的开发，如服务注册、服务发现、配置中心、消息总线、负载均衡、断路器、数据监控等，这些都可以用 Spring Boot 的开发风格做到一键启动和部署。

通俗地讲，Spring Cloud 就是用于构建微服务开发和治理的框架集合（并不是具体的一个框架），主要贡献来自 Netflix OSS。

### 模块介绍

- Eureka：服务注册中心，用于服务管理。

- Ribbon：基于客户端的负载均衡组件。

- Hystrix：容错框架，能够防止服务的雪崩效应。

- Feign：Web 服务客户端，能够简化 HTTP 接口的调用。

- Zuul：API 网关，提供路由转发、请求过滤等功能。

- Config：分布式配置管理。

- Sleuth：服务跟踪。

- Stream：构建消息驱动的微服务应用程序的框架。

- Bus：消息代理的集群消息总线。

  此外还有Cli  Task

  # ## spring boot 开发优点

  - 基于 Spring 开发 Web 应用更加容易。
  - 采用基于注解方式的配置，避免了编写大量重复的 XML 配置。
  - 可以轻松集成 Spring 家族的其他框架，比如 Spring JDBC、Spring Data 等。
  - 提供嵌入式服务器，令开发和部署都变得非常方便。
  - ​

总结下来就是@PostMapping和@GetMapping都可以用@RequestMapping代替，如果读者怕在映射的时候出错，可以统一写@RequestMapping，当然这样写的话也有弊端，笼统的全用@RequestMapping, 写好路径过滤



spring-boot-devtools 的依赖即可实现热部署功能



自定义的actuator

```
引入依赖  直接启动 springboot  访问http://localhost:81/actuator/health
看到 健康信息
<!--监控-->
   <dependency>
      <groupId>org.springframework.boot</groupId>
      <artifactId>spring-boot-starter-actuator</artifactId>
   </dependency>
```

```
 UserHealthIndicator extends AbstractHealthIndicator
 //up 方法指定应用的状态为健康，down 方法指定应用的状态为不健康
		builder.up().withDetail("status",true);
		builder.down().withDetail("status", false);
```

```
{"status":"UP",
"components":{"diskSpace":{"status":"UP","details":{"total":321912827904,"free":103868465152,"threshold":10485760}},"ping":{"status":"UP"},"user":{"status":"UP","details":{"status":true}}}}
```

```
{"status":"DOWN","components":{"diskSpace":{"status":"UP","details":{"total":321912827904,"free":103868465152,"threshold":10485760}},"ping":{"status":"UP"},"user":{"status":"DOWN","details":{"status":false}}}}
```

访问 /actuator/user 可以看到返回的用户信息如下：

```
[{"userName":"yh521","userId":"521"}]
```

@ ControllerAdvice 注解  异常进行统一处理

为了方便对异常的统一管理，spring mvc提供了ControllerAdvice注解对异常进行统一的处理，拿到这些异常信息后，可以做一些处理，比如提供一个统一的web界面查看异常信息，或者普通到异常信息后，发送短信、邮件形式通知到相关人员，可以帮助开发人员快速发现并定位问题，减少以往通过查看线上日志文件排查问繁琐锁耗时的所耗费的时间。下面我跟大家介绍具体步骤。

可以省去set  get  方法  加上  @Data  注解

```
<dependency>
   <groupId>org.projectlombok</groupId>
   <artifactId>lombok</artifactId>
</dependency>
```

## Spring Cloud Eureka是什么？

Spring Cloud Eureka 是一个基于 REST 的服务，并且提供了基于 的客户端组件，能够非常方便地将服务注册到 Spring Cloud Eureka 中进行统一管理。

服务治理是微服务架构中必不可少的一部分，阿里开源的 Dubbo 框架就是针对服务治理的。服务治理必须要有一个注册中心，除了用 Eureka 作为注册中心外，我们还可以使用 Consul、Etcd、Zookeeper 等来作为服务的注册中心。

为什么 Eureka 比 Zookeeper 更适合作为注册中心呢？主要是因为 Eureka 是基于 AP 原则构建的，而 ZooKeeper 是基于 CP 原则构建的。

在分布式系统领域有个著名的 CAP 定理，即 C 为数据一致性；A 为服务可用性；P 为服务对网络分区故障的容错性。这三个特性在任何分布式系统中都不能同时满足，最多同时满足两个。

注册中心配置

```
spring.application.name=eureka-server
server.port=8761
# 由于该应用为注册中心, 所以设置为false, 代表不向注册中心注册自己
eureka.client.register-with-eureka=false
# 由于注册中心的职责就是维护服务实例, 它并不需要去检索服务, 所以也设置为 false
eureka.client.fetch-registry=false
```

启动报错的话很可能是cloud  版本 跟你引入的依赖不匹配 

服务提供者的一段配置   8761/eureka/  注入到eureka注册中心上去

```
#Eureka 服务的地址，在启动的时候需要将自身的信息注册到 Eureka 中去。
eureka.client.serviceUrl.defaultZone=http://localhost:8761/eureka/

```

服务提供者编写完成后  正常启动会打印出 

DiscoveryClient_EUREKA-CLIENT-USER-SERVICE/eureka-client-user-service:192.168.43.86:8081 - registration status: 204

，添加一个 @LoadBalanced 注解，这个注解会自动构造 LoadBalancerClient 接口的实现类并注册到 Spring 容器中]



交给spring 来创建实例

1. @Configuration

2. public class BeanConfiguration {

3. ​    @Bean

4. ​    public RestTemplate getRestTemplate() {

5. ​        return new RestTemplate();

6. ​    }

7. }

   > > > > > 注入Rest   


1. @RestController

2. public class ArticleController {

3. ​    @Autowired

4. ​    private RestTemplate restTemplate;

5. ​

6. ​    @GetMapping("/article /callHello")

7. ​    public String callHello() {

8. ​        return restTemplate.getForObject("http://localhost:8081/user/hello" , String.class);

9. ​    }

10. }

11. ​    或者 不用注入  直接加上 @LoadBalanced  会自动构造 LoadBalancerClient 接口的实现类并注册到 Spring 容器中，代码如下所示。

12. ​

    > > > > 1. @Configuration
    > > > > 2. public class BeanConfiguration {
    > > > > 3. ​    @Bean
    > > > > 4. ​    @LoadBalanced
    > > > > 5. ​    public RestTemplate getRestTemplate() {
    > > > > 6. ​        return new RestTemplate();
    > > > > 7. ​    }
    > > > > 8. }
    > >
    > >   此处较 上次 代码简化了
    > >
    > > 1. @GetMapping("/article/callHello2")
    > > 2. public String callHello2() {
    > > 3. ​    return restTemplate.getForObject("http://eureka-client-user-service/user/hello", String.class);
    > > 4. }



Eureka 自带了一个 Web 的管理页面，方便我们查询注册到上面的实例信息，但是有一个问题：如果在实际使用中，注册中心地址有公网 IP 的话，必然能直接访问到，这样是不安全的。所以我们需要对 Eureka 进行改造，加上权限认证来保证安全性。

改造我们的 eureka-server，通过集成 Spring-Security 来进行安全认证。

##### server端

![](../../img/springCloud/eureka-server.png)

 

###### client 端



![](../../img/springCloud/eureka-service.png)

###### 调用这个服务

![](../../img/springCloud/eureka-consumer.png)

#### CSRF跨域攻击 

CSRF（Cross-site request forgery），中文名称：跨站请求伪造，也被称为：one click attack/session riding，缩写为：CSRF/XSRF。



cloud  默认的安全保护

![](../../img/springcloud/eureka-preservation.png)



关闭eureka 自我保护机制   配置如下  eureka.server.enable-self-preservation=false



#### **THE SELF PRESERVATION MODE IS TURNED OFF.THIS MAY NOT PROTECT INSTANCE EXPIRY IN CASE OF NETWORK/OTHER PROBLEMS.**   //已关闭自我保护模式。这可能无法在出现网络/其他问题时保护实例过期。



***************************************************************************************************************************************************************************************************

2020/2/25 解决的问题

eureka 加上  security 后 服务注册有问题 启动就报错 没有注册的实例

server 端  

```
# 开启安全验证
#用户名
spring.security.user.name=yh
#密码
spring.security.user.password=521521
```

service  端 ,consumer  端

```
#Eureka 服务的地址，在启动的时候需要将自身的信息注册到 Eureka 中去。
# 加上security 后 注册地址也需要可以改一下
eureka.client.serviceUrl.defaultZone=http://yh:521521@localhost:8761/eureka
#eureka.client.serviceUrl.defaultZone=http://localhost:8761/eureka
```

自定义配置

```
/**
 * 安全认证配置类  security
 */
@Configuration
@EnableWebSecurity
public class WebSecurityConfig extends WebSecurityConfigurerAdapter {
   @Override
   protected void configure(HttpSecurity http) throws Exception {
      //http.sessionManagement().sessionCreationPolicy(SessionCreationPolicy.NEVER);
      // 关闭csrf
      http.csrf().disable();
      // 支持httpBasic
      http.authorizeRequests().anyRequest().authenticated().and().httpBasic();
   }
}
```

***************************************************************************************************************************************************************************************************



### 自定义 Eureka 的 InstanceID

服务名称：服务所在 IP：服务端口”的格式来定义：

eureka.instance.instance-id=${spring.application.name}:${spring.cloud.client.ip-address}:${server.port}

### eureka 快速移除失效服务  

在实际开发过程中，我们可能会不停地重启服务，由于 Eureka 有自己的保护机制，故节点下线后，服务信息还会一直存在于 Eureka 中。我们可以通过增加一些配置让移除的速度更快一点，当然只在开发环境下使用，生产环境下不推荐使用。



spring  观察者模式  

   spring cloud  用到的@EventListener  注解 事件监听

Spring Cloud Eureka 是 Spring Cloud Netflix 微服务套件的一部分，基于 Netflix Eureka 做了二次封装，主要负责实现微服务架构中的服务治理功能。



###  eureka 整合ribbon



![](../../img/springcloud/eureka-ribbon-1.png)



![](../../img/springcloud/eureka-ribbon-2.png)



@bean  注解 配合普通rest 风格访问   单纯的eureka  

@loadBalanced 配合eureka 整合ribbon 

注入loadBalancedClient  直接掉ribbon的 api  rest  风格访问如下  

```
{"serviceId":"eureka-client-user-service","server":{"host":"192.168.43.86","port":8081,"scheme":null,"id":"192.168.43.86:8081","zone":"defaultZone","readyToServe":true,"instanceInfo":{"instanceId":"eureka-client-user-service:192.168.43.86:8081","app":"EUREKA-CLIENT-USER-SERVICE","appGroupName":null,"ipAddr":"192.168.43.86","sid":"na","homePageUrl":"http://192.168.43.86:8081/","statusPageUrl":"http://192.168.43.86:8081/actuator/info","healthCheckUrl":"http://192.168.43.86:8081/actuator/health","secureHealthCheckUrl":null,"vipAddress":"eureka-client-user-service","secureVipAddress":"eureka-client-user-service","countryId":1,"dataCenterInfo":{"@class":"com.netflix.appinfo.InstanceInfo$DefaultDataCenterInfo","name":"MyOwn"},"hostName":"192.168.43.86","status":"UP","overriddenStatus":"UNKNOWN","leaseInfo":{"renewalIntervalInSecs":30,"durationInSecs":90,"registrationTimestamp":1582683393590,"lastRenewalTimestamp":1582684323694,"evictionTimestamp":0,"serviceUpTimestamp":1582683393591},"isCoordinatingDiscoveryServer":false,"metadata":{"management.port":"8081","jmx.port":"50882"},"lastUpdatedTimestamp":1582683393592,"lastDirtyTimestamp":1582683393389,"actionType":"ADDED","asgName":null},"metaInfo":{"instanceId":"eureka-client-user-service:192.168.43.86:8081","appName":"EUREKA-CLIENT-USER-SERVICE","serverGroup":null,"serviceIdForDiscovery":"eureka-client-user-service"},"alive":true,"hostPort":"192.168.43.86:8081"},"secure":false,"metadata":{"management.port":"8081","jmx.port":"50882"},"scheme":null,"host":"192.168.43.86","port":8081,"uri":"http://192.168.43.86:8081"}
```



ctrl +n快速查找    alt + enter  快速补全代码   ctrl + H 查看某个接口的树形结构

for循环  快捷键 fori    foreach 快捷键   iter 



@EnableDiscoveryClient和@EnableEurekaClient共同点就是：都是能够让注册中心能够发现，扫描到改服务。

不同点：@EnableEurekaClient只适用于Eureka作为注册中心，@EnableDiscoveryClient 可以是其他注册中心。

### cloud集成feign 



Feign是一个声明式web 服务调用服务，他使得一切web服务得以简化

pom 加上  

```
eureka客户端
<dependency>
   <groupId>org.springframework.cloud</groupId>
   <artifactId>spring-cloud-starter-netflix-eureka-client</artifactId>
</dependency>
```

```
feign  客户端 
<dependency>
   <groupId>org.springframework.cloud</groupId>
   <artifactId>spring-cloud-starter-openfeign</artifactId>
</dependency>
```

```
8082 端口上的一个服务

RestController
public class HelloController {
   @RequestMapping ("/user/hello")
   public String hello() {
      return "hello  eureka";
   }
}
```

```
8085端口定义一个feign  客户端

@FeignClient(value = "eureka-client-user-service")
@RestController
public interface UserRemoteClient {
   @GetMapping("/user/hello")
   String hello();
}


#####  feign会对value与GetMapping提供的地址进行拼接，远程调用方法。 必须一致
返回值类型 要一致  方法名可以不一样  但是建议一样  清晰明了 



controller 端   

@RestController
public class controller {

	@Autowired
	private UserRemoteClient userRemoteClient;

	@RequestMapping("/callHello")
	public String callHello() {
		//return restTemplate.getForObject("http://localhost:8083/house/hello",String.class);
		//String result = restTemplate.getForObject("http://eureka-client-user-service/user/hello",String.class);
		
		*****   通过一个feign 客户端调用 hello  这个服务  
		String result = userRemoteClient.hello();
		System.out.println("调用结果：" + result);
		return result;
	}
}
```





![](../../img/springcloud/cloud-feign.png) 

注释掉的代码相比可以发现，我们的调用方式变得越来越简单了，从最开始的指定地址，到后面通过 Eureka 中的服务名称来调用，再到现在直接通过定义接口来调用。

#### 什莫是服务降级

> > > 服务降级，当服务器压力剧增的情况下，根据当前业务情况及流量对一些服务和页面有策略的降级， 以此释放服务器资源以保证核心任务的正常运行。

使用feign组件完成降级操作，到内容提供者无法提供服务时， 消费者会调用降级操作，返回服务不可用等信息，或者返回提前准备好的静态页面。

###    解决问题 : 设置 feign  日志级别

properties 配置文件 

```
#feign 日志级别设置  logging.level (你的feign client全路径类名)
logging.level.cloudribbon.ribbon.UserRemoteClient= debug
```

```
@Configuration
public class FeignConfiguration {

   /**
    * 日志级别
    */


   @Bean
   Logger.Level feignLoggerLevel(){
      return Logger.Level.FULL;
   }

}
```



```
@FeignClient(value = "eureka-client-user-service",configuration = FeignConfiguration.class)


效果图 如下
```

![](../../img/springcloud/feign-log.png)

## Spring Cloud Hystrix（熔断器）介绍及使用

Hystrix 是 Netflix 针对微服务分布式系统采用的熔断保护中间件，相当于电路中的保险丝。

在微服务架构下，很多服务都相互依赖，如果不能对依赖的服务进行隔离，那么服务本身也有可能发生故障，Hystrix 通过 HystrixCommand 对调用进行隔离，这样可以阻止故障的连锁效应，能够让接口调用快速失败并迅速恢复正常，或者回退并优雅降级。





单个 监控

![](../../img/springcloud/hystrix-dashboard.png)

数据化展示

![](../../img/springcloud/monitor.png)

#### Turbine  涡轮机 

单个实例的监控数据没有多大的价值，我们更需要的是一个集群系统的监控信息，这时我们就需要 Turbine。

Turbine 是用来监控集群的，通过它来汇集监控信息，并将聚合后的信息提供给 Hystrix Dashboard 来集中展示和监控。

### ZUUl

Zuul 是 Netflix OSS 中的一员，是一个基于 JVM 路由和服务端的负载均衡器。提供路由、监控、弹性、安全等方面的服务框架。Zuul 能够与 Eureka、Ribbon、Hystrix 等组件配合使用。

Zuul 的核心是过滤器，通过这些过滤器我们可以扩展出很多功能，比如：

#### 1）动态路由

动态地将客户端的请求路由到后端不同的服务，做一些逻辑处理，比如聚合多个服务的数据返回。

#### 2）请求监控

可以对整个系统的请求进行监控，记录详细的请求响应日志，可以实时统计出当前系统的访问量以及监控状态。

#### 3）认证鉴权

对每一个访问的请求做认证，拒绝非法请求，保护好后端的服务。

#### 4）压力测试

压力测试是一项很重要的工作，像一些电商公司需要模拟更多真实的用户并发量来保证重大活动时系统的稳定。通过 Zuul 可以动态地将请求转发到后端服务的集群中，还可以识别测试流量和真实流量，从而做一些特殊处理。

#### 5）灰度发布

灰度发布可以保证整体系统的稳定，在初始灰度的时候就可以发现、调整问题，以保证其影响度。



### zuul  因为网速不行 插件没法下载先搁置一下 

### Gateway

Spring Cloud Gateway 作为 Spring Cloud 生态系中的网关，其目标是替代 Netflix Zuul，它不仅提供统一的路由方式，并且基于 Filter 链的方式提供了网关基本的功能，例如：安全、监控/埋点和限流等。



  ####  方法总是比办法多

在spring.cloud.gateway.routes中,我们可以根据不同的谓语配置不同的路由,根据配置的先后顺序来跳转,越在前面优先级越高.

其中id,区分不同的路由规则,不可重复,uri,指需要跳转的地址,Predicates就是上面说的谓语了,可以配置多个,使用正则匹配. 

```
server:
  port: 2001
spring:
  cloud:
    gateway:
      routes:
        - id: path_route  路由规则
          uri: http://c.biancheng.net  指需要跳转的地址
          predicates:
            - Path=/spring_cloud # 请求地址携带spring_cloud的,则转发
当你访问 http://localhost:2001/spring_cloud 的时候就会转发到 http://c.biancheng.net/spring_cloud。
```

 Spring Cloud Gateway 内置了许多路由断言工厂，可以通过配置的方式直接使用，也可以组合使用多个路由断言工厂。接下来为大家介绍几个常用的路由断言工厂类。



lb 代表从注册中心获取服务

###### ServerWebExchange



ServerWebExchange是一个HTTP请求-响应交互的契约。提供对HTTP请求和响应的访问，并公开额外的 服务器端处理相关属性和特性，如请求属性。

Spring Cloud Gateway 不使用 Web 作为服务器，而是 **使用 WebFlux 作为服务器**，Gateway 项目已经依赖了 `starter-webflux`，所以这里 **千万不要依赖 starter-web**

由于过滤器等功能依然需要 Servlet 支持，故这里还需要依赖 `javax.servlet:javax.servlet-api`



### Apollo（阿波罗）

Apollo（阿波罗）是携程框架部门研发的分布式配置中心，能够集中化管理应用不同环境、不同集群的配置，配置修改后能够实时推送到应用端，并且具备规范的权限、流程治理等特性，适用于微服务配置管理场景