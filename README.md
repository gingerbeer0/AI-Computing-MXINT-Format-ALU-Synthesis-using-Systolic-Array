MXINT Format ALU Synthesis using Systolic Array
This project implements an ALU (Adder, Subtractor, Multiplier) using the MXINT (Microscaling Integer) format, commonly applied in deep learning for quantized, efficient computation. By leveraging a systolic array architecture, we significantly improve power, area, and throughput (PPA).

🔧 Project Overview
Designed and synthesized a 16-bit ALU using MXINT format

Supports Adder, Subtractor, and Multiplier

Utilizes shared exponent per group for compact representation

Follows data flow:
FP16 (IEEE 754) → MXINT → ALU Computation → Fixed-Point Format

Overflow handled with saturation logic

Internal stage outputs are visible from the Top Module

256 inputs grouped into 32-element vectors, processed with pairwise element operations
(e.g., Group1 = {1,2,...}, Group2 = {5,6,...} → 1×5, 2×6, ...)

🚀 Key Features
✅ Microscaling Format (MXINT)
Reduces exponent bit overhead through group-shared exponent

Enables efficient fixed-point computations while retaining precision

Widely used in deep learning quantization

✅ High-Precision 16-bit Support
Full 16-bit MXINT encoding used to maximize numerical resolution

✅ Systolic Array Architecture
Custom systolic design (Stair Array) enhances parallelism and data reuse
![image](https://github.com/user-attachments/assets/cf2a1310-0076-447b-8954-390e7a1ac0f3)


Optimized for area and power efficiency

✅ Fast Shared Exponent Selection
Tree-based logic enables rapid shared exponent computation for 32 groups

📊 Evaluation Metrics
Power: Total power consumption from synthesis reports

Area: Cell and total area post-synthesis

Precision (SNR):
![_5Ctext_7BSNR_20(dB)_7D_20_3D_2010_20_5Ccdot_20_5Clog__7B10_7D_20_5Cleft(_20_5Cfrac_7B_5Csum__7Bi_3D0_7D_5E_7B895_7D_20x__5Ctext_7Bexpected_7D_5Bi_5D_5E2_7D_7B_5Csum__7Bi_3D0_7D_5E_7B895_7D_20_5Cleft(x__5Ctext_7Be](https://github.com/user-attachments/assets/0127e5aa-c028-4e99-ae32-e74deab95cb0)

Throughput: Clock cycle × clock speed (averaged over Add, Mul, Sub)

📐 Architecture Diagram(Brief ver.)
![image](https://github.com/user-attachments/assets/ef83383a-14f5-4c02-b974-fb39486a66d5)


🧪 Verification & Testing
Random 256-value FP16 inputs used

RTL and gate-level simulations performed

All outputs printed in the top module for debugging and verification

📁 Result
![image](https://github.com/user-attachments/assets/88b5d775-c792-43f6-ae30-4c66de34859b)
![image](https://github.com/user-attachments/assets/694310ed-8b83-470b-8516-dbdbaae17cc5)



📌 Additional Notes
SpyGlass used for linting and static checks

Low Voltage Threshold (LVT) cells utilized for power optimization
