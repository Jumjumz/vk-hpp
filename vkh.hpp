#ifndef VKH_HPP
#define VKH_HPP

#pragma once

#include <optional>
#include <vector>
#include <vulkan/vulkan_raii.hpp>

struct VulkanResources {
    // validation layer
    static inline const std::vector<char const *> validation_layers = {
        "VK_LAYER_KHRONOS_validation"};

#ifdef NDEBUG
    static constexpr bool enable_validation_layers = false;
#else
    static constexpr bool enable_validation_layers = true;
#endif
    // core
    static inline std::optional<vk::raii::Context> context;
    static inline std::optional<vk::raii::Instance> instance = nullptr;
    static inline std::optional<vk::raii::SurfaceKHR> surface_khr = nullptr;

    // devices
    static inline std::optional<vk::raii::PhysicalDevice> physical_device =
        nullptr;
    static inline std::optional<vk::raii::Device> logical_device = nullptr;

    // queue
    static inline std::optional<vk::raii::Queue> graphics_queue = nullptr;
    static inline std::optional<vk::raii::Queue> present_queue = nullptr;

    // surface config
    struct SurfaceConfig {
        vk::SurfaceCapabilitiesKHR capabilities;
        std::vector<vk::SurfaceFormatKHR> formats;
        std::vector<vk::PresentModeKHR> present_modes;

        vk::SurfaceFormatKHR chosen_format;
        vk::PresentModeKHR chosen_present_mode;
        vk::Extent2D chosen_extent;

        uint32_t image_count;
    };

    // swapchain
    static inline vk::raii::SwapchainKHR swapchain_khr = nullptr;

    // shader module
    static inline vk::raii::ShaderModule shader_module = nullptr;

    // pipeline
    static inline vk::raii::Pipeline graphics_pipeline = nullptr;
    static inline vk::raii::PipelineLayout pipeline_layout = nullptr;

    // layout
    static inline vk::raii::DescriptorSetLayout descriptor_set_layout = nullptr;

    // command pool
    static inline vk::raii::CommandPool command_pool = nullptr;

    // descriptor pool
    static inline vk::raii::DescriptorPool descriptor_pool = nullptr;
};

#endif // !VKH_HPP
