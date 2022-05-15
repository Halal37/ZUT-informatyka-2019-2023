import math
import unittest
#zad2
class do_testow(unittest.TestCase):
 def funkcja_log10():
     self.assertEqual(math.log10,)
     self.assertRaises(math.log10)
 def funkcja_sqrt():
     self.assertFreaterEqual(math.sqrt(2),2**(1/2))
     self.asserEqual(math.sqrt(2),2**(1/2))
     self.assertRaises(math.sqrt(2),2**(1/2))
 def funkcja_isfinite():
     self.assertTrue(math.isfinite)
     self.assertFalse(math.isfinite)
 def funkcja_pi():
       self.assertGreater(math.pi,3.14)
       self.assertAlmostEqual(math.pi,3.14159265359, places=7)
if __name__=='__main__':
    unittest.main(verbosity=2)