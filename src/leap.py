import os, sys, inspect, thread, time, serial
src_dir = os.path.dirname(inspect.getfile(inspect.currentframe()))
arch_dir = '../lib/x64'
sys.path.insert(0, os.path.abspath(os.path.join(src_dir, arch_dir)))

import Leap
from Leap import CircleGesture, KeyTapGesture, ScreenTapGesture, SwipeGesture

arduino = serial.Serial('/dev/ttyACM1', 9600)

class SampleListener(Leap.Listener):

	def on_init(self, controller):
		print "Initialized"

	def on_connect(self, controller):
		print "Connected"
		controller.enable_gesture(Leap.Gesture.TYPE_SCREEN_TAP)

	def handAnalysis(self, frame):
		hand = frame.hands[0]
		pitch = hand.direction.pitch
		yaw = hand.direction.yaw
		roll = hand.palm_normal.roll
		output = "Pitch: %f Yaw: %f Roll: %f" % (pitch, yaw, roll)

		packet = 0
		# Forward
		if pitch < -0.2:
			print "Forward",
			packet += 1
		elif pitch > 0.4:
			print "Backward",
			packet += 2
		else:
			print "Stationary",

		if roll < -0.4:
			packet = packet * 2
			print "and Right"
			packet += 4
		elif roll > 0.3:
			packet = packet * 2
			print "and Left"
			packet += 3
		else:
			print "and Straight"

		print "writing "+str(packet)+"to arduino"

		arduino.write(chr(packet))
		

	def on_frame(self, controller):
		frame = controller.frame()
        #print "Frame id: %d, timestamp: %d, hands: %d, fingers: %d, tools: %d, gestures: %d" % (
         # frame.id, frame.timestamp, len(frame.hands), len(frame.fingers), len(frame.tools), len(frame.gestures()))
        	self.handAnalysis(frame)


def main():
	listener = SampleListener()
	controller = Leap.Controller()
	controller.add_listener(listener)

	print "Press Enter to quit..."
	try:
		sys.stdin.readline()
	except KeyboardInterrupt:
		pass
	finally:
		controller.remove_listener(listener)

if __name__ == "__main__":
	main()
