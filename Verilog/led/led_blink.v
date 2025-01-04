module led_blink(
	input wire clk,
	output reg led
);

reg [31:0] counter; // 32 bit counter register

// how many clock cycles to flip led?
parameter DIVISOR=100000;
// whenever clk is 1 this will execute
always @(posedge clk) begin
	// <= is a non blocking assignment
	counter <= counter + 1;
	if(counter >= DIVISOR) begin
		counter <= 0;
		led <= ~led;
	end
end

endmodule
