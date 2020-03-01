package springeureka.eurekaserver;


import org.springframework.context.annotation.Configuration;
import org.springframework.security.config.annotation.web.builders.HttpSecurity;
import org.springframework.security.config.annotation.web.configuration.EnableWebSecurity;
import org.springframework.security.config.annotation.web.configuration.WebSecurityConfigurerAdapter;

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
