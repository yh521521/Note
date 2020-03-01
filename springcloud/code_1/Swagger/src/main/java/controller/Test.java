//package controller;
//
//import io.swagger.annotations.ApiOperation;
//import io.swagger.annotations.ApiResponse;
//import io.swagger.annotations.ApiResponses;
//import org.springframework.web.bind.annotation.PostMapping;
//import org.springframework.web.bind.annotation.RequestBody;
//import org.springframework.web.bind.annotation.RestController;
//
//@RestController
//public class Test {
//	@ApiOperation(value = "新增用户")
//	@ApiResponses({ @ApiResponse(code = 200, message = "OK", response = UserDto.class) })
//	@PostMapping("/user")
//	public UserDto addUser(@RequestBody AddUserParam param) {
//		System.err.println(param.getName());
//		return new UserDto();
//	}
//}
