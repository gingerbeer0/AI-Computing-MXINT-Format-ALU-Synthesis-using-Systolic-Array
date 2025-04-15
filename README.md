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

Optimized for area and power efficiency

✅ Fast Shared Exponent Selection
Tree-based logic enables rapid shared exponent computation for 32 groups

📊 Evaluation Metrics
Power: Total power consumption from synthesis reports

Area: Cell and total area post-synthesis

Precision (SNR):

Throughput: Clock cycle × clock speed (averaged over Add, Mul, Sub)

📐 Architecture Diagram
(Insert Block Diagram Image Here)
Example:
![Block Diagram](./images/block_diagram.png)

🧪 Verification & Testing
Random 256-value FP16 inputs used

RTL and gate-level simulations performed

All outputs printed in the top module for debugging and verification

📁 Reports
report_timing -delay_type max → *_timing_report_max.txt

report_timing -delay_type min → *_timing_report_min.txt

report_area → *_area_report.txt

report_power → *_power_report.txt

📌 Additional Notes
SpyGlass used for linting and static checks

Low Voltage Threshold (LVT) cells utilized for power optimization