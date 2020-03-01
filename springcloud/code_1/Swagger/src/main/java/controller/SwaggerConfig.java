package controller;

import io.swagger.annotations.ApiOperation;
import org.springframework.context.annotation.Bean;
import org.springframework.context.annotation.Configuration;
import springfox.documentation.builders.ApiInfoBuilder;
import springfox.documentation.builders.PathSelectors;
import springfox.documentation.builders.RequestHandlerSelectors;
import springfox.documentation.service.ApiInfo;
import springfox.documentation.spi.DocumentationType;
import springfox.documentation.spring.web.plugins.Docket;
import springfox.documentation.swagger2.annotations.EnableSwagger2;

@Configuration
@EnableSwagger2
public class SwaggerConfig {
	@Bean
	public Docket productApi(){
		return new Docket(DocumentationType.SWAGGER_2).
				apiInfo(apiInfo()).
				select().
				apis(RequestHandlerSelectors.withMethodAnnotation(ApiOperation.class)).//添加ApiOpentaion注解的被扫描
				paths(PathSelectors.any()).
				build();
	}
	private ApiInfo apiInfo(){
		return new ApiInfoBuilder().
				title("swagger和springboot整合").
				description("swagger的api文档").
				version("1.0").build();
	}
}
